//code
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>


/*
for every student we will track two pointer head and tail for easily insertion and deletion
*/
typedef struct Course{
     char *course_title;
     int course_code;
     int course_credit;

     struct Course *next;
}course;

typedef struct Student{
    char *name;
    int id;
    int password;

    float cgpa;
    char *semeter;
    int credit; 
    course *course; // head for course

    struct Student *next;
    struct Student *prev;
    
}student;

// From the above code we create a student structure which represents a single student with containing attributes like name,cgpa,

student *createStudent(const char *name,int id,int password,float cgpa,const char *semester){
    student newStd=(student)malloc(sizeof(student));

    newStd->name=(char*)malloc(50*sizeof(char));
    strcpy(newStd->name,name);

    newStd->id=id;
    newStd->password=password;
    newStd->cgpa=cgpa;

    newStd->semeter=(char*)malloc(20*sizeof(char));
    strcpy(newStd->semeter,semester);

    newStd->course=NULL; //current head null as no course added till now
    newStd->credit=0;

    newStd->messages=NULL;

    newStd->prev=NULL;
    newStd->next=NULL;

    return newStd;
}

course *createCourse(const char *title, int code,int credit){
    course newCourse= (course)malloc(sizeof(course));

    newCourse->course_title=(char*)malloc(50*sizeof(char));
    strcpy(newCourse->course_title,title);
    
    newCourse->course_code=code;
    newCourse->course_credit=credit;
     
    newCourse->next=NULL; 
    return newCourse;

}

void addStudent(student **head,student **tail,student *newStudent){ // always adding in the end 

//time complexity:O(1)

    if(*head==NULL){
        *head=*tail=newStudent;
    }
    else{
        newStudent->prev=*tail;
        (*tail)->next=newStudent;
         *tail=newStudent;
    }

}

void deleteStudent(int position,student **head,student **tail){ // at position  

//time complexity:O(n)
     if(*head==NULL || position<0){
            printf("The List is Empty or the Position is wrong\n");
            return;
     }
    
    student *temp=*head;
    student *prevTemp=NULL;

    for(int i=0; i<position && temp!=NULL ; i++){
         prevTemp=temp;
         temp=temp->next;
    }

    if(temp==NULL){
        printf("The position is out of bound\n");
        return;
    }
    if(prevTemp==NULL){  
        // int the case of 1st Student
        
         *head= temp->next;

         if(*head != NULL){
            (*head)->prev=NULL; 
         }
         free(temp);
         return;
    }

    else{
        prevTemp->next=temp->next;

        if(temp->next != NULL){
        temp->next->prev=prevTemp;
        }
       if(temp->next==NULL){
            // temp is the last node so we should change the tail pointer also
           *tail= prevTemp;
        }

        free(temp);
    }
}
void addCourse(student *std,const char *fileName,int courseNumber){

     if(std==NULL){
     printf("The student not found\n");
      return;
     }

    FILE *file= fopen(fileName,"r");
    if(file==NULL){
    printf("File cannot open sorry\n");
      return;
    }

    int currentNumber=1;
    char line[100];

    while(currentNumber<courseNumber){
       if(fgets(line,sizeof(line),file)==NULL){
        printf("Data missing in the file\n");
        fclose(file);
        return;
       }
       currentNumber++;
    }

    char title[50];
    int code,credit;

    if(fscanf(file,"%s %d %d",title,&code,&credit) != 3){
        printf("Input has no 3 data\n");
        fclose(file);
        return;

    }

    course *newCourse= createCourse(title,code,credit);

 if(std->credit+newCourse->course_credit<=12){
    if(std->course==NULL){
        std->course=newCourse;
    }
    else{
       course *ptr=std->course;

       while(ptr->next != NULL){
        ptr=ptr->next;
       }
       ptr->next=newCourse;
    }

    std->credit=std->credit+newCourse->course_credit;
    printf("Course added successfully\n");
     printf("---------------------------------\n");
    fclose(file);
    return;
  }
  else{
    printf("No course will be added As it cross the limit\n");
     printf("---------------------------------\n");
    fclose(file);
    return;
  }

}


void deleteCourse(student *std, int position){
   if(std==NULL){
    printf("Invalid student\n");
     printf("---------------------------------\n");
    return;
   }

    if(position<0 || std->course==NULL){
        printf("The List is empty or position wrong\n");
         printf("---------------------------------\n");
        return;
    }
    
    course *temp= std->course;
    course *prev=NULL;
    for(int i=0; i<position && temp!=NULL; i++){
           prev=temp;
           temp=temp->next;
    }
    if(temp==NULL){
        printf("The position is out of bound\n");
       printf("---------------------------------\n");
        return;
    }

    if(prev==NULL){
        // means head is going to change
        std->course=temp->next;
         std->credit=std->credit-temp->course_credit;
        free(temp);

     printf("Course deleted successfully\n");
     printf("---------------------------------\n");
        return;
    }
    else{
        prev->next=temp->next;
        std->credit=std->credit-temp->course_credit;
        free(temp);

    printf("Course deleted successfully\n");
     printf("---------------------------------\n");
        return;
    }
}

void printStudents(student *head){

student *ptr=head;
printf("------------Resistered Students:-----------\n");
int counts=1;
    while(ptr !=NULL ){
        printf("%d,Name: %s, Id: %d,Semester: %s,CGPA: %f,Credit: %d\n",counts,ptr->name,ptr->id,ptr->semeter,ptr->cgpa,ptr->credit);

        counts++; 
        ptr=ptr->next;
    }

       printf("-----------------------------------------\n");
}
void addedCourse(student *std){
     
     course *ptr= std->course;
     int i=1;

     while(ptr != NULL){
        printf("%d.Title: %s,Code: %d,Credit: %d\n",i,ptr->course_title,ptr->course_code,ptr->course_credit);
        i++;

        ptr=ptr->next;
     }
     printf("-----------------------------------------\n");
  
}

void printStudentDetail(student *head,int id,int password){
    student *ptr= head;

    while(ptr != NULL){
       if(ptr->password==password && ptr->id==id){
        printf("----------------The Information about Student----------------\n");
        printf("Name: %s\n",ptr->name);
        printf("Id: %d\n",ptr->id);
        printf("CGPA: %f\n",ptr->cgpa);
        printf("Semester: %s\n",ptr->semeter);
        printf("Credit: %d\n",ptr->credit);
        printf("Take courses: \n");
        addedCourse(ptr);
       }

       ptr=ptr->next;
    }
}

void printAvailableCourse(const char *fileName){
    FILE *file= fopen(fileName,"r");

    if(file==NULL){
        printf("File Will not open.\n");
        return;
    }

    printf("-------- Available Courses -------------\n");

    char line[100];
      int i=1;
    while(fgets(line,sizeof(line),file) != NULL){
        char title[50];
        int code,credit;

        if(sscanf(line,"%49s %d %d",title,&code,&credit)==3){
            printf("%d.Title: %s,Code: %d,Credit: %d\n",i,title,code,credit);
            i++;
        }    
    }
    printf("-----------------------------------------\n");
    fclose(file);
}

student *findStudent(student *head,int id,int pass){
        student *ptr=head;

    while(ptr != NULL){
        if(ptr->id==id && ptr->password==pass){

            return ptr;
        }
        ptr=ptr->next;
    }
}


void printingMessage(student *s){
    printf("---------------------------\n");
    if(s->messages != NULL){
        printf("%s\n",s->messages);
    }
    else{
        printf("You have no messages\n");
    }
    printf("---------------------------\n");
}



int main(){
   student *head,*tail;
   head=tail=NULL;

   int choice1,choice2,choice3,choice4;

   printf("\t\t------Student Management System--------\n\n");
do{
   
    printf("------------Main Menu------------\n");\
    printf("1.Student\n");
    printf("2.Advisor\n");
    printf("3.Messaing System\n");
    printf("4.Exit\n");

    printf("Enter Choice: ");
    scanf("%d",&choice1);
    getchar();

    printf("----------------------------------\n");


  switch(choice1){
    case 1:{
    do{
        
        printf("----------------Student Menu:---------------\n");
        printf("1.Register\n");
        printf("2.Login\n");
        printf("3.View Student List\n");
        printf("4.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice2);
        getchar();

        printf("----------------------------------\n");

        switch(choice2){
            case 1:{
                printf("Please fill up the below form\n");
                char name=(char)malloc(50*sizeof(char));
                char sem=(char)malloc(50*sizeof(char));
                int id,pass;
                float cgpa;

                printf("Enter Name: ");
                fgets(name,50,stdin);
                printf("Enter Id: ");
                scanf("%d",&id);
                getchar();
                printf("Enter CGPA: ");
                scanf("%f",&cgpa);
                getchar();
                printf("Enter Semester: ");
                fgets(sem,50,stdin);
                printf("Set a Password: ");
                scanf("%d",&pass);
                getchar();
                
                addStudent(&head,&tail,createStudent(name,id,pass,cgpa,sem));

                printf("Student is added successfully\n");
                
                break;
            }

            case 2:{
                int id,pass;
                bool isFound=false;

                printf("Enter Student Id: ");
                scanf("%d",&id);
                getchar();
                printf("Enter Password: ");
                scanf("%d",&pass);
                getchar();

                student *ptr=head;

                while(ptr != NULL){
                   if(ptr->password==pass && ptr->id==id){
                         isFound=true;
                         break;
                   }
                   ptr=ptr->next;
                }

               // options for login data.....

             if(isFound==true){

                student *s=findStudent(head,id,pass); // to get the right student from the list
                
               do{  
                printf("---------------Wlcome To Student profile-----------------\n");
                printf("Name: %s,Id: %d\n",s->name,s->id);
               
                printf("1.Print Student Details\n");
                printf("2.See offered Course\n");
                printf("3.Add Course\n");
                printf("4.Delete Course\n");
                printf("5.See Added Course\n");
                printf("6.See Message\n");
                printf("7.Exit student profile\n");
                
                printf("Enter Choice: ");
                scanf("%d",&choice3);
                getchar();

                printf("-------------------------------------\n");

                switch(choice3){
                   case 1:{
                    printf("---------Printing Student's Information---------\n");
                    printStudentDetail(head,id,pass);
                    break;
                   }
                   case 2:{
                    printAvailableCourse("course.txt");
                    break;
                   }
                   case 3:{
                    int n;
                    printf("Enter the desire Course Number: ");
                    scanf("%d",&n);
                    getchar();
                    addCourse(s,"course.txt",n);

                    break;
                   }
                   case 4:{
                    int pos;
                    printf("Select the number your desire course to delete: ");
                    scanf("%d",&pos);
                    getchar();

                    deleteCourse(s,(pos-1));
                    break;
                   }
                   case 5:{
                     printf("Added Course: \n");
               
                     addedCourse(s);
                     break;
                   }
                   case 6:{
                    printf("Messages: \n");
                     printingMessage(s);

                    break;
                   }
                   case 7:{
                    printf("You'r exiting the log in profile\n");
                    break;
                   }
                   default:{
                    printf("Invalid choice.\n");
                    break;
                   }
                }

                 }while(choice3 != 7);   
            }
               else{
                printf("Password or id invalid\n");
               }

               break;

            }  
            case 3:{
                printStudents(head);
                break;
                

            }
            case 4:{
                printf("The Student Profile is Now exiting\n");
                break;
            }
            default:{
                printf("You pressed wrong Button\n");
                break;
            }
        }
    }while(choice2 != 4);

    break;
    
  }
  case 2:{

    printf("-------------Advisor Menu--------------\n");
      int password,id;

      printf("Enter Unique ID: ");
      scanf("%d",&id);

      printf("Enter Password: ");
      scanf("%d",&password);

      if(id==2023160213 && password== 6969){
       do{
        
      printf("1.Fix Students ID\n");
      printf("2.Delete Student\n");
      printf("3.See Notification\n");
      printf("4.See Student List\n");
      printf("5.Leave\n");

      printf("Enter Choice: ");
      scanf("%d",&choice4);
      getchar();

      switch(choice4){
        case 1:{
            printf("Fixing the student\n");
            int id,pass;
            
            printf("Enter Id: ");
            scanf("%d",&id);
            getchar();
            printf("Enter student password: ");
            scanf("%d",&pass);
            getchar();
    
            student *std=findStudent(head,id,pass);

            printf("Please fill up the below form\n");
                char new_name=(char)malloc(50*sizeof(char));
                char new_sem=(char)malloc(50*sizeof(char));
                int new_id;
                float new_cgpa;

                printf("Enter Name: ");
                fgets(new_name,50,stdin);
                printf("Enter Id: ");
                scanf("%d",&new_id);
                getchar();
                printf("Enter CGPA: ");
                scanf("%f",&new_cgpa);
                getchar();
                printf("Enter Semester: ");
                fgets(new_sem,50,stdin);

               strcpy(std->name,new_name);
               strcpy(std->semeter,new_sem);
               std->id=new_id;
               std->cgpa=new_cgpa;
    
             printf("-----------Student information is edited successfully--------------\n");
            

            break;
        }
        case 2:{
            int pos;

             printf("Enter the position you want to delete: ");
             scanf("%d",&pos);
             getchar();

             if(head==NULL){
                printf("Student list is empty\n");
             } 
             else{
                deleteStudent(pos-1,&head,&tail);
                printf("Student is successfully deleted\n");

             }

             printf("-----------------------------------\n");

            break;
        }
        case 3:{



            break;
        }
        case 4:{

            printf("Printing the Student List\n");
            
            printStudents(head);
            break;
        }
        case 5:{
            printf("You are leaving the site\n");
            break;
        }
        default:{
            printf("You presseed something wrong\n");
            break;
        }
      }
     
      }while(choice4 != 5);

      }
      else{
        printf("Password or id wrong\n");
      }


      break;
  }
  case 3:{
     printf("--------------Message Portal-------------\n");
     printf("Enter ID: ");


    break;
         
  }
  case 4:{
    printf("-----------------FULL CLOSE APPLICATION---------------\n");
    break;
  }
  default :{
     printf("Pressed Wrong\n");
     break;
  }


    }
   
}while(choice1 !=4);
return 0;
}
