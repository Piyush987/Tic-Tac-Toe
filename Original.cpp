#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
char n[3][3]={'0','1','2','3','4','5','6','7','8'};
int i,j;
char p,c,input;
class game
{
public:
void choice();
void display();
void computer();
void player();
void first();
int check();
};
void game::first()
{
cout<<"          COMPUTER PROJECT"<<endl;
cout<<"     Welcome to the exciting game: XORO  "<<endl;
cout<<"  This is a game of Cross And Zero, also known as tic tac toe"<<endl;
cout<<" Instructions to play this game:"<<endl;
cout<<"1.Choose either X or O(this is capital o) as your letter, the other one will be used by computer"<<endl;
cout<<"2.Each box has a number assigned to it. There are nine boxes in total"<<endl;
cout<<"3.Choose a box in which you want to add your letter and enter the number assigned to the box."<<endl;
cout<<"4:The next move will be played by the computer"<<endl;
cout<<"5.Repeat the above steps till the game completes"<<endl<<endl;
cout<<"   Rules to play this game:"<<endl;
cout<<"To win the game, you have to fill all boxes in a row or column or the diagonals with your chosen letter."<<endl;
cout<<"After your turn, the computer will play"<<endl;
cout<<"The first one to fill all 3 boxes in a row/column/diagonal wins."<<endl<<endl;
cout<<"           This game has been developed by Piyush Khedkar"<<endl;
cout<<"Press any key to continue"<<endl;
getch();
clrscr();
}

void game::choice()
{
int t2=0;
while(t2==0)
{
cout<<"What do you want to choose? X or O(This is capital o) (Enter in capital letters)"<<endl;
cin>>p;
if(p=='X')
{
c='O';
break;
}
else if(p=='O')
{
c='X';
break;
}
else
cout<<"Wrong choice"<<endl;
}
}
void game::display()
{
cout << "     |     |     " << endl;
cout << "  " << n[0][0]<< "  |  " << n[0][1] << "  |  " << n[0][2] << endl;
cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;
cout << "  " << n[1][0]<< "  |  " << n[1][1] << "  |  " << n[1][2] << endl;
cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;
cout << "  " << n[2][0]<< "  |  " << n[2][1] << "  |  " << n[2][2] << endl;
cout << "     |     |     " << endl << endl;
}
void game::player()
{
int c=0;
beg:
cout<<"Player, enter your choice"<<endl;
cin>>input;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(n[i][j]==input)
{
n[i][j]=p;
c++;
}
}
}
if(c==0)
{
cout<<"This move has been made,try another move"<<endl;
goto beg;
}
}
void game::computer()
{
int t1;
for(i=0;i<3;i++)
{
if(n[i][0]==n[i][1]&&int(n[i][2])<=56)
{
n[i][2]=c;
goto last;
}
if(n[i][0]==n[i][2]&&int(n[i][1])<=56)
{
n[i][1]=c;
goto last;
}
if(n[i][1]==n[i][2]&&int(n[i][0])<=56)
{
n[i][0]=c;
goto last;
}
}
for(j=0;j<3;j++)
{
if(n[0][j]==n[1][j]&&int(n[2][j])<57)
{
n[2][j]=c;
goto last;
}
if(n[0][j]==n[2][j]&&int(n[1][j])<=56)
{
n[1][j]=c;
goto last;
}
if(n[1][j]==n[2][j]&&int(n[0][j])<=56)
{
n[0][j]=c;
goto last;
}
}
if(n[0][0]==n[1][1]&&int(n[2][2])<=56)
{
n[2][2]=c;
goto last;
}
if(n[0][0]==n[2][2]&&int(n[1][1])<=56)
{
n[1][1]=c;
goto last;
}
if(n[1][1]==n[2][2]&&int(n[0][0])<=56)
{
n[0][0]=c;
goto last;
}

if(n[0][2]==n[2][0]&&int(n[1][1])<=56)
{
n[1][1]=c;
goto last;
}
if(n[0][2]==n[1][1]&&int(n[2][0])<=56)
{
n[2][0]=c;
goto last;
}
if(n[2][0]==n[1][1]&&int(n[0][2])<57)
{
n[0][2]=c;
goto last;
}

label1:
t1=random(8999);
t1=t1%10;
if(t1==9)
t1-=1;
t1=t1+48;

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(n[i][j]>=48&&n[i][j]<=56)
{
if(t1==int(n[i][j]))
{
n[i][j]=c;
goto last;
}
}
}
}
goto label1;
last:;
}
int game::check()
{
for(i=0;i<3;i++)
{
if(n[i][0]==p&&n[i][1]==p&&n[i][2]==p)
{
return 1;
}
if(n[i][0]==c&&n[i][1]==c&&n[i][2]==c)
{
return -1;
}

if(n[0][i]==p&&n[1][i]==p&&n[2][i]==p)
{
return 1;
}
if(n[0][i]==c&&n[1][i]==c&&n[2][i]==c)
{
return -1;
}
}

if(n[0][0]==p&&n[1][1]==p&&n[2][2]==p)
{
return 1;
}
if(n[0][0]==c&&n[1][1]==c&&n[2][2]==c)
{
return -1;
}

if(n[2][0]==p&&n[1][1]==p&&n[0][2]==p)
{
return 1;
}
if(n[2][0]==c&&n[1][1]==c&&n[0][2]==c)
{
return -1;
}

if(int(n[0][0])!=48&&int(n[0][1])!=49&&int(n[0][2])!=50&&int(n[1][0])!=51&&int(n[1][1])!=52&&int(n[1][2])!=53&&int(n[2][0])!=54&&int(n[2][1])!=55&&int(n[2][2])!=56)
{
return 0;
}
return 2;
}
void main()
{
clrscr();
game ob;
int status=2;
ob.first();
ob.choice();
ob.display();
while(status==2)
{
ob.player();
status=ob.check();
ob.display();
if(status==0)
{
ob.display();
break;
}
ob.computer();
cout<<"Computer has made it's move"<<endl;
ob.display();
status=ob.check();
}
if(status==1)
cout<<"  CONGRATULATIONS!!  YOU ARE VICTORIOUS  "<<endl;
if(status==-1)
cout<<"   YOU HAVE BEEN DEFEATED. The Computer wins this game."<<endl;
if(status==0)
cout<<"  This game ended with a DRAW"<<endl;
getch();
}
