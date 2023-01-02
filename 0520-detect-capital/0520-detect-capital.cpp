class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool ans=true;
        int lr=0,sr=0;
        if(word[0]<='Z')
        {
            for(int i=1;i<word.size();i++)
            {
                if(word[i]<='Z') lr++;
            }
        }
        else
        {
            for(int i=1;i<word.size();i++) 
            {
                if(word[i]<='Z') return false;
            }
            return true;
        }
        if(lr+1==word.size()) return true;
        else if(word[0]<='Z' && lr==0) return true;
        else return false;
        // return ans;  
    }
};