#include<iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>
int i=0,j=0,n=0;
int brd[8][8],empty[35][2];
char draw[10][10];
char score_out[7];
int score=0,fail=0,check=0,emp_no=0;
int xmax=getmaxx();
int ymax=getmaxy();

void score_display()
  {  int tmp=0,tmp1=0,count=0,count1=0;
     tmp=score;

     while(tmp!=0)
	      { tmp1=(tmp1*10);
		tmp1=tmp1+(tmp%10);
		tmp=(tmp/10);
		count++;
	      }

	    while(count1!=count)
	      {
		score_out[count1]=char((tmp1%10)+48);
		tmp1=(tmp1/10);
		count1++;
	      }

	     score_out[count1+1]='\0';
    settextstyle (0, 0,2);
    outtextxy (xmax/2 - 100 ,ymax/2 + 190," YOUR SCORE :");
    outtextxy (xmax/2 +150 ,ymax/2 + 190, score_out);
   }




void welcome_screen()
  {
     for(i=1;i<=4;i++)
    { settextstyle (0, 0, 6);
    setcolor (i);
    outtextxy ((xmax/2)-320+(i*10),ymax/2-180+(i*2)," WELCOME !!! ");
    settextstyle (0, 0,5);
    outtextxy ((xmax/2)-250+(i*10),ymax/2-70," LETS PLAY ");
    }


      for (i=0;i<20;i++)
  { setfillstyle(9,(i/4));
    bar (0, 0, i,ymax);
    bar (0, 0, xmax,i);
    bar (xmax, 0, xmax-i,ymax);
    bar (xmax, ymax, 0, ymax-i);
    delay (50);
  }



    setcolor(WHITE);
    circle(xmax/2,ymax/2+100,100);
    setfillstyle(1,BLUE);
    floodfill(xmax/2,ymax/2+100,getmaxcolor());

    settextstyle(0,0,5);
    setcolor(12);
    outtextxy(xmax/2-70,ymax/2+80,"2048");


  delay(1000);
    getch();
  cleardevice();

  }

void begin()
 {
   int tmp=0,tmp1=0,count=0,set=0;

   char arr[12][4]={'\0'};

   for(i=1;i<=11;i++)
      { count=0;
	tmp=pow(2,i);

	 while(tmp!=0)
	      { tmp1=(tmp1*10);
		tmp1=tmp1+(tmp%10);
		tmp=(tmp/10);
	      }

	    while(tmp1!=0)
	      {
		arr[i][count]=char((tmp1%10)+48);
		tmp1=(tmp1/10);
		count++;
	      }

	     arr[i][count]='\0';
	}


  for(i=1;i<12;i++)
    {
     set=((i-1)/3);
     for (int j=0;j<17;j++)
       {
	  circle((xmax/2),(ymax/2)-50,25+(i*11));
	  setfillstyle(SOLID_FILL,i+1);
	  floodfill((xmax/2)-24+(i*11),(ymax/2)-50,getmaxcolor());

       if(i<11)
	 {
	  circle((xmax-(j*20)),(ymax/2)-50,25+(i*11));
	  settextstyle(1,0,6);
	  outtextxy(((xmax-10)-(j*20)-(set*15)),(ymax/2)-80,arr[i]);
	  floodfill((xmax-(j*20))-24-(i*11),(ymax/2)-50,getmaxcolor());
	  floodfill((xmax-(j*20))+24+(i*11),(ymax/2)-50,getmaxcolor());
    setcolor(WHITE);
    }
	  settextstyle(1,0,6);
	  outtextxy(((xmax/2)-(set*15)-10),(ymax/2)-80,arr[i]);
	  setcolor(WHITE);
	  rectangle(40,ymax-90,xmax-40,ymax-60);
	  setfillstyle(1,i+1);
	  bar(40,ymax-90,(i*48)+(j*3),ymax-60);

	  delay(40-(i*2));

	  cleardevice();
	 }

     }

     welcome_screen();

}

void display_balls(int xm,int ym)
 {
     int count=0,tmp=0,tmp1=0;
     char no[1][7]={'\0'};
     score=0;
     emp_no=0;
     for(i=0;i<n;i++)
      {
	for(j=0;j<n;j++)
	  {
	    tmp=brd[i][j];
	    tmp1=0;

	    while(tmp!=0)
	      { tmp1=(tmp1*10);
		tmp1=tmp1+(tmp%10);
		tmp=(tmp/10);
	      }
	    count=0;

	    while(tmp1!=0)
	      {
		no[0][count]=char((tmp1%10)+48);
		tmp1=(tmp1/10);
		count++;
	      }

	     no[0][count]='\0';

	     if(brd[i][j]>64  && check==0)
		 {check=1;}

	    if( brd[i][j]!=0 )
	      {
		score+=brd[i][j];
		setcolor (WHITE);
		circle(xm-((n-1)*35)+(j*70),ym-((n-1)*35)+(i*70),30);

		settextstyle (10, 0, 1);
		setusercharsize(1, 2, 1, 2);
		outtextxy (xm-((n-1)*35)+(j*70)-((count-1)*9),ym-((n-1)*40)+(i*70),no[0]);
		setfillstyle(9,(log(brd[i][j])/M_LN2));
		floodfill(xm-((n-1)*35)+(j*70),ym-((n-1)*35)+(i*70)-13,getmaxcolor());
	      }
	    else
		{
		 empty[emp_no][0]=i;
		 empty[emp_no][1]=j;
		 emp_no++;
		}

	  }
      }

       score_display();

 }



void draw_board()
 {
   setcolor(WHITE);
   int xm=(getmaxx()/2);
   int ym=(getmaxy()/2);
   setlinestyle(SOLID_LINE,1,2);
   rectangle(xm-(n*35),ym-(n*35),xm+(n*35),ym+(n*35));
   setlinestyle(DOTTED_LINE,1,2);
   for(int i=0;i<(n-1);i++)
    {
      line(xm-(n*35)+(70*(i+1)),ym-(n*35),xm-(n*35)+(70*(i+1)),ym+(n*35));
      line(xm-(n*35),ym-(n*35)+(70*(i+1)),xm+(n*35),ym-(n*35)+(70*(i+1)));
    }

    display_balls(xm,ym);
 }

int accept_key()
 {
  int key =0;
   key = bioskey(0);

   if(key==19200)
    {return 1;}
   else if(key==19712)
     {return 3;}
   else if(key==18432)
     {return 2;}
   else if(key==20480)
     {return 4;}

   return key;
}

int endgame()
 {
   for(i=0;i<n;i++)
      { for (j=0;j<n;j++)
	 {
	   if(brd[i][j]==brd[i][j+1])
	      {return 1;}
	   if (brd[i][j]==brd[i+1][j])
	      {	return 1;}
	  }
	}
     return 0;
 }


void initial()
 { int a1=0,b1=0,a2=0,b2=0;

   for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
	{
	  brd[i][j]=0;
	}
     }

 while(((a1==a2)&&(b1==b2)))
 {
   a1=random(n);
   b1=random(n);
   a2=random(n);
   b2=random(n);
  }
  brd[a1][b1]=2;
  brd[a2][b2]=2;
  draw_board();

}

void rand(int n)
 { int count=0,ran=0;
    ran=random(emp_no);

    delay(500);
    if(check==0)
    {brd[(empty[ran][0])][(empty[ran][1])]=2;}
    else
    {brd[(empty[ran][0])][(empty[ran][1])]=pow(2,(random(2)+1));}
   clrscr();
   cleardevice();
   draw_board();
}


void arrange(int x)
  {
    int i=0,j=0,temp=0,tmp=0;
    if( (x==1)|| (x==2))
      {
	for(i=0;i<n;i++)
	 {
	   temp=0;
	   for(j=0;j<n;j++)
	    {
	      if(x==1)
		{
		   if(brd[i][j]!=0)
		     { tmp=brd[i][j];
		       brd[i][j]=0;
		       brd[i][temp]=tmp;
		      temp++;
		     }
		    else {fail=1;}

		}
	      else if(x==2)
		{
		    if(brd[j][i]!=0)
		      {
		       tmp=brd[j][i];
		       brd[j][i]=0;
		       brd[temp][i]=tmp;
		       temp++;
		      }
		    else {fail=1;}
		 }
	     }
	}
    }

    if( (x==3)|| (x==4))
      {
	for(i=(n-1);i>=0;i--)
	 {
	   temp=(n-1);
	   for(j=(n-1);j>=0;j--)
	    {
	      if(x==3)
		{
		   if(brd[i][j]!=0)
		     { tmp=brd[i][j];
		       brd[i][j]=0;
		       brd[i][temp]=tmp;
			temp--;
			}
		    else {fail=1;}
		}
	      else if(x==4)
		{
		    if(brd[j][i]!=0)
		      {
		      tmp=brd[j][i];
		       brd[j][i]=0;
		       brd[temp][i]=tmp;
		       temp--;
			}
		    else {fail=1;}
		 }
	      }
	     }
	}
  }


void move(int x)
{
  int tmp=0;
  arrange(x);

  if((x==1)||(x==2))
   {
     for(i=0;i<n;i++)
      {
	for(j=0;j<n;j++)
	   {
	     if(x==1 && brd[i][j]!=0)
	      {
	       if(brd[i][j]==brd[i][j+1])
		{
		 brd[i][j]*=2;
		 brd[i][j+1]=0;
		 j++;
		}
	       }
	     else if(x==2  && brd[j][i]!=0)
	     {
		if(brd[j][i]==brd[j+1][i])
		{brd[j][i]*=2;
		brd[j+1][i]=0;
		j++;
		}
	       }
	   }
      }
   }

 if((x==3)||(x==4))
   {
     for(i=(n-1);i>=0;i--)
      {
	for(j=(n-1);j>=0;j--)
	   {
	     if(x==3  && brd[i][j]!=0)
	      {
		if(brd[i][j]==brd[i][j-1])
		{
		 brd[i][j]*=2;
		 brd[i][j-1]=0;
		 j--;
		}
	       }
	     else if(x==4 && brd[j][i]!=0)
	     {
	       if(brd[j][i]==brd[ j-1][i])
	       {
		brd[j][i]*=2;
		brd[j-1][i]=0;
		j--;
	       }
	     }
	}
      }
  }

  arrange(x);
  cleardevice();
  draw_board();
  delay(100);
  if(emp_no != 0)
     {rand(n);}
  else if(endgame()==0)
     {
       cout<<"\ngame is over";
       getch();
     }
  else
	{ draw_board();}

 }


void main()
{ int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "d://tc//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
     cout<<"Graphics error: %s\n", grapherrormsg(errorcode);
      cout<<"Press any key to halt:";
      getch();
      exit(1); /* terminate with an error code */
   }


xmax=getmaxx();
ymax=getmaxy();

int xm=(getmaxx()/2);
int ym=(getmaxy()/2);
//begin();

 int x;

 cleardevice();
 randomize();

 cout<<"enter the side of board";
 cin>>n;
 clrscr();
 cleardevice();

 initial();

 do
 {
   x=accept_key();
   move(x);
 }
 while(x!=4209);


 getch();
}
