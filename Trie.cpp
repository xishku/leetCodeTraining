class Trie {
private:
    bool isEnd = false;
    Trie* next[26];

public:
    Trie() {
        isEnd = false;
        memset( next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* node = this;
        for ( char ch: word) {
            if ( node->next[ ch - 'a' ] == NULL) {
                node->next[ ch - 'a' ] = new Trie();
            }

            node = node->next[ ch - 'a' ];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for ( char ch : word ) {
            if (node-next[ ch - 'a' ] != NULL) {
                node = node->next[ ch - 'a'];
            } else {
                return false;
            }
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for ( char ch : prefix ) {
            if (node->next[ ch - 'a'] != NULL) {
                node = node->next[ ch - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
