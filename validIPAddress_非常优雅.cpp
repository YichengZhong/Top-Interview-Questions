class Solution {
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) return "IPv4"; 
        if (isValidIPv6(IP)) return "IPv6";
        return "Neither";
    }
    
    // 优雅的split
    void split(const string s, vector<string>& vs, const char delim= ' '){
        istringstream iss(s);
        string temp;
        while (getline(iss,temp,delim)){
            vs.emplace_back(move(temp));
        }
        if (!s.empty() && s.back() == delim) vs.push_back({});//加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1.","2001:0db8:85a3:0:0:8A2E:0370:7334:"之类的情况
    }
    
    // 判定是否IPv4
    bool isValidIPv4(string IP){
        vector<string> vs;
        split(IP,vs,'.');
        if (vs.size()!=4) return false;
        
        for (auto &v:vs) {
            if (v.empty() || (v.size()>1 && v[0] == '0') || v.size()>3) return false;
            for (auto c:v) {
                if (!isdigit(c)) return false;
            }
            int n = stoi(v);
            if (n<0||n>255) return false;
        }
        
        return true;
    }
    
    // 判定是否IPv6
    bool isValidIPv6(string IP){
        vector<string> vs;
        split(IP,vs,':');
        if (vs.size()!=8) return false;
        for (auto &v:vs) {
            if (v.empty() || v.size()>4 ) return false;
            for (auto c:v){
                if (!(isdigit(c) || (c>='a'&&c<='f') || (c>='A'&&c<='F'))) return false;
            }
        }
        
        return true;
        
    }
};