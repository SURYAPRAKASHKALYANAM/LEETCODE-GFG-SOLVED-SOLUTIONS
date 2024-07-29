class Solution {
public:
    int help2(vector<int> rating,int curr,int pos,bool less)
    {
        int cnt=0;
        if(less)
        {
            while(pos>=0)
            {
                if(rating[pos--]>curr) cnt++;
            }
        }
        else
        {
            while(pos<rating.size())
            {
                if(rating[pos++]<curr) cnt++;
            }
        }
        return cnt;
    }
    int help(vector<int> rating,int curr,int pos,bool less)
    {
        int cnt=0;
        if(less)
        {
            while(pos>=0)
            {
                if(rating[pos--]<curr) cnt++;
            }
        }
        else
        {
            while(pos<rating.size())
            {
                if(rating[pos++]>curr) cnt++;
            }
        }
        return cnt;
    }
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=1;i<rating.size()-1;i++)
        {
            int left=help(rating,rating[i],i-1,true),right=help(rating,rating[i],i+1,false);
            if(left && right)
            {
                ans+=left*right;
            }
            int rleft=help2(rating,rating[i],i-1,true),rright=help2(rating,rating[i],i+1,false);
            if(rleft && rright) ans+=rleft*rright;
        }
        return ans;
    }
};