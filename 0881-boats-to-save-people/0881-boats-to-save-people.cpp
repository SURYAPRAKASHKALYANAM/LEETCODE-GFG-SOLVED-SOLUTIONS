class Solution
{
    public:
        int numRescueBoats(vector<int> &people, int limit)
        {
            sort(people.begin(), people.end());
            int left = 0, right = people.size() - 1, boats = 0, cap = 0, cnt = 0;
            while (left <= right)
            {
                if (people[left] + people[right] <= limit)
                {
                    left++;
                    right--;
                    boats++;
                }
                else if (cnt != 2 && cap + people[right] <= limit)
                {
                    cap += people[right--];
                    cnt++;
                }
                else if (cnt != 2 && cap + people[left] <= limit)
                {
                    cap += people[left++];
                    cnt++;
                }
                else if (cnt <= 2)
                {
                    cnt = 0;
                    cap = 0;
                    boats++;
                }
            }
            if (cap != 0) boats++;
            return boats;
        }
};