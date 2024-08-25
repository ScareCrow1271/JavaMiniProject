#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};
struct Tree *root = NULL;

struct Tree *createNew(int data) {
    struct Tree *new = (struct Tree *)malloc(sizeof(struct Tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(int data) {
    if(root==NULL) {
        root = createNew(data);
        return;
    }

    struct Tree *current = root;
    struct Tree *parent = NULL;

    while(current!=NULL) {
        parent = current;
        if(data<current->data) {
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if(data<parent->data) {
        parent->left = createNew(data);
    }
    else{
        parent->right = createNew(data);
    }
}

void preorder(struct Tree *root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Tree *root) {
    if(root!=NULL) {
       postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    }
    
}

void inorder(struct Tree *root) {
    if(root!=NULL) {
         inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
   
}


int main() {
    int choice,subchoice,data;
      do{
      printf("\n-------------------Menu------------------\n");
      printf("\n");
      printf(" 1. PreOrder \n");
      printf(" 2. PostOrder \n");
      printf(" 3. InOrder \n");
      printf(" 4. Exit ");
      printf("\n");
      printf("Enter Your Choice: ");
      scanf("%d",&choice);
      
      switch (choice)
      {
        case 1:
        printf("Enter value to insert: ");
        scanf("%d",&data);
        insert(data);
        do{
            printf(" 1. Continue inserting \n");
            printf(" 2. Exit from inserting and Printing\n");
            printf("Enter Your Choice: ");
            scanf("%d",&subchoice);
            switch(subchoice) {
                case 1:
                 printf("Enter value to insert: ");
                 scanf("%d",&data);
                 insert(data);
                 break;
                 case 2:
                  printf("PreOrder: ");
                   preorder(root);
                    printf("\n");
                
                   
                 break;

                 default:
                 printf("Invalid choice! Enter a valid option...\n");
            }
        }while(subchoice!=2);
        break;
          
      case 2:
         printf("Enter value to insert: ");
        scanf("%d",&data);
        insert(data);
        do{
            printf(" 1. Continue inserting \n");
            printf(" 2. Exit from inserting and Printing\n");
            printf("Enter Your Choice: ");
            scanf("%d",&subchoice);
            switch(subchoice) {
                case 1:
                 printf("Enter value to insert: ");
                 scanf("%d",&data);
                 insert(data);
                 break;

                 case 2:
                  printf("PostOrder: ");
                 postorder(root);
                printf("\n");
                 
                 break;

                 default:
                 printf("Invalid choice! Enter a valid option...\n");
            }
        }while(subchoice!=2);

         break;

       case 3:
          printf("Enter value to insert: ");
        scanf("%d",&data);
        insert(data);

         do{
            printf(" 1. Continue inserting \n");
            printf(" 2. Exit from inserting and Printing\n");
            printf("Enter Your Choice: ");
            scanf("%d",&subchoice);
            switch(subchoice) {
                case 1:
                 printf("Enter value to insert: ");
                 scanf("%d",&data);
                 insert(data);
                 break;

                 case 2:
                 printf("InOrder: ");
                 inorder(root);
                 printf("\n");
                 
                 break;

                 default:
                 printf("Invalid choice! Enter a valid option...\n");
            }
        }while(subchoice!=2);
         break;

         case 4:
         printf("Exit...!!!");
         exit(0);

         default:
          printf("Invalid choice! Enter a valid option...\n");

      } 
}while(choice!=4);
   }