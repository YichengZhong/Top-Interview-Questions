class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>v_temp;
        vector<int>v_temp_2;
        vector<vector<int>>v_out;

        v_temp.clear();
        v_out.clear();

        if(0==numRows)
        {
            return v_out;
        }

        if(1==numRows)
        {
            v_temp.push_back(1);
            v_out.push_back(v_temp);
            return v_out;
        }

        if(2==numRows)
        {
            v_temp.push_back(1);
            v_out.push_back(v_temp);
            v_temp.push_back(1);
            v_out.push_back(v_temp);
            return v_out;
        }

        //第一行
        v_temp.push_back(1);
        v_out.push_back(v_temp);

        //第二行
        v_temp.push_back(1);
        v_out.push_back(v_temp);

        for (int i = 3; i <= numRows; ++i)
        {
            v_temp_2.push_back(1);
            for (int j = 0; j < v_temp.size() - 1; ++j)
            {
                int temp = v_temp[j] + v_temp[j + 1];
                v_temp_2.push_back(temp);
            }

            v_temp_2.push_back(1);

            v_out.push_back(v_temp_2);
            v_temp = v_temp_2;
            v_temp_2.clear();
        }

        return v_out;
        
    }
};