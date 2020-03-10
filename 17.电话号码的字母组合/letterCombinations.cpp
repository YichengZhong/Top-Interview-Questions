class Solution {
public:
    std::unordered_map<char, std::string> m;

void InitMap() {
  m['2'] = "abc";
  m['3'] = "def";
  m['4'] = "ghi";
  m['5'] = "jkl";
  m['6'] = "mno";
  m['7'] = "pqrs";
  m['8'] = "tuv";
  m['9'] = "wxyz";
}
void Helper(const std::string &digits, string &phone_number, std::vector<std::string> &result) 
{
  if (phone_number.size() == digits.size())
   {
    result.push_back(phone_number);
  } else 
  {
    for (char c: m[digits[phone_number.size()]]) 
    {
      phone_number.push_back(c);
      Helper(digits, phone_number, result);
      phone_number.pop_back();
    }
  }
}
  
vector<string> letterCombinations(string digits) {
  if (digits.empty()) return {};
  InitMap();
  std::string phone_number;
  std::vector<std::string> result;
  Helper(digits, phone_number, result);
  return result;
}
};