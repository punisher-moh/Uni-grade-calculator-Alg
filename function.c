#include "function.h"
node creatNode (char *subname , int cf , float noteE , float noteT)
{
    node h=alloc();
    setcoef(h , cf);
    setexam(h , noteE);
    setmodulename(h , subname);
    setTD(h , noteT);
    setnext(h , NULL);
    return h;
}

void lecture (node *p ,char * subname , int cf , float noteE , float noteT )
    {
      node h = creatNode (subname , cf , noteE , noteT);
      if (*p == NULL)
           *p = h;
      else{
           setnext(h , *p);
           *p = h;
          }
    }

float calcMoy (node p , float examp , float TDp)
{
    float  moy = 0;
    int CF = 0;
    node tmp ;
    while (p != NULL)
        {
         moy = moy + (getexam(p) *examp + getTD(p) * TDp) * getcoef(p);
         CF = CF+getcoef(p);
         tmp = p;
         p = getnext(p);
         FreeNode(&tmp);
        }
   return(moy/CF);
}
