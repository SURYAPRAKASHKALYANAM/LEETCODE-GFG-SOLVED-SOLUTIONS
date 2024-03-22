class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26,0),leftover;
        for(auto i:tasks) counts[i-'A']++;
        priority_queue<int> order;
        for(auto i:counts)
        {
            if(i) order.push(i);
        }
        int time=0,cool;
        while(!order.empty())
        {
            cool=n+1;
            while(cool && !order.empty())
            {
                auto it=order.top();
                order.pop();
                if(it>1) leftover.emplace_back(--it);
                time++;
                cool--;
            }
            for(auto i:leftover) order.push(i);
            leftover.clear();
            if(order.empty()) break;
            time+=cool;
        }
        return time;
    }
};