#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
int a,b,c,d;
cout<<" enter three angles of the triangles validity you want to check";
cin>>a>>b>>c;
d=(a+b+c);
if (d==180){
 if (a !=0 && b !=0 && c !=0)
 cout<<"valid";
 else
 cout<<"not valid";
}
else
cout<<"not valid";
getch();
}
