// class Router {
// public:
//     deque<vector<int>> dq;
//     unordered_map<int, multiset<pair<int, int>>>
//         sourceToDest;                          //  source : [[dest,time]]
//     unordered_map<int, multiset<int>> destMap; // dest : time
//     int memorySize, currSize = 0;
//     Router(int memoryLimit) {
//         memorySize = memoryLimit;
//         currSize = 0;
//     }

//     bool addPacket(int source, int destination, int timestamp) {
//         auto& destList = sourceToDest[source];
//         if (destList.find({destination, timestamp}) != destList.end())
//             return false;
//         if (currSize == memorySize) {
//             forwardPacket();
//         }
//         currSize += 1;
//         sourceToDest[source].insert({destination, timestamp});
//         destMap[destination].insert(timestamp);
//         dq.push_back({source, destination, timestamp});
//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (dq.empty())
//             return {};
//         auto pack = dq.front();
//         sourceToDest[pack[0]].erase({pack[1], pack[2]});
//         auto it = destMap[pack[1]].find(pack[2]);
//         if (it != destMap[pack[1]].end())
//             destMap[pack[1]].erase(it);
//         dq.pop_front();
//         currSize -= 1;
//         return pack;
//     }
//     int getCount(int destination, int startTime, int endTime) {
//         return distance(destMap[destination].lower_bound(startTime),
//                         destMap[destination].upper_bound(endTime));
//     }
// };
// optimal approach
class Router {
private:
    int size;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) |
               timestamp;
    }

    int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) -
                     list.begin());
    }

    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) -
                     list.begin());
    }

public:
    Router(int memoryLimit) { size = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (packets.find(key) != packets.end())
            return false;

        if ((int)packets.size() >= size)
            forwardPacket();

        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty())
            return {};

        long long key = q.front();
        q.pop();

        vector<int> packet = packets[key];
        packets.erase(key);

        int dest = packet[1];
        counts[dest].erase(counts[dest].begin()); // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);

        return right - left;
    }
};
/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */