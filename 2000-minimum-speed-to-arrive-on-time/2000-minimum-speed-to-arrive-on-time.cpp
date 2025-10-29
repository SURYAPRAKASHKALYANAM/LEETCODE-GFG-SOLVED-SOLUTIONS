class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1, end = 1e7, mid;
        int minSpeed = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (timeTaken(dist, mid) <= hour) {
                if (minSpeed == -1)
                    minSpeed = mid;
                else
                    minSpeed = min(minSpeed, mid);
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return minSpeed;
    }

    double timeTaken(vector<int>& dist, int& speed) {
        double t = 0;
        for (int i = 0; i < dist.size(); i++) {
            double jortime = ((double)dist[i]) / (double)speed;
            if (i == dist.size() - 1)
                t += jortime;
            else
                t += ceil(jortime);
        }
        // cout << speed << " " << t << endl;
        return t;
    }
};