/*
 * 二叉树相关的算法
*/

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct TreeNode {
    TreeNode *lptr;
    TreeNode *rptr;
    char value;

    TreeNode(): lptr(NULL), rptr(NULL), value('\0') { }
    TreeNode(char v): lptr(NULL), rptr(NULL) { value = v; }
} TreeNode;

/*
 * 算法：先序递归创建二叉树
*/
void creatBinaryTree(TreeNode *T){
    // 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
    char ch = getchar();
    if (ch == '\n') {
        T = NULL;
    } else {
        T = new TreeNode; // 产生新的子树
        T->value = ch; // 由getchar()逐个读进来
        creatBinaryTree(T->lptr); // 递归创建左子树
        creatBinaryTree(T->rptr); // 递归创建右子树
    }
} 

/*
 * 算法：递归获取二叉树高度
*/
int getTreeHeight(TreeNode *root) {
    if ( root == NULL ) {
        return 0;
    }
    // 遍历左树
    TreeNode *tmp = root->lptr;    
    int lHeight = getTreeHeight(tmp);
    // 遍历右树
    tmp = root->rptr;
    int rHeight = getTreeHeight(tmp);

    return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

int getShortTreeHeight(TreeNode *root) {
    if ( root == NULL ) {
        return 0;
    } else {
        return max(getShortTreeHeight(root->lptr), getShortTreeHeight(root->rptr)) + 1;
    }
}

/*
 * 算法：递归获取二叉树叶子数
*/
int getLeaves(TreeNode *root) {
    if ( root == NULL ) {
        return 0;
    } else {
        return getLeaves(root->lptr) + getLeaves(root->rptr) + 1;
    }
}


typedef void(*CallBack)(TreeNode *);
void print(TreeNode *node) {
    if ( node ) { 
        cout << node->value << " ";
    }
}

/*
 * 算法：递归先序遍历二叉树
*/
void frontVisitor(TreeNode *root, CallBack callback) {
    if ( root ) {
        if ( callback ) {
            callback(root);
        }
        frontVisitor(root->lptr, callback);
        frontVisitor(root->rptr, callback);
    }
} 

/*
 * 算法：递归中序遍历二叉树
*/
void middleVisitor(TreeNode *root, CallBack callback) {
    if ( root ) {
        middleVisitor(root->lptr, callback);
        if ( callback ) {
            callback(root);
        }
        middleVisitor(root->rptr, callback);
    }
} 

/*
 * 算法：递归后序遍历二叉树
*/
void afterVisitor(TreeNode *root, CallBack callback) {
    if ( root ) {
        afterVisitor(root->lptr, callback);
        afterVisitor(root->rptr, callback);
        if ( callback ) {
            callback(root);
        }
    }
}

/*
 * 算法：二叉树排序
*/
void sortBinaryTree(TreeNode *root)  {

}

/*
 * 算法：二叉树递归先序遍历搜索
*/
TreeNode* search_by_key(TreeNode *root, char key) {
    if ( root == NULL ) {
        return NULL;
    }

    if ( root->value == key ) {
        return root;
    } else {
        TreeNode *tmp = search_by_key(root->lptr, key);
        if ( tmp && tmp->value == key ) {
            return tmp;
        } else {
            tmp = search_by_key(root->rptr, key);
            if ( tmp && tmp->value == key ) {
                return tmp;
            } else {
                return NULL;
            }
        }
    }
}

int main() {
    // 测试demo,暂不考虑内存问题

    cout << "算法：递归获取二叉树高度 " << endl;
    /*
        测试用例1,树形结构如下
               空树
    */
    TreeNode *root = NULL;
    cout << "leaves = " << getLeaves(root) << "; height = " << getTreeHeight(root) << ";" << endl;

    /*
        测试用例2,树形结构如下
                a
    */
    root = new TreeNode('a');
    cout << "leaves = " << getLeaves(root) << "; height = " << getShortTreeHeight(root) << ";" << endl;

    /*
        测试用例3,树形结构如下
                a
            b       c
    */
    root->lptr = new TreeNode('e');
    root->rptr = new TreeNode('b');
    cout << "leaves = " << getLeaves(root) << "; height = " << getTreeHeight(root) << ";" << endl;
 
    /*
        测试用例4,树形结构如下
                a
            b       c
          d   e   f   g
    */
    root->lptr->lptr = new TreeNode('g');
    root->lptr->rptr = new TreeNode('c');
    root->rptr->lptr = new TreeNode('f');
    root->rptr->rptr = new TreeNode('d');
    cout << "leaves = " << getLeaves(root) << "; height = " << getShortTreeHeight(root) << ";" << endl;

    cout << "算法：递归先序遍历二叉树 " << endl;
    frontVisitor(root, print);
    cout << endl;

    cout << "算法：递归中序序遍历二叉树 " << endl;
    middleVisitor(root, print);
    cout << endl;

    cout << "算法：递归后序序遍历二叉树 " << endl;
    afterVisitor(root, print);
    cout << endl;

    cout << "算法：顺序搜索 " << endl;
    TreeNode *tmp = search_by_key(root, 'c');
    if ( tmp ) {
        cout << "搜索到字母: " << tmp->value << endl;
    } else {
        cout << "没有搜索到: c" << endl;
    }

    tmp = search_by_key(root, 'k');
    if ( tmp ) {
        cout << "搜索到字母: " << tmp->value << endl;
    } else {
        cout << "没有搜索到: k" << endl;
    }
    

    return 0;
}
