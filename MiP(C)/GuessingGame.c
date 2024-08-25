/* A guessing game using C programming 

#include<stdio.h>

int main() {

int guess_number[10];
int secret_number;
int i;
int guess_limit;
int count;

 secret_number = 7;
 guess_limit = 3;
  count = 0;

for(i=1; i<=guess_limit; i++) {
      printf("Enter number %d from 1-25: ",i);
      scanf("%d",&guess_number[i]);
      }

     for(i=1; i<=guess_limit; i++) {
    if(secret_number==guess_number[i]) {
        printf("You Won...!!!\n");
        break;
         }
     }

    for(i=1; i<=guess_limit; i++) {
    if(secret_number!=guess_number[i]) {
       count++;
    }
      }
        
         if(count==3) {
         printf("You Lost...!!!\n");
        printf("secret number is %d\n",secret_number);
         }
         return 0;
}

*/

#include<stdio.h>

int main() {
    int guess_number[10];
    int secret_number;
    int i;
    int guess_limit;

    secret_number = 7;
    guess_limit = 3;
  
    for(i = 0; i < guess_limit; i++) {
        printf("Enter number %d from 1-25: ", i + 1);
        scanf("%d", &guess_number[i]);
        
        if(secret_number == guess_number[i]) {
            printf("You Won...!!!\n");
            return 0; // Exit the program since the player has won
        }
    }

    printf("You Lost...!!!\n");
    printf("secret number is %d\n", secret_number);
    
    return 0;
}
