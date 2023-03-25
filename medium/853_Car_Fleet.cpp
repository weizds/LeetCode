class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int> > combined;
        for(int i = 0; i < position.size(); ++i)
            combined.push_back({position[i], speed[i]});
        sort(combined.begin(), combined.end(), greater<pair<int, int> >());
        stack<double> fleets;
        for(auto car : combined){
            double time = (static_cast<double>(target - car.first) / car.second);
            if(fleets.empty() || time > fleets.top())
                fleets.push(time);
        }
        return fleets.size();
    }
};