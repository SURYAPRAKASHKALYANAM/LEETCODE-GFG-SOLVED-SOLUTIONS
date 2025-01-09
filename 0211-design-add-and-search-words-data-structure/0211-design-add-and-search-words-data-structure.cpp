class Node
{
    public:
    Node *link[26];
    bool isEndofWord = false;
    bool containkey(char ch)
    {
        return link[ch - 'a'] != NULL;
    }
    void putkey(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node* get(char ch)
    {
        return link[ch - 'a'];
    }
    void setend()
    {
        isEndofWord = true;
    }
    bool isend()
    {
        return isEndofWord;
    }
};
class WordDictionary
{
    private:
        Node * root;
    public:
        WordDictionary()
        {
            root = new Node();
        }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->get(word[i]) == NULL)
                node->putkey(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setend();
    }

    bool search(string word)
    {
        Node *node = root;
        node = dfs(word, 0, node);
        return node && node->isend();
    }

    Node* dfs(string word, int pos, Node *node)
    {
        if (pos == word.size()) return node;
        if (word[pos] == '.')
        {
            for (int i = 0; i <= 25; i++)
            {
                Node *next = node->get('a' + i);
                if (next)
                {
                    Node *res = dfs(word, pos + 1, next);
                    if (res && res->isend()) return res;
                }
            }
        }
        else
        {
            Node *next = node->get(word[pos]);
            if (next == NULL) return NULL;
            return dfs(word, pos + 1, next);
        }
        return NULL;
    }
};

/**
 *Your WordDictionary object will be instantiated and called as such:
 *WordDictionary* obj = new WordDictionary();
 *obj->addWord(word);
 *bool param_2 = obj->search(word);
 */