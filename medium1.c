[{"insert":"Medium 1 \nGiven a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.\nAccording to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”\n \nExample 1:\n\nInput: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8\nOutput: 6\nExplanation: The LCA of nodes 2 and 8 is 6.\nExample 2:\n\nInput: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4\nOutput: 2\nExplanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.\nExample 3:\nInput: root = [2,1], p = 2, q = 1\nOutput: 2\n\nCODE\n\n#include <stdio.h>\n#include <stdlib.h>\n\nstruct TreeNode {\n    int val;\n    struct TreeNode *left;\n    struct TreeNode *right;\n};\n\nstruct TreeNode* createNode(int val) {\n    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));\n    newNode->val = val;\n    newNode->left = newNode->right = NULL;\n    return newNode;\n}\n\nstruct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {\n    if (root == NULL) return NULL;\n\n    if (root->val > p->val && root->val > q->val)\n        return lowestCommonAncestor(root->left, p, q);\n    else if (root->val < p->val && root->val < q->val)\n        return lowestCommonAncestor(root->right, p, q);\n    else\n        return root;\n}\n\nint main() {\n    struct TreeNode* root = createNode(6);\n    root->left = createNode(2);\n    root->right = createNode(8);\n    root->left->left = createNode(0);\n    root->left->right = createNode(4);\n    root->right->left = createNode(7);\n    root->right->right = createNode(9);\n    root->left->right->left = createNode(3);\n    root->left->right->right = createNode(5);\n\n    struct TreeNode* p = root->left;\n    struct TreeNode* q = root->right;\n\n    struct TreeNode* result = lowestCommonAncestor(root, p, q);\n    if (result != NULL) {\n        printf(\"Lowest Common Ancestor of %d and %d is %d\\n\", p->val, q->val, result->val);\n    } else {\n        printf(\"Nodes not found in the BST.\\n\");\n    }\n\n    return 0;\n}\nOUTPUT\nLowest Common Ancestor of 2 and 8 is 6\n"}]