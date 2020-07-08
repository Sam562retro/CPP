#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
long int i,b,c=0,marks[5];
for(i=0;i<=4;i++)
{
cout<<"enter a no. ";
cin>>marks[i];
}
cout<<"enter a no. to b searched ";
cin>>b;
for(i=0;i<=4;i++)
{
if (b==marks[i])
{
c=1;
}
}
if(c==1)
cout<<"found";
else
cout<<"not found";
getch();
}
