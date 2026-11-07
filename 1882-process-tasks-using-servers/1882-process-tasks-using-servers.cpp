class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long, long>, vector<pair<long, long>>,
                       greater<pair<long, long>>> availableServers;

        priority_queue<pair<long, pair<long, long>>,
                       vector<pair<long, pair<long, long>>>,
                       greater<pair<long, pair<long, long>>>> busyServers;
        ;
        for (int i = 0; i < servers.size(); i++) {
            availableServers.push({servers[i], i});
        }
        long long tLen = tasks.size(), currTask = 0, currTime = 0;
        vector<int> ans(tLen);
        while (currTask < tLen) {
            currTime = max(currTime, currTask);
            while (!busyServers.empty() &&
                   busyServers.top().first <= currTime) {
                availableServers.push(busyServers.top().second);
                busyServers.pop();
            }
            if (availableServers.empty()) {
                currTime = busyServers.top().first;
                continue;
            }
            busyServers.push(
                {currTime + tasks[currTask], availableServers.top()});
            ans[currTask] = availableServers.top().second;
            availableServers.pop();
            currTask++;
            currTime = max(currTime, currTask);
        }
        return ans;
    }
};