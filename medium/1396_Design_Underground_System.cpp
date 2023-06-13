struct Event{
    string station;
    int time;
};

struct Average{
    double sum;
    int count;
};

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        unfinished[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto found = unfinished.find(id);
        if(found != unfinished.end()) {
            auto& average = finished[found->second.station + "#" + stationName];
            average.sum += t - found->second.time;
            ++average.count;
            unfinished.erase(found);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto found = finished.find(startStation + "#" + endStation);
        if(found != finished.end())
            return found->second.sum / found->second.count;
        return 0;
    }
private:
    unordered_map<int, Event> unfinished;
    unordered_map<string, Average> finished;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */