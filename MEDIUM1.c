
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *newNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            
            root = root->right;
        } else {
           
            return root;
        }
    }
    return NULL; 
}

int main() {
     int val_p, val_q;
    
    struct TreeNode *root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);

    printf("Enter the values of nodes p and q: ");
    scanf("%d %d", &val_p, &val_q);

    struct TreeNode *p = newNode(val_p);
    struct TreeNode *q = newNode(val_q);

    struct TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        printf("Lowest Common Ancestor: %d\n", lca->val);
    } else {
        printf("Lowest Common Ancestor not found.\n");
    }

    
    return 0;
}
