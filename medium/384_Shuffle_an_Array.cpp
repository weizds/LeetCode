class Solution {
public:
    Solution(vector<int>& nums) : original(nums), array(nums), seed(random_device{}()){
        
    }
    
    vector<int> reset() {
        array = original;
        return array;
    }
    
    vector<int> shuffle() {
        // std::shuffle(begin(array), end(array), seed);
        int n = array.size();
        for(int i = n - 1; i >= 0; --i) {
            int new_i = uniform_int_distribution<int>(0, i)(seed);
            swap(array[i], array[new_i]);
        }
        return array;
    }
private:
    vector<int> original;
    vector<int> array;
    default_random_engine seed;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */