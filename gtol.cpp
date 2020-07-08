#include <iostream.h>;
#include <math.h>;
main()
{
int a,b,d;
int c=2;
cout<<"please emter the type of gallon you want to enter (1 for us or 2 for uk) and enter the value you want to change.";
cin>>a;
cin>>b;
if(a==c)
cout<<b<<" gallons in liters is "<<(4.5461/b)<<" L";
else
cout<<b<<" gallons in literes is "<<(3.7854/b)<<" L";
int e;
cin>>e;
return 0;
}
