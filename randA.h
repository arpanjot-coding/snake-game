#include <stdlib.h>
#include <time.h>

int CycleCounterC=0,CycleCounterR=0;//Counts the cycles and decides with method of value generating to use.
int randPreviousC=0,randPreviousR=0;



void numberGen(size_t total, int *retTemp, size_t cycleCount)
{
 if(cycleCount%2==0)
 {for(int i=0;i<4;i++)
    {
     *retTemp+=total%10; 
     total/=10;
    }
 }else{
   for(int i=0;i<2;i++)
    {
     *retTemp+=total%10; 
     total/=10;
    }

 }  
    
    
}     






int randA(char axis)
{ clock_t start_t,end_t,total_t;int retTemp_t=0;
    
  start_t=clock();
  for(int i=0;i<1000000;i++){}
  end_t=clock();
  total_t=start_t-end_t;  
  
  //printf("%c\n",axis);

  if(axis=='C')
  {
    lableC:
    numberGen(total_t, &retTemp_t,CycleCounterC);
    if(retTemp_t==randPreviousC && retTemp_t==0/*&& player location != retTemp_t   */){goto lableC;}//You will need to add the condtion to check if the player is on the axis that it generated. 
    randPreviousC= retTemp_t;  
    CycleCounterC++; 
  }

 

   if(axis=='R')
  { lableR:
    numberGen(total_t, &retTemp_t,CycleCounterR);
    if(retTemp_t==randPreviousC && retTemp_t==0 /*&& player location != retTemp_t   */){goto lableR;}//You will need to add the condtion to check if the player is on the axis that it generated.
    if(retTemp_t>18){retTemp_t-=18;} //IF YOU WANT TO INCRESE THE NUMBER VALUES JUST CHNAGE THEM HERE
    randPreviousR= retTemp_t;  
    CycleCounterR++; 
  }

 

  
return retTemp_t;
}