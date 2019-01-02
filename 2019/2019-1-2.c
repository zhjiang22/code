#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

TreeNode *reConstructBinaryTree(int *pre, int *in, int n)
{
    if (n == 0)
        return NULL;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = pre[0];
    pre[0] = -1;
    if (n <= 1)
    {
        root->left = root->right = NULL;
        return root;
    }
    int cur = 0;
    while (in[cur] != root->val && cur < n)
        cur++;
    root->left = reConstructBinaryTree(pre + 1, in, cur);
    int pos = 0;
    while (pre[pos] == -1 && pos < n)
        pos++;
    if (pos == n)
    {
        root->right = NULL;
        return root;
    }
    root->right = reConstructBinaryTree(pre + pos, in + cur + 1, n - cur - 1);
    return root;
}

void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main()
{
    int preOrder[100], inOrder[100];
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &preOrder[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &inOrder[i]);
    }

    TreeNode *root = reConstructBinaryTree(preOrder, inOrder, size);
    postOrder(root);
    printf("\n");
    deleteTree(root);
    root = NULL;
    return 0;
}
