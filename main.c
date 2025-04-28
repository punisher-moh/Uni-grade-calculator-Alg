#include "function.h"

int main()
{
    int n , i , cf , x , a = 1;
    float M , noteE , noteT , examp , TDp;
    char subname [20];
    char fpath [30];
    FILE *f1;
    node p;
    init(&p);
    printf("\n1. get data from keyboard.");
    printf("\n2. get data from a file.");
    printf("\nchoose (1-2) : ");
    scanf("%d",&x);
    printf("give pourcentage of exam:");
    scanf("%f",&examp);
    printf("give pourcentage of exam:");
    scanf("%f",&TDp);
    switch(x)
    {
        case 1:
            printf("do you want to save your marks in a file press '1' if no '0'");
            scanf("%d",&a);
            if (a == 1)
              {
               printf("give file name where you want to save your data :");
               scanf("%s",fpath);
               f1 = fopen(fpath,"w");
               if(f1 == NULL) printf("error");
              }
                printf("how many modules do you have :");
                scanf("%d",&n);
                for(i = 1 ; i <= n ; i++)
                {
                  printf("give the %d subject name :",i);
                  scanf("%s",subname);

                  printf("give the coefition of %s :",subname);
                  scanf("%d",&cf);

                  printf("give the exam mark of %s :",subname);
                  scanf("%f",&noteE);

                  printf("give the TD note of %s :",subname);
                  scanf("%f",&noteT);
                  lecture(&p,subname,cf,noteE,noteT);
                  if (a == 1)
                     fprintf(f1,"subname:%s coef:%d noteE:%f noteT:%f\n",subname,cf,noteE,noteT);
                }
                  if (a == 1)
                    fclose(f1);
                break;
        case 2:
            printf("Your markes must be written in this format:\n");
            printf("subname:?? coef:?? noteE:?? noteT:??\n");
            printf("give the file path : ");
            scanf("%s",fpath);
            f1 = fopen(fpath,"r");
            if(f1 == NULL) printf("\nfile not exist !");
            else{
                while(!feof(f1))
                    {
                    fscanf(f1,"subname:%s coef:%d noteE:%f noteT:%f\n",subname,&cf,&noteE,&noteT);
                    lecture(&p,subname,cf,noteE,noteT);
                    }
                fclose(f1);
            }
            break;
      }
     printf("\nvotre moyenne est =%.2f",calcMoy(p , examp , TDp));
     free(&p);
   return 0;
}
