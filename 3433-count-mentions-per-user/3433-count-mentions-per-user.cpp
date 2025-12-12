class Solution {
public:
    vector<int> get_ids(string& str) {
        vector<int> ids;
        stringstream ss(str);
        string sub;
        while (ss >> sub) {
            ids.emplace_back(stoi(sub.substr(2)));
        }
        return ids;
    }
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers), offlineTill(numberOfUsers);
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int timeA = stoi(a[1]);
                 int timeB = stoi(b[1]);
                 if (timeA != timeB) {
                     return timeA < timeB;
                 }
                 return a[0] > b[0];
             });
        for (auto& event : events) {
            int currTimeStamp = stoi(event[1]);
            cout << currTimeStamp << endl;
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineTill[i] <= currTimeStamp)
                            mentions[i]++;
                    }
                } else {
                    for (int& id : get_ids(event[2])) {
                        mentions[id]++;
                    }
                }

            } else {
                offlineTill[stoi(event[2])] = currTimeStamp + 60;
            }
        }

        return mentions;
    }
};