class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()) return false;

        string C=A+A;

        if(C.find(B)!=(-1))
            return true;

        return false;

    }
};