#include<stdio.h>
#include<string.h>

int n = 1; //number of students you want

typedef struct {
    int math;
    int stat;
    int pl1;


}Subj;
typedef struct {
    char name[30];
    int id;
    Subj mada;
    int Total;


}Student;
int main()
{
           char Name[30];
    int m,ID;
    Student taleb[n];// makes array of struct of n student
    printf("the number of students:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the student#%d name:\n",i+1);
        scanf("%s",taleb[i].name);
         printf("Enter the student#%d ID:\n",i+1);
        scanf("%d",&taleb[i].id);
        //taking the subjects information
        printf("math : ");
        scanf("%d",&taleb[i].mada.math);
        printf("stat : ");
        scanf("%d",&taleb[i].mada.stat);
        printf("pl1 : ");
        scanf("%d",&taleb[i].mada.pl1);
    }
    //sum the grades
    for(int i = 0; i < n; i++)
    {
         taleb[i].Total =  taleb[i].mada.math + taleb[i].mada.pl1 + taleb[i].mada.stat;

    }

    //searching
    printf("----------------------------------------------\n");
    label2:
    printf("choose how to search 1.with id \t 2.with name \t 3.with highest marks???\n");
    scanf("%d",&m);
    switch(m)
    {
      case 1:
          //with id
          ID = 0;
          printf("student ID:\n"); scanf("%d",&ID);
          for(int i = 0; i < n; i++)
          {
              if(ID == taleb[i].id)
              {
                  printf("student[%s] [ID:%d] information: \n\t math:%d\n\t stat:%d\n\t pl1:%d\n\t total:%d\n "
                         ,taleb[i].name
                         ,taleb[i].id
                         ,taleb[i].mada.math
                         ,taleb[i].mada.stat
                         ,taleb[i].mada.pl1
                         ,taleb[i].mada.math + taleb[i].mada.pl1 + taleb[i].mada.stat
                         );
                         goto label3;
              }
              if(i==n-1)
               {
                   printf("Not found\n");
                   printf("TRY again: \n");
                   goto label2;
               }
          }
          break;
          //case 2 to search with name
       case 2:
           printf("student name: "); scanf("%s",Name);
           for(int i = 0; i< n; i++)
           {
               if(!strcmp(Name,taleb[i].name)) //returns 0 if the two strings are the same
               {
                   printf("student[%s] [ID:%d] information: \n\t math:%d\n\t stat:%d\n\t pl1:%d\n\t total:%d\n "
                         ,taleb[i].name
                         ,taleb[i].id
                         ,taleb[i].mada.math
                         ,taleb[i].mada.stat
                         ,taleb[i].mada.pl1
                         ,taleb[i].mada.math + taleb[i].mada.pl1 + taleb[i].mada.stat
                         );
                          goto label3;

               }
               if(i==n-1)
               {
                   printf("Not found\n");
                   printf("TRY again: \n");
                   goto label2;
               }
           }
           break;
           //search with ranking or with grades
           case 3:
               for(int i = 0,max = 0,min = 101,count1,count2,max2 = 0,max3 = 0,max2Count,max3Count; i < n; i++)
               {
                   //taleb[i].Total
                   if(taleb[i].Total > max)
                   {
                       max = taleb[i].Total;
                       count1 = i;
                   }
                   if(taleb[i].Total < min)
                   {
                       min = taleb[i].Total;
                       count2 = i;
                   }
                   //this is for determine the second rank
                   if(i== n-1)
                   {
                       for(int j = 0; j < n; j++)
                       {
                           if(taleb[j].Total > max2 && taleb[j].Total > max)
                           {
                                max2Count = j;
                               max2 = taleb[j].Total;
                           }
                       }
                   }
                   //third rank
                    if(i== n-1)
                   {
                       for(int j = 0; j < n; j++)
                       {
                           if(taleb[j].Total > max3 && taleb[j].Total > max2)
                           {
                                max3Count = j;
                               max3 = taleb[j].Total;
                           }
                       }
                   }

                   if(i == n-1)
                   {
                       printf("the first student is [%s] [ID:%d] with total of: %d\n",taleb[count1].name,taleb[count1].id, max);
                       printf("the Last student is [%s] [ID:%d] with total of: %d\n",taleb[count2].name,taleb[count2].id, min);
                       printf("the second student is [%s] [ID:%d] with total of: %d\n",taleb[ max2Count].name,taleb[ max2Count].id, max2);
                       printf("the third student is [%s] [ID:%d] with total of: %d\n",taleb[max3Count].name,taleb[max3Count].id, max);
                   goto label3;
                   }

               }

               break;
           case 999:
            goto label4;
            break;
           default:
            printf("this is not an option\n Try again...");
            goto label2;




}

         label3:
             printf("do you want to choose again?  press 999 to leave\n");

                 goto label2;
        label4:
            printf("\n-------Good bye-----\n");

}
