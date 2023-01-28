class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]])
            {
                m[s[i]]=i-m[s[i]];
                if(m[s[i]]!=distance[25-('z'-s[i])]) return false;
                
            }
            else m[s[i]]=i+1;
        }
//         for(int i=0;i<26;i++)
//         {
            
//         }
        return true;
    }
};