class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> diff;
        int len = startTime.size();
        int cnt = 1;
        diff.push_back(startTime[0]);
        int max_time = diff[0], curr_time = diff[0];
        for (int i = 0; i < len - 1; i++) {
            diff.push_back(startTime[i + 1] - endTime[i]);
            if (cnt - (k + 1) >= 0) {
                curr_time -= diff[cnt - (k + 1)];
            }
            curr_time += diff[cnt];
            cnt++;
            max_time = max(max_time, curr_time);
        }
        diff.push_back(eventTime - endTime[len - 1]);
        if (cnt - (k + 1) >= 0) {
            curr_time -= diff[cnt - (k + 1)];
        }
        curr_time += diff[cnt];
        cnt++;
        max_time = max(max_time, curr_time);
        return max_time;
    }
};