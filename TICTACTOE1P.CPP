
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<time.h>
#include<dos.h>
#include<string.h>

int y[5];
int no=0,no1=0;
int d[9][5];
int e[9][5];
int f[9][5];
int g[9][5];
  int b[10][5];
   int a[10][5];
   int c[10][5];
   int move[10][5];
   int ginti[2][10];
   int winner();
   void compwin();
   void plwin();
   char alpha[10][9]={"A","B","C","D","E","F","G","H","I"};
   char beta;
   char x;
   int chance=-2;
   int i,j,k,ran=0,p=0,ran1=0,flag5=0;
   void graphmove();
   void initialize();
   void moves();
   void compwinmove();
   void draw();
   void check();
   void instructions();
   void loaddriver();
   void initialboard();
   int ok2=0,dr=0,pl=0,comp=0;
void  main()
{   loaddriver();
    instructions();

   char consent='Y';
   while(consent!='N')
	{initialboard();
	randomize();
	initialize();
	moves();
	cleardevice();
	gotoxy(10,20);
	cout<<"Do you want to play again (Y/N)";
	cin>>consent;
   }
   getch();
   closegraph();

}


void initialize()
 {
     chance=-2;
   for(no=0;no<10;no++)
     {
     for(no1=0;no1<5;no1++)
       {
	a[no][no1]=10;
	b[no][no1]=10;
	c[no][no1]=10;
	move[no][no1]=10;
       }
     }

   //DEFAULT ARRAY A
   for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	   {
	  a[((i*3)+j)][0]=i;
	  a[((i*3)+j)][1]=j;
	  a[((i*3)+j)][2]=((i*3)+j)+65;
	  a[((i*3)+j)][3]=((i*3)+j);
	   }
      }
  }


void moves()
{  int x1;

  chance= -1;

   for(i=0;i<5;i++)
      { gotoxy(6,27);
	cout<<"Enter the position: ";

    reenter:
    ok2=0;
    cin>>x;
    for(j=0;j<9;j++)
       {
	if(int(x)== a[j][2])
	 {
	 b[i][0]=a[j][0];
	 b[i][1]=a[j][1];
	 b[i][3]=a[j][3];
	 for(k=0;k<9;k++)
	    {
	     if(move[k][0]==b[i][0] && move[k][1]==b[i][1])
	       {
		cout<<"re-enter the position";
		goto reenter;
		}
	    }
       chance+=2;
       move[chance][0]=a[j][0];
       move[chance][1]=a[j][1];
       move[chance][2]=a[j][2];
       ok2=1;
	}
     }

     if(ok2!=1)
       {cout<<"re-enter the position";
       goto reenter;
       }

   int flag5=0;
   if(i==0)
     {
	gotoxy(6,29);
	cout<<"THINKING........";
	 delay(1000);
     reload:
     ran=random(3);
     delay(10);
     ran1=random(3);
      for(p=0;p<9;p++)
	 { flag5=0;
	   if(move[p][0]==ran && move[p][1]==ran1)
	     {flag5=1;
	      goto reload;
	     }
	 }
       if(flag5==0)
	 {
	  move[0][0]=ran;
	  move[0][1]=ran1;
	  c[0][0]=move[0][0];
	  c[0][1]=move[0][1];
	  c[(chance-1)/2][3]=((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
	 }
     }

   if(i!=0 && i!=4)
      {
	gotoxy(6,29);
	cout<<"THINKING........";
	 delay(1000);
      compwinmove();
      }
      graphmove();

     if( winner()==2)
	 {
	  cout<<"P1 Wins";
	  delay(200);
	  plwin();
	  goto finish;
	    }

     if ( winner()==1)
	{
	 cout<<"Computer Wins";
	 delay(200);
	 compwin();
	 goto finish;
	 }

      else if(winner()==0 && i==4)
	   {
	   cout<<"Draw";
	   delay(200);
	   draw();
	   goto finish;
	   }

   }
    finish:
    ;
}

int winner()
 { int i,j;
   for(i=0;i<10;i++)
      {
      ginti[0][i]=0;
      ginti[1][i]=0;
      }

   for(i=0;i<9;i++)
      {
	if(b[i][0]==b[i][1] && b[i][0]<4 && b[i][1]<4)
	   {ginti[0][0]++;}
	if(b[i][0]==0)
	  {ginti[0][1]++;}
	if(b[i][0]==1)
	  {ginti[0][2]++;}
	if(b[i][0]==2)
	   {ginti[0][3]++;}
	if((b[i][0]+b[i][1])==2)
	   {ginti[0][4]++;}
	if(b[i][1]==0)
	  {ginti[0][5]++;}
	if(b[i][1]==1)
	  {ginti[0][6]++;}
	if(b[i][1]==2)
	   {ginti[0][7]++;}
      }
   for(j=0;j<8;j++)
       {
	 if(ginti[0][j]==3)
	 return 2;
       }
    for(i=0;i<9;i++)
      {
	if(c[i][0]==c[i][1] && c[i][0]<4 && c[i][1]<4)
	   {ginti[1][0]++;}
	if(c[i][0]==0)
	  {ginti[1][1]++;}
	if(c[i][0]==1)
	  {ginti[1][2]++;}
	if(c[i][0]==2)
	   {ginti[1][3]++;}
	if((c[i][0]+c[i][1])==2)
	   {ginti[1][4]++;}
	if(c[i][1]==0)
	  {ginti[1][5]++;}
	if(c[i][1]==1)
	  {ginti[1][6]++;}
	if(c[i][1]==2)
	   {ginti[1][7]++;}
      }
      for(j=0;j<8;j++)
       {
	 if(ginti[1][j]==3)
	 return 1;
       }
   return 0;
}

void compwin()
   { cleardevice();
      setcolor(YELLOW);
      settextstyle(3, HORIZ_DIR, 6);
     outtextxy(200,200,"Computer Wins");
     comp++;
     getch();
    }

void plwin()
   { cleardevice();
    setcolor(YELLOW);
      settextstyle(3, HORIZ_DIR, 6);
     outtextxy(200,200,"Player Wins");
     pl++;
     getch();
    }

void draw()
   { cleardevice();
      setcolor(YELLOW);
      settextstyle(3, HORIZ_DIR, 6);
     outtextxy(200,200,"Draw");
     dr++;
     getch();
     }

void graphmove()
{
 int j=0,k=0,z=0,y=0,x1=0;
  no=0;no1=0;
   while(b[no1][0]!=10)
	{
	for(y=0;y<9;y++)
	   {
	   beta=char((65+(3*b[no1][0]))+b[no1][1]) ;
	   if(alpha[y][0]==beta)
	     {strcpy(alpha[y],"X");
	      break;
	     }
	   }
	no1++;
	}
   while (c[no][0]!=10)
      {
       for(y=0;y<9;y++)
	  {
	  beta=char((65+(3*c[no][0]))+c[no][1]);
	   if(alpha[y][0]==beta)
	     { strcpy(alpha[y],"O");
	       break;
	     }

	}
	no++;
       }

   cleardevice();
   setfillstyle(9,15);

      /* draw the bar */
      bar( 250,80,260,380);
	bar( 350,80,360,380);
	  bar( 160,180,440,190);
	    bar( 160,280,440,290);

   /* select the text style */
   settextstyle(0, HORIZ_DIR,4);
    x1=0;

   for(j=0;j<3;j++)
      {
       for(k=0;k<3;k++)
	  { setcolor(WHITE);
	    if(strcmp(alpha[x1],"X")==0)
	      {setcolor(BLUE);}
	      if(strcmp(alpha[x1],"O")==0)
		{setcolor(GREEN);}

   outtextxy(180+(110*k) ,110+(110*j) ,alpha[x1]);
    x1++;
	  }
      }
   z++;

   settextstyle(0, HORIZ_DIR,2);
   setcolor(YELLOW);
   outtextxy(40,20,"Player");
   outtextxy(220,20,"Computer");
   outtextxy(450,20,"Draw");
   gotoxy(10,4);
   cout<<pl;
   gotoxy(35,4);
   cout<<comp;
   gotoxy(60,4);
   cout<<dr;
}


void compwinmove()
{
   int invalid=0,i=0,z=0,j=0,k=0,m=0,l=0,x=0,x1=0,x2=0,x3=0,ok=0,go=0;
   int flag=0,flag2=0;
   int tmp[6];
   int tmp2[6];
   int tmp3[6];
   int temp[6];
   int tmp4[6];
    for(i=0;i<10;i++)
       {tmp[i]=10;
	tmp2[i]=10;
	tmp3[i]=10;
	temp[i]=10;
	tmp4[i]=10;
       }

   //MAJOR DIAGONAL
   x2=0;
 for(z=0;z<=9;z+=4)
   {
     for(k=0;k<9;k++)
	{
	 if(c[k][3] == z)
	   {
	    temp[x2]=(z);
	    x2++;
	   }
	}
     }

    if(x2==2)
      {
	for(l=0;l<9;l+=4)
	    {flag=0;
	     for(m=0;m<3;m++)
		{if(temp[m]==l)
		    {flag=1;
		    }
		     }
	       if(flag!=1)
		{
		y[0]=(l/4);
		y[1]=(l/4);
		}

		}
	     for(i=0;i<9;i++)
		{
		 if(move[i][0]==y[0] && move[i][1] == y[1])
		 {invalid =1;
		   break;
		}
	     }
	     if(invalid!=1)
	     {
	     move[chance-1][0]=y[0];
	     move[chance-1][1]=y[1];
	     c[(chance-1)/2][0]=y[0];
	     c[(chance-1)/2][1]=y[1];
	     c[(chance-1)/2][3]=((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
	      go=1;
	      ok=1;
	     }

 }

 //MINOR DIAGONAL
 if(go!=1)
   {x3=0;
    for(j=0;j<9;j++)
       {
	if((c[j][0]+c[j][1])== 2  && (c[j][0]+c[j][1])<=4)
	  {tmp4[x3]=c[j][3];
	   x3++; }
       }

      if(x3==2)
	{
	for(l=2;l<7;l+=2)
	    {flag2=0;
	     for(m=0;m<3;m++)
		{if(tmp4[m]==l)
		    {flag2=1;
		    }
		     }
	       if(flag2!=1)
		{ if(l==2)
		{y[0]=0;
		y[1]=2;}

		 if(l==4)
		{y[0]=1;
		y[1]=1;}

		 if(l==6)
		{y[0]=2;
		y[1]=0;}

		}

		}
	     for(i=0;i<9;i++)
		{
		 if(move[i][0]==y[0] && move[i][1] == y[1])
		   {invalid =11;
		    break;
		    }
		 }
	     if(invalid!=11)
	       {
		move[chance-1][0]=y[0];
		move[chance-1][1]=y[1];
		c[(chance-1)/2][0]=y[0];
		c[(chance-1)/2][1]=y[1];
		c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
		go=2;
		ok=1;
	     }

      }
}

//row
if(go!=2 && go!=1)
{
for(j=0;j<3;j++)
   {x=0;

     for(k=0;k<9;k++)
       {
       if(c[k][0]==j)
	{
	 tmp[x]=c[k][3];
	  x++;}

	}

      if(x==2)
      {
	y[0]=j ;

	for(l=0;l<3;l++)
	    {
	     flag=0;
	     for(m=0;m<5;m++)
		{if(tmp[m]==((j*3)+l))
		    {flag=1;
		     }
		     }
		 if(flag!=1)
		   {y[1]=l;
		   break;}
		   }


	     for(i=0;i<9;i++)
		{
		 if(move[i][0]==y[0] && move[i][1] == y[1])
		   { invalid=2;
		     break;
		   }
		 }
	     if(invalid!=2)
	       {
		move[chance-1][0]=y[0];
		move[chance-1][1]=y[1];
		c[(chance-1)/2][0]=y[0];
		c[(chance-1)/2][1]=y[1];
		c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
	     go=3;
	     ok=1;
	       }
       }
   }
}

   //COLUMN
   if(go!=1 && go!=2 && go!=3)
     {
      for(j=0;j<3;j++)
	 {x1=0;
	  for(k=0;k<9;k++)
	     {
	      if(c[k][1]==j)
		{
		 tmp2[x1]=c[k][3];
		 x1++;}
	     }
    if(x1==2)
      {
	y[1]=j ;

	for(l=0;l<3;l++)
	    { flag=0;
	     for(m=0;m<5;m++)
		{if(tmp2[m]==j+(l*3))
		    {flag=1;
		    }
		     }
	       if(flag!=1)
		 {y[0]=l;
		 }
		}

	  for(i=0;i<9;i++)
	     {
	     if(move[i][0]==y[0] && move[i][1] == y[1])
	       {invalid =3;
		break;
		}
	     }
	     if(invalid!=3)
		{
		 move[chance-1][0]=y[0];
		 move[chance-1][1]=y[1];
		 c[(chance-1)/2][0]=y[0];
		 c[(chance-1)/2][1]=y[1];
		 c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
		 ok=1;}
		}
       }
 }
 if(ok!=1)
   {
    check();
    goto endattack;
   }
 endattack:
 }

//End of Lead

void check()
 { void plawinprot();
   int invalid=0,i=0,z=0,j=0,k=0,m=0,l=0,x=0,x1=0,x2=0,x3=0,ok=0,go=0;
   int flag=0,flag2=0;
   int tmp[6];
   int tmp2[6];
   int tmp3[6];
   int temp[6];
   int tmp4[6];
   for(i=0;i<10;i++)
      {
      tmp[i]=10;
      tmp2[i]=10;
      tmp3[i]=10;
      temp[i]=10;
      tmp4[i]=10;
     }

   //MAJOR DIAGONAL
   x2=0;
 for(z=0;z<=9;z+=4)
   {

     for(k=0;k<9;k++)
       {
       if(b[k][3] == z)
	 {
	 temp[x2]=(z);
	 x2++;
	  }
	}
	}

    if(x2==2)
      {
	for(l=0;l<=9;l+=4)
	    {
	     flag=0;
	     for(m=0;m<3;m++)
		{
		 if(temp[m]==l)
		    {
		    flag=1;
		    }
		     }
	       if(flag!=1)
		{
		y[0]=(l/4);
		y[1]=(l/4);
		}

		}
	     for(i=0;i<9;i++)
	     {
	     if(move[i][0]==y[0] && move[i][1] == y[1])
	       {
		invalid =1;
		break;
		}
	     }
	     if(invalid!=1)
	       {
	       move[chance-1][0]=y[0];
	       move[chance-1][1]=y[1];
	       c[(chance-1)/2][0]=y[0];
	       c[(chance-1)/2][1]=y[1];
	       c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
	       go=1;
	       ok=1;
	       }
      }

 //MINOR DIAGONAL
 if(go!=1)
   {x3=0;
    for(j=0;j<9;j++)
       {
	  if((b[j][0]+b[j][1]) == 2  && (b[j][0]+b[j][1])<=4)
		{
		tmp4[x3]=b[j][3];
		 x3++; }
       }

      if(x3==2)
	{
	 for(l=2;l<7;l+=2)
	    {
	     flag2=0;
	     for(m=0;m<3;m++)
		{
		 if(tmp4[m]==l)
		    {
		    flag2=1;
		    }
		     }
	       if(flag2!=1)
		{
		 if(l==2)
		{y[0]=0;
		y[1]=2;}

		 if(l==4)
		{y[0]=1;
		y[1]=1;}

		 if(l==6)
		{y[0]=2;
		y[1]=0;
		}

		}

		}
	     for(i=0;i<9;i++)
		{
		 if(move[i][0]==y[0] && move[i][1] == y[1])
		   {invalid =11;
		   break;
		 }
	     }
	     if(invalid!=11)
		{
		 move[chance-1][0]=y[0];
		 move[chance-1][1]=y[1];
		 c[(chance-1)/2][0]=y[0];
		 c[(chance-1)/2][1]=y[1];
		 c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
		 go=2;
		 ok=1;
		 }

       }
}

//row
if(go!=2 && go!=1)
  {
    for(j=0;j<3;j++)
       {x=0;
	for(k=0;k<9;k++)
	   {
	    if(b[k][0]==j)
		{
		 tmp[x]=b[k][3];
		 x++;}
	   }

      if(x==2)
      {
	y[0]=j ;

	for(l=0;l<3;l++)
	    {
	    flag=0;
	     for(m=0;m<3;m++)
		{
		 if(tmp[m]==(j*3)+l)
		    {flag=1;
		    }
		     }
	       if(flag!=1)
		{y[1]=l;
	       }
		}

	     for(i=0;i<9;i++)
		{
		  if(move[i][0]==y[0] && move[i][1] == y[1])
		     { invalid=2;
			break;
			}
		}
	     if(invalid!=2)
		{
		 move[chance-1][0]=y[0];
		 move[chance-1][1]=y[1];
		 c[(chance-1)/2][0]=y[0];
		 c[(chance-1)/2][1]=y[1];
		 c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
		 go=3;
		 ok=1;
	     }

       }
   }
}
   //COLUMN
   if(go!=1 && go!=2 && go!=3)
 {
 for(j=0;j<3;j++)
   {x1=0;
     for(k=0;k<9;k++)
       {
       if(b[k][1]==j)
	{
	 tmp2[x1]=b[k][3];
	  x1++;
	 }
       }
    if(x1==2)
      {
	y[1]=j ;

	for(l=0;l<3;l++)
	    { flag=0;
	     for(m=0;m<4;m++)
		{if(tmp2[m]==j+(l*3))
		    {flag=1;
		    }
		     }
	       if(flag!=1)
		{y[0]=l;
		}
		}

	  for(i=0;i<9;i++)
	     {
	     if(move[i][0]==y[0] && move[i][1] == y[1])
	     {invalid =3;

	     break;
		}
	     }
	     if(invalid!=3)
	     {
	     move[chance-1][0]=y[0];
	     move[chance-1][1]=y[1];
	     c[(chance-1)/2][0]=y[0];
	     c[(chance-1)/2][1]=y[1];
	     c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
	     ok=1;}
	     }
   }
 }
 if(ok!=1)
 {
 plawinprot();
 goto endattack1;
 }
 else
 {

 }
 endattack1:
 }

//Computer move

 void plawinprot()
 {
 int go1=0,ran=0,i=0,j=0,flag=0,xc=0,l=0,yc=0,z=0,countc=0,countr=0,countd=0;
  int countr1=0,countr2=0,countc1=0,countc2=0,countd1=0,countd2=0,countm=0,countm1=0,countm2=0;
  int dtmp[6],etmp[6],ftmp[6],gtmp[6];

  for(i=0;i<4;i++)
  {
   if(go1!=1 && go1!=2 && go1!=3 && go1!=4)
  {
  xc=c[i][0];
  yc=c[i][1];
  countc=0;
  countr=0;
  countc1=0;
  countc2=0;
  countr1=0;
  countr2=0;
  countd1=0;
  countd2=0;

   for(z=0;z<9;z++)
  {
  d[z][0]=10;
  d[z][1]=10;
  d[z][2]=10;
  e[z][0]=10;
  e[z][1]=10;
  e[z][2]=10;
  f[z][0]=10;
  f[z][1]=10;
  f[z][2]=10;
  g[z][0]=10;
  g[z][1]=10;
  g[z][2]=10;

  }

  for(z=0;z<6;z++)
      {dtmp[z]=11;
	etmp[z]=11;
	ftmp[z]=11;
	gtmp[z]=11;
      }

   //row
    for(j=0;j<9;j++)
       {
	if(move[j][0]==xc)
	  {
	   dtmp[countc]=move[j][1];
	   countc++;
	  }
       }

  if(countc==1)
    { for(countc1=0;countc1<3;countc1++)
	 { flag=0;
	    for(l=0;l<3;l++)
	       {
		if(countc1==dtmp[l])
		  {flag=1;
	       }

	  }
      if(flag!=1)
	{
	  d[countc2][1]=countc1;
	  d[countc2][0]=xc;
	  countc2++;
	  }
     }
  }
   //column
     for(j=0;j<9;j++)
	{
	if(move[j][1]==yc)
	  {
	  etmp[countr]=move[j][0];
	  countr++;
	  }
      }
  if(countr==1)
    {
      for(countr1=0;countr1<3;countr1++)
	 {
	 flag=0;
	 for(l=0;l<3;l++)
	    {
	    if(countr1==etmp[l])
		{flag=1;}

	    }
     if(flag!=1)
       {
	  e[countr2][1]=yc;
	  e[countr2][0]=countr1;
	  countr2++;
	  }

      }
     }
    //Diagonals

     for(j=0;j<9;j++)
	{
	  if(  xc==yc && move[j][1]==move[j][0] && move[j][1]<=3 && move[j][1]<=3 )
	    {
	    ftmp[countd]=move[j][1];
	    countd++;
	}
    }

  if(countd==1)
    { for(countd1=0;countd1<3;countd1++)
	 { flag=0;
	   for(l=0;l<3;l++)
	      {
		if(countd1==ftmp[l])
		  {flag=1;
		   }
	       }
     if(flag!=1)
       {
	  f[countd2][1]=countd1;
	  f[countd2][0]=countd1;
	  countd2++;
	  }
     }
  }
     //Minor Diagonals

     for(j=0;j<9;j++)
	{
	  if((xc+yc)==2 && (move[j][1] + move[j][0])==2 && move[j][1]<=5 && move[j][1]<=5 )
       {
	  gtmp[countm]=move[j][1];
	  countm++;
       }
    }

  if(countm==1)
     { for(countm1=0;countm1<3;countm1++)
	  { flag=0;
	    for(l=0;l<3;l++)
		{
		if(countm1==gtmp[l])
		  {flag=1;
		  }
		}
     if(flag!=1)
       {
	  g[countm2][1]=countm1;
	  g[countm2][0]=2-countm1;
	  countm2++;
	  }
     }
  }

  go1=10;

//Final move
//diagonal move
     if(countd==1)
       {ran = random(2);
	move[chance-1][0]=f[ran][0];
	move[chance-1][1]=f[ran][1];
	c[(chance-1)/2][0]=f[ran][0];
	c[(chance-1)/2][1]=f[ran][1];
	c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);

      go1=1;
     }

    //column  move

     if(countc==1 && go1!=1)
       {ran = random(2);
	move[chance-1][0]=d[ran][0];
	move[chance-1][1]=d[ran][1];
	c[(chance-1)/2][0]=d[ran][0];
	c[(chance-1)/2][1]=d[ran][1];
	c[(chance-1)/2][3]=((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);

      go1=2;
     }
     //row move
   if(countr==1 && go1!=1 && go1!=2)
     {
      ran = random(2);
      move[chance-1][0]=e[ran][0];
      move[chance-1][1]=e[ran][1];
      c[(chance-1)/2][0]=e[ran][0];
      c[(chance-1)/2][1]=e[ran][1];
      c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);

      go1=3;
   }

    if(countm==1 && go1!=1 && go1!=2 && go1!=3)
       {ran = random(2);
	move[chance-1][0]=g[ran][0];
	move[chance-1][1]=g[ran][1];
	c[(chance-1)/2][0]=g[ran][0];
	c[(chance-1)/2][1]=g[ran][1];
	c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);

      go1=4;

     }
  }
 }
   if(go1==10)
   {
     reload1:
     ran=random(3);
     delay(10);
     ran1=random(3);
     for(p=0;p<9;p++)
	{ flag5=0;
	  if(move[p][0]==ran && move[p][1]==ran1)
	     {flag5=1;
	      goto reload1;
	    }
	   }
   if(flag5==0)
     {
      move[chance-1][0]=ran;
      delay(10);
      move[chance-1][1]=ran1;
      c[(chance-1)/2][0]= move[chance-1][0];
      c[(chance-1)/2][1]= move[chance-1][1];
      c[(chance-1)/2][3]= ((3 * c[(chance-1)/2][0])+ c[(chance-1)/2][1]);
     }
   }

}
void instructions()
  {
  int i=0;
  gotoxy(10,10);
  setcolor(YELLOW);
    settextstyle(4, HORIZ_DIR,4);
    outtextxy(200,50,"INSTRUCTIONS");
     setcolor(WHITE);
     settextstyle(1, HORIZ_DIR,2);
    outtextxy(50,150,"1. Player always plays X \n Computer always plays O\n");
     settextstyle(1, HORIZ_DIR,2);
   outtextxy(50,250,"2. Player always plays first\n");
     settextstyle(1, HORIZ_DIR,2);
    outtextxy(50,350,"3. Only use capital letters throughout the game\n") ;
    delay(7000);
    cleardevice();
    setcolor(2);
    for(i=0;i<11;i++)
    { setcolor(i);
    settextstyle(0, HORIZ_DIR,5);
    outtextxy(100,200,"TURN ON CAPS");
    outtextxy(200,300,"LOCK") ;
    delay(500);
    cleardevice();
     }
    }

void loaddriver()
  {
    /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
      {
      cout<<"Graphics error: %s\n", grapherrormsg(errorcode);
      cout<<"Press any key to halt:";
      getch();
      exit(1);
      }
   }

void initialboard()
    { int x1=0,j,k;
      cleardevice();
       setfillstyle(9,15);

	for(i=0;i<9;i++)
	   { alpha[i][0]=char(65+i);
	    }

      /* draw the bar */
      bar( 250,80,260,380);
	bar( 350,80,360,380);
	  bar( 160,180,440,190);
	    bar( 160,280,440,290);

   settextstyle(0, HORIZ_DIR,2);
   setcolor(YELLOW);
   outtextxy(40,20,"Player");
   outtextxy(220,20,"Computer");
   outtextxy(450,20,"Draw");
   gotoxy(10,4);
   cout<<pl;
   gotoxy(35,4);
   cout<<comp;
   gotoxy(60,4);
   cout<<dr;
   settextstyle(0, HORIZ_DIR,4);
   setcolor(WHITE);
    x1=0;


   //Initial board
   for(j=0;j<3;j++)
   {
   for(k=0;k<3;k++)
   {
   outtextxy(180+(110*k) ,110+(110*j) ,alpha[x1]);
    x1++;
    }
   }

  }
