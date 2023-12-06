#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <dirent.h>
#include <string>
#include <process.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <typeinfo>
#include <windows.h>

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int deleteAllStudents();
int deleteStudentData();
int checkListOfStudentsRegistered();
int registerStudent();
int adminLogin();
int markMyAttendance(string username);
int countMyAttendance(string username);
int send_leave_application(string username);
int delay();
void title();
void date();

void date(){
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout<<"Date:"<<tm.tm_mday<<"/"<<tm.tm_mon+1<<"/"<<tm.tm_year +1900<<endl; 
}

void title(){
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t|Student Attendance Management System|"<<endl;
    cout<<"-------------------------------------------------------"<<endl<<endl;
}

int delay()
{
for(int i = 0; i<3; i ++)
{
	cout<<"Saving Records ..."<<endl;
    for(int ii = 0; ii<20000; ii ++)
    {
    	for(int iii = 0; iii<20000; iii ++);
    }
}
cout<<"Exiting Now ..."<<endl;
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<20000; ii ++) { 
     for(int iii = 0; iii<20000; iii ++);
    } 
}
return 0;
}

int adminView(){	
int goBack = 0;
while(1)
{
system("cls");
cout<<" 1. Register a Student"<<endl;
cout<<" 2. Delete All students registered"<<endl;
cout<<" 3. Delete student data"<<endl;
cout<<" 4. Check List of Student registered"<<endl;
cout<<" 0. Go Back <- "<<endl;
int choice;

cout<<" Enter you choice: ";
cin>>choice;

switch(choice)
{
	case 1: registerStudent();break;  
	case 2: deleteAllStudents(); break;
	case 3: deleteStudentData(); break;
	case 4: checkListOfStudentsRegistered(); break;
	case 0: goBack = 1;break;
    default: cout<<endl<<" Invalid choice. Enter again "<<endl;
    getchar();           	
}   

if(goBack == 1)
{
break; //break the loop
}     
}
return 0;
}

int studentLogin(){
system("cls");
    system("cls");
	title();
    cout<<"---------- Student Login ---------"<<endl<<endl;
    studentView();
    return 0;
}

int adminLogin()
{
system("cls");
cout<<"\n --------- Admin Login --------"<<endl;	
string username;
string password;
cout<<" Enter username : ";
cin>>username;
cout<<" Enter password : ";
cin>>password;

if(username=="admin" && password=="jecrc@123") 
{
    adminView();
    getchar();	
    delay();
}   
else
{
cout<<" Error ! Invalid Credintials.."<<endl;	
cout<<" Press any key for main menu "<<endl;
getchar();
getchar();
}
return 0;
}

int checkStudentCredentials(string username, string password)
{
// read file line by line & check if username-password.dat exist?
// if it exsist return 1 else 0

ifstream read;
read.open("db.dat");

if (read) {
// The file exists, and is open for input
int recordFound = 0;
string line;
string temp = username + ".dat";
while(getline(read, line)) {
	if(line == temp)
	{
		recordFound = 1;
		break;
	}
}

if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}   		
}

int deleteStudentData()
{
	system("cls");
    DIR *di;
    char *ptr1, *ptr2;
    char name[20];
    int retn;
    int status;
    struct dirent *dir;
    di = opendir("."); // specify the directory name
    if (di)
    {
        cout << "\n---- Lsit of Students with data ----\n"<<endl;

        while ((dir = readdir(di)) != NULL)
        {
            ptr1 = strtok(dir->d_name, ".");
            ptr2 = strtok(NULL, ".");
            if (ptr2 != NULL)
            {
                retn = strcmp(ptr2, "dat");
                if (retn == 0)
                {
                    cout << "\n";
                    printf("%s", ptr1);
                    cout << ".dat";
                    cout << endl;
                }
            }
        }
        closedir(di);
    }

    cout << "\n\nEnter the name of the file which is to be deleted: ";
    cin >> name;
    status = remove(name);
    if (status == 0)
        cout << "\nFile Deleted Successfully!"<<endl;
    else
    {
        cout << "\nError Occurred!"<<endl;
        cout << "\nPlease enter a valid data"<<endl;
    }

    cout << "\nPlease press any key to continue ..."<<endl;
    getchar();
    getchar();
    return 0;
}

int send_leave_application(string username){
    char add[1000];
    cout<<"Write your application here: "<<endl;
    getchar();
    cin.getline(add,1000);
    time_t now = time(0);
    tm*ltm = localtime(&now);
    ofstream out;
    out.open("application.dat",ios::app);
    out<<add<<"->"<<ltm->tm_mday<<"/"<<1+ ltm->tm_mon<<"/"<<1900 + ltm->tm_year<<"->"<<username<<endl;
    out.close();
    cout<<"Application successfully sent!!"<<endl;
    cout<<"Please press any key to continue..."<<endl;
    getchar();
    return 0; 
}

int studentView(){
string username, password;

cout<<" Enter username : ";
cin>>username;

cout<<" Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();	
   return 0;
} 

int goBack = 0;
while(1)
{
system("cls");

cout<<" 1. Mark Attendance of Today "<<endl;
cout<<" 2. Count my Attendance"<<endl;
cout<<" 3. Submit Leave Application"<<endl;
cout<<" 0. Go Back <- "<<endl<<endl;
int choice;

cout<<" Enter you choice: ";
cin>>choice;

switch(choice)
{
	case 1: markMyAttendance(username); break;
	case 2: countMyAttendance(username); break;
	case 3: send_leave_application(username); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();           	
}   

if(goBack == 1)
{
break; //break the loop
}     
	
}
   
}

int deleteAllStudents()
{
    cout << "\n\n --- Deleting all registered students!! --- \n\n";
    cout << "Deleting";
    delay();
    remove("db.dat");
    remove("application.dat");

    cout << "\n\nAll registered Students deleted successfully...";
    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

int markMyAttendance(string username)
{
cout<<"\n---- Marking Attendance for today! ----"<<endl<<endl;
    int total_lines = 0;
    string filename = username + ".dat";
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        // Format the date and time
        // Write the record to the file
        time_t T = time(NULL);
        struct tm tm = *localtime(&T);
        outFile<<"Date:"<<tm.tm_mday<<"/"<<tm.tm_mon+1<<"/"<<tm.tm_year +1900<<endl;
        outFile << "Present" << endl;
        // Close the file
        outFile.close();

        cout << "Attendance marked successfully for " << endl;
    } else {
        cout << "Error opening the file: " << filename << endl;
    }
    cout<<"Please press any key to continue..."<<endl;
    getchar();
    getchar();
    return 0;
} 

int countMyAttendance(string username)
{
cout<<"---- Counting Attendance !! ----"<<endl<<endl;
    int total_lines = 0;
    string filename = username + ".dat";
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string line;
        int totalAttendance = 0;

        while (getline(inFile, line)) {
            // Assuming each line in the file corresponds to one attendance record
            if( line == "Present"){
                totalAttendance++;}
        }

        inFile.close();

        cout << "Total attendance: " << totalAttendance << endl;
    } else {
        cout << "Error opening the file: " << filename << endl;
    }
    cout << "\nPlease press any key to continue ..."<<endl;
    getchar();
    getchar();
    return 0;

}

int checkListOfStudentsRegistered(){
cout<<"\n - Check List of Student Registered by Username-- ";	

//check if record already exist..
ifstream read;
read.open("db.dat");
if(read)
{   int recordFound =0; 
    string line;
    while(getline(read, line)) {
    	char name[100];
    	strcpy(name, line.c_str());
    	char onlyname[100];
    	strncpy(onlyname, name, (strlen(name) - 4));
    	cout<<" \n " << onlyname;
    }
     read.close();        
}
else
{
cout<<"\n No Record found :(";
}
	
cout<<"\n Please any key to continue..";
getchar(); getchar();
return 0;
}

int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, f_name, l_name, username, password, rollno, address, father, mother;
    
    cout<<"\n Enter  Name : ";     
	cin>>f_name>>l_name;
    name = f_name + l_name;
    cout<<"\n Enter Username : ";     
	cin>>username;
    cout<<"\n Enter password : ";     
	cin>>password;
    cout<<"\n Enter rollno : ";     
	cin>>rollno;
    getchar();
    
    char add[100];
    cout<<"\n Enter address : ";     
	cin.getline(add, 100);
    cout<<"\n Enter father : ";     
	cin>>f_name>>l_name;
    father = f_name + l_name;
    cout<<"\n Enter mother : ";     
	cin>>f_name>>l_name;
    mother = f_name + l_name;
    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) {
    	if(line == username + ".dat" )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n Username already Register. Please choose another username ";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	
	out1<<username<<"\n"; 	
	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	
	out1<<add<<"\n"; 	
	out1<<father<<"\n";
	out1<<mother<<"\n";
	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

int main(int argc, char** argv) {
	
while(1)
{
	system("cls");
	cout<<"\n Attendance Management System \n";
	cout<<"-------------------------------------\n\n";
	
	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";
	
	cout<<"0. Exit\n";
	int choice;
	
	cout<<"\n Enter you choice: ";
	cin>>choice;
	
	switch(choice)
	{
	case 1: studentLogin(); break;
	case 2: adminLogin(); break;
	case 0: 
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
             }

     	   }
            break;
             	 
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
	}   		        

}
	
return 0;
}    