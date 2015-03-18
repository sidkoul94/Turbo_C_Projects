#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<process.h>
#include<string.h>
#define PI 3.14
float z,w,r=100;
int midx=300,midy=200;
int m=0,n=1,l=0,t=0;
int cnt=0,mnt=0;


void tip(char a,float Q)
{
 setlinestyle(0,1,2);
 float x,y;
 float i;
 switch(a)
 {
  case 1: for( i=Q-0.1;i<Q+0.1;i+=0.01)
	   {
	     moveto(300,200)  ;
	     x=cos(i);
	     y=sin(i);
	     linerel(-(y*50),(x*50));
	     moveto(300,200);
	   }
	   break;
  case 2: for( i=Q-0.1;i<Q+0.1;i+=0.01)
	   {
	     moveto(300,200) ;
	     x=cos(i);
	     y=sin(i);
	     linerel(-(x*50),-(y*50));
	     moveto(300,200);
	   }
	   break;
  case 3:  for( i=Q-0.1;i<=Q+0.1;i+=0.01)
	   {
	     moveto(300,200);
	     x=cos(i);
	     y=sin(i);
	     linerel((y*50),-(x*50));
	     moveto(300,200);
	   }
	   break;
  case 4:  for( i=Q-0.1;i<=Q+0.1;i+=0.01)
	   {
	     moveto(300,200);
	     x=cos(i);
	     y=sin(i);
	     linerel((x*50),(y*50));
	     moveto(300,200);
	   }

}
setlinestyle(2,1,2);
}
void dig_dis()
{      char d[]={'0','1','2','3','4','5','6','7','8','9'};
 char f[]={'a','0','1','2','3','4','5','6','7','8','9'};
 char s[3];
 s[2]='\0';
 s[0]=d[m];
 s[1]=d[n];
 n++;
 char g[3] ;
 g[2]='\0';
 g[0]=f[l];
 g[1]=f[t];

 outtextxy(40,30,g) ;
 outtextxy(60,30,":");
 outtextxy(70,30,s);
 if(n%10==0)
 { n=0;
   m++;
 }
 if(m%6==0)
 m=0;
 if(cnt%58==0)
 {
  t++;
  cnt=0;
 }
 if(mnt%600==0)
  l++;
 if(l%6==0)
  l=0;

  cnt++;
  mnt++;
}

int f=11,a=1;
void crcle(int x,int y,int r)
{
 setfillstyle(f,a);
 setcolor(a);
 bar3d(100,70,500,330,5,1);
 setcolor(3);
 for(int i=0;i<7;i++)
 {
   circle(x,y,r+20+i);
 }
 setcolor(15);
 circle(x,y,2) ;
}

void lines()
{
    setlinestyle(0,1,1);
    float x,y,w,z;
    for(int i=0;i<60;i++)
   {
    x=cos((PI/30)*(i+1));
    y=sin((PI/30)*(i+1));
    w=midx+r*y;
    z=midy+r*x;
    moveto(w+10*y,z+10*x);
    if((i+1)%5==0)
    {
    moveto(w+10*y,z+10*x);
    linerel(10*y,10*x);
    }
    else
    linerel(5*y,5*x)  ;
   }
   moveto(midx,midy);
   setlinestyle(2,1,2) ;
   setlinestyle(3,1,1);
}
void display()
{
   setcolor(YELLOW);
   char d[12]={'1','2','3','4','5','6','7','8','9','0','1','2'};
   char c[2],b[3];
   c[1]='\0';
   b[0]='1';
   b[2]='\0';
   char h[2];
   h[1]='\0';
   h[0]='1';
   for(int k=0;k<=12;k++)
  {
    z=cos((PI/6)*(k-2));
    w=sin((PI/6)*(k-2));
    if(k==5||k==11)
    {
     if(k==5)
     outtextxy(midx+r*z-3,midy+r*w,"6");
     else
     outtextxy(midx+r*z-5,midy+r*w-3,"12");
    }
    else if(k==10)
    outtextxy(midx+r*z-3,midy+r*w-3,"11");
    else if(k==9)
    {
      outtextxy(midx+r*z-4,midy+r*w-4,"10");
    }
    else if(k==0)
    {
     outtextxy(midx+r*z,midy+r*w,h)    ;
    }
    else if(k==2||k==8)
    {
     if(k==2)
     outtextxy(midx+r*z,midy+r*w-2,"3")    ;
     else
     outtextxy(midx+r*z,midy+r*w-3,"9")    ;
    }
    else if(k<9)
    {
     c[0]=d[k];
     outtextxy(midx+r*z,midy+r*w,c)    ;
    }
    else
    {
     b[1]=d[k];
     outtextxy(midx+r*z,midy+r*w,b)    ;
    }
   }
setcolor(15) ;
}

void clock()
{
 float x,y,m,n;
 int a=90;
 float Q;
 cleardevice();
 for(int k=0;;k++)
 {
  m=cos((PI/30)*(k));
  n=sin((PI/30)*(k));
  //clrscr();
  cleardevice();
  crcle(midx,midy,r);
  moveto(midx,midy) ;
  //setlinestyle(1,1,0);
  setcolor(GREEN) ;
  linerel(((a-30)*n),-((a-30)*m));
  moveto(midx,midy) ;
  linerel((-(20)*n),((20)*m));
  for(int j=1;j<=4;j++)
  {
   for(int i=0;i<15;i++)
   {
    setcolor(RED);
    Q=(PI/30)*(i+1)       ;
    x=cos(Q)    ;
    y=sin(Q);
    moveto(midx,midy) ;
    //setlinestyle(3,1,7);
    if(kbhit())   //manual exit from the program
    {
     nosound();
     exit(0);
    }
    switch(j)
    {
     case 1:
      linerel((a*y),-(a*x))   ;
      tip(1,Q);
      break;
     case 2:
      linerel((a*x),(a*y));
      tip(2,Q);
      break;
     case 3:
      linerel(-(a*y),(a*x));
      tip(3,Q);
      break;
     case 4:
      linerel(-(a*x),-(a*y));
      tip(4,Q);
    }
    setcolor(15);
    lines();
    display();
    dig_dis();
    nosound();
    delay(1000);
    sound(3000);
    cleardevice();
    crcle(midx,midy,r);
    setcolor(GREEN);
    moveto(midx,midy) ;
    linerel(((a-30)*n),-((a-30)*m));
    moveto(midx,midy) ;
    linerel(-((20)*n),((20)*m));
   }
  }
 }
}

void main()
{
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi") ;
 cleardevice();
 setcolor(WHITE);
 outtextxy(180,200,"Press any key to enter and leave")    ;
 getch();
 clock();
 closegraph();
}






