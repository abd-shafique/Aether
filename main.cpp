#include <iostream>
#include <fstream>
#include "huffman.h"

std::string readFile(const std::string &filename)
{
    std::ifstream ifs(filename, std::ios::binary);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return content;
}

void writeFile(const std::string &filename, const std::string &content)
{
    std::ofstream ofs(filename, std::ios::binary);
    ofs << content;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " <compress|decompress> <input file> <output file>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    std::string content = readFile(inputFile);
    HuffmanCoding huffman;
    huffman.buildTree(content);

    if (command == "compress")
    {
        std::string encoded = huffman.encode(content);
        writeFile(outputFile, encoded);
    }
    else if (command == "decompress")
    {
        std::string decoded = huffman.decode(content);
        writeFile(outputFile, decoded);
    }
    else
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
