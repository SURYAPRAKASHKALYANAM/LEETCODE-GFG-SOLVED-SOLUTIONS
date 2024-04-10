class Solution
{
    public:
        vector<int> deckRevealedIncreasing(vector<int> &deck)
        {
            sort(deck.begin(), deck.end());
            int right = deck.size() - 1;
            deque<int> q;
            q.push_back(deck[right--]);
            while (right >= 0)
            {
                q.push_front(q.back());
                q.pop_back();
                q.push_front(deck[right--]);
            }
            vector<int> ans(q.begin(), q.end());
            return ans;
        }
};