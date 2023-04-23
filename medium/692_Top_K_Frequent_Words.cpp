class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> words_count;
        for(const auto &word : words)
            ++words_count[word];
        vector<set<string>> buckets(words.size() + 1);
        for(const auto &p : words_count)
            buckets[p.second].insert(p.first);
        vector<string> res;
        for(auto set_it = buckets.rbegin(); set_it != buckets.rend(); ++set_it) {
            for(auto it = set_it->begin(); it != set_it->end() && k > 0; ++it) {
                res.push_back(*it);
                --k;
            }
        }
        return res;
    }
};