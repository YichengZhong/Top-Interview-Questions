class Solution {
public:
     bool valid(int n){
        int nt = n;
        while(true){
            int temp = n%10;
            if(temp==0 || nt%temp != 0) return false;
            n /= 10;
            if(n==0) return true;
        }
    }
    vector<int> selfDividingNumbers(int left, int right) {
 vector<int> ans;
        for(int i = left; i <= right; i++)
            if(valid(i)) ans.push_back(i);
        return ans;

        
    }
};