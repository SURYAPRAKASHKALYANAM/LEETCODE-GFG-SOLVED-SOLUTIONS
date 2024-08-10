class Solution
{
    public:
        vector<vector < int>> sortTheStudents(vector<vector < int>> &score, int k)
        {
            sort(score.begin(), score.end(), [& k](vector<int> v1, vector<int> v2){
                return v1[k] > v2[k];
            });
            return score;
        }
};