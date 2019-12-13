class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>v_str_out;
        v_str_out.clear();

        if(0==n)
        {
            return v_str_out;
        }

        string Fizz="Fizz";
        string Buzz="Buzz";
        string FizzBuzz="FizzBuzz";

        for(int i=0;i<n;++i)
        {
            if((i+1)%15==0 && (i+1)>=15)
            {
                v_str_out.push_back(FizzBuzz);
                continue;
            }
            else if((i+1)%3==0)
            {
                v_str_out.push_back(Fizz);
                continue;
            }
            else if((i+1)%5==0)
            {
                v_str_out.push_back(Buzz);
                continue;
            }
            else
            {
                v_str_out.push_back(to_string(i+1));
                continue;
            }
        }


        return v_str_out;
    }
};