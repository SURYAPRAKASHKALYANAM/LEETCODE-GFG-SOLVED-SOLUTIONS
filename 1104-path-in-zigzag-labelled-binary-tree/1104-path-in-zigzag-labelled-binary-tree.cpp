class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height=log2(label)+1;
        vector<int> ans;
        while(label)
        {
            ans.emplace_back(label);
            label=label/2;
            if(label==0) break;
            int pow2=log2(label);
            int diff=abs(label-pow(2,pow2))+1;
            label=pow(2,pow2)*2-diff;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};