//
//  main.cpp
//  HuffmanTree
//
//  Created by dbaofd on 2020/8/8.
//  Copyright © 2020 dbaofd. All rights reserved.
//
#include "HUFFMANTREE.hpp"

int main(int argc, const char * argv[]) {
    store *p1, *p2;
    int i, j, count = 0;
    store *node, temp;
    char str[100];
    haffNode hNode[100]; //定义哈夫曼树节点
    haffCode hCode[100]; //定义哈夫曼树叶节点编码存储数组
    cout << "请输入字符串" << endl;
    cin >> str;
    p1 = p2 = returnTr(str);
    while (p1 != NULL)
    {
        count++; //计算出节点数量，为了数组的大小
        p1 = p1->next;
    }
    if (count > Maxnode)
    {
        cout << "节点数越界，请重新设定！" << endl;
        system("pause");
        exit(0);
    }
    node = (store *)malloc(sizeof(store) * count); //节省内存
    i = 0;
    while (p2 != NULL) //将链表的数据传给数组
    {
        node[i].weight = p2->weight;
        node[i].ch = p2->ch;
        i++;
        p2 = p2->next;
    }
    /*TEST for (i = 0; i < count; i++)
    {
    cout << node[i].ch << ":"<<node[i].weight<<endl;
    }*/
    for (i = 0; i < count - 1; i++) //将得到的数组权值从小到大冒泡排序
        for (j = 0; j < count - i - 1; j++)
        {
            if (node[j].weight > node[j + 1].weight)
            {
                temp = node[j];
                node[j] = node[j + 1];
                node[j + 1] = temp;
            }
        }
    /*以上是利用returnTr函数返回的链表头所携带的链表信息转化为数组形式*/
    transHafftree(hNode, count, node);    //构建哈夫曼树
    transHaffcode(hNode, count, hCode); //计算哈夫曼编码
    cout << "ch  weight  code" << endl;
    for (i = 0; i < count; i++)
    {
        cout << " " << node[i].ch << "    " << node[i].weight << "     ";
        for (j = 0; j < hCode[i].start; j++)
            cout << hCode[i].codebit[j];
        cout << endl;
    }
    bottomCode(str, hCode, count, node);
    system("pause");
    return 0;
}
