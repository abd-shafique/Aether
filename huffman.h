#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

class HuffmanCoding
{
public:
    void buildTree(const std::string &text);
    std::string encode(const std::string &text);
    std::string decode(const std::string &encodedStr);

private:
    Node *root;
    void buildCode(Node *node, const std::string &str);
    std::unordered_map<char, std::string> codes;
    std::unordered_map<std::string, char> reverseCodes;
};

#endif
