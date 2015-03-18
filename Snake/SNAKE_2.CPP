    /****************************SNAKE_GAME_2****************************/
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<limits.h>
#include<dos.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 10
#define MAX_LEN 500       //Max length of the snake:In pixels
int hd_x,hd_y; //Coordinates of the head of the snake
int LEN=10;  //Starting length of the snake:In pixels
int stop=0;
int fd_etn=0;
int itr_stop=INT_MAX;
int fx=300,fy=200;    //Starting coordinates of the Snake_food
int i=0,j=0;
int k=0,l=0;
int flg=0;

struct pix
{
 int m;
 int n;
 int itr;
 int flag;
};

struct cut
{
 int co_x;
 int co_y;
};
cut hd[501];

void check();
void iterate(pix**);
void change(pix**,int* ,int* );
void food();     //Generates the random location of snake food
void game_screen(int *,int ,int ,int ,int) ;   //To change the size of gaming area

void main()
{
 clrscr();

 int g=DETECT,q;
 initgraph(&g,&q,"c:\\turboc3\\bgi");
 int p=0;
 pix **pixel;

 pixel=(pix**)malloc(sizeof(pix)*MAX_LEN);
 for(int u=0;u<MAX_LEN;u++)
   pixel[u]=(pix*)malloc(sizeof(pix)*SIZE);

 int a=1,b=0;
 int c=1,d=0;
 int m,n;
 int time=5; //Delay time
 int cnt=0;
 while(i<MAX_LEN)
 {
  while(j<SIZE)
  {
   pixel[i][j].flag=0;
   j++;
  }
  j=0;
  i++;
 }
 int itr1=LEN+1;
 i=0;
 j=0;
 getch();
 while(1)
 {
   hd_x=200+i;
   hd_y=200+j;
   game_screen(&itr1,400,300,200,100);
   setcolor(YELLOW);
   rectangle(200+1,100+4, 400+4,300+7);
   if(itr1<=LEN)
   {
       itr1++;
   }
   setbkcolor(RED);
   setcolor(BLUE);
   outtextxy(hd_x,hd_y,".");
   if(!stop)
   {
    setcolor(RED);
    outtextxy(200+k-LEN,200+l,".");
   }
   if(kbhit())            //To check the buffer
   {
    int y=0;
    p=cnt;
    while(1)
    {
     if(!pixel[p][y].flag)
     {
      pixel[p][y].flag=1;
      pixel[p][y].itr=0;
      break;
     }
     y++;
    }
    a=getche();            //To retrieve the character from the buffer
    switch(a)
    {
     case 97: a=pixel[p][y].m=-1;
	      b=pixel[p][y].n=0;//left
	      time=5;
	      break;
     case 119:a=pixel[p][y].m=0;
	      b=pixel[p][y].n=-1;//top
	      time=5;
	      break;
     case 115:a=pixel[p][y].m=0;
	      b=pixel[p][y].n=1;//down
	      time=5;
	      break;
     case 100:a=pixel[p][y].m=1;
	      b=pixel[p][y].n=0;//right
	      time=5;
	      break;
     case 101:a=pixel[p][y].m=1;
	      b=pixel[p][y].n=-1;//diagnolly right up
	      time=7;
	      break;
     case 113:a=pixel[p][y].m=-1;
	      b=pixel[p][y].n=-1;//diagonally left up
	      time=7;
	      break;
     case 122:a=pixel[p][y].m=-1;
	      b=pixel[p][y].n=1;//diagonally left down
	      time=7;
	      break;
     case 99:a=pixel[p][y].m=1;
	      b=pixel[p][y].n=1;//diagnolly right down
	      time=7;
	      break;
     default:exit(0);


    }
  cnt=0;
  }
  check();
  food();
  i+=a;
  j+=b;
  change(pixel,&c,&d);

  if(!stop)
  {
   k+=c;
   l+=d;
  }
  else
  {
   k++;
  }
  iterate(pixel);

  delay(5);
  if(cnt!=LEN-1)
    cnt++;

  if(itr_stop==4)
   {
    stop=0;
   }
  if(itr_stop!=INT_MAX)
   itr_stop++;
 }

}

void iterate(pix **pixel)
{
 for(int i=0;i<MAX_LEN;i++)
 {
  for(int j=0;j<SIZE;j++)
  {

   if(pixel[i][j].flag)
   {
    pixel[i][j].itr++;
   }

  }
 }
}

void change(pix **pixel,int *c,int *d)
{
 for(int i=0;i<MAX_LEN;i++)
 {
  for(int j=0;j<SIZE;j++)
  {
   if(pixel[i][j].itr==LEN&&pixel[i][j].flag)
   {
    *c=pixel[i][j].m ;
    *d=pixel[i][j].n ;
    pixel[i][j].flag=0;
   }
  }
 }
}

void food()
{
   if(((hd_x>(fx-4)&&hd_x<(fx+4))&&(hd_y>(fy-4)&&hd_y<(fy+4))))
   {
   setcolor(RED);
   outtextxy(fx-1,fy+1,".");
   outtextxy(fx,fy,".");
   outtextxy(fx-1,fy,".");
   outtextxy(fx-1,fy-1,".");
   outtextxy(fx,fy+1,".");
   outtextxy(fx+1,fy+1,".");
   outtextxy(fx+1,fy-1,".");
   fd_etn=1;
  }
   if(fd_etn)
  {
   randomize();
   c:
   a:fx=rand()%400;

   if(fx<200)
   goto a;

   b:fy=rand()%300;

   if(fy<100)
   goto b;

   for(int i=1;i<=LEN;i++)    //Loop to check if the food coordinates
   {                          //coincide with snake body
      if(fx==hd[i].co_x&&fy==hd[i].co_y)
      goto c;
      else if(fx==(hd[i].co_x-1)&&fy==(hd[i].co_y-1))
      goto c;
      else if(fx==(hd[i].co_x-1)&&fy==(hd[i].co_y+1))
      goto c;
      else if(fx==(hd[i].co_x-1)&&fy==hd[i].co_y)
      goto c;
      else if(fx==(hd[i].co_x)&&fy==(hd[i].co_y+1))
      goto c;
      else if(fx==(hd[i].co_x+1)&&fy==(hd[i].co_y+1))
      goto c;
      else if(fx==(hd[i].co_x+1)&&fy==(hd[i].co_y-1))
      goto c;
   }
   fd_etn=0;
   LEN+=5;
   itr_stop=0;
   stop=1;
  }

  {
   setcolor(YELLOW);
   outtextxy(fx-1,fy+1,".");
   outtextxy(fx,fy,".");
   outtextxy(fx-1,fy,".");
   outtextxy(fx-1,fy-1,".");
   outtextxy(fx,fy+1,".");
   outtextxy(fx+1,fy+1,".");
   outtextxy(fx+1,fy-1,".");
  }
}


void game_screen(int *itr1,int x1,int y1,int x2,int y2)
{
   if(hd_x>x1||hd_x<x2)
   {
     if(hd_x>x1)
     {
       i=x2-200;
       flg=1;
     }
     if(hd_x<x2)
     {
      i=x1-200;
      flg=2;
     }
     *itr1=0;
   }

   if(hd_y>y1||hd_y<y2)
   {
     if(hd_y>y1)
     {
      j=y2-200;
      flg=3;
     }
     if(hd_y<y2)
     {
      j=y1-200;
      flg=4;
     }
     *itr1=0;
   }

   if(*itr1==(LEN))
   {
    switch(flg)
    {
     case 1:k=LEN+x2-200;
	    break;
     case 2:k=LEN+x1-200;
	    break;
     case 3:l=y2-200;
	    break;
     case 4:l=y1-200;
	    break;
     }
    flg=0;
    *itr1=LEN+1;
  }
}


void check()
{
  int a=4,it=0;
  for(int i=LEN;i>1;i--)
  {
   hd[i]=hd[i-1];
  }

  hd[1].co_x=hd_x;
  hd[1].co_y=hd_y;

  for(i=2;i<=LEN;i++)
  {
   if(hd[1].co_x==hd[i].co_x&&hd[1].co_y==hd[i].co_y)
   {
   do         //Blinking loop
   {
    for(i=1;i<=LEN;i++)
    {
     setcolor(a);
     outtextxy(hd[i].co_x,hd[i].co_y,".");
    }
     delay(80);
     if(a==4)
     {
      a=1;
     }
     else
     a=4;
     it++;
   }
   while(it<20);
   cleardevice();

   setbkcolor(BLACK);
   setcolor(WHITE);

   outtextxy(300,200,"Game Over");
   getch();
   exit(0);
  }
 }
}