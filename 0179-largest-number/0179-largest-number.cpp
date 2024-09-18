class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        // sort(nums.begin(),nums.end(),[&](int n1,int n2)
        //      {
        //          if(n1==n2) return true;
        //          string s1=to_string(n1),s2=to_string(n2);
        //          int len=min(s1.size(),s2.size());
        //          string mini=to_string(min(n1,n2)),maxi=to_string(max(n1,n2));
        //          int curr=0;
        //          while(curr<len)
        //          {
        //              if(s1[curr]==s2[curr]) curr++;
        //              else break;
        //          }
        //          // if(curr==len && (maxi.size()-curr)>mini.size()) return n1>n2;
        //          return curr<len?s1[curr]>s2[curr]:s1.back()>s2[0];
        //      });
        // simple
        if(*max_element(nums.begin(),nums.end())==0) return "0";
        sort(nums.begin(),nums.end(),[&](int n1,int n2)
             {
                 if(n1==n2) return true;
                 string s1=to_string(n1),s2=to_string(n2);
                 return (s1+s2)>(s2+s1);
             });
        for(auto i:nums) ans+=to_string(i);
        return ans;
    }
};