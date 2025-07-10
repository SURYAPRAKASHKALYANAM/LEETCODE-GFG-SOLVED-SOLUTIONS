class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> diff;
        int len = startTime.size();
        diff.push_back(startTime[0]);
        for (int i = 0; i < len - 1; i++) {
            diff.push_back(startTime[i + 1] - endTime[i]);
        }
        diff.push_back(eventTime - endTime[len - 1]);
        int max_time = 0, curr_time = 0;
        for (int i = 0; i < diff.size(); i++) {
            if ((i - (k + 1)) >= 0)
                curr_time -= diff[i - (k + 1)];
            curr_time += diff[i];
            max_time = max(max_time, curr_time);
        }
        return max_time;
    }
};