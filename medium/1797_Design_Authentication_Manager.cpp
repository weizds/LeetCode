class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        tokens_map[tokenId] = currentTime + timeToLive;
        pq.push({currentTime + timeToLive, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        udpateTokens(currentTime);
        auto it = tokens_map.find(tokenId);
        if(it != tokens_map.end()) {
            it->second = currentTime + timeToLive;
            pq.push({it->second, it->first});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        udpateTokens(currentTime);
        return tokens_map.size();
    }
private:
    void udpateTokens(int currentTime) {
        while(!pq.empty() && pq.top().first <= currentTime) {
            if(pq.top().first == tokens_map[pq.top().second])
                tokens_map.erase(pq.top().second);
            pq.pop();
        }
    }
    int timeToLive;
    unordered_map<string, int> tokens_map;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */