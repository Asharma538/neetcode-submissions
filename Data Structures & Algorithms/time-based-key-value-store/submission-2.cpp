class TimeMap {
public:
    map<string, set<pair<int,string>>> mp;
    TimeMap(){

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].lower_bound({timestamp, ""});
        if (it!=mp[key].end() and it->first == timestamp ){
            return mp[key].lower_bound({timestamp, ""})->second;
        }
        if (it == mp[key].begin()) return "";
        return (--it)->second;
    }
};
