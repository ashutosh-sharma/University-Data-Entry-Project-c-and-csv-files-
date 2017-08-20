#include<dos.h>
#include<process.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<iostream>

using namespace std;
class student;
class faculty;
class society;
class university
{
int stu;        //Total Number of student
int fac;        //total number of faculties
int soc;        //Total number of societies;
public:
    university(){
    stu=0;
    fac=0;
    soc=0;
    }
    void upStu(){
    stu++;
    }
    void upFac(){
    fac++;
    }
    void upSoc(){
    soc++;
    }
    void display(){
    cout<<"Number of Students:"<<stu;
    cout<<"\nNumber of Faculty:"<<fac;
    cout<<"\nNumber of Society:"<<soc;
    }
}u;

class student
{
string rollNo,year,name,stream,email;
public:
    void input(){
    cout<<"\nEnter Roll no:";
    cin.ignore(); cin>>rollNo;
    cout<<"Name of the student:";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter Year:";
    cin>>year;
    cout<<"Enter Stream:";
    cin.ignore();
    cin>>stream;
    cout<<"Enter email:";
    cin.ignore(); cin>>email;
    }
    string Rroll(){
    return rollNo;
    }
    string Ryear(){
    return year;
    }
    string Rname(){
    return name;
    }
    string Rstream(){
    return stream;
    }
    string Remail(){
    return email;
    }
}s;

class faculty
{
    string Fid,name,field,email,type;
public:
    void input(){
    cout<<"\nEnter Fid:";
    cin.ignore(); cin>>Fid;
    cout<<"Enter Faculty Name:";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter 1->Teaching or 2->Non-teaching?:";
    int ch;
    cin>>ch;

    if(ch==1)
        type="Teaching";
    else
        type="Non-Teaching";

    cout<<"Enter Subject/Office:";
    cin.ignore(); getline(cin,field);
    cout<<"Enter email:";
    cin>>email;
    }

    string RFid(){
    return Fid;
    }
    string Rname(){
    return name;
    }
    string Rtype(){
    return type;
    }
    string Rfield(){
    return field;
    }
    string Remail(){
    return email;
    }
}f;

class society
{
string sId,sName;
int HF,Tstu;

public:
    void input(){
    cout<<"Enter Society Id:";
    cin.ignore();
    getline(cin,sId);

    cout<<"Enter Society Name:";
    getline(cin,sName);

    cout<<"Enter Faculty Id who heads this society:";
    cin>>HF;

    cout<<"Enter total Number of students in society:";
    cin>>Tstu;
    }
    string RsId(){
    return sId;
    }
    string RsName(){
    return sName;
    }
    int RHF(){
    return HF;
    }
    int RTstu(){
    return Tstu;
    }
}x;

void ask(){
cout<<"\nChoose from the given options:";
//cout<<"\n_____________________________";
cout<<"\n\nPRESS:\n 0)For Searching operations \n 1)Data Entry for Student \n 2)Data Entry for faculty \n 3)Data Entry for society \n\nEnter choice:";
}

void welcome(){
 cout<<"\n________________________________________________________________________________________________________________________________________________________________________";
 cout<<"\n\n************************************************************************************************************************************************************************";
 cout<<"\n*********************************************************************WELCOME TO DATA ACCESS SYSTEM**********************************************************************";
 cout<<"\n****************************************************************This software is based upon c++ language*************************************";
 cout<<"***************************************************************************************************************************************************************************************************";
 cout<<"\n________________________________________________________________________________________________________________________________________________________________________";
 cout<<"\n\n";
}

int a,b,c; // choice -page 1

fstream stu("StudentData.csv",ios::app);   //,ios::app
ofstream fac("FacultyData.csv",ios::app);
ofstream soc("SocietyData.csv",ios::app);

/********************************************
PAGE 1- Choices function()
********************************************/
void choice1()
{
ask();

cin>>c;

system("cls");

while(c!=0)
{   university u;
    cout<<"\n\n";
   switch(c){
      case 1:                 //data entry student
        cout<<"\n\n************************************************************************************************************************************************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\tDATA ENTRY FOR STUDENT\n";
        cout<<"\n************************************************************************************************************************************************************************";
        cout<<"\n\n";
        u.upStu();
        s.input();
        stu<<s.Rroll()<<","<<s.Rname()<<","<<s.Ryear()<<","<<s.Rstream()<<","<<s.Remail()<<"\n";
        break;

    case 2:                 //data entry faculty
        cout<<"\n\n************************************************************************************************************************************************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\tDATA ENTRY FOR FACULTY:\n";
        cout<<"\n************************************************************************************************************************************************************************";
        cout<<"\n\n";
        u.upFac();
        f.input();
        fac<<f.RFid()<<","<<f.Rname()<<","<<f.Rtype()<<","<<f.Rfield()<<","<<f.Remail()<<"\n";
        break;
    case 3:                //data entry for society
        cout<<"\n\n************************************************************************************************************************************************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\tDATA ENTRY FOR SOCEITY:\n";
        cout<<"\n************************************************************************************************************************************************************************";
        cout<<"\n\n";
        u.upSoc();
        x.input();
        soc<<x.RsId()<<","<<x.RsName()<<","<<x.RHF()<<","<<x.RTstu()<<"\n";
        break;
    default:
        cout<<"Invalid Choice!Try again";
        break;
  }
  cout<<"DATA SAVED!";
  cout<<"\n________________________________________________________________________________________________________";

  ask();
  cin>>c;
  system("cls");
 }
}

void asksearch(){
cout<<"\n\n************************************************************************************************************************************************************************";
cout<<"\n\n\t\t\t\t\t\t\t\tChoosing for Search Operations\n\n";
cout<<"\n\n************************************************************************************************************************************************************************";
cout<<"\n\nPRESS:\n 0)To Exit \n 1)Searching operations \n";
}

/*************************
Search operations:Student
**************************/
void StuSearch(){
    system("cls");
cout<<"\n\n________________________________________________________________________________________________________________________________________________________________________";
cout<<"\t\t\t\t\t\t\t\tSTUDENT SEARCHING OPERATIONS\n";
cout<<"\n________________________________________________________________________________________________________________________________________________________________________";

  int f=0,i=0,rnf=0;
    char temp,c,check[11];
    cout<<"\nEnter Student's University ID : ";
    cin.ignore();
    cin.getline(check,11);

    fstream obj("StudentData.csv",ios::in);

    cout<<"\n\nSearching\n";
    Sleep(3000);

    cout<<"\n\n";
    cout<<"________________________________________\n";
    cout<<"Search Results:\n";

    while(!obj.eof())
    {
        obj.read((char *) &temp,sizeof(temp));
            //cout<<temp;
        if(temp=='\n')
          {
            i=0;f=0;

          while(i<10){
             obj.read((char *)&temp,sizeof(temp));

                if(check[i]==temp)
                 {
                    f=1;
                   }
                else
                 {
                   f=0;
                   break;
                   }
                  i++;
            }

           if(f==1)
             { rnf=1;
              while (obj.get(c))
               {
                 if(c==','){
                  cout<<"\n";
                  continue;
                 }

                  cout << c;

                if(c=='\n')
                 break;
               }
              }
         }
    }

    if(rnf==0){
        cout<<"**Record Not Found**\n";
        }
    cout<<"________________________________________\n";
    obj.close();
}

/*************************
Search operations:Faculty
**************************/
void FacSearch(){
 system("cls");
cout<<"\n\n________________________________________________________________________________________________________________________________________________________________________";
cout<<"\t\t\t\t\t\t\t\tFACULTY SEARCHING OPERATIONS\n";
cout<<"\n________________________________________________________________________________________________________________________________________________________________________";

  int f=0,i=0,rnf=0;
    char temp,c,check[4];
    cout<<"\nEnter Faculty Id: ";
    cin.ignore();
    cin.getline(check,4);

    fstream obj("FacultyData.csv",ios::in);

    cout<<"\n\nSearching\n";
    Sleep(3000);

    cout<<"\n\n";
    cout<<"________________________________________\n";
    cout<<"Search Results:\n";

    while(!obj.eof())
    {
        obj.read((char *) &temp,sizeof(temp));
            //cout<<temp;
        if(temp=='\n')
          {
            i=0;f=0;

          while(i<3){
             obj.read((char *)&temp,sizeof(temp));

                if(check[i]==temp)
                 {
                    f=1;
                   }
                else
                 {
                   f=0;
                   break;
                   }
                  i++;
            }

           if(f==1)
             { rnf=1;
              while (obj.get(c))
               {
                 if(c==','){
                  cout<<"\n";
                  continue;
                 }

                  cout << c;

                if(c=='\n')
                 break;
               }
              }
         }
    }

    if(rnf==0){
        cout<<"\n**Record Not Found**\n";
        }
    cout<<"________________________________________\n";
    obj.close();
}

/*************************
Search operations:Society
**************************/
void SocSearch(){
     system("cls");
cout<<"\n\n________________________________________________________________________________________________________________________________________________________________________";
cout<<"\t\t\t\t\t\t\t\tSOCIETY SEARCHING OPERATIONS\n";
cout<<"\n________________________________________________________________________________________________________________________________________________________________________";

  int f=0,i=0,rnf=0;
    char temp,c,check[4];
    cout<<"\nEnter Society Id: ";
    cin.ignore();
    cin.getline(check,4);

    fstream obj("SocietyData.csv",ios::in);

    cout<<"\n\nSearching\n";
    Sleep(3000);

    cout<<"\n\n";
    cout<<"________________________________________\n";
    cout<<"Search Results:\n";

    while(!obj.eof())
    {
        obj.read((char *) &temp,sizeof(temp));
            //cout<<temp;
        if(temp=='\n')
          {
            i=0;f=0;

          while(i<3){
             obj.read((char *)&temp,sizeof(temp));

                if(check[i]==temp)
                 {
                    f=1;
                   }
                else
                 {
                   f=0;
                   break;
                   }
                  i++;
            }

           if(f==1)
             { rnf=1;
              while (obj.get(c))
               {
                 if(c==','){
                  cout<<"\n";
                  continue;
                 }

                  cout << c;

                if(c=='\n')
                 break;
               }
              }
         }
    }

    if(rnf==0){
        cout<<"\n**Record Not Found**\n";
        }
    cout<<"________________________________________\n";
    obj.close();

}


/**********************************
Asking for Searching Operations
**********************************/
void choice2(){
asksearch();//

cin>>a;
if(a==1)
{
system("cls");
cout<<"\n\n########################################################################################################################################################################";
cout<<"\n\t\t\t\t\t\t\t\t\t\tWhat Do You Wanna Search For?\n";
cout<<"\n\n########################################################################################################################################################################";
cout<<"\nPRESS:\n 0)To exit \n 1)Search for Student \n 2)Search for faculty \n 3)Search for society \nEnter choice:";

cin>>b;
switch(b)
{
case 1:
    StuSearch();
    break;
case 2:
    FacSearch();
    break;
case 3:
    SocSearch();
    break;
default:
    system("cls");
    break;
   }
 }
  cout<<"\n\n\n\n==============================================Exiting Search Page=======================================";
}

void dhyanwad(){
cout<<"\n\n________________________________________________________________________________________________________________________________________________________________________";
cout<<"\n\n************************************************************************************************************************************************************************";
cout<<"\t\t\t\t\t\t\t\t\t\tThanks for using our software";
cout<<"\n************************************************************************************************************************************************************************";
cout<<"\n\n________________________________________________________________________________________________________________________________________________________________________";
}


int main()
{
    int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


setcolor(YELLOW);
   settextstyle(1,HORIZ_DIR,4);
outtextxy(500,100,"WELCOME TO");

settextstyle(1,HORIZ_DIR,4);
outtextxy(150,170,"EXPERTISE BASED DATA ACESS SYSTEM");

   settextstyle(1,HORIZ_DIR,4);
outtextxy(650,240,"OF");

settextstyle(1,HORIZ_DIR,4);
outtextxy(400,310,"FACULTY & STUDENT");
   settextstyle(1,HORIZ_DIR,3);

   setcolor(MAGENTA);
outtextxy(1000,470,"Made By:-");

settextstyle(1,HORIZ_DIR,2);
outtextxy(1000,510,"ANURAG 1103");

settextstyle(1,HORIZ_DIR,2);
outtextxy(1000,540,"AROOSH 1114");

settextstyle(1,HORIZ_DIR,2);
outtextxy(1000,570,"ARPAN 1115");

settextstyle(1,HORIZ_DIR,2);
outtextxy(1000,600,"ASHUTOSH 1132");



getch();

cleardevice();
setcolor(12);
   settextstyle(1,HORIZ_DIR,4);
outtextxy(10,0,"DESCRIPTION :-");

getch();
setcolor(15);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,50," A great faculty in an educational institution can transform how the students learn and create");

   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,75," an environment of innovation, creativity and excellence.There is an extensive need for ");


   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,100,"development of a comprehensive database which keeps a record of the key players in the ");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,125,"It should also maintain students education system i.e the teachers and faculty, their");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,150," qualifications, and contact details information,details about their courses, performance,");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,175," subject interests and goals.With EBASys (Expertise based access system of and student ");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,200," information), the faculties get enhanced horizons and improved control over different aspects ");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,225," of teaching the students.For management also this system would help in performance evaluation");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,250,"of the teachers as well as in development of strategies which could lead to higher standards in");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,275,"education.It would also serve as an online directory that can work both at intranet and internet ");

//setcolor(12);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,300,"level.");



getch();
cleardevice();


setcolor(12);
   settextstyle(1,HORIZ_DIR,4);
outtextxy(10,0,"UTILITY OF PROJECT :-");
getch();

  setcolor(15);
   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,45," Database maintenance and online interaction has become key focus area across all prominent");


   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,70," institutions.Information at the tip of a finger by a single click is the current state of ");


   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,95," demand of education systems.This system would optimize the education and human resource ");


   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,120," management at faculty, student as well as at management level apart from serving as an ");

   settextstyle(1,HORIZ_DIR,2);
outtextxy(10,145,"internal communication platform and organizational directory.");



getch();
setcolor(BLUE);
   settextstyle(1,HORIZ_DIR,3);
outtextxy(450,300,"Project Guide:- Mrs. Merry Saxena");


   getch();
cleardevice();

/**********************************
WELCOME
**********************************/
welcome();


/******************************************************
To search or data entry?
*******************************************************/
choice1(); // Switch case for options DATA ENTRY and SearchAsk()


/**************************************************
Searching Operations
**************************************************/
choice2(); //searching operations


/*************************************************
Exiting software-Thank you function
*************************************************/
dhyanwad();
closegraph();
return 0;
}
