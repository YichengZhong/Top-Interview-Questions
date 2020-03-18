class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //首先建立一个graph
        vector<vector<int> > graph(numCourses, vector<int>());
        //graph的第i行存储的是完成课程i所需提前修读的课程
        for(auto num: prerequisites){
            graph[num[1]].push_back(num[0]);
        }
        vector<int> visit(numCourses);
        //遍历所有课程，判断修读课程i是否会出现冲突
        for(int i = 0; i < numCourses; i++){
            if(!dfs(graph, visit, i)) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int> >& g, vector<int>& visit, int i){
        if(visit[i] == -1) return false;
        if(visit[i] == 1) return true;
        visit[i] = -1; //表示课程i是待选修的，不能在后面的递归中出现课程i为需提前修读的课程
        for(auto a: g[i]){
            if(!dfs(g, visit, a)) return false;
        }
        visit[i] = 1;  //表示课程i能够成功修读
        return true;
    }
};