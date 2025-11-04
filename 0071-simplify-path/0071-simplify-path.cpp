class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> subs;
        string sub;
        while (getline(ss, sub, '/')) {
            if (sub == "..") {
                if (subs.size())
                    subs.pop_back();
            } else if (sub != "." && !sub.empty())
                subs.emplace_back(sub);
        }
        string s = "/";
        for (int i = 0; i < subs.size(); i++) {
            // cout<<subs[i]<<" "<<s<<endl;
            s += subs[i];
            if (i != subs.size() - 1)
                s += "/";
        }
        return s;
    }
};