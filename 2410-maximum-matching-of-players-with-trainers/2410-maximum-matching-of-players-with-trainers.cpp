class Solution
{
    public:
        int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
            int i = 0, j = 0;
            while (1)
            {
                if(j>=trainers.size() || i>=players.size()) break; 
                if (trainers[j] >= players[i])
                {
                    i++;
                    j++;
                }
                else j++;
            }
            return i;
        }
};