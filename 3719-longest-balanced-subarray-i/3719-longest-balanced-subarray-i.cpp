class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len = nums.size();
        int max_len = 0;
        for (int i = 0; i < len; i++) {
            unordered_map<int, int> eve, odd;
            int ecnt = 0, ocnt = 0;
            for (int j = i; j < len; j++) {
                if(nums[j]&1){
                    if(!odd[nums[j]]) ocnt++;
                    odd[nums[j]]=1;
                } else{
                    if(!eve[nums[j]]) ecnt++;
                    eve[nums[j]]=1;
                }
                if(ocnt==ecnt){
                    max_len = max(max_len,j-i+1);
                }
                
            }
        }
        return max_len;
    }
};