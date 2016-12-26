
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct TreeNode {
    TreeNode *lptr;
    TreeNode *rptr;
    int value;
} TreeNode;

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

int teseCase_none() {
    return getShortTreeHeight(NULL);
}

int teseCase_one() {
    TreeNode *root = new TreeNode;
    int height = getShortTreeHeight(root);
    delete root;
    return height;
}

int teseCase_two() {
    TreeNode *root = new TreeNode;
    root->lptr = new TreeNode;
    root->rptr = new TreeNode;
    int height = getShortTreeHeight(root);
    return height;
}

int teseCase_tree() {
    TreeNode *root = new TreeNode;
    root->lptr = new TreeNode;
    root->rptr = new TreeNode;
    root->lptr->lptr = new TreeNode;
    root->lptr->rptr = new TreeNode;
    root->rptr->lptr = new TreeNode;
    root->rptr->rptr = new TreeNode;
    int height = getShortTreeHeight(root);
    return height;
}

int main() {
    cout << "teseCase_none = " << teseCase_none() << endl;
    cout << "teseCase_one = " << teseCase_one() << endl;
    cout << "teseCase_two = " << teseCase_two() << endl;
    cout << "teseCase_none = " << teseCase_tree() << endl;
    return 0;
}
