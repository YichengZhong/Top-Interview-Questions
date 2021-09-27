class Solution {
public:
    int openLock(const vector<string>& deadends, string target) {
        queue<string>BFS_queue;
        unordered_map<string,int>BFS_visited;
        unordered_map<string,int>BFS_Dead;

        //死亡数字进组
        for(const auto & deadend : deadends)
        {
            BFS_Dead[deadend]=1;
        }

        int step=0;
        BFS_queue.push("0000");
        BFS_visited["0000"]=1;

        while(!BFS_queue.empty())
        {
            int size=BFS_queue.size();

            for(int i=0;i<size;++i)
            {
                string cur=BFS_queue.front();
                BFS_queue.pop();

                if(cur==target)
                {

                    return step;
                }
                
                if(BFS_Dead.find(cur) != BFS_Dead.end())
                {
                    continue;
                }

                for(int j=0;j<4;++j)
                {
                    string up=plusOne(cur,j);
                    string down=minusOne(cur,j);

                    if(BFS_visited.find(up) == BFS_visited.end())
                    {
                        BFS_queue.push(up);
                        BFS_visited[up]=1;
                    }

                    if(BFS_visited.find(down) == BFS_visited.end())
                    {
                        BFS_queue.push(down);
                        BFS_visited[down]=1;
                    }
                }
            }

            step++;
        }

        return -1;
    }

    //向上拨动
    string plusOne(string s,int i)
    {
        if(s[i]=='9')
            s[i]='0';
        else
            s[i]=s[i]+1;
        return s;
    }

    //向下拨动
    string minusOne(string s,int i)
    {
        if(s[i]=='0')
            s[i]='9';
        else
            s[i]=s[i]-1;
        return s;
    }
};