/**/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

struct node *createNew(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

void  addNode(int data) {
    struct node *node = createNew(data);
    if(head==NULL) {
        head = node;
        return;
    }
    struct node *ptr = head;
    while(ptr->next!=NULL) {
        ptr = ptr->next;
    }
    ptr->next = node;
    ptr = ptr->next;
}

void  deleteNode() {
    if(head==NULL) {
        printf("list is already empty");
    }
    else if(head->next==NULL) {
        free(head);
        head = NULL;
        return;
    }
    else{
        struct node *ptr = head;
        while(ptr->next->next!=NULL) {
            ptr= ptr->next;
        } 
        free(ptr->next);
        ptr->next = NULL;
    }
}

void  displayList(){
    struct node *ptr= head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    head = NULL;
    int choice, data;
    int number,i;

    do {
    printf("\nLinked List Operations: \n");
    printf("1. Add node at last position\n");
    printf("2. Delete node at last position\n");
    printf("3. Display list\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            printf("Enter the number of nodes to take input: ");
            scanf("%d", &number);
            printf("Enter data for %d nodes separated by spaces: ", number);
            for(i = 0; i < number; i++) {
                scanf("%d", &data);
                addNode(data);
            }
            break;
       
        case 2:
            deleteNode();
            break;

        case 3:
            displayList();
            break;

        case 4:
            printf("Exiting operations!!!...\n");
            exit(0);

        default:
            printf("Invalid choice! Enter a valid option...\n");
    }
} while(choice != 4);

return 0;
}