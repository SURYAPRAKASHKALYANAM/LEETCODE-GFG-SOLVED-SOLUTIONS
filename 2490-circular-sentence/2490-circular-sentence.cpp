class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string first="",prev="",word="";
        while(ss>>word)
        {
            if(first=="") prev=first=word;
            else if(prev.back()!=word[0]) return false;
            else prev=word;
        }
        return word.back()==first[0];
    }
};