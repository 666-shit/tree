//
// Created by c1533 on 2022/8/3.
//

/**
 * *******树的概念：
 * 结点的度：有几个孩子(分支)就有几个度，没有孩子就是0个度，叶子结点
 * 树的度：各结点的度的最大值(一个结点度为2，一个为3，所以树的度为3)
 * 结点的层次默认从1开始，有的从0开始，结点之间的路径只能从上到下
 * 有序树：各子树从左至右是有次序的，如家谱
 * 无序树：各子树无次序
 * 森林：m个互不相交的树的·集合·
 * 树和森林都可以为空
 * */
/**
 * *******考点：
 * 1. 结点数=总度数+1
 * 2. 度为m的树(各结点的度的最大值，至少有一个度为m，一定是非空树)和
 *     m叉树的区别(每个结点最多只能有，m个孩子的树，也可以是m叉空树)   (易错)
 * 3. 度为m的树第i层最多有m^(i-1)个结点，如第二层的三叉树有3^(2-1)=3，第三层有3^(3-1)=9个结点
 * 4. 高度为h的m叉树最多有(m^h - 1)/(m - 1)个结点，如高度为二的三叉树有(9-1)/(3-1)=4，高度为三有(3^3-1)/(3-1)=13个结点(等比数列求和)
 * 5. 高度为h的m叉树至少有h个结点；高度为h，度为m的树至少有h+m-1个结点
 * 6. 有n个结点的m叉树的最小高度为[logm(n(m-1)+1)]
 * */

/********二叉树*********/

/**
 * 二叉树是n个结点的有限集合：
 *      1. 或者为空二叉树，n=0；
 *      2. 或者由一个结点和两个互不相交的被称为左子树和右子树组成，
 *      左右子树分别是二叉树；
 * 注意与度为2的树区别
 * 特点：
 *      1. 每个结点最多有两个子树；
 *      2. 左右子树不能颠倒顺序(二叉树是有序树)
 * */
/**
 * 满二叉树：高度为h，且含有2^h - 1个结点的二叉树，结点的度要么是2要么是0
 * 特点：
 *      1. 只有最后一层有叶子结点
 *      2. 不存在度为1的结点
 *      3. 按层序从1开始编号，结点为i的左孩子为2i，
 *      有孩子为2i+1；结点i的父节点为i/2向下取整
 * 完全二叉树：当且仅当其每个结点都与高度为h的满二叉树中
 *      编号为1~n的结点一一对应时，称为完全二叉树
 * 特点：
 *      1. 只有最后两层可能有叶子节点
 *      2. 最多只有一个度为1的结点
 *      3. 同满二叉树特点3
 *      4. 有n个结点，当i<=[n/2]为分支结点，i>[n/2]为叶子结点 (向下取整)
 *      对于完全二叉树，一个结点若只有一个孩子，必然是左孩子
 * 特殊二叉树：
 * 二叉排序树：一个二叉树或空二叉树或有以下性质的树：
 *      左子树上所有结点关键字均小于根结点的关键字；右子树上所有结点的关键字均大于根节点关键字，左右子树又各是二叉树
 * 平衡二叉树：树上任一结点的左子树和右子树的深度差不超过1
 * */
/**
 * 二叉树考点：
 * 1. 设非空二叉树中度为0，1，2的结点个数分别为n,n1,n2，则n0=n2+1(叶子结点比二分支结点多一个)
 *      假设二叉树中结点总数为n，则：1. n=n0+n1+n2; 2. n=n1+2n2+1(总度数+1); 2.-1.= n0 =n2+1(高频)
 * 2. 二叉树第二层最多有2^(i-1)个结点(i>=1)；m叉树第i层最多有m^(i-1)个结点
 * 3. 高度为h的二叉树至多有2^h - 1个结点(满二叉树)；高度为h的m叉树最多有(m^h - 1)/(m-1)
 *      等比数列求和公式：a+aq+aq^2+ ... +aq^(n-1) = (a(1-qn))/(1-q)
 *
 * 完全二叉树考点：
 * 1. 有n个结点的完全二叉树高度h为[log2^(n+1)]或[log2^n + 1] (取整)
 *      高度为h的满二叉树有n=2^h - 1个结点
 *      高度为h-1的满二叉树共有n=2^(h-1) - 1个结点
 *      2^(h-1) - 1 < n < 2^h - 1
 *      推出：h-1 < log2^(n+1) <= h
 *      高为h的完全二叉树至少有2^(h-1)个结点，至多有2^h - 1个结点
 *      2^(h-1) <= n < 2^h
 *      推出: h-1 <= log2^n < h
 * 2. 对于完全二叉树，可以由结点数n推出度为0，1，2的结点个数为n0, n1, n2
 *      完全二叉树最多只有一个度为1的结点，即：n1=0或1; n0=n2+1 -> n0+n2一定是奇数
 *      推论：若完全二叉树由偶数(2k)个结点，则必然有：n1=1, n0=k, n2=k-1
 * */















