
#include <stdio.h>
#include <stdlib.h>
#include<dos.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define M 50
#define N 25 //row
int X4,Y4,Game,i,j,Game=1,temp,X1=13,Y1=21,X2,Y2,X3,Y3,C1,C3,C4;
int field[N][M];int a=10,b=14,c=7,k=0,p=0,q=0,C2=0,head=2,count = 0;
char key;
int move,dir='s';
// This initialise the begin game screen  
void Initialisation()
{
	for(i=0;i<15;i++)
	printf("\n");
	for(j=0;j<25;j++)
	printf(" ");
	printf("FLAPPY BIRD\n BY YUVRAJ DARWANI");
	printf("\n\n PRESS ANY KEY TO CONTINUE.....");
	scanf("%c",&key);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++){
		
            field[i][j] =0;    
    }

}

	
	
}
// Used for initialising the bridge or pipes
void bridge()
{
	
	

	
	if(C2%50==0){	
	C2=0;
	srand(time(0));
	a = 10+rand()%3;  // random height
	
	}
	if(p%50==0){
	p=0;
	srand(time(0));
		b = 11 + rand()%3;
		
		}
	if(q%50==0)
	{
	q=0;
	srand(time(0));
	c = 12 + rand()%3;
	
	}
	  
	  	for(i=0;i<=25;i++)
	  	{
	  		if(i>a && i<17) continue;
	  		
	  		for(j=M-2-C2;j>=M-5-C2;j--)
	  		{
	  			
	  			field[i][j] = -1;
	  			
			  }
		
			
		  }
		 ++k;
		++C2;  
	

	 
	  if(k>=15)
	  {
	  	for(i=0;i<=25;i++)
	  	{
	  		if(i>b && i<17) continue;
	  		for(j=M-2-p;j>=M-5-p;j--)
	  		{
	  			field[i][j] =-1;
			  }
			  
			  
		  }
		  p++;
	
	  }
	  if(k>=30)
	  {
	  		for(i=0;i<=25;i++)
	  	{
	  		if(i>c && i<18) continue;
	  		for(j=M-2-q;j>=M-5-q;j--)
	  		{
	  		field[i][j] =-1;
			  }
			
			  
		  }
		 
		   
	  	q++;
	  
  	
  }
   
    
}
// for rendering purpose
void print()
{
        for(i=0;i<M;i++)
 {
     if(i==0)
        printf("%c",201);
        else
        {
        	if(i==M-1)
        printf("%c\n",187);
        else
        printf("%c",205);
		}
     
 }
 
 for(i=0;i<N;i++)
 {
     printf("%c",186);
     for(j=1;j<M;j++)
     {
             if(j==M-1) 
			 printf("%c\n",186);
             else{
             	if(field[i][j]==0) printf(" ");
             	else{
				 
             	if(field[i][j]<0) printf("*");
             	else{
				 
             	if(field[i][j]==head) 
				 printf("%c",176);
			 }}}
     }
 }
 for(i=0;i<M;i++)
 {
     if(i==0)
        printf("%c",200);
     else{
	 
	 if(i==M-1)
        printf("%c",185);
     else
        printf("%c",205);
 }
}
}
// for reseting the cursor position
void ResetScreenPosition()
{
	HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X =0;
    Position.Y =0;
    SetConsoleCursorPosition(hOut,Position);

}
// erasing or deleting the field[][] values
void erase()
{
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
	   	
	   	if(field[i][j]!=head)
		field[i][j]=0;
	}}
}
// final game state
void GameOver()
{
	

	Game = 0;
	printf("\a");
    Sleep(1500);
    system("Cls");

}
// inputing key
int get_key()
{
    if(_kbhit())
        return _getch();
    else
        return -1;
}
// snale or flappy bird initailisation
void snaleInitialisation()
{
	field[X1][Y1]= head;
}
// acutually snake is the flappy bird 
void snale()
{

move = get_key();
if(move=='w') 
{
	X1=X1-2;
		head++;
		X1 = (int) X1;
		
		if(field[X1][Y1]<0|| X1==0) GameOver();
	
}

else{


    if(count %5==0) {
	
    X1 = X1 + 1;
    X1 = (int) X1;
	head++;
	if(field[X1][Y1]<0 || X1==N) GameOver();
}
}
}
int main()
{
	Initialisation();
	if(key>=65 && key<=120){
	
	system("Cls");
	// The game Loop!
   while(Game!=0)
   {
   	
bridge();
snaleInitialisation();
   
   print();
   snale();
   
   erase();
   ResetScreenPosition();
   count = count +1;

   
   
}
printf("\n THE GAME IS OVER");



C3 = (k/50)*3;
 printf("\n\nYOUR TOTAL SCORE IS .........%d",C3);
}
}




