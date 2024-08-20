class Solution
{
    public:
        bool asteroidsDestroyed(int mass, vector<int> &asteroids)
        {
            long sum=(long)mass;
            sort(asteroids.begin(), asteroids.end());
            for (auto i: asteroids)
            {
                if (sum < i) return false;
                sum += i;
            }
            return true;
        }
};