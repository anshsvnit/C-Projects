
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>




class hscore
  {
    public:
    int m;
    int n;
    int s1;
    int s2;
    int s3;
    char name_s1[20];
    char name_s2[20];
    char name_s3[20];
    void update(float,char*);
    void output();

     }cscore,bscore,tempo;

void hscore::update(float score,char *p)
  { int tmp=0,tmp1=0;
    char name[20],name1[20];
     if(score>s1)
       {
	 tmp=s1;
	 strcpy(name,name_s1);

	 s1=score;
	 strcpy(name_s1,p);
	 tmp1=s2;
	 strcpy(name1,name_s2);
	 s2=tmp;
	 strcpy(name_s2,name);
	 s3=tmp1;
	 strcpy(name_s3,name1);
	}
      else if(score>s2)
	{
	 tmp=s2;
	 strcpy(name,name_s2);
	 s2=score;
	 strcpy(name_s2,p);
	 s3=tmp;
	 strcpy(name_s3,name);
	 }
       else if(score>s3)
	{s3=score;
	 strcpy(name_s3,p);}
  }
void hscore::output()
  {
    puts(name_s1);
    cout<<'\n';
    puts(name_s2);
    cout<<'\n';
    puts(name_s3);
  }

void main()
{ clrscr();

  ofstream a;
  a.open("high.txt",ios::app);
for(int i=1;i<10;i+=2)
  {
    for( int j=2;j<10;j+=2)
    {
  cout<<"Enter records";
  cout<<i<<"x"<<j;
    cscore.m=i;
    cscore.n=j;
    cscore.s1=0;
    cscore.s2=0;
    cscore.s3=0;
	cout<<"next\n";
	 a.write((char*)&cscore,sizeof(hscore));
     }
  }
for(i=2;i<10;i+=2)
  {
   for(int j=i;j<10;j+=2)
   {
  cout<<"Enter records";
  cout<<i<<"x"<<j;
    cscore.m=i;
    cscore.n=j;
    cscore.s1=0;
    cscore.s2=0;
    cscore.s3=0;
	cout<<"next\n";
	 a.write((char*)&cscore,sizeof(hscore));
     }

  }

//  a.write((char*)&cscore,sizeof(hscore));

  a.close();
  clrscr();
  cout<<"DONE";
/*  ifstream b;
  b.open("high.txt",ios::in);
  b.read ((char*)&bscore,sizeof (bscore));
  cout<<"\n\n\n\n"<<bscore.m<<'\t'<<bscore.n<<'\t'<<bscore.s1<<'\t'<<bscore.s2<<'\t'<<bscore.s3<<"\n names \n";
  bscore.output();
  b.close();

 /*  ifstream c;
  c.open("rehnedo.txt",ios::in);
  c.read ((char*)&dscore,sizeof (dscore));
  cout<<"\n\n\n\n"<<dscore.m<<'\t'<<dscore.n<<'\t'<<dscore.s1<<'\t'<<dscore.s2<<'\t'<<dscore.s3;
 getch();   */
 getch();
 }


