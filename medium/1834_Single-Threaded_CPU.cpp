class Solution {
public:
    struct Task {
        int start;
        int duration;
        int index;
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> sorted_tasks(tasks.size());
        for(int i = 0; i < tasks.size(); ++i)
            sorted_tasks[i] = {tasks[i][0], tasks[i][1], i};
        sort(sorted_tasks.begin(), sorted_tasks.end(), [](const Task &t1, const Task &t2){
            if(t1.start == t2.start)
                return t1.index < t2.index;
            return t1.start < t2.start;
        });
        vector<int> res;
        long long time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        while(i < sorted_tasks.size() || !pq.empty()) {
            if(pq.empty() && time < sorted_tasks[i].start)
                time = sorted_tasks[i].start;
            while(i < sorted_tasks.size() && time >= sorted_tasks[i].start) {
                pq.push({sorted_tasks[i].duration, sorted_tasks[i].index});
                ++i;
            }
            auto [duration, index] = pq.top();
            pq.pop();
            time += duration;
            res.push_back(index);
        }
        return res;
    }
};