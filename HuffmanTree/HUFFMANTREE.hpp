//
//  HUFFMANTREE.hpp
//  HuffmanTree
//
//  Created by dbaofd on 2020/8/8.
//  Copyright © 2020 dbaofd. All rights reserved.
//

#ifndef HUFFMANTREE_hpp
#define HUFFMANTREE_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX_WEIGHT_VALUE = 1000; //Maxium weught is 1000.
//Encoding bit is not greater than 20, which means Huffman tree has less than 20 levels.
const int MAXBIT = 20;
struct CharacterNode               //Data structure for storing characters and its weight.
{
    char ch;
    int weight;
    struct CharacterNode *next;
};
struct HuffmanNode //Hauffman tree node data structure
{
    int flag;
    int parent;
    int weight;
    int leftchild;
    int rightchild;
};
struct HuffmanCode //Hauffman leaf node data structure.
{
    int start;
    int weight;
    int codevalue[MAXBIT];
};

CharacterNode *CharacterStatistic(char str[]);
int GetNumberOfNodesInLinkedList(CharacterNode *p1);
CharacterNode *TransformLinkedListToArray(CharacterNode *p, int count);
void BubbleSort(CharacterNode node[],int count);
void FormHuffmanTree(HuffmanNode node[], int n, CharacterNode Weight[]);
void GenerateHuffmanCode(HuffmanNode node[], int n, HuffmanCode code[]);
void DisplayCompressedCode(char str[], HuffmanCode code[], int n, CharacterNode Weight[]);
#endif /* HUFFMANTREE_hpp */
