class Solution {
public:
    vector<string>v_out;
    int countVowelStrings(int n) {
        v_out.clear();
        vector<string>dig_list;
        dig_list.clear();

        dig_list.push_back("a");
        dig_list.push_back("e");
        dig_list.push_back("i");
        dig_list.push_back("o");
        dig_list.push_back("u");


        helpDFS("",dig_list,0,n);
        return v_out.size();
    }

    void helpDFS(string temp,vector<string>&dig_list,int index,int n)
    {
        if(temp.size()==n)
        {
            v_out.push_back(temp);
        }

        if(temp.size()>n) return ;

        for(int i=index;i<dig_list.size();++i)
        {
            helpDFS(temp+dig_list[i],dig_list,i,n);
        }
    }
};