class Solution
{
    public:
        vector<int> majorityElement(vector<int> &v)
        {
           	//vector<int> ans;
           	//better TC: O(N*LOG(N)+O(N)) SC:O(N)
           	// map<int,int > m;
           	// for(auto i:nums) m[i]++;
           	// for(auto i:m)
           	// {
           	//     if(i.second>nums.size()/3) ans.emplace_back(i.first);
           	//     if(ans.size()==2) break;
           	// }
           	// return ans;

           	//OPTIMAL : 
            int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
            for (int i = 0; i < v.size(); i++)
            {
                if (cnt1 == 0 && ele2 != v[i])
                {
                    cnt1++;
                    ele1 = v[i];
                }
                else if (cnt2 == 0 && ele1 != v[i])
                {
                    cnt2++;
                    ele2 = v[i];
                }
                else if (v[i] == ele1) cnt1++;
                else if (v[i] == ele2) cnt2++;
                else
                {
                    cnt1--;
                    cnt2--;
                }
            }
            cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == ele1) cnt1++;
                if (v[i] == ele2) cnt2++;
            }
            int mini = (v.size() / 3) + 1;
            vector<int> ans;
            if (cnt1 >= mini) ans.emplace_back(ele1);
            if (cnt2 >= mini) ans.emplace_back(ele2);
            sort(ans.begin(), ans.end());
            return ans;
        }
};