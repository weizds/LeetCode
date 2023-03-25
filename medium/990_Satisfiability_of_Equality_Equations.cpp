class Solution {
public:
    struct Subset {
        int parent;
        int rank;
    };
    int find(int val) {
        if(subsets[val].parent != val) {
            subsets[val].parent = find(subsets[val].parent);
        }
        return subsets[val].parent;
    }
    void unionSubsets(int root1, int root2) {
        if(subsets[root1].rank < subsets[root2].rank) {
            subsets[root1].parent = root2;
        }else if(subsets[root1].rank > subsets[root2].rank) {
            subsets[root2].parent = root1;
        }else{
            subsets[root2].parent = root1;
            ++subsets[root1].rank;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; ++i) {
            subsets.push_back({i, 0});
        }
        for(auto equation : equations) {
            if(equation[1] == '=') {
                int first = find(equation[0] - 'a');
                int second = find(equation[3] - 'a');
                unionSubsets(first, second);
            }
        }
        for(auto equation : equations) {
            if(equation[1] == '!') {
                int first = find(equation[0] - 'a');
                int second = find(equation[3] - 'a');
                if(first == second)
                    return false;
            }
        }
        return true;
    }
private:
    vector<Subset> subsets;
};