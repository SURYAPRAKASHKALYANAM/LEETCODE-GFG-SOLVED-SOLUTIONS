class Solution
{
    int string_to_int(string s)
    {
        int rem = 0;
        int l = 0;
        while (l < s.size())
        {
            rem = rem *10 + (s[l] - '0');
            l++;
        }
        return rem;
    }
    string removeLeadingZeros(string & str)
    {
        auto pos = str.find_first_not_of('0');
        if (pos != string::npos)
        {
            return str.substr(pos);
        }
        return "0";
    }
    void adv_tokenizer(string s, char del, vector<int> &vec)
    {
        stringstream ss(s);
        string word;
        while (!ss.eof())
        {
            getline(ss, word, del);
            vec.emplace_back(string_to_int(removeLeadingZeros(word)));
        }
    }
    public:
        int compareVersion(string version1, string version2)
        {
            vector<int> vec1, vec2;
            adv_tokenizer(version1, '.', vec1);
            adv_tokenizer(version2, '.', vec2);
            int l1 = vec1.size(), l2 = vec2.size();
            if (l1 < l2)
            {
                while (l1 < l2)
                {
                    vec1.emplace_back(0);
                    l1++;
                }
            }
            else if (l1 > l2)
            {
                while (l1 > l2)
                {
                    vec2.emplace_back(0);
                    l2++;
                }
            }
            for (int i = 0; i < l1; i++)
            {
                if (vec1[i] > vec2[i]) return 1;
                else if (vec2[i] > vec1[i]) return -1;
            }
            return 0;
        }
};