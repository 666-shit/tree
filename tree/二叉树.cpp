//
// Created by c1533 on 2022/8/9.
//
#include<iostream>
/*顺序存储*/
#define MaxSize 100
/**
 * 基本操作：                                                *完全二叉树*中共有n个结点，则:
 * i的左孩子        2i                                        i是否由左孩子               2i<=n?有:无
 * i的右孩子        2i+1                                     i是否有右孩子               2i+1<=n?
 * i的父节点        [i/2]                                    i是否是叶子/分支结点   i>[n/2]?
 * i所在的层次     [log2^(n+1)]或[log2^n] + 1    (普通二叉树需要把编号和完全树对应)
 * */ //思考：从0开始编号怎么计算？
//struct TreeNode {
//    int value; //数据元素
//    bool isEmpty;   //结点是否为空
//};
//
//void initTree(TreeNode) {
//    TreeNode t[MaxSize];    //从上到下从左到右一次存储完全二叉树中各个结点
//    for (int i = 0; i < MaxSize; i++) {
//        t[i].isEmpty = true;
//    }
//}     //缺点：空间利用率低

/*链式存储*/
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild, *parent;   //新插入父节点，变成三叉链表，父指针一般不考
} BiTNode, *BiTree;

// n个结点的二叉链表共有n+1个空链域(可用于构造线索二叉树)***
void initBiNode(BiTNode) {
    BiTree root = nullptr;      //定义空树
    //插入根节点
    root = (BiTree) malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = nullptr;
    root->rchild = nullptr;
    //插入新结点
    BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = nullptr;
    p->rchild = nullptr;
    root->lchild = p;       //作为根结点的左孩子
    p->parent = root;      //指向父节点
}       //找孩子结点简单，找父节点难，在结构体里定义一个父节点指针
/**遍历
 * 先序：根左右 NLR   波兰式 前缀式
 * 中序：左根右 LNR   中缀式(加括号)
 * 后序：左右根 LRN   逆波兰式 后缀式
 * */
void visit(BiTNode *T) {
    printf("root = %d", T->data);
}

// 先序
void PreOrder(BiTree T) {
    if (T != nullptr) {     //判空
        visit(T);   //访问根节点
        PreOrder(T->lchild);    //递归遍历左子树
        PreOrder(T->rchild);    //遍历右子树
    }
    printf("%d ", T->data);
}   // 时间复杂度O(h+1), h为树高度，空结点最后还要加一层; 空间复杂度O(h)

// 中序
void InOrder(BiTree T) {
    if (T != nullptr) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
    printf("%d ", T->data);
}

// 后序
void PostOrder(BiTree T) {
    if (T != nullptr) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
    printf("%d ", T->data);
}

//求树深度
int treeDepth(BiTree T) {
    if (T == nullptr) {
        return 0;
    } else {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //公式，树的深度=max{左右}+1
        return l > r ? l + 1 : r + 1;
    }
}
/**
 * 层序遍历：
 * 1. 初始化辅助队列
 * 2. 根结点入队
 * 3. 若队列非空，则队头结点出队，访问该结点(刚出队的)，将左右孩子插入队尾
 * 4. 重复上一步直到队列为空
 * */
//声明队列
typedef struct LinkNode {
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;
//声明队列
typedef struct {
    LinkNode *front, *rear;     //队头队尾
} LinkQueue;

//以下乱写
void InitQueue(BiTree T) {
    printf("Init ok");
}
void EnQueue(BiTNode *Q, BiTree T) {
    printf("En ok");
}
void DeQueue(BiTree T, BiTree pNode) {
    printf("De ok");
}
bool IsEmpty(BiTNode *Q) {
    if (Q == nullptr)
        return true;
    if (Q != nullptr)
        return false;
}
//以上乱写

void LevelOrder(BiTree T) {
    BiTNode *Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);      //根结点入队
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);      //队头结点出队
        visit(p);       //访问出队结点
        if (p->lchild != nullptr)
            EnQueue(Q, p->lchild);  //左孩子入队
        if (p->rchild != nullptr)
            EnQueue(Q, p->rchild);
    }
}

/**遍历序列构造二叉树：
 * 仅通过一个遍历序列无法推出唯一形态的二叉树
 * 通过两个序列(前序，后续或层序+中序)可以推出二叉树，中序是必须的
 * 前序最开始的是根结点，中序找出根结点，根左右，即可推出树
 * 后续最后一个是根结点，同理，左右根
 * 层序最开始是根，然后是左子树的根和右子树的根，可以分出左右子树，以此类推可出树
 * 注意每次确定出根结点，要把先序或后续序列分成两个子树部分
 * */
