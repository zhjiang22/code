#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	int value;
};

void insert(struct Node** head, int num) {
    static int k = 1;
    if(k == 1) {
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->next = NULL;
        k = 0;
    }
    struct Node* p = *head; 
    while(p != NULL && p->next != NULL && num > p->next->value)  p = p -> next;
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    q->value = num; q->next = p->next;  p->next = q;
}

void print_linklist(struct Node* head) {
    struct Node *p = head->next;
    while(p != NULL) {
        if(p->next != NULL)  printf("%d ",p->value);
        else    printf("%d\n",p->value);
        p = p->next;
    }
}

void delete_linklist(struct Node* head) {
    struct Node *p = head->next;
    while(p != NULL) {
        free(head);
        head = p;   p = head->next;
    }
    free(head);
}

int main(void) {
	int n, num;
	scanf("%d", &n);

	struct Node* head = NULL;
	while (n--) {
		scanf("%d", &num);
		insert(&head, num);
	}
	print_linklist(head);
	delete_linklist(head);
    return 0;
}

