#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cstring>

//https://www.topcoder.com/community/competitive-programming/tutorials/using-tries/
#define SIGMA  26
#define CH (*s - 'a') // values between 0-25, vector de frecv de la 'a' - 'z', poz 0 reprezinta a

class Trie {

    class TrieNode {

    public:
        TrieNode* children[SIGMA];
        int words = -1, childrenNum = -1;
        // words = the number of words that match with a given string

    public:
        TrieNode()
        {
            words = childrenNum = 0;

            memset(children, NULL, sizeof(children));
        }
    };

private:
    TrieNode* MyTrieRoot = new TrieNode;

private:

    void InsertWord(TrieNode* node, char* s)
    {
        if (*s == '\0')
        {
            node->words++;
            return;
        }

        if (node->children[CH] == NULL)
        {
            node->children[CH] = new TrieNode;
            node->childrenNum++;
        }

        InsertWord(node->children[CH], s + 1);
    }

    bool DeleteWord(TrieNode* node, char* s)
    {
        if (*s == '\0')
        {
            node->words--;
        }
        else if (DeleteWord(node->children[CH], s + 1))
        {
            node->children[CH] = NULL;
            node->childrenNum--;
        }

        if (node->words == 0 && node->childrenNum == 0 && node != MyTrieRoot)
        {
            delete node;
            return true;
        }

        return false;
    }

    int NumberOfWords(TrieNode* node, char* s)
    {
        if (*s == '\0')
            return node->words;

        if (node->children[CH] != NULL)
        {
            return NumberOfWords(node->children[CH], s + 1);
        }
        return 0;
    }

    int LongestCommonPrefix(TrieNode* node, char* s, int k)
    {
        if (*s == NULL || node->children[CH] == NULL)
            return k;

        return LongestCommonPrefix(node->children[CH], s + 1, k + 1);
    }


public:
    void Solve()
    {
        char line[0x1A];

        std::ifstream in("trie.in");
        std::ofstream out("trie.out");

        while (in.getline(line, 0x1A))
        {
            char* word = line + 2;
            switch (line[0])
            {
            case '0':
                InsertWord(MyTrieRoot, word);
                break;

            case '1':
                DeleteWord(MyTrieRoot, word);
                break;

            case '2':
                out << NumberOfWords(MyTrieRoot, word) << '\n';
                break;

            case '3':                // word = a prefix in this case
                out << LongestCommonPrefix(MyTrieRoot, word, 0) << '\n';
                break;
            }
        }

        in.close();
        out.close();
    }

};

int main()
{
    Trie t;
    t.Solve();
}
