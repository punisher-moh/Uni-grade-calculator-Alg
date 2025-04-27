#include "function.h"
#include "module.h"
node creatNode (char *subname , int cf , float noteE , float noteT)
{
    node h=alloc();
    setcoef(h,cf);
    setexam(h,noteE);
    setmodulename(h,subname);
    setTD(h,noteT);
    setnext(h,NULL);
    return h;
}

void lecture (node *p,char * subname , int cf , float noteE , float noteT )
    {
      node h=creatNode (subname , cf , noteE , noteT);
      if (*p==NULL)
           *p = h;
      else{
           setnext(h,*p);
           *p = h;
          }
    }

float calcMoy (node p)
{
    float  moy=0;
    int CF=0;
    while (p!=NULL)
        {
         moy= moy + (getexam(p)*0.6 + getTD(p)*0.4)*getcoef(p);
         CF=CF+getcoef(p);
         p=getnext(p);
        }
   return(moy/CF);
}
