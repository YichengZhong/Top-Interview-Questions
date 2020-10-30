class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int>v_a;
        v_a=split(a);

        vector<int>v_b;
        v_b=split(b);

        int first=v_a[0]*v_b[0]-v_a[1]*v_b[1];
        int second=v_a[0]*v_b[1]+v_a[1]*v_b[0];

        string v_out="";
        v_out=to_string(first)+"+"+to_string(second)+"i";
        
        return v_out;
    }

    vector<int>split(string a)
    {
        string::size_type position_add;
        position_add = a.find("+");

        string::size_type position_i;
        position_i = a.find("i");

        string first_str=a.substr(0,position_add);
        int first=atoi(first_str.c_str());

        string second_str=a.substr(position_add+1);
        second_str.pop_back();
        int second=atoi(second_str.c_str());
        
        vector<int>temp;
        temp.clear();
        temp.push_back(first);
        temp.push_back(second);
        return temp;
    }
};