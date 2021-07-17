class Solution {
    vector<vector<int>>res;
public:
    void dfs(vector<int>&temp,vector<vector<int>>&graph,int index){
        if(temp.back()==graph.size()-1){
            res.push_back(temp);
            return ;
        }
        for(int i=0;i<graph[index].size();i++){
            temp.push_back(graph[index][i]);
            dfs(temp,graph,graph[index][i]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        temp.push_back(0);
        dfs(temp,graph,0);
        return res;
    }
};