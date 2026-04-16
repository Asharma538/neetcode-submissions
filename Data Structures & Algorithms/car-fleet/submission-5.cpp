class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0; i<speed.size(); i++) cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        float e = 0;
        int fleets = 0;

        for(auto i : cars){
            cout<<i.first<<' '<<i.second<<'\n';
            if (e < (float)(target-i.first)/(float)i.second){
                fleets++;
                e = (float)(target-i.first)/(float)i.second;
            }
            cout<<e<<'\n';
        }

        return fleets;
    }
};
