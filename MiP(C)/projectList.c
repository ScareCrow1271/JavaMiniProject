/**/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

  
  void addNodeAtBeg(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
      newNode->data= data;
      newNode->next = NULL;

    if(head==NULL) {
        head=newNode;
        return;
    }
        newNode->data = data;
        newNode->next = head;
        head = newNode;
  }

  void addNodeAtEnd(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL) {
        head= newNode;
        return;
    }
    struct node *ptr = head;
      while(ptr->next!=NULL) {
        ptr = ptr->next;
      }
      ptr->next= newNode;
      ptr = ptr->next;

  }

  void  displayList(){
    struct node *ptr= head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

int main() {
    head = NULL;
    int mainChoice,subChoice,choice, data;
    int number,position,i;

do {
    printf("\n--------------Menu--------------\n");
    printf("1. LinkedList\n");
    printf("2. Stack\n");
    printf("3. Queue\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", & mainChoice);
    
    switch(mainChoice){
        case 1:
        do{
            printf("1. Linked List Insertion\n");
            printf("2. Linked List Deletion\n");
            printf("3. Display List\n");
            printf("4. Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&subChoice);
           
           switch(subChoice){
            case 1:
              do{
            printf("1. Insertion at Beginning\n");
            printf("2. Insertion at End\n");
            printf("3. Insertion at Any Point\n");
            printf("4. Display List\n");
            printf("5. Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice) {
                case 1:
                 printf("Enter the number of nodes to take input: ");
            scanf("%d", &number);
            printf("Enter data for %d nodes separated by spaces: ", number);
            for(i = 0; i < number; i++) {
                scanf("%d", &data);
                addNodeAtBeg(data);
            }
            break;

            case 2:
                 printf("Enter the number of nodes to take input: ");
            scanf("%d", &number);
            printf("Enter data for %d nodes separated by spaces: ", number);
            for(i = 0; i < number; i++) {
                scanf("%d", &data);
                addNodeAtEnd(data);
            }
            break;
            
            case 3:
               printf("Enter the number of nodes to take input: ");
            scanf("%d", &number);
            printf("Enter data for %d nodes separated by spaces: ", number);
            for(i = 0; i < number; i++) {
                scanf("%d", &data);
                 addNodeAtEnd(data);
            }
            printf("Enter the position to take input the node: ");
            scanf("%d", &position);
            printf("Enter the data to take input the node: ");
            scanf("%d", &data);
             //addNodeAtPos(position,data);  
            break;
            
            case 4:
            displayList();
             break;

             case 5:
              printf("Exit!!!...\n");
            exit(0);

            default:
            printf("Invalid choice! Enter a valid option...\n");

            } 
           }while(choice!=4);
            break;
            
            case 2:
            do{
            printf("1. Deletion at Beginning\n");
            printf("2. Deletion at End\n");
            printf("3. Deletion at Any Point\n");
            printf("4. Display List\n");
            printf("5. Back from the page\n");
             
            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice){
                case 1:
                //deleteAtBeg();
                break;

                case 2:
                //deleteAtEnd();
                break;

                case 3:
                printf("Enter a position to delete the node: ");
                scanf("%d",&position);
                //deleteAtPos(position);
                break;

                case 4:
                displayList();
                break;

                case 5:
                printf("exit!!!...\n");
                exit(0);
                break;
                         
            default:
            printf("Invalid choice! Enter a valid option...\n");   

               }
            }while(choice!=4);
            break;

            case 3:
               displayList();
                break;

            case 4:
                printf("exit!!!...\n");
            exit(0);
 
               default:
            printf("Invalid choice! Enter a valid option...\n");


           }
        }while(subChoice!=4);
        break; 
    }
         }while(mainChoice!=4);
         return 0;
  }

      
