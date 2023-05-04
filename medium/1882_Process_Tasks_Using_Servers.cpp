class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res(tasks.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        for(int i = 0; i < servers.size(); ++i)
            free.push({servers[i], i});
        int task_index = 0;
        int current_time = 0;
        while(task_index < tasks.size()) {
            while(!busy.empty() && busy.top().first <= current_time) {
                int i = busy.top().second; 
                free.push({servers[i], i});
                busy.pop();
            }
            if(free.empty()) {
                current_time = busy.top().first;
                continue;
            }
            while(!free.empty() && task_index <= current_time && task_index < tasks.size()) {
                int i = free.top().second;
                busy.push({tasks[task_index] + current_time, i}); 
                free.pop();
                res[task_index] = i; 
                ++task_index;
            }
            ++current_time;
        }
        return res;
    }
};