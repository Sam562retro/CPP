#include<iostream.h>
#include<conio.h>
template<class t>
t greatest (t x,t y,t z)
{
if(x>y&&x>z)
return x;
else if (y>x&&y>z)
return y;
else
return z;
}
void main()
{
clrscr();
int ch;
char choice;
do
{
cout<<"1.integers \n2. decimals \nenter your choice";
cin>>ch;
switch(ch)
{
case 1:
int a,b,c,m1;
cout<<"\nenter three integers \n";
cin >>a>>b>>c;
m1=greatest(a,b,c);
cout<<"greatest number = "<<m1;
break;

case 2:
float x,y,z,m;
cout<<"\nenter three decimals \n";
cin>>x>>y>>z;
m=greatest(x,y,z);
cout<<"greatest number is "<<m;
break;

default:
cout<<"\nwrong\nchoice\nentered";
break;
}
cout<<"do you want to continue (y/n)";
cin>>choice;
}
while(choice=='y'||choice=='Y');

getch();
}
