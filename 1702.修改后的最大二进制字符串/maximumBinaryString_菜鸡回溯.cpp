class Solution {
public:
    string maxStr; 
    string orgStr;
    string maximumBinaryString(string binary) {
        if(binary.find("00")==string::npos && binary.find("10")==string::npos) return binary;
        
        maxStr=binary;
        orgStr=binary;
        helpDFS(binary);

        return maxStr;
    }

    void helpDFS(string binary)
    {
        maxStr=max(maxStr,binary);
        if(binary.find("00")==string::npos && binary.find("10")==string::npos) return;

        int find_ZeroZero_Index=binary.find("00");
        if(find_ZeroZero_Index!=string::npos)
        {
            string temp=binary;
            temp=temp.replace(find_ZeroZero_Index,2,"10");
            if(temp==orgStr) return;
            helpDFS(temp);
        }

        int find_OneZero_Index=binary.find("10");
        if(find_OneZero_Index!=string::npos)
        {
            string temp=binary;
            temp=temp.replace(find_OneZero_Index,2,"01");
            if(temp==orgStr) return;
            helpDFS(temp);
        }
    }
};