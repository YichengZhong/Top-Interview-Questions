class Solution {
private:
    vector<int> Elements;
 
public:
    Solution(vector<int> nums) {
        Elements = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return Elements;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> vShuffle = Elements;
        //srand(time(NULL));
        for(int i=0;i<vShuffle.size();i++){
            int r = rand()%(vShuffle.size()-i)+i;
            if(r!=i)
                swap(vShuffle[r], vShuffle[i]);
                
            
           
        }
        return vShuffle;
    }
};