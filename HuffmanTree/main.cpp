//
//  main.cpp
//  HuffmanTree
//
//  Created by dbaofd on 2020/8/8.
//  Copyright © 2020 dbaofd. All rights reserved.
//
#include "HUFFMANTREE.hpp"
#include<string>

int main(int argc, const char * argv[]) {
    CharacterNode *p1, *p2;
    CharacterNode *node_array;
    int count;
    char str[100];
    cout << "Please input the string (less than 100 characters):" << endl;
    cin.getline(str,100);
    p1 = p2 = CharacterStatistic(str);
    count=GetNumberOfNodesInLinkedList(p1);
    HuffmanNode *huffman_node=(HuffmanNode *)malloc(sizeof(HuffmanNode) * (2*count+1)); //Define Huffman nodes, total number of nodes in Huffman tree is 2n+1, n is the unique character number.
    HuffmanCode *huffman_code=(HuffmanCode *)malloc(sizeof(HuffmanCode) * count); //Define Huffman code.
    node_array=TransformLinkedListToArray(p2, count);
    BubbleSort(node_array, count);
    FormHuffmanTree(huffman_node, count, node_array);
    GenerateHuffmanCode(huffman_node, count, huffman_code);
    DisplayCompressedCode(str, huffman_code, count, node_array);
    return 0;
}
