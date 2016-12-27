/*
算法描述：递归创建二叉树
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
} TreeNode;

// 先序递归创建二叉树
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

int main() {
    cout << "创建一棵二叉树,其中A~Z字符代表树的数据,用'#'表示空树:" << endl;
    TreeNode *root = NULL;
    creatBinaryTree(root);
    return 0;
}
