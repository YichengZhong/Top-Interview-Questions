class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first_point=0;
        int second_point=numbers.size()-1;
        
        vector<int>twoSum_Indexs;
        twoSum_Indexs.clear();
        
        while(first_point<second_point)
        {
            if(target==(numbers[first_point]+numbers[second_point]))
            {
                twoSum_Indexs.push_back(first_point+1);
                twoSum_Indexs.push_back(second_point+1);
                return twoSum_Indexs;
            }
            
            if(target<(numbers[first_point]+numbers[second_point]))
            {
                second_point--;
                continue;
            }
            
            if(target>(numbers[first_point]+numbers[second_point]))
            {
                first_point++;
                continue;
            }
            
        }
        
        return twoSum_Indexs;
               
             
    }
              
};