class Solution
{
    public:
        string longestDiverseString(int aa, int bb, int cc)
        {
            priority_queue<pair<int, char>> q;
            if (aa) q.push({ aa,'a' });
            if (bb) q.push({ bb,'b' });
            if (cc) q.push({ cc,'c' });
            char a, b,last='_';
            int cnt1, cnt2 = 0;
            string ans = "";
            while (!q.empty())
            {
                a = q.top().second;
                cnt1 = q.top().first;
                q.pop();
                if (last==a) break;
                if (cnt1 > 1)
                {
                    ans += a;
                    ans += a;
                    cnt1 -= 2;
                }
                else  ans += a, cnt1--;
                last=a;
                if (!q.empty())
                {
                    b = q.top().second;
                    cnt2 = q.top().first;
                    q.pop();
                    if (cnt2 > 1 && cnt2>=cnt1)
                    {
                        ans += b;
                        ans += b;
                        cnt2 -= 2;
                    }
                    else ans += b, cnt2--;
                    last=b;
                }
                if (cnt1 > 0) q.push({ cnt1,a });
                if (cnt2 > 0) q.push({ cnt2,b });
            }
            return ans;
        }
};