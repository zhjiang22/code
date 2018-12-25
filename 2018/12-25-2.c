#include <stdlib.h> 
#include <stdio.h>
struct Node {
	struct Node* left_child;
	struct Node* right_child;
	int value;
};

void insert(struct Node** root, int num) {
    static int k = 1;
    if(k == 1) {
        (*root) = (struct Node*)malloc(sizeof(struct Node));
        (*root)->left_child = (*root)->right_child = NULL;
        (*root)->value = num;
        k = 0;
        return;
    }
    struct Node *p = (*root);
    for(;;) {
        if(num < p->value) {
            if(p->left_child == NULL)  break;
            p = p->left_child;
        }
        else {
            if(p->right_child == NULL)  break;
            p = p->right_child;
        }
    }
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    q->left_child = q->right_child = NULL;   q->value = num;
    if(num < p->value)  p->left_child = q;
    else    p->right_child = q;
}

void traverse_inorder(struct Node* root) {
    if(root == NULL)    return;
    traverse_inorder(root->left_child);
    printf("%d\n",root->value);
    traverse_inorder(root->right_child);
}

void delete_tree(struct Node* root) {
    if(root == NULL)    return;
    delete_tree(root->left_child);
    delete_tree (root->right_child);
    free(root);
}

int main(void) {
	int n, num;
	scanf("%d", &n);

	struct Node* root = NULL;
	while (n--) {
		scanf("%d", &num);
		insert(&root, num);
	}
	traverse_inorder(root);
	delete_tree(root);
	return 0;
}
