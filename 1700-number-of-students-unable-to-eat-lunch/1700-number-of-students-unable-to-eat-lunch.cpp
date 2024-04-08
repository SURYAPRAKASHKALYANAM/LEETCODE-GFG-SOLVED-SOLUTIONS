class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<pair<int,int>> s;
        queue<int> q;
        for(int i=students.size()-1;i>=0;i--)
        {
            s.push({sandwiches[i],0});
            q.push(students[students.size()-i-1]);
        }
        int rem=0;
        while(s.size())
        {
            if(s.top().second==q.size()) break;
            if(s.top().first==q.front())
            {
                q.pop();
                s.pop();
            }
            else 
            {
                s.top().second++;
                q.push(q.front());
                q.pop();
                rem=q.size();
            }
        }
        return q.size();
    }
};