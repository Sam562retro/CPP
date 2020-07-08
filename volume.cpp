#include <iostream.h>;
#include <math.h>;
main()
{
int d,y,Y;
do{
int a,b,c;
cout<<"please enter the following information of the tank:\n";
cout<<"width:\n";
cin>>a;
cout<<"breadth:\n";
cin>>b;
cout<<"hight:\n";
cin>>c;
cout<<"the volume of the tank is "<<((a*b)*c)<<"\n";
cout<<"do you want to get th volume of another tank ?\n(y for yes and n for no)";
cin>>d;
}while (d==y||d==Y);
int a;
cin>>a;
return 0;
}
