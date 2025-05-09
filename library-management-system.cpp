#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<iostream.h>
#include<fstream.h>
#include<math.h>
#include<dos.h>
#include<process.h>
#include<string.h>
class book
{
   char bno[10];
   char bname[50];
   char aname[50];
   public:
       void create_book()
       {
       cout<<"\nnew book entry..\n";
       cout<<"\nenter book no. ";
       cin>>bno;
       cout<<"\nenter name of book :";
       gets(bname);
       cout<<"\nenter the author's name :";
       gets(aname);
       cout<<"\n\nbook created...";
       }
       void show_book()
       {
       cout<<"\nbook no. :"<<bno;
       cout<<"\nbook name :";
       puts(bname);
       cout<<"\nauthor name :";
       puts(aname);
       }
       void modify_book()
       {
       cout<<"\nbook no. :"<<bno;
       cout<<"\nmodify book name :";
       gets(bname);
       cout<<"\nmodify author's name :";
       gets(aname);
       }
       char* retbno()
       {
       return bno;
       }

       void report()
       {
       cout<<bno<<"\t"<<bname<<"\t"<<aname<<"\n";
       }

  };
  class student
  {
     char admno[50];
     char name[50];
     char stbno[6];
     int token;
     public:
	void create_student()
	{
	 clrscr();
	 cout<<"\nnew student entry..\n";
	 cout<<"\nenter student admision no. ";
	 cin>>admno;
	 cout<<"\nenter name of student ";
	 gets(name);
	 token=0;
	 stbno[0]='/0';
	 cout<<"\n\nstudent record created..";
	}
	void show_student()
	{
	 cout<<"\nadmision no. : "<<admno;
	 cout<<"\nstudent name : ";
	 puts(name);
	 cout<<"\nbooks issued : "<<token;
	 if(token==1)
	   cout<<"\nbook no. "<<stbno;
	}
	void modify_student()
	{
	  cout<<"\nadmission no. of student :"<<admno;
	  cout<<"\nmodify student name :";
	  gets(name);
	}
      char* retadmno()
      {
	 return admno;
      }
      char* retstbno()
      {
	return stbno;
      }
      int rettoken()
      {
	return token;
      }
      void addtoken()
      {token=1;}
      void resettoken()
	{token=0;}
      void getstbno(char t[])
      {
       strcpy(stbno,t);
      }
      void report()
      {
      if(token==1)
      cout<<"\t"<<admno<<"\t"<<name<<"\t"<<token<<"\t"<<stbno<<"\n";
      else
      cout<<"\t"<<admno<<"\t"<<name<<"\t"<<token<<"\n";
      }
  };






  fstream fp,fp1;
  book bk;
  student st;



  void write_book()
  {
     char ch;
     fp.open("rook.dat",ios::out|ios::app);
     do
     {
	clrscr();
	bk.create_book();
	fp.write((char*)&bk,sizeof(book));
	cout<<"\n\ndo you want to add more books to record...\n(y/n)?";
	cin>>ch;
     }while(ch=='y'||ch=='Y');
     fp.close();

  }
 void write_student()
 {
   char ch;
   fp.open("tudent.dat",ios::out|ios::app);
   do
   {
      clrscr();
      st.create_student();
      fp.write((char*)&st,sizeof(student));
      cout<<"\n\ndo you want to add more students to record...\n(y/n)?";
      cin>>ch;
   }while(ch=='y'||ch=='Y');
   fp.close();
}

void display_spb(char n[])
{
   cout<<"\nbook details\n";
   int flag=0;
   fp.open("rook.dat",ios::in);
   while(fp.read((char*)&bk,sizeof(book)))
   {
      if(strcmpi(bk.retbno(),n)==0);
      {
	 bk.show_book();
	 flag=1;
      }
   }
   fp.close();
   if(flag==0)
      cout<<"book not found";
   getch();
 }

 void display_sps(char n[])
 {
    cout<<"\nstudent details\n";
    int flag=0;
    fp.open("tudent.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
	if((strcmpi(st.retadmno(),n)==0))
	{
	    st.show_student();
	    flag=1;
	}
    }
    fp.close();
    if(flag==0)
	 cout<<"\n\nstudent does not exist";
    getch();
 }


 void modify_book()
 {
    char n[6];
    int found=0;
    clrscr();
    cout<<"\n\nmodify book record....";
    cout<<"\n\n\tenter the book no. of the book youwant to modify :";
    cin>>n;
    fp.open("rook.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
      if(strcmpi(bk.retbno(),n)==0)
	{
		bk.show_book();
		cout<<"\nenter new details of book"<<"\n";
		bk.modify_book();
		int pos=-1*sizeof(bk);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&bk,sizeof(book));
		    cout<<"\n\n\trecord updated";
		    found=1;
	 }
 }
 fp.close();
 if(found==0)
   cout<<"record not found";
   getch();
}

void modify_student()
{

  char n[6];
  int found=0;
  clrscr();
  cout<<"\n\n\tmodify student record...";
  cout<<"\n\n\tenter admission no. of student : ";
  cin>>n;
  fp.open("tudent.dat",ios::in|ios::out);
  while(fp.read((char*)&st,sizeof(student)) && found==0)
  {
     if(strcmpi(st.retadmno(),n)==0)
     {
	st.show_student();
	cout<<"\nenter the new details of student"<<"\n";
	st.modify_student();
	int pos=-1*sizeof(st);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&st,sizeof(student));
	cout<<"\n\n\trecord updated ";
	found=1;
	}
    }

    fp.close();
    if(found==0)
       cout<<"record not found";
    getch();
 }

 void delete_student()
     {
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\n\n\tdelete student...";
	cout<<"\n\nenter the admission number of student you want to delete :";
	cin>>n;
	fp.open("tudent.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("remove.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
	 if(strcmpi(st.retadmno(),n)!=0)
	     fp2.write((char*)&st,sizeof(student));
	 else
	     flag=1;
       }
       fp2.close();
       fp.close();
       remove("tudent.dat");
       rename("remove.dat","tudent.dat");
       if(flag==1)
	   cout<<"\n\n\trecord deleted..";
	else
	  cout<<"\n\nrecord not found";
	getch();
   }

   void delete_book()
   {
      char n[6];
      clrscr();
      cout<<"\n\n\n\tdelete book...";
      cout<<"\n\nenter the book no. of the book you want to delete : ";
      cin>>n;
      fp.open("rook.dat",ios::in|ios::out);
      fstream fp2;
      fp2.open("rename.dat",ios::out);
      fp.seekg(0,ios::beg);
      while(fp.read((char*)&bk,sizeof(book)))
      {
	 if(strcmpi(bk.retbno(),n)!=0)
	  {
	    fp2.write((char*)&bk,sizeof(book));
	  }
      }
      fp2.close();
      fp.close();
      remove("rook.dat");
      rename("rename.dat","rook.dat");
      cout<<"\n\n\trecord delete";
      getch();
  }


  void display_alls()
  {
     clrscr();
	 fp.open("tudent.dat",ios::in);
	 if(!fp)
	 {
	    cout<<"error!!!file could not be open";
	    getch();
	    return;
	 }
    cout<<"\n\n\t\tstudent list\n\n";
    while(fp.read((char*)&st,sizeof(student)))
    {
       st.report();
    }
    fp.close();
    getch();
}
//**************************************************************************
void display_allb()
{
   clrscr();
   fp.open("rook.dat",ios::in);
   if(!fp)
   {
     cout<<"error!!!file can't be opened ";
     getch();
     return;
  }
  cout<<"\n\n\tbook list\t\n\n";
  while(fp.read((char*)&bk,sizeof(book)))
  {
    bk.report();
  }
  fp.close();
  getch();
}

void book_issue()
{
 char sn[6],bn[6];
 int found=0,flag=0;
 clrscr();
 cout<<"\n\n\tbook issue..";
 cout<<"enter admission number of student ";
 cin>>sn;
 fp.open("tudent.dat",ios::in|ios::out);
 fp1.open("rook.dat",ios::in|ios::out);
 while(fp.read((char*)&st,sizeof(student)) && found==0)
 {
    if(strcmpi(st.retadmno(),sn) ==0)
    {
      found=1;
      if(st.rettoken()==0)
      {
	  cout<<"\n\n\tenter book no. : ";
	  cin>>bn;
	  while(fp1.read((char*)&bk,sizeof(book)) && flag==0)
	    {
	       if(strcmpi(bk.retbno(),bn)==0)
		 {
		   bk.show_book();
		   flag=1;
		   st.addtoken();
		   st.getstbno(bk.retbno());
		   int pos=-1*sizeof(st);
		   fp.seekp(pos,ios::cur);
		   fp.write((char*)&st,sizeof(student));
		   cout<<"\n\n\tbook issued";
		 }
		 }
		 if (flag==0)
		      cout<<"book no. does not exist";
		      }
		      else
		       cout<<"you have not returned the last book";
	   }
 }
  if(found==0)
  cout<<"student record does not exist";
  getch();
  fp.close();
  fp1.close();
}

  void book_deposit()
  {
     char sn[6],bn[6];
     int found=0,flag=0,day,fine;
     clrscr();
     cout<<"\n\nbook deposit...";
     cout<<"\n\n\tenter the student's admission number ";
     cin>>sn;
     fp.open("tudent.dat",ios::in|ios::out);
     fp1.open("rook.dat",ios::in|ios::out);
     while(fp.read((char*)&st,sizeof(student)) && found==0)
     {
      if(strcmpi(st.retadmno(),sn)==0)
      {
	 found=1;
	 if(st.rettoken()==1)
	 {
	 while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
	 {
	 if (strcmpi(bk.retbno(),st.retstbno())==0)
	 {
	 bk.show_book();
	 flag=1;
	 st.resettoken();
	 int pos=-1*sizeof(st);
	 fp.seekp(pos,ios::cur);
	 fp.write((char*)&st,sizeof(student));
	 cout<<"\n\n\t book deposited succesfully ";
	 }
	 }
	 if(flag==0)
	 cout<<"book no. does not exist";
	 }
	 else
	 cout<<"no book issued .. please check!!";
	 }
	 }
	 if (found==0)
	 cout<<"student record does'nt exist";
	 getch();
	 fp.close();
	 fp1.close();
	 }




	 void intro()
	 {
	    clrscr();
	    cout<<"\n\n\n\tLIBRARY MANAGEMENT SYSTEM";
	    cout<<"\n\nschool : bal bharati public school";
	    cout<<"\n\nmade by : soham gupta";
	    getch();
	 }







	 void admin_menu()
	 {
	    clrscr();
	    int ch2;
	    cout<<"\n\tadministrator's menu";
	    cout<<"\n\t1. create student record";
	    cout<<"\n\t2.display all student records";
	    cout<<"\n\t3.display specific student record";
	    cout<<"\n\t4.modify student record";
	    cout<<"\n\t5.delete student record";
	    cout<<"\n\t6.create book";
	    cout<<"\n\t7.display all books";
	    cout<<"\n\t8.display specific book";
	    cout<<"\n\t9.modify book";
	    cout<<"\n\t10.delete book";
	    cout<<"\n\t11.issue book";
	    cout<<"\n\t12.deposit book";
	    cout<<"\n\t13.exit";
	    cout<<"\n\n\tplease enter your choice (1-13) : ";
	    cin>>ch2;
	    switch(ch2)
	    {
		 case 1:
		     clrscr();
		     write_student();
		     delay(1000);
		     admin_menu();
		     break;
		 case 2:
		     clrscr();
		     display_alls();
		     delay(5000);
		     admin_menu();
		     break;
		 case 3:
		     clrscr();
		     char num[6];
		     cout<<"\n\n\tplease enter the admission no. ";
		     cin>>num;
		     display_sps(num);
		     delay(5000);
		     admin_menu();
		     break;
		 case 4:
		     clrscr();
		     modify_student();
		     delay(1000);
		     admin_menu();
		     break;
		 case 5:
		     clrscr();
		     delete_student();
		     delay(1000);
		     admin_menu();
		     break;
		 case 6:
		     clrscr();
		     write_book();
		     delay(1000);
		     admin_menu();
		     break;
		case 7:
		     clrscr();
		     display_allb();
		     delay(5000);
		     admin_menu();
		     break;
	       case 8:
		     clrscr();
		     char nums[6];
		     cout<<"\n\n\tenter book no. ";
		     cin>>num;
		     display_spb(nums);
		     delay(5000);
		     admin_menu();
		     break;
	       case 9:
		     clrscr();
		     modify_book();
		     delay(1000);
		     admin_menu();
		     break;
	       case 10:
		     clrscr();
		     delete_book();
		     delay(1000);
		     admin_menu();
		     break;
	       case 11:
		     clrscr();
		     book_issue();
		     delay(1000);
		     admin_menu();
		     break;
	       case 12:
		     clrscr();
		     book_deposit();
		     delay(1000);
		     admin_menu();
		     break;
	      case 13:
		     return;


	  }
}

void main()
{

      int ch;
      intro();
      admin_menu();
		getch();
	 }
