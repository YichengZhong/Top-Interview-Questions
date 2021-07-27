class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        // 点的数量不够
        if(len < 3) {
            return len;
        }
        int maxNum = 2;
        // 遍历每两个点
        for(int i = 0; i < len; i ++) {
            unordered_map<double, int> count;
            for(int j = 0; j < len; j ++) {
                if(i != j) {
                    long long dx = points[i][0] - points[j][0];
                    long long dy = points[i][1] - points[j][1];
                    double gradient = dy * 1.0 / dx;
                    if(count.count(gradient)) {
                        count[gradient] ++;
                    } else {
                        count[gradient] = 2;
                    }
                    maxNum = max(maxNum, count[gradient]);
                } 
            }  
        }
        
        return maxNum;
    }
};