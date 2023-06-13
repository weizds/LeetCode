class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.size(), false);
        q.push(0);
        while(!q.empty()) {
            int start = q.front();
            q.pop();
            if(visited[start])
                continue;
            for(int end = start + 1; end <= s.size(); ++end) {
                if(word_set.find(s.substr(start, end - start)) != word_set.end()) {
                    q.push(end);
                    if(end == s.size())
                        return true;
                }
            }
            visited[start] = true;
        }
        return false;
    }
};