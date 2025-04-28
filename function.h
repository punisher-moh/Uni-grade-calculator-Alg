#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "module.h"
node creatNode (char *subname , int cf , float noteE , float noteT);
void lecture (node *p,char * subname , int cf , float noteE , float noteT );
float calcMoy (node p, float examp , float TDp);
#endif
