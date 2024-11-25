class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int min_steps=0;
        vector<vector<int>> moves={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string curr="",target="123450";
        for(int i=0;i<2;i++) for(int j=0;j<3;j++) curr+=to_string(board[i][j]);
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        visited.insert(curr);
        q.push({curr,0});
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            curr=it.first;
            int steps=it.second,pos=curr.find('0');
            if(curr==target) return steps;
            for(auto i:moves[pos])
            {
                string next = curr;
                swap(next[pos], next[i]);
                if(!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};