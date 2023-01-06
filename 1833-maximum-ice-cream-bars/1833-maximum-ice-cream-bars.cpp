class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        int c=0;
        for(auto i:costs)
        {
            if(i>coins) break;
            else
            {
                c++;
                coins-=i;
            }
        }
        return c;
        
    }
};