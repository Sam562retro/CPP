#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,b;

for(a=1;a<=5;a++)
{
for(b=1;b<=5;b++)
{
if(b==1||b==3||b==5)
cout<<"1";
else
cout<<"0";
}
cout<<"\n";
}
getch();
}
