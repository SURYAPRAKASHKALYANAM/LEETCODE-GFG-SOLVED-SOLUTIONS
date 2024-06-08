class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int size = hand.size();
            if (size % groupSize != 0) return false;
            map<int, int> m;
            for (auto i: hand) m[i]++;
            for (auto i: m)
            {
                if (m[i.first] > 0)
                {
                    // cout << m[i.first];
                    for (int ii = groupSize - 1; ii >= 0; ii--)
                    {
                       	// cout<<" "<<i.first+ii<<" "<<m[i.first + ii]-m[i.first]<<endl;
                        if ((m[i.first + ii] -= m[i.first]) < 0) return false;
                    }
                }
            }
            return true;
    }
};