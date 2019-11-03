class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int length=s.length();
        //字符串长度为0、1时直接返回数字，双指针没有地方指。
        if(!length)
            return 0;
        if(length==1)
            return 1;
        //头指针p，最大长度mlen至少为1。
        int p=0,mlen=1;
        //尾指针end
        for(int end=1;end<length;end++){
            for(int aim=p;aim<end;aim++){
                //情况1
                if(s[aim]==s[end]){
                    //更新头指针p
                    p=aim+1;
                    //更新最大长度mlen
                    if(mlen<(end-aim))
                        mlen=end-aim;
                    break;
                }
            }
            //情况2。要算上尾指针所以+1。
            if(mlen<end-p+1)
                mlen=end-p+1;
        }
        return mlen;
        
    }
};