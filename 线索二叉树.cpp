//
// Created by c1533 on 2022/8/15.
//
#include<iostream>

/**
 * 线索二叉树：
 * 叶子结点，左孩子指向前驱，右孩子指向后继
 * */
//线索二叉树结点
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //左右线索标志，当tag=1，对应指针是线索，指向前驱或后继；tag=0，指针指向孩子
} ThreadNode, *ThreadTree;
//线索二叉树有前序中序和后续，指针指向不同，需要根据遍历序列判断
//注意手画线索二叉树
ThreadNode *pre = nullptr;    //指向当前访问结点的前驱

void visit(ThreadNode *q) {
    if (q->lchild == nullptr) { //左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//中序遍历
void InThread(ThreadTree T) {
    if (T != nullptr) { //中序遍历
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

/**中序线索化二叉树*/
void createInThread(ThreadTree T) {
    pre = nullptr;  //初始化为空
    if (T != nullptr) { //只有非空二叉树能被线索化
        InThread(T);
        if ((pre->rchild = nullptr))
            pre->rtag = 1;    //处理遍历的最后一个结点
    }
}

//找到以p为根的子树中，第一个被中序遍历的结点（左下结点）
ThreadNode *Firstnode(ThreadNode *p) {
    while (p->ltag == 0)   //还有左子树的子树共同点：ltag=0，就可以循环找到最左下的结点
        p = p->lchild;
    return p;
}

//中序线索二叉树中找到p的
// 后继
ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag == 0)  //右子树中最左下结点
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

//中序遍历找（线索实现的非递归）
void Inorder(ThreadNode *T) {       //传入根节点指针
    for (ThreadNode *p = Firstnode(T); p != nullptr; p = Nextnode(p))
        visit(p);
}//空间复杂度O(1)

//中序线索二叉树中找到p的
// 前驱   pre=p的左子树中最右下结点
ThreadNode *Lastnode(ThreadNode *p) {    //找到以p为根的子树中最后一个被中序遍历的结点
    while (p->rtag == 0)   //循环找到最右下结点(不一定是叶子节点)
        p = p->rchild;
    return p;
}

//中序线索二叉树中找到结点p的前驱
ThreadNode *Prenode(ThreadNode *p) {
    if (p->ltag == 0)      //左子树中
        return Lastnode(p->lchild);     //最右下的结点
    else
        return p->lchild;   //ltag==1，直接返回前驱
}

//对中序线索二叉树*逆向*中序遍历
void RevInorder(ThreadNode *T) {
    for (ThreadNode *p = Lastnode(T); p != nullptr; p = Prenode(p))
        visit(p);
}

/**先序*/
// 如果用原来的visit函数，先把左子树确定为前驱，然后再次访问左子树的时候会返回前驱造成错误
void PreThread(ThreadTree T) {
    if (T != nullptr) {
        visit(T);
        if (T->ltag == 0)  //lchild不是前驱线索***易错
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void CreatePreThread(ThreadTree T) {
    pre = nullptr;
    if (T != nullptr) {
        PreThread(T);   //先序线索化
        if (pre->rchild == nullptr)
            pre->rtag = 1;    //处理遍历的最后一个结点
    }
}

//先序前驱
// ltag=0，未被线索化，肯定有左孩子
// p不为根结点才能找到前驱；p为左孩子，前驱为根；p为右孩子，如果无左子树，前驱为根；有左子树，前驱为左子树最后遍历的结点


/**后序*/
// 一边遍历一边线索化
void PostThread(ThreadTree T) {
    if (T != nullptr) {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

void CreatePostThread(ThreadTree T) {
    pre = nullptr;
    if (T != nullptr) {
        PostThread(T);
        if (pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

//后续前驱
// 如果p有右孩子，则前驱为右孩子；如果没有右孩子，则为左孩子

//后续后继，左右子树的结点只能是前驱，无法找到后继
// 如果能找到p的父节点，若p是右孩子，后继为其父节点；若p是左孩子且右兄弟为空，后继为父节点；若p为左，右非空，则后继为右子树第一个遍历的结点

/**要会推出结果*/
