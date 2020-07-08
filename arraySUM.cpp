#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int array[5];
int i;
for(i=0;i<=4;i++)
{
cout<<"enter the no. ""\n";
cin>>array[i];
}
int a=0;
for(i=0;i<=4;i++)
{
a = a+ array[i];
}
cout<<a;
getch();
}
