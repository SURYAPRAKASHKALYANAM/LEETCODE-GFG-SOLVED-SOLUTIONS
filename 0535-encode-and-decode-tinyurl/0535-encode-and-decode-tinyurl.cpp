
class Solution {
private:
    unordered_map<string, string> urlDir;

    static string generateRandomString(int length = 9) {
        static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz"
                                    "0123456789";

        static thread_local mt19937 gen(random_device{}());
        static thread_local uniform_int_distribution<> dist(0,
                                                            chars.size() - 1);

        string result;
        result.reserve(length);

        for (int i = 0; i < length; ++i) {
            result += chars[dist(gen)];
        }
        return result;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(const string& longUrl) {
        string tiny;
        do {
            tiny = generateRandomString();
        } while (urlDir.find(tiny) != urlDir.end());

        urlDir.emplace(tiny, longUrl);
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string& shortUrl) const {
        auto it = urlDir.find(shortUrl);
        if (it != urlDir.end()) {
            return it->second;
        }
        return {};
    }
};