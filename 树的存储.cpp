//
// Created by c1533 on 2022/8/21.
//
#include<iostream>

#define MaxTreeSize 100     //树中最多结点数
/**双亲表示法
 * 每个结点中保存指向双亲的“指针”
 * 优点：找父节点方便
 * 缺点：找孩子不方便
 * */
typedef struct{    //定义结点
    int data;      //数据元素
    int parent;    //双亲位置域，即位置下标
}PTNode;
typedef struct{        //树的类型定义
    PTNode nodes[MaxTreeSize];     //双亲表示
    int n;     //结点数
}PTree;

/**孩子表示法
 * 顺序存储各个结点，每个结点中保存孩子链表头指针
 * 优点：找孩子方便
 * 缺点：找父节点不方便
 * */
struct CTNode {
    int child;      //孩子结点在数组中位置
    struct CTNode *next;        //下一个孩子
};
typedef struct {
    int data;
    struct CTNode *firstChild; //第一个孩子
} CTBox;
typedef struct {
    CTBox nodes[MaxTreeSize];
    int n, r;       //结点数和根的位置
} CTree;

/**孩子兄弟表示法(链式存储)
 * 考点：树与二叉树的转换
 * */
typedef struct CSNode{
    int data;
    struct CSNode *first_child, *next_sibling;      //第一个孩子(看作左指针)和右兄弟指针(看作右指针)
    /** (二叉链表，可用于树和二叉树相互转换)*/
}CSNode, *CSTree;

/**森林和二叉树的转换
 * 森林是m棵互不相交的树的集合
 * 1. 将这些树通过二叉链表一次转换为二叉树
 * 2. 每个树的根结点可看作兄弟结点，放在其中一个树的右子树上
 * 森林中各个树的根节点之间视为兄弟关系
 * */





