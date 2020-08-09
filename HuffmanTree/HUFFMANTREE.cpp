//
//  HUFFMANTREE.cpp
//  HuffmanTree
//
//  Created by dbaofd on 2020/8/8.
//  Copyright © 2020 dbaofd. All rights reserved.
//

#include "HUFFMANTREE.hpp"

//Compute the number of every character in a string.
CharacterNode *CharacterStatistic(char str[])
{
    int i, j = 0, k, flag; //j: the number of the linked list node;flag:to mark if find the same character in the linked list.
    CharacterNode *p1, *p2, *p3;
    CharacterNode *head;
    head = p1 = p2 = p3 = (CharacterNode *)malloc(sizeof(CharacterNode));
    for (i = 0; i < strlen(str); i++)
    {
        if (i == 0) //If i=0，then assign the first character of string to this node.
        {
            head->ch = str[0];
            head->weight = 0;
            p1 = p2 = head;//p2 is the tail of the linked list.
        }
        flag = 0; //Reset flag.
        p3 = head; //After each loop, reset p3.
        //Traverse the linked list.
        for (k = 0; k <= j; k++) //j is dynamic, j+1 is the current total number of nodes in linked list.
        {
            if (str[i] == p3->ch) //If the current character is the same with value of the linked list node. update the weight.
            {
                p3->weight++;
                flag = 1; //Mark flag, to show the current character is found in linked list.
                break;
            }
            p3 = p3->next;
        }
        if (flag == 0)//The current character is not found in the linked list, add a new node in the end of the linked list.
        {
            j++; //Add a node means total number of linked list plus one.
            p1 = (CharacterNode *)malloc(sizeof(CharacterNode));
            p1->ch = str[i];
            p1->weight = 1;
            p2->next = p1;
            p2 = p1;//p2 is the tail of the linked list.
        }
    }
    p1->next = NULL;
    return head;
}

int GetNumberOfNodesInLinkedList(CharacterNode *p){
    int count=0;
    while (p != NULL)
    {
       count++; //Compute the total number of Huffman tree.
       p = p->next;
    }
    return count;
}

CharacterNode  *TransformLinkedListToArray(CharacterNode *p, int count){
    int i = 0;
    CharacterNode *node = (CharacterNode *)malloc(sizeof(CharacterNode) * count); //Dynamic array.
    while (p != NULL) //Assign linked list value to array.
    {
        node[i].weight = p->weight;
        node[i].ch = p->ch;
        i++;
        p = p->next;
    }
    return node;
}

void BubbleSort(CharacterNode node_array[], int count){
    int i,j;
    CharacterNode temp;
    for (i = 0; i < count - 1; i++) //Bubble sorting
    for (j = 0; j < count - i - 1; j++)
    {
        if (node_array[j].weight > node_array[j + 1].weight)
        {
            temp = node_array[j];
            node_array[j] = node_array[j + 1];
            node_array[j + 1] = temp;
        }
    }
}
//Form Hauffman tree
void FormHuffmanTree(HuffmanNode node[], int n, CharacterNode node_array[])
{
    int i, j, m1, m2, x1, x2;
    for (i = 0; i < 2 * n - 1; i++) //Initialize all the nodes, a Hauffman tree with 2*n-1 nodes will be formed based on n leaf nodes. Also, the size of node array is 2*n-1.
    {
        if (i < n)
            node[i].weight = node_array[i].weight;
        else
            node[i].weight = 0;
        node[i].parent = 0;
        node[i].flag = 0;
        node[i].leftchild = -1;
        node[i].rightchild = -1;
    }
    for (i = 0; i < n - 1; i++) //Strat to form a Hauffman tree
    {
        m1 = m2 = MAX_WEIGHT_VALUE; //m1,m2,x1,x2 need to be reset before each loop starts.
        x1 = x2 = 0;
        for (j = i; j < n + i; j++)
        {
            if (node[j].weight < m1 && node[j].flag == 0)
            {
                m2 = m1;
                x2 = x1;
                m1 = node[j].weight;
                x1 = j;
            }
            else if (node[j].weight < m2 && node[j].flag == 0)
            {
                m2 = node[j].weight;
                x2 = j;
            }
        }
        node[x1].parent = n + i;
        node[x2].parent = n + i;
        node[x1].flag = 1;
        node[x2].flag = 1;
        node[n + i].leftchild = x1;
        node[n + i].rightchild = x2;
        node[n + i].weight = node[x1].weight + node[x2].weight;
    }
}

//Compute Huffman code for each character
void GenerateHuffmanCode(HuffmanNode node[], int n, HuffmanCode code[])
{
    HuffmanCode mycode;
    int i, j, child, parent;
    for (i = 0; i < n; i++) //the first n elements in Huffman array are leaf nodes.
    {
        child = i;
        parent = node[child].parent;
        mycode.start = 0;
        mycode.weight = node[i].weight;
        while (parent != 0)
        {
            if (node[parent].leftchild == child)
                mycode.codevalue[mycode.start] = 0;
            else if (node[parent].rightchild == child)
                mycode.codevalue[mycode.start] = 1;
            mycode.start++;
            child = parent;
            parent = node[child].parent;
        }
        code[i].weight = mycode.weight;
        code[i].start = mycode.start;
        for (j = 0; j < mycode.start; j++)
        {
            code[i].codevalue[mycode.start - j - 1] = mycode.codevalue[j];
        }
    }
}

//Show compressed code.
void DisplayCompressedCode(char str[], HuffmanCode code[], int n, CharacterNode node_array[])
{
    int i, j, k;
    cout << "ch  weight  code" << endl;
    for (i = 0; i < n; i++)
    {
        cout << " " << node_array[i].ch << "    " << node_array[i].weight << "     ";
        for (j = 0; j < code[i].start; j++)
            cout << code[i].codevalue[j];
        cout << endl;
    }
    cout << "Compressed code of string." << endl;
    for (i = 0; i < strlen(str); i++)
    {
        for (j = 0; j < n; j++)
            if (str[i] == node_array[j].ch)
            {
                for (k = 0; k < code[j].start; k++)
                    cout << code[j].codevalue[k];
            }
    }
    cout << endl;
}
