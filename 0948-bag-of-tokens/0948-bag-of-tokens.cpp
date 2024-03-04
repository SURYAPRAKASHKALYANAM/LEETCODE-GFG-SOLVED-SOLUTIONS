class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int score=0,max_sc=0;
        sort(tokens.begin(),tokens.end());
        int begin=0,end=tokens.size()-1;
        while(begin<=end)
        {
            if(power>=tokens[begin])
            {
                power-=tokens[begin++];
                score++;
            }
            else if(score>=1)
            {
                power+=tokens[end--];
                score--;
            }
            else return max_sc;
            max_sc=max(score,max_sc);
        }
        return max_sc;
    }
};