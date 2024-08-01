#include "huffman.h"
#include <queue>
#include <vector>
#include <iostream>

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void HuffmanCoding::buildTree(const std::string &text)
{
    std::unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    std::priority_queue<Node *, std::vector<Node *>, compare> minHeap;
    for (auto pair : freq)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();

        Node *right = minHeap.top();
        minHeap.pop();

        int sum = left->freq + right->freq;
        Node *newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    root = minHeap.top();

    buildCode(root, "");
}

void HuffmanCoding::buildCode(Node *node, const std::string &str)
{
    if (!node)
        return;
    if (node->ch != '\0')
    {
        codes[node->ch] = str;
        reverseCodes[str] = node->ch;
    }
    buildCode(node->left, str + "0");
    buildCode(node->right, str + "1");
}

std::string HuffmanCoding::encode(const std::string &text)
{
    std::string encodedStr;
    for (char ch : text)
    {
        encodedStr += codes[ch];
    }
    return encodedStr;
}

std::string HuffmanCoding::decode(const std::string &encodedStr)
{
    std::string decodedStr;
    std::string curr;
    for (char ch : encodedStr)
    {
        curr += ch;
        if (reverseCodes.find(curr) != reverseCodes.end())
        {
            decodedStr += reverseCodes[curr];
            curr.clear();
        }
    }
    return decodedStr;
}
