class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
    }
};