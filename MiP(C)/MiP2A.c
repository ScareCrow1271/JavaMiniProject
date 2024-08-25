#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int stack_arr[MAX];
int top = -1;

int isFull() {
    if(top==MAX-1) {
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data) {
    if(isFull()) {
        printf("Stack Overflow\n");
    }
    top=top+1;
    stack_arr[top] = data;
    
}

int isEmpty() {
    if(top==-1) {
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    if(isEmpty()) {
        printf("stack underflow\n");
    }
    int value;
    value = stack_arr[top];
    top = top-1;
    return value;
}

  int printTop() {
    if(isEmpty()) {
        printf("stack underflow\n");
        exit(1);
    }
       return stack_arr[top];
  }
     int printALL() {
        if(isEmpty()) {
            printf("stack underflow\n");
            exit(1);
        }
        int i;
        printf("all the elements in the stack are: ");
        for(i=top;i>=0;i--) {
            printf(" %d ",stack_arr[i]);
        }
        printf("\n");
     }

int main() {
    int choice,data;
do{
    printf("\nSTACK OPERATION\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.print the top element\n");
    printf("4.print all the element in the stack\n");
    printf("5.quit\n");

    printf("enter the choice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
        printf("Enter the number you want to push: ");
        scanf("%d",&data);
        push(data);
        break;

        case 2:
         data = pop();
         printf("deleted element is %d \n",data);
        break;

        case 3:
        data = printTop();
        printf("top element is %d\n",data);
        break;

        case 4:
        printALL();
        break;

        case 5:
        printf("exiting...!!!\n");
        exit(0);

        default:
        printf("wrong! you entered a wrong key.try again...\n");
       
    }
   
}while(choice!=5);

}