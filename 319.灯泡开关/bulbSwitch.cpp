class Solution {
public:
    int bulbSwitch(int n) {
        int cout=0;

        for(int i=0;i<n;++i)
        {
            int temp=sqrt(i+1);

            if(temp*temp==(i+1))
            {
                cout++;
            }
        }

        return cout;

    }
};