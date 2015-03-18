#include<iostream.h>
#include<process.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void update();
void randomize_update(int i,int j);
void swap(int *,int *);
void batch(int i,int j)  ;
void x_axis(int i)   ;
void y_axis(int j) ;
void set();
void count(int i,int j);
void display_grid();
int solver();
int error();
int sudo[10][10], ch[10][10][10]={0};
int a[10]={0};

void main()
{
 clrscr();
 int i,j;
 char c;
 clock_t s,e;
 ifstream infile;
 infile.open("hard.txt");

 for( i=1;i<=9;i++)
   for( j=1;j<=9;j++)
     infile>>sudo[i][j] ;

 display_grid();
 s=clock();
 solver();
 e=clock();
 display_grid();

 cout<<"Time taken is:"<<(e-s)/CLK_TCK;
 getch();

}

void y_axis(int j){
	for(int i_e=1;i_e<=9;i_e++){
		if(sudo[i_e][j]){
		  a[sudo[i_e][j]]=1;
		}
	}
}

void x_axis(int i){
	for(int j_e=1;j_e<=9;j_e++){
		if(sudo[i][j_e]){
		   a[sudo[i][j_e]]=1;
		}
	}
}


void batch(int i,int j)
{
	int m,n;


	if(i<=3)
	m=1;
	else if(i>3&&i<=6)
	m=4;
	else
	m=7;

	if(j<=3)
	n=1;
	else if(j>3&&j<=6)
	n=4;
	else
	n=7;

	for(int x=m;x<(m+3);x++){
		for(int y=n;y<(n+3);y++){
			if(sudo[x][y]){

			   a[sudo[x][y]]=1;

			}
		}
	}
}

void count(int i,int j)
{
 int cnt=0,k=1;
 for(int l=1;l<=9;l++)
 {
  if(!a[l])
  {
   cnt++;
   ch[i][j][k]=l ;
   k++;
  }
 }
 ch[i][j][0]=cnt;
}

void set()
{
 for(int i=1;i<=9;i++)
      a[i]=0;
}

void update()
{
 for(int i=1;i<=9;i++)
  for(int j=1;j<=9;j++)
   for(int k=1;k<=9;k++)
     ch[i][j][k]=0;

 for(i=1;i<=9;i++)
 {
  for(j=1;j<=9;j++)
  {
    if(!sudo[i][j])
   {
    set();
    y_axis(j);
    x_axis(i);
    batch(i,j);
    count(i,j);
   }
   else
    ch[i][j][0]=0;
  }

 }

}


int solver()
{
 int cnt=1,k=1;
 int flag=0;
 update();


while(cnt<10)
{

 for(int i=1;i<=9;i++)
 {
  for(int j=1;j<=9;j++)
  {
     if(ch[i][j][0]==cnt)
     {
	su:
	sudo[i][j]=0;
	update();
	if(!ch[i][j][k])
	{
	  ch[i][j][0]=k-1;
	  sudo[i][j]=0;
	  return 1;
	}

	sudo[i][j]=ch[i][j][k]  ;
	ch[i][j][0]=0;
	update();
	if(error())
	{
	 k++;
	 sudo[i][j]=0;
	 goto su ;
	}


	if(solver())
	{

	 sudo[i][j]=0;
	 k++;
	 goto su;

	}
	flag=1;
	break;

     }

  }
  if(flag)
   break;
 }
 if(flag)
  break;
 cnt++;
}
 return 0;
}

int error()
{
 for(int i=1;i<=9;i++)
  for(int j=1;j<=9;j++)
   if(!ch[i][j][0]&&!sudo[i][j])
     return 1;

  return 0;
}

void display_grid()
{
 for(int i=1;i<=9;i++)
 {
  for(int j=1;j<=9;j++)
  {
   if(sudo[i][j]==0)
   cout<<"_"<<" ";
   else
   cout<<sudo[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl<<endl;
}

void swap(int *a,int *b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}

void randomize_update(int i,int j)
{
 int l;
 for(int k=1;k<=9;i++)
 {
    l=(rand()%9+1) ;
    swap(&ch[i][j][k],&ch[i][j][l]);

 }
}
