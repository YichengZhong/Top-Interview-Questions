class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(), S.end(),'-'),S.end());
        for (auto& letter : S) {
            letter = toupper(letter);
        }
        int n = S.size();
        for (int i = 1; i * K < n; i++) {
           S.insert(S.begin() + n - i * K, '-');
        }
        return S;
    }
};