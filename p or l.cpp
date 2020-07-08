#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,b;
cout<<"enter buying rate ""\n";
cin>>a;
cout<<"enter seling rate ""\n";
cin>>b;
if (a<b)
cout<<"profit by "<<(b-a);
else
cout<<"loss by "<<(a-b);
getch();
}
