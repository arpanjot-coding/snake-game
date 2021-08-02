#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "randA.h"

#define c 20
#define r 40
int xPos=0,yPos=0,score=0,randC=0,randR=0;




void playerComads()
{ 
  char playerIn=' ';

   scanf("%c",&playerIn);

  //Player location  
   switch(playerIn)
   { case 'w':
     yPos--;
     break;   
     case 's':
     yPos++;
     break;
     case 'd':
     xPos++;
     break;
     case 'a':
     xPos--;
     break;
   }
}


void powerGen(int *randC,int *randR)
{ 
   *randC=randA('C');
   *randR=randA('R');
}


void field()
{ printf("\e[1;1H\e[2J");
  //Food for snake
  //randC=coloums & randR=Rows  
  if((randC==yPos&&randR==xPos)||(randC==0&&randR==0)){powerGen(&randC,&randR);score++;}
   
  printf("Your Score - %d\n\n",score-1);
  //Boundry collision detection
for(int i=0;i<c;i++)
  {for(int j=0;j<r;j++)
   {if(i==0||i==19||j==0||j==39)
      {    
        if(yPos==i&&xPos==j)
        {printf("\e[1;1H\e[2J");
        printf("GAME OVER");exit(0);}
        
      }
   }  
  }

  //printing code
  for(int i=0;i<c;i++)
  {for(int j=0;j<r;j++)
   { if(i==0||i==19||j==0||j==39)
      {printf("*");}
       else{if(i==randC && j==randR)
            {printf("#");}
            else{if(i==yPos && j==xPos)
                 {printf("@");}else{printf(" ");}
                }
           }                             
      }
     printf("\n");
   } 

int tempX=xPos,tempY=yPos;   
playerComads();
//if(tempX!=xPos || tempY!=yPos)
//{field();}//add else to check player health and
field();
}

  
//--------------
int main()
{
  xPos=randA('C');
  yPos=randA('R');
 

  field();
  
  //printf("\e[1;1H\e[2J");
}