#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(int data) {
   struct node *newNode;
   newNode = malloc(sizeof(newNode));
   if(newNode==NULL) {
    printf("stack overflow\n");
    exit(1);
   }
      newNode->data = data;
      newNode->next = NULL;

    newNode->next = top;
    top = newNode;

}
   int pop() {
    struct node *ptr = top;
    if(top==NULL) {
        printf("stack underflow\n");
        exit(1);
    }
    int value;
    value = ptr->data;
     top = top->next;
     free(ptr);
     ptr = NULL;
     return value;
   }

   int peek() {
    if(top==NULL) {
        printf("stack underflow\n");
    }
    return top->data;
   }
  void print(){
    struct node *ptr=top;
    if(top==NULL) {
        printf("stack underflow\n");
        exit(1);
    }
    printf("pushed elements are: ");
     while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
     }
        printf("\n");
   }

int main() {
    int choice,data;
    printf("Operation Using Linked List\n\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.print\n");
    printf("5.quit\n\n");

    while(choice!=5) {
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
        printf("Enter element to push: ");
        scanf("%d",&data);
        push(data);
        break;

        case 2:
        int value = pop();
        printf("poped element is %d",value);
        break;

        case 3:
        int peek_element = peek();
        printf("peek element is %d",peek_element);
        break;

        case 4:
        print();
         break;

        case 5:
        printf("You are quited from the equation\n\n");\
        exit(0);

        default:
        printf("wrong choice...!!!");
        break;
    }

    }
    return 0;
}