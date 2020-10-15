#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;


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
        cout << "search : " << word << endl;

        Trie* node = this;
        cout << "node address: " << node << endl;
        for ( char ch : word ) {
            cout << "current character : " << ch << "  " <<  ch - 'a' << endl;


            if (node->next[ ch - 'a' ] != NULL) {
                cout << "next is not NULL" << endl;
                node = node->next[ ch - 'a'];
            } else {
                return false;
            }
        }
        cout << "node address: " << node << endl;
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        cout << "startsWith : " << prefix << endl;

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

string replaceWordsSimple(vector<string>& dictionary, string sentence) {
    set<string> prefixSet;
    for ( string word: dictionary) {
        prefixSet.insert(word);
        cout << word << endl;
    }

    string resultStr;

    int i = 0;
    int j = 0;
    while (i < sentence.length() && j < sentence.length()) {
        while (j < sentence.length() && sentence[j] != ' ') {
            ++j;
        }

        string thisWord = sentence.substr(i, j - i);
        cout << thisWord << endl;
        string prefix = thisWord;
        for ( int i = 0; i < thisWord.length(); ++i ) {
            string tmpStr = thisWord.substr(0, i);
            if ( prefixSet.find( tmpStr ) != prefixSet.end()) {
                prefix = tmpStr;
                break;
            }
        }

        resultStr.append(prefix).append(" ");

        i = j + 1;
        j = i;
    }

    if (!resultStr.empty()) {
        resultStr.pop_back();
    }
    return resultStr;
}


string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trieNode;
    for ( string prefix: dictionary )  {
        trieNode.insert(prefix);
    }

    string resultStr;

    int i = 0;
    int j = 0;
    while (i < sentence.length() && j < sentence.length()) {
        while (j < sentence.length() && sentence[j] != ' ') {
            ++j;
        }

        string thisWord = sentence.substr(i, j - i);
        cout << "thisWord: " << thisWord << endl;
        string prefix = thisWord;
        for ( int n = 1; n <= thisWord.size(); ++n ) {
            cout << n << endl;
            string tmpStr = thisWord.substr(0, n);
            cout << "tmpStr: " << tmpStr << endl;
            if ( trieNode.search( tmpStr )) {
                prefix = tmpStr;

                break;
            }
        }

        resultStr.append(prefix).append(" ");

        i = j + 1;
        j = i;
    }

    if (!resultStr.empty()) {
        resultStr.pop_back();
    }

    return resultStr;
}


int main() {
    vector<string> dictionary = {"cat", "bat", "rat", "bat"};
    cout << replaceWords(dictionary, "the  cattle was rattled by the battery") << endl;
    return 0;
}
