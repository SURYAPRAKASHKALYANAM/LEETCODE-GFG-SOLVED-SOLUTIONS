class EventManager {
public:
    map<int, set<int>> mp;
    unordered_map<int, int> seen;
    EventManager(vector<vector<int>>& events) {
        for (auto event : events) {
            seen[event[0]] = event[1];
            mp[event[1]].insert(event[0]);
        }
    }

    void updatePriority(int eventId, int newPriority) {
        mp[seen[eventId]].erase(eventId);
        if(mp[seen[eventId]].size()==0) mp.erase(seen[eventId]);
        seen[eventId] = newPriority;
        mp[seen[eventId]].insert(eventId);
    }

    int pollHighest() {
        if (mp.empty())
            return -1;
        auto it = mp.rbegin();
        if (mp[it->first].size() == 0)
            return -1;
        int evnt = *((it->second).begin());
        mp[it->first].erase(evnt);
        if (mp[it->first].size() == 0)
            mp.erase(it->first);
        return evnt;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */