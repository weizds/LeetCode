class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encode_map.find(longUrl) != encode_map.end()) {
            return encode_map[longUrl];
        }
        stringstream ss;
        ss << "http://tinyurl.com/" << hex << hash<string>{}(longUrl);
        encode_map[longUrl] = ss.str();
        decode_map[ss.str()] = longUrl;
        return ss.str();
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode_map[shortUrl];
    }
private:
    unordered_map<string, string> encode_map;
    unordered_map<string, string> decode_map;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));