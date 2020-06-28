class Solution {
public:
    vector<string> split(const string &s, const string &seperator)
    {
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;
  
    while(i != s.size())
    {
        //找到字符串中首个不等于分隔符的字母
        int flag = 0;
        while(i != s.size() && flag == 0)
        {
            flag = 1;
            for(string_size x = 0; x < seperator.size(); ++x)
            if(s[i] == seperator[x])
            {
                ++i;
                flag = 0;
                break;
            }
            }
    
        //找到又一个分隔符，将两个分隔符之间的字符串取出
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0)
        {
            for(string_size x = 0; x < seperator.size(); ++x)
        　　if(s[j] == seperator[x])
            {
                flag = 1;
                break;
            }
            if(flag == 0) 
    　　        ++j;
        }
            if(i != j)
            {
                result.push_back(s.substr(i, j-i));
                i = j;
            }    
    }
    return result;
}

    string simplifyPath(string path) {
        vector<string> path_item;
        path_item.clear();

        if(path.size()==0)
        {
            return "";
        }

        path_item=split(path, "/");

        stack<string>stack_str;

        for(int i=0;i<path_item.size();++i)
        {
            if(path_item[i].size()==0)
            {
                continue;
            }

            if(path_item[i]!=".." && path_item[i]!=".")
            {
                stack_str.push(path_item[i]);         
            }
            else if(path_item[i]=="..")
            {
                if(!stack_str.empty())
                {
                    stack_str.pop();
                }
            }
            else if(path_item[i]==".")
            {
                continue;
            }
        }

        string out="";
        vector<string>v_temp;
        if(stack_str.empty())
        {
            return "/";
        }

        while(!stack_str.empty())
        {
            string temp=stack_str.top();
            v_temp.push_back(temp);
            stack_str.pop();
        }
        reverse(v_temp.begin(),v_temp.end());
        for(int i=0;i<v_temp.size();++i)
        {
            out=out+"/"+v_temp[i];
        }


        return out;
    }
};