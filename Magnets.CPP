
/*   ***********
     * MAGNETS *
     ***********
		   */
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>
//#include <graphics>
#include <dos.h>
//#include <bios>


struct times
{ int hr;
  int min;
  int sec;
  } timer;

class hscore
  { public:
    int m;
    int n;
    int s1;
    int s2;
    int s3;
    char name_s1[20];
    char name_s2[20];
    char name_s3[20];

    void update(float);
    void output();

     }cscore,tempo;


char b[50][50]={"\0"};
int ttime=0,ttime1=0,ch1=0;
int s[50][50];
int calp[50][50], calm[50][50], play[50][50];
int flag=0,retrow=0,retcol=0,retpol=0,occ=0,err=0;
int rrow[15],rcol[15];

void loadgr();
void intro();
int mmenu();
void assign(int, int);
void initialize(int, int );
void sign(int, int);
void load(int &, int &);
void count(int, int);
void game(int, int);
void goleft(int &, int &);
void goright(int &, int &, int);
void goup(int &, int &);
void godown(int &, int &, int);
void move(int, int, int);
void check(int, int, int[][50]);
void error(int, int, int[][50]);
void draw(int, int, int);
void swrite(int, int, int);
void sdraw(int, int, int [][50], int);
void save(int, int, int ,int);
void endgame(int, int, int );
void instr();
void credits();
void main();
int highscore(int, int, int, int);
void highscore1(int, int, int, int);
void viewhscore();

void loadgr()
{ clrscr();
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax,i;
   long int j;

   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   errorcode = graphresult();

   if (errorcode != grOk)
   {
      cout<<"Graphics error: \n"<< grapherrormsg(errorcode);
      cout<<"Press any key to halt:";
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());

   int far getbkcolor(void);
    }


void hscore::update(float score)
{ int tmp=0,tmp1=0;
  char name[20],name1[20],tmpname[20];

  gotoxy (3, 5);
  cout<<" Enter your name: ";
  gets(tmpname);

  if (score>s1)
  { tmp=s1;
    strcpy(name,name_s1);
    strcpy(name_s1,tmpname);
    s1=score;
    tmp1=s2;
    strcpy(name1,name_s2);
    s2=tmp;
    strcpy(name_s2,name);
    s3=tmp1;
    strcpy(name_s3,name1); }

  else if (score>s2)
  { tmp=s2;
    strcpy(name,name_s2);
    strcpy(name_s2,tmpname);
    s2=score;

    s3=tmp;
    strcpy(name_s3,name); }

  else if(score>s3)
  { s3=score;
    strcpy(name_s3,tmpname); }
   }


void hscore::output()
{ cleardevice();

  int xmax = getmaxx();
  int ymax = getmaxy();
  char row[2]={"\0"},col[2]={"\0"};

  row[0]=m+48;
  col[0]=n+48;

  setfillstyle(9, GREEN);
  bar(0, 0, 15,ymax);
  bar(0, 0, xmax,15);
  bar(xmax, 0, xmax-15,ymax);
  bar(xmax, ymax, 0, ymax-15);

  setcolor (6);
  settextstyle (3, 0, 3);
  outtextxy (50, 50, "High Scores for  X  :");
  outtextxy (235, 50, row);
  outtextxy (267, 50, col);
  line (50, 77, 277, 77);

  setcolor (YELLOW);
  settextstyle (6, 0, 2);
  outtextxy (50, 120, "Name");
  outtextxy (200, 120, "Score");

  setcolor (WHITE);
  settextstyle (1, 0, 1);
  outtextxy (50, 170, name_s1);
  gotoxy (28, 12);
  cout<<s1;
  outtextxy (50, 220, name_s2);
  gotoxy (28, 15);
  cout<<s2;
  outtextxy (50, 270, name_s3);
  gotoxy (28, 18);
  cout<<s3;
   }


void intro()
{ cleardevice();
  int i=0,j=0,l=0;
  int xmax = getmaxx();
  int ymax = getmaxy();

  for (i=0,j=0;i<xmax/2,j<ymax/2;i+=5,j+=5)
  { cleardevice();
    settextstyle (8,0,8);

    setcolor (RED);
    for (l=0;l<5;l++)
    { outtextxy (i-120+l, ymax/2-100, "M"); }

    setcolor (WHITE);
    for (l=0;l<5;l++)
    { outtextxy (xmax/2-140+l, j-95, "A"); }

    setcolor (RED);
    for (l=0;l<5;l++)
    { outtextxy (xmax-2*i+65+l, ymax/2-100, "G"); }

    setcolor (WHITE);
    for (l=0;l<5;l++)
    { outtextxy (xmax/2-25+l, ymax-j-105, "N"); }

    setcolor (RED);
    for (l=0;l<5;l++)
    { outtextxy (xmax-i-45+l, ymax/2-100, "E"); }

    setcolor (WHITE);
    for (l=0;l<5;l++)
    { outtextxy (xmax/2+100+l, j-95, "T"); }

    setcolor (RED);
    for (l=0;l<5;l++)
    { outtextxy (2*i+10+l, ymax/2-100, "S"); }

    delay(20); }

  for (i=0;i<20;i++)
  { setfillstyle(9, 3);
    bar (0, 0, i,ymax);
    bar (0, 0, xmax,i);
    bar (xmax, 0, xmax-i,ymax);
    bar (xmax, ymax, 0, ymax-i);
    delay (20); }

  int poly[15];

  poly[0] = 480;
  poly[1] = 400;
  poly[2] = 550;
  poly[3] = 400;
  poly[4] = 550;
  poly[5] = 380;
  poly[6] = 590;
  poly[7] = 415;
  poly[8] = 550;
  poly[9] = 450;
  poly[10]= 550;
  poly[11]= 430;
  poly[12]= 480;
  poly[13]= 430;

  P:
  while (!kbhit())
  { setfillstyle(4, i);
    fillpoly(7, poly);
    delay(90);
    i++; }

  int key;
  key=bioskey(0);
  if (key!=19712)
  { goto P; }

   }


int mmenu()
{ cleardevice();
  int i=0,key=0;
  int xmax = getmaxx(),
      ymax = getmaxy();

  while (key!=7181)
  { cleardevice();
    setfillstyle(9, GREEN);
    bar(0, 0, 15,ymax);
    bar(0, 0, xmax,15);
    bar(xmax, 0, xmax-15,ymax);
    bar(xmax, ymax, 0, ymax-15);


    setcolor (RED);
    settextstyle (6,0,7);
    outtextxy (xmax/2-160, 40, "M  I    M  N ");
    outtextxy (xmax/2-162, 40, "M  I    M  N ");
    outtextxy (xmax/2-163, 40, "M  I    M  N ");
    outtextxy (xmax/2-164, 40, "M  I    M  N ");
    outtextxy (xmax/2-165, 40, "M  I    M  N ");
    setcolor (WHITE);
    outtextxy (xmax/2-160, 40, "  A N    E  U");
    outtextxy (xmax/2-162, 40, "  A N    E  U");
    outtextxy (xmax/2-163, 40, "  A N    E  U");
    outtextxy (xmax/2-164, 40, "  A N    E  U");
    outtextxy (xmax/2-165, 40, "  A N    E  U");

    setcolor (YELLOW);
    settextstyle (1, 0, 2);
    outtextxy (xmax/2-50, 160, "NEW GAME");
    outtextxy (xmax/2-53, 210, "LOAD GAME");
    outtextxy (xmax/2-67, 260, "INSTRUCTIONS");
    outtextxy (xmax/2-55, 310, "HIGH SCORE");
    outtextxy (xmax/2-38, 360, "CREDITS");
    outtextxy (xmax/2-18, 410, "EXIT");

    setcolor (WHITE);
    rectangle (xmax/2-120, 167+50*i, xmax/2-84, 183+50*i);
    line (xmax/2-102, 167+50*i, xmax/2-102, 183+50*i);
    setcolor (WHITE);
    setfillstyle (1,4);
    floodfill (xmax/2-110, 170+50*i, getmaxcolor());
    rectangle (xmax/2-112, 170+50*i, xmax/2-110, 180+50*i);
    rectangle (xmax/2-116, 174+50*i, xmax/2-106, 176+50*i);
    rectangle (xmax/2-98, 174+50*i, xmax/2-88, 176+50*i);

    key=bioskey(0);
    if (key==18432)
     i--;
    else if (key==20480)
     i++;

    if (i<0) i=5;
    else if (i>5) i=0; }

  return i;
   }


void assign(int m,int n)
{ B:
  char a[]={'L','T'};
  int i=0,j=0,l=0,flag=0;

  for (i=0;i<20;i++)
  { for (j=0;j<20;j++)
    { b[i][j]=0; } }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { if (int(b[i][j])==0)
      { l=random(2);
	b[i][j]=a[l];

	if (i==m-1) b[i][j]='L';
	if (j==n-1) b[i][j]='T';
	if (b[i][j+1]=='B') b[i][j]='T';

	if (b[i][j]=='L') b[i][j+1]='R';
	else if (b[i][j]=='T') b[i+1][j]='B';

	if (i==m-1 && b[i][j-1]=='R' && b[i][j+1]=='B')
	{ flag=1;
	  break; }
	else if (i==m-1 && b[i][j-1]=='B' && b[i][j+1]=='B')
	{ flag=1;
	  break; } } }
	  if (flag==1) break; }

  for (i=0;i<n;i++)
  { if (b[m-1][i]=='T')
    { flag=1;
      break; } }

  if (flag==1)
  { goto B; }

   }


void initialize(int m, int n)
{ for (int i=0;i<m;i++)
  { for (int j=0;j<n;j++)
   { play[i][j]=8; } } }


void sign(int m,int n)
{ int i,j,k=0,ran=0;
  ran=random(4)+(-2);
  if (ran==2) ran=1;
  if (ran==-2) ran=-1;
  s[0][0]=ran;

  if(b[0][0]=='T')
  { s[1][0]=(ran*(-1));
    k=1; }

  else if(b[0][0]=='L')
  { s[0][1]=ran*(-1);
    k=2; }

  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
    { if(i==0 && j==0)
      { j=k; }

      if(b[i][j]=='L' || b[i][j]=='T')
      { again:
	int count = -1;
	ran=random(4)+(-2);
	if (ran==2) ran=1;
	if (ran==-2) ran=-1;
	repeat:

	if((s[i-1][j])*ran==1 || (s[i+1][j])*ran==1 || (s[i][j-1])*ran==1 || (s[i][j+1])*ran==1 )
	{ ran=ran*(count) ;
	  count ++;
	  goto repeat; }

	else
	{ if(b[i][j]=='T')
	  { if((s[i+2][j])*(ran*(-1))==1 || (s[i+1][j-1])*(ran*(-1))==1 || (s[i+1][j+1])*(ran*(-1))==1 )
	    { goto again; }
	    else
	    { s[i][j]=ran;
	      s[i+1][j]=(ran*(-1)); } }
	  else if(b[i][j]=='L')
	  { if((s[i-1][j+1])*(ran*(-1))==1 || (s[i+1][j+1])*(ran*(-1))==1 || (s[i][j+2])*(ran*(-1))==1 )
	    { goto again; }
	    else
	    { s[i][j]=ran;
	      s[i][j+1]=ran*(-1); } } } }/*bigger if*/ }/*j*/ }//i
   }


void load (int &m, int &n)
{ cleardevice();
  char name[50],ret[200]={'\0'};
  int i=0,j=0,l=2,var=0,ch[5];
  int xmax = getmaxx(),
      ymax = getmaxy();


  setfillstyle(9, GREEN);
  bar(0, 0, 15,ymax);
  bar(0, 0, xmax,15);
  bar(xmax, 0, xmax-15,ymax);
  bar(xmax, ymax, 0, ymax-15);

  gotoxy (4,3);
  cout<<" Enter the name: ";
  cin>>name;
  fstream f1;
  f1.open (name,ios::in);

  if(f1.fail())
  { gotoxy (3,6);
    cout<<"   FILE NOT FOUND!";
    getch();
    main(); }

  while (!f1.eof())
  { f1.get(ret[i]);
    i++; }

  m=ret[0]-48;
  n=ret[1]-48;

  i=0;
  while (ret[l]!=' ')
  { ch[i]=ret[l]-48;
    l++;
    i++; }

  l++;
  for (i;i>=0;i--)
  { ch1=var*10+ch[i]; }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { b[i][j]=ret[l];
      l++; } }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { s[i][j]=ret[l]-48;
      if (s[i][j]==2) s[i][j]=s[i][j]/(-2);
      l++; } }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { play[i][j]=ret[l]-48;
      if (play[i][j]==2) play[i][j]=play[i][j]/(-2);
      l++; } }

  j=l;
  while (l<strlen(ret)-2)
  { l++; }
  for (i=l;i>=j;i--)
  { ttime1=10*var+(ret[i]-48);
    var++; }

   }


void count(int m, int n)
{ int i=0,tmp=0,tmp1=0,j=0;

  //calp[0]= sum of all vertical lines
  //calp[1]=sum of all horizontal line and same for calm

  for (i=0;i<=n;i++)
  { tmp=0;
    tmp1=0;
    for(j=0;j<=m;j++)
    { if (s[j][i]>0)
      { tmp=tmp+s[j][i];}
      else if (s[j][i]<0)
	{ tmp1=tmp1+s[j][i]; } }

    calp[0][i]=tmp;
    calm[0][i]=tmp1; }

  for (i=0;i<=m;i++)
  { tmp=0;
    tmp1=0;
    for (j=0;j<=n;j++)
    { if (s[i][j]>0)
      { tmp=tmp+s[i][j]; }
      if (s[i][j]<0)
      { tmp1=tmp1+s[i][j]; } }

    calp[1][i]=tmp;
    calm[1][i]=tmp1; }
   }


void game(int m, int n)
{ cleardevice();                               // space: 14624
  int x=0,y=0,i,j,flag=0,
      t1=0,t2=0,t3=0,t4=0,ttime2=0;            // left: 19200
  int choice=0,key,ch=0;                       // right: 19712
  int xmax = getmaxx(),                        // up: 18432
      ymax = getmaxy();                        // down: 20480
					       // enter: 7181
  time_t t;
  char z;

  t1=time(&t);

  t1-=ttime1;
  while (flag==0)
  { setcolor (WHITE);

    cleardevice();
    setfillstyle(9, 3);
    bar(0, 0, 15,ymax);
    bar(0, 0, xmax,15);
    bar(xmax, 0, xmax-15,ymax);
    bar(xmax, ymax, 0, ymax-15);


    draw(m,n,100);
    swrite(m,n,100);
    sdraw(m,n,play,100);

    setcolor (YELLOW);
    if (b[x][y]=='L')
     rectangle (250+20*y-9, 150+20*x-9, 250+20*y+29, 150+20*x+9);
    else if (b[x][y]=='T')
     rectangle (250+20*y-9, 150+20*x-9, 250+20*y+9, 150+20*x+29);
    else if (b[x][y]=='R')
     rectangle (250+20*y-29, 150+20*x-9, 250+20*y+9, 150+20*x+9);
    else if (b[x][y]=='B')
     rectangle (250+20*y-9, 150+20*x-29, 250+20*y+9, 150+20*x+9);

    P:
   while (!kbhit())
   { t2=time(&t)-ttime2;
     ttime=(t2-t1);

     timer.hr=(ttime/3600);
     timer.min=(ttime%3600)/60;
     timer.sec=((ttime%3600)%60);
     gotoxy (65, 3);
     cout<<"Timer  "<<timer.hr<<":"<<timer.min<<":"<<timer.sec; }

   setcolor (WHITE);

   key=bioskey(0);

   if (key==19200)
    goleft(x,y);
   else if (key==19712)
    goright(x,y,n);
   else if (key==18432)
    goup(x,y);
   else if (key==20480)
    godown(x,y,m);

   else if(key==14624)  //spacebar
   { choice=0;
     ch++;
     move(x,y,choice); }

   else if(key==7181)  //Enter
   { choice=1;
     ch++;
     move(x,y,choice); }

   else if(key==21248) //delete
   { choice=2;
     move(x,y,choice); }

   else if (key==8051) //save
   { t3=time(&t);
     gotoxy (3,25);
     cout<<" Do you want to save the game?(y/n)";
     cin>>z;
     if (z=='y')
     { save(m,n,ttime,ch);
	t4=time(&t);
	ttime2=ttime2+(t4-t3); }

      else if (z=='n')
      { t4=time(&t);
	ttime2=ttime2+(t4-t3);
	goto P; } }

   else if (key==4209)  //exit
   {t3=time(&t);
    gotoxy (3,25);
     cout<<" Do you want to quit the game?(y/n)";
     cin>>z;
     if (z=='y')
     { cleardevice();

       setfillstyle (9, 3);
       bar (0, 0, 15,ymax);
       bar (0, 0, xmax,15);
       bar (xmax, 0, xmax-15,ymax);
       bar (xmax, ymax, 0, ymax-15);

       draw(m,n,-20);
       sdraw(m,n,play,-20);
       swrite(m,n,-20);
       settextstyle (3, 0, 1);
       outtextxy ((n*20)+230, 70, "SOLUTION:");
       draw(m,n,(n*20)+100);
       sdraw (m,n,s,(n*20)+100);
       swrite(m,n,(n*20)+100);
       break; }
     else if(z=='n')
	{
	t4=time(&t);
	ttime2=ttime2+(t4-t3);
	goto P; }
	}

   else if (key==283)
   { t3=time(&t);
     gotoxy (3,25);
     cout<<" Do you want to leave the game?(y/n)";
     cin>>z;
     if (z=='y')
      main();

     else if (z=='n')
      {	t4=time(&t);
	ttime2=ttime2+(t4-t3);
       goto P; } }

   else
    goto P;

  int flag1=0;
  for (i=0;i<m ;i++)
  { for (j=0;j<n;j++)
    { if (play[i][j]==8)
      { flag1=1;
	break; } }
    if (flag1==1) break; }

  cleardevice();
  draw(m,n,100);
  swrite(m,n,100);
  sdraw(m,n,play,100);

  if (flag1==0 && err==0)
  { flag=2;

    setfillstyle(9, 3);
    bar(0, 0, 15,ymax);
    bar(0, 0, xmax,15);
    bar(xmax, 0, xmax-15,ymax);
    bar(xmax, ymax, 0, ymax-15);

    settextstyle (3, 0, 1);
    outtextxy (20, 350, " Please Wait....");
    delay (800);
    endgame(ch,m,n);
    getch(); }

   setcolor (WHITE); }

  }


void goleft(int &x, int &y)
{ if (y>0)
  { if (b[x][y]=='T'|| b[x][y]=='B'|| b[x][y]=='L')
    { y--; }
    else if(b[x][y]=='R' && (y-1)!=0)
    { y-=2; } }
   }


void goright(int &x, int &y, int n)
{ if (y<n-1)
  { if (b[x][y]=='T'|| b[x][y]=='B'|| b[x][y]=='R')
    { y++; }
    else if(b[x][y]=='L'&& (y+2)!=n)
    { y+=2; } }
   }


void goup(int &x, int &y)
{ if (x>0)
  { if (b[x][y]=='T'|| b[x][y]=='R'|| b[x][y]=='L')
     x--;
    else if(b[x][y]=='B' && (x-1)!=0)
     x-=2; }
   }


void godown(int &x, int &y, int m)
{ if (x<m-1)
  { if (b[x][y]=='B'|| b[x][y]=='R'|| b[x][y]=='L')
     x++;
    else if(b[x][y]=='T' && (x+2)!=m)
     x+=2; }
   }


void move (int x, int y, int a)
{  //For blank space
  if(a==0 || a==2)
  { play[x][y]=(a*4);
    if(b[x][y]=='L')
    { play[x][y+1]=(a*4); }
    else if(b[x][y]=='R')
    { play[x][y-1]=(a*4); }
    else if(b[x][y]=='T')
    { play[x+1][y]=(a*4); }
    else if(b[x][y]=='B')
    { play[x-1][y]=(a*4); } }

  else if(a==1 && (play[x][y]==1 || play[x][y]==(-1)))
  { play[x][y]=(play[x][y]*(-1));
    if(b[x][y]=='L')
    { play[x][y+1]=(play[x][y]*(-1)); }
    else if(b[x][y]=='R')
    { play[x][y-1]=(play[x][y]*(-1)); }
    else if(b[x][y]=='T')
    { play[x+1][y]=(play[x][y]*(-1)); }
    else if(b[x][y]=='B')
    { play[x-1][y]=(play[x][y]*(-1)); } }

  else if(a==1)
  { play[x][y]=1;
    if(b[x][y]=='L')
    { play[x][y+1]=(-1); }
    else if(b[x][y]=='R')
    { play[x][y-1]=(-1); }
    else if(b[x][y]=='T')
    { play[x+1][y]=(-1); }
    else if(b[x][y]=='B')
    { play[x-1][y]=(-1); } }
   }


void check(int m, int n, int play[][50])
{ int tmp=0,tmp1=0,i=0,j=0,count=0;
  retcol=0,retrow=0,retpol=0,occ=0;

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { if (play[i][j]==1 || play[i][j]==(-1))
      { if (play[i][j]==play[i][j-1] || play[i][j]==play[i][j+1] || play[i][j]==play[i-1][j] || play[i][j]==play[i+1][j])
	{ retpol=1 ; } } } }

  for(i=0;i<15;i++)
  { rrow[i]=10;
    rcol[j]=10; }


 //counting no of column errors
  count=0;
  for (i=0;i<=n;i++)
  { tmp=0;
    tmp1=0;
    occ=0;
    for (j=0;j<=m;j++)
    { if (play[j][i]==1)
      { tmp=tmp+play[j][i];
	occ++; }
      else if (play[j][i]==(-1))
      { tmp1=tmp1+play[j][i];
	occ++; }
      else if (play[j][i]==0)
      { occ++; }  }

    if (tmp>calp[0][i])
    { rcol[count]=i;
      retcol++;
      count++;  }

    else if (tmp1<calm[0][i])
    { rcol[count]=i;
      retcol++;
      count++; }

    else if (occ==(m+1) && (tmp!=calp[0][i] || tmp1!=calm[0][i]))
    { rcol[count]=i;
      retcol++;
      count++; }  }

   // counting no of row errors
  count=0;
  occ=0;
  for (i=0;i<=m;i++)
  { tmp=0;
    tmp1=0;
    occ=0;
    for (j=0;j<=n;j++)
    { if (play[i][j]==1)
      { tmp=tmp+play[i][j];
	occ++; }

      else if (play[i][j]==(-1))
      { tmp1=tmp1+play[i][j];
	occ++; }

      else if (play[i][j]==0)
      { occ++; }  }

  if (tmp>calp[1][i])
  { rrow[count]=i;
    retrow++;
    count++; }

  else if(tmp1<calm[1][i])
  { rrow[count]=i;
    retrow++;
    count++; }

  else if(occ==(n+1) && (tmp!=calp[1][i] || tmp1!=calm[1][i]))
  { rrow[count]=i;
    retrow++;
    count++; } }

   }


void error(int m,int n,int play[][50])
{ int i=0;

  check(m,n,play);

  if (retpol!=0||retcol!=0||retrow!=0)
  { err=1;
    setfillstyle (1, RED);
    circle (250, 50, 15);
    floodfill (250, 50, getmaxcolor()); }

  else
  { err=0;
    setfillstyle (1,GREEN);
    circle (290, 50, 15);
    floodfill (290, 50, getmaxcolor()); }


  if(retcol!=0)
  { for(i=0;i<retcol;i++)
    { int p[10];
      setcolor (WHITE);
      p[0]=(rcol[i]*20)+245;
      p[1]=100;
      p[2]=(rcol[i]*20)+257;
      p[3]=100;
      p[4]=(rcol[i]*20)+251;
      p[5]=110;
      p[6]=(rcol[i]*20)+245;
      p[7]=100;
      setfillstyle (1, YELLOW);
      fillpoly (4, p); } }

     //retcol: no of column errors
     //rrow: array of positions
     //retrow: similar for rows

  if(retrow!=0)
  { for(i=0;i<retrow;i++)
    { int p2[10];
      p2[0]=200;
      p2[1]=(rrow[i]*20)+145;
      p2[2]=200;
      p2[3]=(rrow[i]*20)+156;
      p2[4]=210;
      p2[5]=(rrow[i]*20)+151;
      p2[6]=200;
      p2[7]=(rrow[i]*20)+145;
      setfillstyle (1, YELLOW);
      fillpoly (4, p2); } }

   }


void draw(int m,int n,int corr)
{ setcolor (WHITE);
  int i=0,j=0;
  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { if (b[i][j]=='L')
      { line (150+20*j-8+corr, 150+20*i-8, 150+20*j-8+corr, 150+20*i+8);
	line (150+20*j-8+corr, 150+20*i-8, 150+20*j+10+corr, 150+20*i-8);
	line (150+20*j-8+corr, 150+20*i+8, 150+20*j+10+corr, 150+20*i+8); }

      else if (b[i][j]=='R')
      { line (150+20*j+8+corr, 150+20*i+8, 150+20*j+8+corr, 150+20*i-8);
	line (150+20*j-10+corr, 150+20*i-8, 150+20*j+8+corr, 150+20*i-8);
	line (150+20*j-10+corr, 150+20*i+8, 150+20*j+8+corr, 150+20*i+8); }

      else if (b[i][j]=='T')
      { line (150+20*j-8+corr, 150+20*i-8, 150+20*j+8+corr, 150+20*i-8);
	line (150+20*j-8+corr, 150+20*i-8, 150+20*j-8+corr, 150+20*i+10);
	line (150+20*j+8+corr, 150+20*i-8, 150+20*j+8+corr, 150+20*i+10); }

      else if (b[i][j]=='B')
      { line (150+20*j+8+corr, 150+20*i+8, 150+20*j-8+corr, 150+20*i+8);
	line (150+20*j-8+corr, 150+20*i-10, 150+20*j-8+corr, 150+20*i+8);
	line (150+20*j+8+corr, 150+20*i-10, 150+20*j+8+corr, 150+20*i+8); } } }

   }


void swrite(int m, int n,int corr)
{ int i=0;
  char ph[50][2],pv[50][2],nh[50][2],nv[50][2];
  char t[5]={'\0'};

  setcolor (WHITE);
  settextstyle (1, 0, 1);
  outtextxy (120+corr, 115, "+");

  for (i=0;i<n;i++)
  { t[0]=calp[0][i]+48;
    strcpy(ph[i],t); }            //horizonal +

  for (i=0;i<n;i++)
  { setcolor (WHITE);
    settextstyle (10, 0,1 );
     setusercharsize(1, 3, 1, 3);
    outtextxy ((145+20*i)+corr, 115, ph[i]); }

  for (i=0;i<m;i++)
  { t[0]=calp[1][i]+48;
    strcpy(pv[i],t); }
				  // vertical +
  for (i=0;i<m;i++)
  { setcolor (WHITE);
    settextstyle (10, 0,1 );
     setusercharsize(1, 3, 1, 3);
    outtextxy (120+corr, 136+20*i, pv[i]); }

  settextstyle(1,0,1);
  outtextxy ((146+20*n)+corr, 140+20*m, "-");

  for (i=0;i<n;i++)
  { t[0]=(calm[0][i]*(-1))+48;
    strcpy(nh[i],t); }
				   // horizontal -
  for (i=0;i<n;i++)
  { setcolor (WHITE);
    settextstyle (10, 0,1 );
     setusercharsize(1, 3, 1, 3);
    outtextxy ((145+20*i)+corr, 140+20*m, nh[i]); }

  for (i=0;i<m;i++)
  { t[0]=(calm[1][i]*(-1))+48;
    strcpy(nv[i],t); }

  for (i=0;i<m;i++)                 // vertical -
  { setcolor (WHITE);
    settextstyle (10, 0,1 );
     setusercharsize(1, 3, 1, 3);
    outtextxy ((150+20*n)+corr, 136+20*i, nv[i]); }
   }


void sdraw(int m, int n, int dr[][50],int corr)
{ int i=0,j=0;

  setcolor (WHITE);
  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { setcolor (WHITE);
      if (dr[i][j]==0)
      { setfillstyle (1, 2);
	floodfill ((150+20*j)+corr, 150+20*i, getmaxcolor());
	circle ((150+20*j)+corr, 150+20*i, 5);
	circle ((150+20*j)+corr, 150+20*i, 4);
	circle ((150+20*j)+corr, 150+20*i, 3); }

      else if (dr[i][j]==1 && b[i][j]=='T')
      { setcolor (RED);
	line (150+20*j-7+corr, 150+20*i+10, 150+20*j+7+corr, 150+20*i+10);
	setcolor (WHITE);
	setfillstyle (1,4);
	floodfill (150+20*j+corr, 150+20*i, getmaxcolor());
	rectangle (150+20*j-1+corr, 150+20*i-4, 150+20*j+1+corr, 150+20*i+4);
	rectangle (150+20*j-4+corr, 150+20*i-1, 150+20*j+4+corr, 150+20*i+1); }

      else if (dr[i][j]==1 && b[i][j]=='L')
      { //setcolor (RED);
	line (150+20*j+10+corr, 150+20*i-8, 150+20*j+10+corr, 150+20*i+8);
	setcolor (WHITE);
	setfillstyle (1,4);
	floodfill (150+20*j+corr, 150+20*i, getmaxcolor());
	rectangle (150+20*j-1+corr, 150+20*i-4, 150+20*j+1+corr, 150+20*i+4);
	rectangle (150+20*j-4+corr, 150+20*i-1, 150+20*j+4+corr, 150+20*i+1); }

     else if (dr[i][j]==1 && b[i][j]=='B')
      { setcolor (RED);
	line (150+20*j-7+corr, 150+20*i-10, 150+20*j+7+corr, 150+20*i-10);
	setcolor (WHITE);
	setfillstyle (1,4);
	floodfill (150+20*j+corr, 150+20*i, getmaxcolor());
	rectangle (150+20*j-1+corr, 150+20*i-4, 150+20*j+1+corr, 150+20*i+4);
	rectangle (150+20*j-4+corr, 150+20*i-1, 150+20*j+4+corr, 150+20*i+1); }

     else if (dr[i][j]==1 && b[i][j]=='R')
      {
	line (150+20*j-10+corr, 150+20*i-8, 150+20*j-10+corr, 150+20*i+8);
	setcolor (WHITE);
	setfillstyle (1,4);
	floodfill (150+20*j+corr, 150+20*i, getmaxcolor());
	rectangle (150+20*j-1+corr, 150+20*i-4, 150+20*j+1+corr, 150+20*i+4);
	rectangle (150+20*j-4+corr, 150+20*i-1, 150+20*j+4+corr, 150+20*i+1); }

     else if (dr[i][j]==-1)
     { rectangle (150+20*j-4+corr, 150+20*i-1, 150+20*j+4+corr, 150+20*i+1); } } }

  if (corr==100)
  { error(m,n,dr); }
 }


void save(int m, int n, int t, int ch)
{ int i=0,j=0;
  char name[50];
  fstream f1;

  gotoxy (3, 26);
  cout<<" Enter the name of the file (.txt): ";
  cin>>name;

  f1.open (name,ios::out);
  f1<<m;
  f1<<n;

  f1<<ch;
  f1<<" ";

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { f1<<b[i][j]; } }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { if (s[i][j]==-1)
      { f1<<(s[i][j]*(-2)); }
      else
       f1<<s[i][j]; } }

  for (i=0;i<m;i++)
  { for (j=0;j<n;j++)
    { if (play[i][j]==-1)
      { f1<<play[i][j]*(-2); }
      else
       f1<<play[i][j]; } }

  f1<<t;
  f1.close();

  gotoxy (3, 29);
  cout<<" The game has been saved."
      <<" Press any key to continue.";
  getch();
   }


void endgame(int ch,int m ,int n)
{ cleardevice();
  int xmax = getmaxx(),
      ymax = getmaxy();

  setcolor (4);
  settextstyle (4, 0, 5);
  outtextxy (95, 50, "CONGRAGULATIONS!!");
  setcolor (5);
  settextstyle (5, 0, 4);
  outtextxy (150, 100, "You finished the game!");
  gotoxy (10, 18);
  cout<<"Number of chances: "<<ch;

  gotoxy (10, 20);
  cout<<"Time taken: "<<timer.hr<<" hours  "
      <<timer.min<<" minutes  "<<timer.sec<<" seconds ";

  setfillstyle(9, GREEN);
  bar(0, 0, 15,ymax);
  bar(0, 0, xmax,15);
  bar(xmax, 0, xmax-15,ymax);
  bar(xmax, ymax, 0, ymax-15);


  if (highscore(m,n,ch,ttime)==1)
  { setcolor(BLUE);
    settextstyle (1, 0, 3);
    outtextxy (220, 155, "Excellent !!!");
    outtextxy (200, 190, "New Highscore ");

    gotoxy(10,16);
    cout<<" Press any key to proceed.";
    getch();
    cleardevice();
    highscore1(m,n,ch,ttime);

    cscore.output();
    getch();
    main(); }


  else
  { gotoxy(10,16);
    cout<<"Your score: "<<10000/(ch*ttime);

    setcolor (15);
    settextstyle (15, 0, 1);
    outtextxy (50, 380, "Press m to return to menu.");
    outtextxy (50, 410, "Press q to exit.");

    int key;
    A:
    key=bioskey(0);
    if (key==12909)
    main();
    else if (key==4209)
    exit(0);
    else
    goto A; }
   }


void instr()
{ cleardevice();
  int xmax = getmaxx(),
      ymax = getmaxy();

  setcolor (RED);
  settextstyle (6, 0, 6);
  outtextxy (xmax/2-172, 25, "I  S  R  C  I  N");
  outtextxy (xmax/2-174, 25, "I  S  R  C  I  N");
  outtextxy (xmax/2-175, 25, "I  S  R  C  I  N");
  outtextxy (xmax/2-176, 25, "I  S  R  C  I  N");
  outtextxy (xmax/2-177, 25, "I  S  R  C  I  N");
  setcolor (WHITE);
  outtextxy (xmax/2-180, 25, " N  T  U  T O  S");
  outtextxy (xmax/2-182, 25, " N  T  U  T O  S");
  outtextxy (xmax/2-183, 25, " N  T  U  T O  S");
  outtextxy (xmax/2-184, 25, " N  T  U  T O  S");
  outtextxy (xmax/2-185, 25, " N  T  U  T O  S");


  gotoxy (1, 8);
  cout<<"    The objective of this game is to work out the correct arrangement of\n "
      <<"   magnets and blank spaces in the given board using the clues provided.\n "
      <<"   The number of positive and negative poles in a row/column is indicated by\n "
      <<"   the numbers at the end of each row/column. Two similar poles cannot be\n "
      <<"   present adjecent to each other. You have to solve the game in minimum\n "
      <<"   possible time. The time elapsed is indicated by a timer. Any wrong move\n "
      <<"   is indicated by a red circle above the board and a small triangle showing\n "
      <<"   the row/column. \n\n\n ";

  cout<<"   Use arrow keys to navigate on the board.\n "
      <<"   Press 'Enter'     to insert magnets and change their polarity.\n "
      <<"   Press 'Space bar' to insert blank spaces.\n "
      <<"   Press 'Delete'    to claear a block.\n "
      <<"   Press 's'         to save the game.\n "
      <<"   Press 'q'         to quit the game and see the answer.\n "
      <<"   Press 'esc'       to leave the game and return to main menu.\n ";

  cout<<"\n\n\n    Press any key to return to menu. ";

  setfillstyle(9, GREEN);
  bar(0, 0, 15,ymax);
  bar(0, 0, xmax,15);
  bar(xmax, 0, xmax-15,ymax);
  bar(xmax, ymax, 0, ymax-15);

  getch();
  main();
  }


void credits()
{ cleardevice();
  int xmax = getmaxx(),
      ymax = getmaxy();

  setfillstyle(9, GREEN);
  bar(0, 0, 15,ymax);
  bar(0, 0, xmax,15);
  bar(xmax, 0, xmax-15,ymax);
  bar(xmax, ymax, 0, ymax-15);

  setcolor (RED);
  settextstyle (6,0,7);
  outtextxy (xmax/2-120, 20, "  R  D T ");
  outtextxy (xmax/2-122, 20, "  R  D T ");
  outtextxy (xmax/2-124, 22, "  R  D T ");
  outtextxy (xmax/2-126, 22, "  R  D T ");
  outtextxy (xmax/2-128, 24, "  R  D T ");
  setcolor (WHITE);
  outtextxy (xmax/2-115, 20, "C  E  I  S");
  outtextxy (xmax/2-117, 20, "C  E  I  S");
  outtextxy (xmax/2-119, 22, "C  E  I  S");
  outtextxy (xmax/2-121, 22, "C  E  I  S");
  outtextxy (xmax/2-123, 24, "C  E  I  S");

  setcolor (6);
  settextstyle (5, 0, 4);
  outtextxy (50, 110, "Game Designed by:");

  setcolor (14);
  settextstyle (7, 0, 2);
  outtextxy (50, 160, "Anshul Jain        Roll no.: 10");
  outtextxy (50, 190, "Preshit Wazalwar   Roll no.: 35");

  setcolor (6);
  settextstyle (5, 0, 3);
  outtextxy (50, 250, "Special Thanks To:");

  setcolor (WHITE);
  settextstyle (6, 0, 1);
  outtextxy (50, 290, "Smriti Ma'am");
  outtextxy (50, 310, "Vinod Sir");
  outtextxy (50, 330, "Rishabh Bhattacharya");
  outtextxy (50, 350, "Adhish Shrivastava");
  settextstyle (0, 0, 1);
  outtextxy (50, 420, "Press any key to continue");

  getch();
  main();
   }


int highscore(int m, int n,int chance,int ttime)
{ float score=0;
  char ret[15], newname[20];

  fstream a;
  a.open("high.txt",ios::in);
  score=10000/(ttime*chance);

  if(a.fail())
  { return 0; }

  while (!a.eof())
  { a.read((char*)&cscore,sizeof(hscore));
    if ((cscore.m==m && cscore.n==n)||(cscore.m==n && cscore.n==m))
    { break; } }

  if(cscore.s3<score)
  { return 1; }

  a.close();
  return 0;

   }


void highscore1(int m,int n,int ch ,int ttime)
{ float score;

  score=10000/(ch*ttime);

  cscore.update(score);

  fstream edit;
  edit.open("high.txt",ios::in);
  fstream put;
  put.open("tempo.txt",ios::out);

  while (!edit.eof())
  { edit.read((char*)&tempo,sizeof(hscore));
    if ((tempo.m==m && tempo.n==n)||(tempo.m==n && tempo.n==m))
    { put.write((char*)&cscore,sizeof(hscore)); }

    else
    { put.write((char*)&tempo,sizeof(hscore)); } }

  edit.close();
  put.close();
  remove("high.txt");
  rename("tempo.txt","high.txt");
   }


void viewscore()
{ cleardevice();
  int flag=0,m=0,n=0;
  char ret[15], newname[20];

  gotoxy(3,4);
  cout<<"Enter the size of the board: \n";
  gotoxy(3,6);
  cout<<" Enter the number of rows: ";
  cin>>m;
  gotoxy (3, 8);
  cout<<" Enter the number of columns: ";
  cin>>n;


  fstream a;
  a.open("high.txt",ios::in);

  while (!a.eof())
  { a.read((char*)&cscore,sizeof(hscore));
    if ((cscore.m==m && cscore.n==n)||(cscore.m==n && cscore.n==m))
    { flag=1;
      break; } }

    if (flag==1)
    { gotoxy(5,10);
      cscore.output();}

    else
     cout<<"\n  No high scores for the given board size.";

  getch();
  main();
  }


void main()
{ clrscr();
  randomize();
  int m=0,n=0;
  int choice=0;
  int xmax = getmaxx(),
      ymax = getmaxy();

  if (flag==0)
  { loadgr();
    intro();
    flag=1; }

  choice=mmenu();
  switch (choice)
  { case 0: { cleardevice();

	      A:
	      setfillstyle(9, GREEN);
	      bar(0, 0, 15,ymax);
	      bar(0, 0, xmax,15);
	      bar(xmax, 0, xmax-15,ymax);
	      bar(xmax, ymax, 0, ymax-15);

	      gotoxy (3, 5);
	      cout<<" Select the size of the board.";
	      gotoxy (3, 6);
	      cout<<" Please ensure that both nos. are not odd and they are less than 9";

	      gotoxy (3, 8);
	      cout<<" Enter the number of rows: ";
	      cin>>m;
	      gotoxy (3, 10);
	      cout<<" Enter the number of columns: ";
	      cin>>n;

	      if (m%2!=0 && n%2!=0)
	      { cleardevice();
		gotoxy(3,3);
		cout<<" Please enter even nos.";
		goto A; }

	      else if(m>9 || n>9)
	      { cleardevice();
		gotoxy(3,3);
		cout<<" Please enter valid nos.";
		goto A; }
	      ttime1=0;

	      for (int v1=0;v1<50;v1++)
	      { for (int v2=0;v2<50;v2++)
		{ calp[v1][v2]=0;
		  calm[v1][v2]=0;
		  play[v1][v2]=0;
		  s[v1][v2]=0; } }

	      assign(m,n);
	      initialize(m,n);
	      sign(m,n);
	      break; }

  case 1: load(m,n);
	  break;

  case 2: instr();
	  break;

  case 3: viewscore();
	  break;

  case 4: credits();
	  break;

  case 5: exit(0); }

  draw(m,n,100);
  count(m,n);
  swrite(m,n,100);
  game(m,n);

  getch();


   }
