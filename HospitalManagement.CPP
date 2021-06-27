/*
 ************************************************
 *						*
 *        HEADER FILES USE IN THE PROGRAM       *
 *						*
 ************************************************
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#define max 100
/*
 ************************************************
 *                                              *
 *	   STRUCTURE USED IN THE PROGRAM        *
 *                                              *
 ************************************************
 */
struct hospital             //a structure named hospital
{
	char name[25];
	char sex[6];
	int age;
	char add_date[20];
	char address[50];
	char phone[20];
	char bed[20];
	char doc[25];
	char disease[20];
	char doc_phone[20];
	char release[20];
	char doc_address[50];
	char unit[10];
}patient[max];	      //object for the structure
/*
 *************************************************
 *                                               *
 *         FUNCTIONS USED IN THE PROGRAM         *
 *                                               *
 *************************************************
 */
void search(int a)        //a function to search patient's record
{
	fstream infile;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	infile.seekg(ios::beg);
	char name11[20];
	int found=0;
	for(int i=0;i<80;i++)
		cout<<'=';
	cout<<"\n\nt\tSEARCH PATIENT'S RECORD\n\n";
	for(i=0;i<80;i++)
		cout<<'=';
	cout<<"\n\t\tEnter Name of the patient to be searched:";
	gets(name11);
	for(int t=0;t<a;t++)
	{
		infile.read((char*)&patient[t],sizeof(patient[t]));
		if(strcmpi(name11,patient[t].name)==0)
		{
			cout<<"Patient Name:"<<patient[t].name;
			cout<<"\nAge:"<<patient[t].age;
			cout<<"\nSex:"<<patient[t].sex;
			cout<<"\nAddress:"<<patient[t].address;
			cout<<"\nTelephone No:"<<patient[t].phone;
			cout<<"\nDisease:"<<patient[t].disease;
			cout<<"\nAddimision Data:"<<patient[t].add_date;
			cout<<"\nDate of Release:"<<patient[t].release;
			cout<<"\nBed No:"<<patient[t].bed;
			cout<<"\nUnit:"<<patient[t].unit;
			cout<<"\nDoctor Name:"<<patient[t].doc;
			cout<<"\nDoctor Ph No:"<<patient[t].doc_phone;
			cout<<"\nDoctor Address:"<<patient[t].doc_address<<endl;
			cout<<"Press any key to return to main menu..."<<endl;
			found++;
			getch();
			clrscr();
		}
	}
	if(found==0)
	{
		cout<<"Sorry, data not found!!"<<endl;
		cout<<"Press any key to return to main menu..."<<endl;
		getch();
	}
	getch();
	infile.close();
}
void addition(int &i)       //a function to add patient's record
{
	fstream infile;
	int n;
	infile.open("HOSPITAL.DAT",ios::in|ios::binary);
	for(int a=0;a<80;a++)
		cout<<'=';
	cout<<"\n\n\t\tADDITION OF A PATIENT'S RECORD\n\n";
	for(a=0;a<80;a++)
		cout<<'=';
	cout<<"\n\tEnter the information:\n\n";
	cout<<" Name:";
	gets(patient[i].name);
	cout<<"Sex (M/F):";
	cin>>patient[i].sex;
	cout<<"Age:";
	cin>>patient[i].age;
	cout<<"Addmission Date of the Patient:";
	gets(patient[i].add_date);
	cout<<"Phone Number of the Patient:";
	gets(patient[i].phone);
	cout<<"Bed Number:";
	cin>>patient[i].bed;
	cout<<"DOCTOR's Name:";
	gets(patient[i].doc);
	cout<<"Disease:";
	gets(patient[i].disease);
	cout<<"DOCTOR's Phone Number:";
	gets(patient[i].doc_phone);
	cout<<"Date of Release from the Hospital:";
	gets(patient[i].release);
	cout<<"DOCTOR's Address:";
	gets(patient[i].doc_address);
	cout<<"Unit:";
	gets(patient[i].unit);
	cout<<"\tStoring on to the file...";
	infile.write((char*)&patient[i],sizeof(patient[i]));
	infile.close();
	cout<<"\n\t\tPress any key to return to the main menu"<<endl;
	getch();
}
int menu()          //a menu function to display the menu
{
	int a;
	clrscr();
	for(int i=0;i<80;i++)
		cout<<'=';
	cout<<"\n\n\t\tWELCOME TO OUR HOSPITAL PATIENT MANAGEMENT SYSTEM\n\n";
	for(i=0;i<80;i++)
		cout<<'=';
	cout<<" \t\t************** MENU ************** \n\n";
	cout<<" 1.Addition of new Record\n";
	cout<<" 2.Display the List\n";
	cout<<" 3.Delete a record\n";
	cout<<" 4.Searching the record using patient name\n";
	cout<<" 5.Disease wise report\n";
	cout<<" 6.Doctor wise report \n";
	cout<<" 7.Modify the record \n";
	cout<<" 8.Quit\n";
	for(i=0;i<80;i++)
		cout<<'=';
	cout<<"\nYour Option:";
	cin>>a;
	return(a);
}
void modi(int a)         //a function to modify patient's record
{
	fstream infile;
	fstream tfile;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	infile.seekg(ios::beg);
	char name1[30];
	int i,found=0;
	tfile.open("temp1.dat",ios::out|ios::binary);
	for(int b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tMODIFICATION OF A PATIENT'S RECORD\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\tEnter the Name of the patient to modified:";
	gets(name1);
	for(int t=0;t<a;t++)
	{
		infile.read((char*)&patient[t],sizeof(patient[t]));
		if(strcmpi(name1,patient[t].name)!=0)
		{
			tfile.write((char*)&patient[t],sizeof(patient[t]));
			i=t;
			found++;
		}
	}
	if(found==0)
	{
		cout<<"\n\n\t\tPATIENT'S RECORD NOT FOUND!";
		cout<<"\n\t\tPress any key to return to main menu..";
		getch();
	}
	infile.close();
	tfile.close();
	remove("HOSPITAL.DAT");
	rename("temp1.dat","HOSPITAL.DAT");
	infile.open("HOSPITAL.DAT",ios::app|ios::out|ios::binary);
	clrscr();
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tENTER PATIENT'S DETAILS FOR MODIFICATION\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\tEnter the following information:\n";
	cout<<"Name:";
	gets(patient[i].name);
	cout<<"Sex (M/F):";
	cin>>patient[i].sex;
	cout<<"Age:";
	cin>>patient[i].age;
	cout<<"Addmission Date of the Patient:";
	gets(patient[i].add_date);
	cout<<"Phone Number of the Patient:";
	gets(patient[i].phone);
	cout<<"Bed Number:";
	cin>>patient[i].bed;
	cout<<"DOCTOR's Name:";
	gets(patient[i].doc);
	cout<<"Disease:";
	gets(patient[i].disease);
	cout<<"DOCTOR's Phone Number:";
	gets(patient[i].doc_phone);
	cout<<"Date of Release from the Hospital:";
	gets(patient[i].release);
	cout<<"DOCTOR's Address:";
	gets(patient[i].doc_address);
	cout<<"Unit:";
	gets(patient[i].unit);
	cout<<"\n\t\tPATIENT'S RECORD IS MODIFIED!"<<endl;
	getch();
	infile.write((char*)&patient[i],sizeof(patient[i]));
	infile.close();
}
void disease(int a)      //a function to display the patient's records
{                       // according to the disease
	fstream infile;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	infile.seekg(ios::beg);
	char name1[30];
	int found=0;
	for(int b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tDISPLAY RECORDS BY DISEASE\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t Enter Disease of the Patient:";
	gets(name1);
	for(int t=0;t<a;t++)
	{
	infile.read((char*)&patient[t],sizeof(patient[t]));
	if(strcmpi(name1,patient[t].disease)==0)
	{
		cout<<"Record "<<t+1<<" of "<<a;
		cout<<"\nPatient Name:"<<patient[t].name;
		cout<<"\nAge:"<<patient[t].age;
		cout<<"\nSex:"<<patient[t].sex;
		cout<<"\nAddress:"<<patient[t].address;
		cout<<"\nTelephone No:"<<patient[t].phone;
		cout<<"\nDisease:"<<patient[t].disease;
		cout<<"\nAddimision Data:"<<patient[t].add_date;
		cout<<"\nDate of Release:"<<patient[t].release;
		cout<<"\nBed No:"<<patient[t].bed;
		cout<<"\nUnit:"<<patient[t].unit;
		cout<<"\nDoctor Name:"<<patient[t].doc;
		cout<<"\nDoctor Ph No:"<<patient[t].doc_phone;
		cout<<"\nDoctor Address:"<<patient[t].doc_address;
		found++;
		getch();
		clrscr();
	}
      }
      if(found==0)
      {
	cout<<"No records found with disease ";
	puts(name1);
	getch();
      }
	infile.close();
}
void doc(int a)           //a function to display the patient's records
{                         //according to doctor's name
	fstream infile;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	infile.seekg(ios::beg);
	char name1[30];
	int found=0;
	for(int b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tDISPLAY THE RECORDS BY DOCTOR'S NAME\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t Enter Doctor's Name:";
	gets(name1);
	for(int t=0;t<a;t++)
	{
		infile.read((char*)&patient[t],sizeof(patient[t]));
		if(strcmpi(name1,patient[t].doc)==0)
		{
			cout<<"Record "<<t+1<<" of "<<a<<endl;
			cout<<"Patient Name:"<<patient[t].name;
			cout<<"\nAge:"<<patient[t].age;
			cout<<"\nSex:"<<patient[t].sex;
			cout<<"\nAddress:"<<patient[t].address;
			cout<<"\nTelephone No:"<<patient[t].phone;
			cout<<"\nDisease:"<<patient[t].disease;
			cout<<"\nAddimision Data:"<<patient[t].add_date;
			cout<<"\nDate of Release:"<<patient[t].release;
			cout<<"\nBed No:"<<patient[t].bed;
			cout<<"\nUnit:"<<patient[t].unit;
			cout<<"\nDoctor Name:"<<patient[t].doc;
			cout<<"\nDoctor Ph No:"<<patient[t].doc_phone;
			cout<<"\nDoctor Address:"<<patient[t].doc_address;
			found++;
			getch();
			clrscr();
		}
	}
	if(found==0)
	{
		cout<<"No record is found with doctor's name ";
		puts(name1);
		getch();
	}
	infile.close();
}
void delete1(int a)        //function to delete a patient's record
{
	fstream infile;
	fstream tfile;
	char name1[30];
	int found=0;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	tfile.open("temp1.dat",ios::out|ios::binary);
	infile.seekg(ios::beg);
	for(int b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tDELETION OF A RECORD\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\tEnter the Name of the patient whose record is to be deleted:";
	gets(name1);
	for(int t=0;t<a;t++)
	{
		infile.read((char*)&patient[t],sizeof(patient[t]));
		if(strcmpi(name1,patient[t].name)!=0)
		{
			tfile.write((char*)&patient[t],sizeof(patient[t]));
			found++;
		}
	}
	if(found==0)
	{
		cout<<"\n\n\t\tPATIENT'S RECORD NOT FOUND!"<<endl;
		cout<<"Press any key to return to main menu..."<<endl;
	}
	infile.close();
	tfile.close();
	remove("HOSPITAL.DAT");
	rename("temp1.dat","HOSPITAL.DAT");
	getch();
}
void display(int a)     //a function to display all records
{
	fstream infile;
	int found=0;
	infile.open("HOSPITAL.DAT",ios::in|ios::out|ios::binary);
	for(int b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t\tDISPLAY THE RECORDS\n\n";
	for(b=0;b<80;b++)
		cout<<'=';
	cout<<"\n\n\t Reading From the File:\n"<<endl;
	infile.seekg(ios::beg);
	for(int t=0;t<a;t++)
	{
		infile.read((char*)&patient[t],sizeof(patient[t]));
		cout<<" Record Number "<<(t+1)<<" out of "<<a<<" records";
		cout<<"\n===============================\n";
		cout<<"Patient Name:"<<patient[t].name;
		cout<<"\nAge:"<<patient[t].age;
		cout<<"\nSex:"<<patient[t].sex;
		cout<<"\nAddress:"<<patient[t].address;
		cout<<"\nTelephone No:"<<patient[t].phone;
		cout<<"\nDisease:"<<patient[t].disease;
		cout<<"\nAddimision Data:"<<patient[t].add_date;
		cout<<"\nDate of Release:"<<patient[t].release;
		cout<<"\nBed No:"<<patient[t].bed;
		cout<<"\nUnit:"<<patient[t].unit;
		cout<<"\nDoctor Name:"<<patient[t].doc;
		cout<<"\nDoctor Ph No:"<<patient[t].doc_phone;
		cout<<"\nDoctor Address:"<<patient[t].doc_address;
		found++;
		getch();
		clrscr();
	}
	if(found==0)
	{
		clrscr();
		cout<<"No Records entered!!"<<endl;
		cout<<"Press any key to reutrn to main menu..."<<endl;
		getch();
	}
	infile.close();
}
/*
 ******************************************
 *                                        *
 *      MAIN FUNCTION OF THE PROGRAM      *
 *                                        *
 ******************************************
 */
void main()
{
	clrscr();
	int n,a=0;
	do
	{
		n=menu();
		 switch(n)
		{
			case 1 : clrscr();
				   addition(a);
				   a++;
				   break;
			case 2 : clrscr();
				   display(a);
				   break;
			case 3 : clrscr();
				   delete1(a);
				   display(a);
				   break;
			case 4 : clrscr();
				   search(a);
				   break;
			case 5 : clrscr();
				   disease(a);
				   break;
			case 6 : clrscr();
				   doc(a);
				   break;
			case 7 : clrscr();
				   modi(a);
				   break;
			case 8 : exit(0);
		}
	}while(n!=8);
	getch();
}