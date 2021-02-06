#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int num;
    struct node *next;
}node;
void push(node *head,int data);
void pop(node *head);
int size(node *head);
void empty(node *head);
int top(node *head);

int main(void){
    node *head = (node *)malloc(sizeof(node));
    head -> next = NULL;
    char order[10];
    int N,num,cnt=0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%s",order);
        if (strcmp(order, "push") == 0) {
            scanf("%d",&num);
            push(head,num);
            cnt++;
        }
        else if (strcmp(order, "pop") == 0) {
            if(cnt > 0){
                printf("%d\n",top(head));
                pop(head);
                cnt--;
            }
            else
                printf("-1\n");
        }
        else if (strcmp(order, "size") == 0)
            printf("%d\n", cnt);
        else if (strcmp(order, "empty") == 0) {
            if (cnt > 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else if (strcmp(order, "top") == 0) {
            if (cnt > 0)
                printf("%d\n", top(head));
            else
                printf("-1\n");
        }
    }
    return 0;
}

void push(node *head,int data){
    node *newnode =(node *)malloc(sizeof(node));
    newnode -> next = head -> next;
    newnode -> num = data;
    head -> next = newnode;
}

void pop(node *head){
    node *newnode;
    newnode = head -> next;
    head -> next = newnode -> next;
    free(newnode);
}

int top(node *head){
    return (head -> next -> num);
}