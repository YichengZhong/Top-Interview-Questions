class AuthenticationManager {
public:
    unordered_map<string,int>token_time;
    int g_timeToLive;
    AuthenticationManager(int timeToLive) {
        g_timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        token_time[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(token_time.find(tokenId)==token_time.end()) return ;
        if((token_time[tokenId]+g_timeToLive)==currentTime) return;
        if((token_time[tokenId]+g_timeToLive)<currentTime) return;
        token_time[tokenId]=currentTime;

    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto iter=token_time.begin();iter!=token_time.end();++iter)
        {
            if((iter->second+g_timeToLive)>currentTime) count++;
        }
        
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */