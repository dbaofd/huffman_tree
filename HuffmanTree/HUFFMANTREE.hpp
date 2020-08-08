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
const int Maxvalue = 1000; //Maxium weught is 1000.
//Encoding bit is not greater than 20, which means Huffman tree has less than 20 levels.
const int Maxbit = 20;
const int Maxnode = 100;   //Maxium nodes in Hauffman tree.
struct store               //Data structure for storing characters and its weight.
{
    char ch;
    int weight;
    struct store *next;
};
struct haffNode //哈夫曼树节点数据构成
{
    int flag;
    int parent;
    int weight;
    int leftchild;
    int rightchild;
};
struct haffCode //哈夫曼叶节点的编码存储结构
{
    int start;
    int weight;
    int codebit[Maxbit];
};
void transHafftree(haffNode node[], int n, store Weight[]);
void transHaffcode(haffNode node[], int n, haffCode code[]);
store *returnTr(char str[]);
void bottomCode(char str[], haffCode code[], int n, store Weight[]);
#endif /* HUFFMANTREE_hpp */
