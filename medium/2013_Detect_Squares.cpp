class DetectSquares {
public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        ++map[{point[0], point[1]}];
        list.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int res = 0;
        for(auto point : list){
            int point_x = point.first;
            int point_y = point.second;
            if((abs(x - point_x) != abs(y - point_y)) ||
              x == point_x || y == point_y)
                continue;
            res += map[{x, point_y}] * map[{point_x, y}];
            }
        return res;
    }
private:
    map<pair<int, int>, int> map;
    list<pair<int, int> > list;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */