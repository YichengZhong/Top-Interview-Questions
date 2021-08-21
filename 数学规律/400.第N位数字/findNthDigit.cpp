class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL")!=(-1)) return false;

        int count=0;class Solution {
public:
    int findNthDigit(int k) {
        //直接数学找规律法
        if(k == 0) 
            return 0;

        int digit = 1; 
        long start = 1; 
        long index_count = digit * 9 * start; 

        while(k > index_count ) 
        {
            k=k-index_count; 
            ++digit;
            start=10*start;
            index_count =digit*9*start;
        }

        long num = start + (k - 1) / digit; 
        int remainder = (k - 1) % digit;
        
        string s_num = to_string(num); 
        return int(s_num[remainder] - '0'); 
    }
};
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='A')
            {
                count++;
            }

            if(count>=2) return false;
        }

        return true;

    }
};