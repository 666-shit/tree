//
// Created by c1533 on 2022/8/22.
//
#include<iostream>

#define MaxTreeSize 100
#define Size 15

int UFSets[Size];

void Init(int S[]) {
    for (int i = 0; i < Size; ++i) {
        S[i] = -1;      //初始不知道每个元素属于哪个集合，所以都设为-1
    }
}

int Find(int S[], int x) {      //查，找x所属集合(x为数组下标)
    while (S[x] >= 0)       //循环找x根
        x = S[x];       //父节点做下标
    return x;       //根的S[]小于0
}//最坏时间复杂度O(n)

void Unions_low(int S[], int Root1, int Root2) {    //并，两个合并为一个(root为数组下标的编号)
    if (Root1 == Root2) return;     //根相同无法合并
    S[Root2] = Root1;       //root2根连接到root1下面
}//时间复杂度O(1)
// 并操作的优化：小树合并到大树，树高度不会变。思路：1. 用根节点的绝对值表示树的结点总数；2. 让小树合并到大树
void Unions(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    if (S[Root2] > S[Root1]) {      //root2结点更少
        S[Root1] += S[Root2];     //累加结点总数
        S[Root2] = Root1;     //小树合并到大树
    } else {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}//树高度不超过log_2n + 1，时间复杂度不超过log_2n

typedef struct {
    int data;
    int parent;
} PTNode;
typedef struct {
    PTNode nodes[MaxTreeSize];  //双亲表示
    int n;      //结点数
} PTree;











