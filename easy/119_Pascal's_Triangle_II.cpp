class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1};
        int index = 0;
        while(index++ < rowIndex) {
            for(int i = res.size() - 1; i > 0; --i)
                res[i] += res[i - 1];
            res.push_back(1);
        }
        return res;
    }
};