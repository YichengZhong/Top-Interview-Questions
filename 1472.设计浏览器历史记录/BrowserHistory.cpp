class BrowserHistory {
public:
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        cur = 0;
        last = cur + 1;
    }

    void visit(string url)
     {
        if (cur == history.size() - 1) 
        {
            history.push_back(url);
        }
        else 
        {
            history[cur + 1] = url;
        }
        cur += 1;
        last = cur + 1;
    }

    string back(int steps)
    {
        steps = min(cur, steps);
        cur -= steps;
        return history[cur];
    }

    string forward(int steps)
    {
        steps = min(last - cur - 1, steps);
        cur += steps;
        return history[cur];
    }

private:
    vector<string> history;
    int cur = 0;
    int last = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */