#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
long int n,b,a=0,c;
cout<<"enter a number ";
cin>>n;
c=n;
while(n!=0)
{
b=n%10;
a=a*10+b;
n=n/10;
}
cout<<"reverse of "<<c<<" = "<<a;
if(c==a)
cout<<"palidrome";
else
cout<<"not palidrome ";
getch();
}
