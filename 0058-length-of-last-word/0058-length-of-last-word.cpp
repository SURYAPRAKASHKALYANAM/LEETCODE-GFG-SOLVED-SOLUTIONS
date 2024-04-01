class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0,n=s.size()-1;;
        while(s[n]==' ') n--;
        while(n>=0 && s[n]!=' ') n--,cnt++;
        return cnt;
    }
};