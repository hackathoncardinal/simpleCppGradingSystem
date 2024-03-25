#include <iostream>
#include <conio.h>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <stdexcept>
using namespace std;
using std::runtime_error;
using std::exception;

void throwexception();
void throwexception()
{
	try{
		throw exception();
	}
	catch(exception &)
	{
		throw;
	}
}
void wrong() throw (runtime_error)
{
	throw runtime_error("runtime_error");
}

void editmenu();
int change_personal_info(int i);
void access_denied();
void access_granted();
void database();
int head2(int x);
void end();
int findID(int x);
int view_all_records(int r);
double shortquiz();
double longquiz();
void head();
void intro();
void menu();
int RemoveStudent(int x);
int create(int x);
int prelim(int z);
int midterm(int z);
int semifinal(int z);
int final(int x);
int diplay(int z);
int editP(int z);
double formulaB(int z);
double calculatePrelim(int z);
double calculateMidterm(int z);
double calculateSemiFinal(int z);
double calculateFinal(int z);

struct Prelim
{
	double Quiz;
	double Longquiz;
	double Project;
	double Assignment;
	double Character;
	double Prelim;
	double Grade;
}P[100];
struct Midterm
{
	double Quiz;
	double Longquiz;
	double Project;
	double Assignment;
	double Character;
	double Prelim;
	double Grade;
}M[100];
struct Semifinal
{
	double Quiz;
	double Longquiz;
	double Project;
	double Assignment;
	double Character;
	double Prelim;
	double Grade;
}SF[100];
struct Final
{
	double Quiz;
	double Longquiz;
	double Project;
	double Assignment;
	double Character;
	double Prelim;
	double Grade;
}F[100];
struct Student_info
{
	int id;
	string name;
	string surname;
	string course;
	string gender;
}info[100];
struct formula_B
{
	double OverallGrade;
}formula_B[100];

int main()
{			
database();
	int c=1,choice;
	bool t = false,t3 = false,q=true;
	int id,id_valid[9]={201400433,20140054,201400397,13107,201400113,20140094,201400279,201400162,123};
	char ask,name1[10];
	string name_valid[9]={"benjie","lasam","ryan","aina","lerica","mico","jeryl","ronald","admin"};
do
{	system("COLOR F3");
cout<<"\4====================== SYSTEM SECURITY Logic Formolation =====================\4\n";
cout<<"Caution ::  Avoid Combination Letter And Numbers in ID# Section And Grading Area\n\n";
cout<<"\nSign In Your ID Number \n";
cout<<"Enter Your ID number : ";
cin>>id;
if(id == cin.eof())
{
}

cout<<"\nEnter User : ";
cin>>name1;
for(int a=0 ; a < 9 ; a++)
{
	if(id_valid[a] == id )
	{
		cout<<"Your ID# "<<id_valid[a]<<" is valid";
		
		if(name_valid[a] == name1)
		{
			t=true;
			cout<<"\nHello Mr./Mrs. Now you can acess this Program\n\n";
			access_granted();
			getche();
			intro();
		}else{
			cout<<"\n\nYour ID Number Is Valid But your Name : "<<name_valid[a];
			cout<<"  Is Not Match To your ID number\n\n";
			cout<<"Press Any Key To Continue ...";
			getche();
		}
	}        
}
if(t == false )
{system("CLS");	access_denied();
	cout<<"\n\nYour IDnumber : "<<id<<" is Invalid to Acess this Program \n\n";
	cout<<"\nDo you Want to Try again And Continue This Program";
	cout<<"\n Yes Or No <Y/N> :";
	again:
	cin>>ask;
	switch(ask)
	{
		case 'Y':
		case 'y':break;
		case 'N':
		case 'n':t3=true;break;
		default:cout<<"Please Enter Correct Input < Y/N >or<y/n> : ";
		{
		goto again;
		}
	}
	
}			system("COLOR 07");system("CLS");
}while(t==false && t3 == false);
if(t == false)
{
	end();
}
while(t == true)
{menu(); system("COLOR F3");
	cout<<"Enter Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:create(c);c++;break;
		case 2:findID(c);break;
		case 3:view_all_records(c);break;
		case 4:editP(c);break;
		case 5:	system("CLS");
				system("COLOR F0");
				end();
				getche();
				return EXIT_SUCCESS;break;
		case 6:RemoveStudent(c);break;
		default:system("CLS");cout<<"Try Again !\n";
	}
}
	getche();
}

int create(int x)
{system("CLS");			system("COLOR F9");
cout<<"Caution ::  Avoid Combination Letter And Numbers in ID# Section And Grading Area\n";
	if(x == 0)
	cout<<setw(40)<<"Start Create Data \n";
	else
	cout<<setw(40)<<"Start Add Data \n";
	cout<<"\nEnter Your ID# : ";
	cin>>info[x].id;
	cout<<"Enter Your Name : ";
	cin>>info[x].name;
	cout<<"Surname : ";
	cin>>info[x].surname;
	cout<<"Enter Your Gender :";
	cin>>info[x].gender;
	cout<<"Enter Your Course :";
	cin>>info[x].course;
	cout<<"_________________________________________________\n\n";
	prelim(x);
	midterm(x);
	semifinal(x);
	final(x);
return 0;
}
int prelim(int z)
{			system("COLOR F1");
	bool  t = true;
	double all=0;
	cout<<"\n\4==================== Prelim ====================\4\n";
P[z].Longquiz=longquiz();
P[z].Quiz=shortquiz();
cout<<"***************************************************\n";
cout<<"Long Quiz : "<<P[z].Longquiz<<endl;
cout<<"Short Quiz : "<<P[z].Quiz<<endl;
while(t == true)
{
cout<<"Enter Assignment : ";
cin>>P[z].Assignment;
	if(P[z].Assignment >= 65 && P[z].Assignment <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false )
{
cout<<"Enter Character : ";
cin>>P[z].Character;
	if(P[z].Character >= 65 && P[z].Character <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t==true)
{
cout<<"Enter Project : ";
cin>>P[z].Project;
if(P[z].Project >= 65 && P[z].Project <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false)
{
cout<<"Prelim : ";
cin>>P[z].Prelim;
if(P[z].Prelim >= 65 && P[z].Prelim <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
all=calculatePrelim(z);
P[z].Grade=all;
cout<<"\nPrelimGrade : "<<all<<endl;
formula_B[z].OverallGrade;
return 0;
}
double calculatePrelim(int z)
{
	 double cal;
cal = (P[z].Longquiz *.10) + (P[z].Quiz *.10) + (P[z].Assignment *.10) + (P[z].Character *.10) + (P[z].Project * .10) + (P[z].Prelim * .50);
	return cal;
}
int midterm(int z)
{			system("COLOR F5");
	bool  t = true;
	double all=0;
	cout<<"\n\4==================== Midterm ====================\4\n";
	M[z].Longquiz=longquiz();
	M[z].Quiz=shortquiz();
cout<<"***************************************************\n";
cout<<"Long Quiz : "<<M[z].Longquiz<<endl;
cout<<"Short Quiz : "<<M[z].Quiz<<endl;
while(t == true)
{
cout<<"Enter Assignment : ";
cin>>M[z].Assignment;
	if(M[z].Assignment >= 65 && M[z].Assignment <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false )
{
cout<<"Enter Character : ";
cin>>M[z].Character;
	if(M[z].Character >= 65 && M[z].Character <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t==true)
{
cout<<"Enter Project : ";
cin>>M[z].Project;
if(M[z].Project >= 65 && M[z].Project <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false)
{
cout<<"Midterm : ";
cin>>M[z].Prelim;
if(M[z].Prelim >= 65 && M[z].Prelim <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
all=calculateMidterm(z);
M[z].Grade=all;
cout<<"\nMidtermGrade : "<<all<<endl;
return 0;
}
double calculateMidterm(int z)
{
	double cal;
cal = (M[z].Longquiz *.10) + (M[z].Quiz *.10) + (M[z].Assignment *.10) + (M[z].Character *.10) + (M[z].Project * .10) + (M[z].Prelim * .50);
	return cal;
}
int semifinal(int z)
{			system("COLOR F1");
	bool  t = true;
	double all=0;
	cout<<"\n\4==================== SemiFinal ====================\4\n";
		SF[z].Longquiz=longquiz();
	SF[z].Quiz=shortquiz();
cout<<"***************************************************\n";
cout<<"Long Quiz : "<<SF[z].Longquiz<<endl;
cout<<"Short Quiz : "<<SF[z].Quiz<<endl;
while(t == true)
{
cout<<"Enter Assignment : ";
cin>>SF[z].Assignment;
	if(SF[z].Assignment >= 65 && SF[z].Assignment <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false )
{
cout<<"Enter Character : ";
cin>>SF[z].Character;
	if(SF[z].Character >= 65 && SF[z].Character <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t==true)
{
cout<<"Enter Project : ";
cin>>SF[z].Project;
if(SF[z].Project >= 65 && SF[z].Project <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false)
{
cout<<"SemiFinal : ";
cin>>SF[z].Prelim;
if(SF[z].Prelim >= 65 && SF[z].Prelim <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
all=calculateSemiFinal(z);
SF[z].Grade=all;
cout<<"\nSemiFinalGrade : "<<all<<endl;
return 0;
}
double calculateSemiFinal(int z)
{
	double cal;
cal = (SF[z].Longquiz *.10) + (SF[z].Quiz *.10) + (SF[z].Assignment *.10) + (SF[z].Character *.10) + (SF[z].Project * .10) + (SF[z].Prelim * .50);
	return cal;
}
int final(int z)
{			system("COLOR F3");
	bool  t = true;
	double all=0;
	cout<<"\n\4==================== Final ====================\4\n";
F[z].Longquiz=longquiz();
F[z].Quiz=shortquiz();
cout<<"*****************************************\n";
cout<<"Long Quiz : "<<F[z].Longquiz<<endl;
cout<<"Short Quiz : "<<F[z].Quiz<<endl;
while(t == true)
{
cout<<"Enter Assignment : ";
cin>>F[z].Assignment;
	if(F[z].Assignment >= 65 && F[z].Assignment <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false )
{
cout<<"Enter Character : ";
cin>>F[z].Character;
	if(F[z].Character >= 65 && F[z].Character <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t==true)
{
cout<<"Enter Project : ";
cin>>F[z].Project;
if(F[z].Project >= 65 && F[z].Project <= 100)
	{t=false;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
while(t == false)
{
cout<<"Final : ";
cin>>F[z].Prelim;
if(F[z].Prelim >= 65 && F[z].Prelim <= 100)
	{t=true;}
	else cout<<"Try Again! 65 t0 100 % only \n";
}
all=calculateFinal(z);
F[z].Grade=all;
cout<<"\nFinalGrade : "<<all<<endl;
formulaB(z);
return 0;
}
double calculateFinal(int z)
{
	double cal;
cal = (F[z].Longquiz *.10) + (P[z].Quiz *.10) + (F[z].Assignment *.10) + (F[z].Character *.10) + (F[z].Project * .10) + (F[z].Prelim * .50);
	return cal;
}
void intro()
{system("CLS");
	system("COLOR 0E");
	cout<<"\n\n\t\t\t\tWELCOME";
	cout<<endl<<"\t ";
	for(int a =0 ; a <= 11 ; a++)
		cout<<"\4\4\4\4\4";
		cout<<endl;
		cout<<"\t\2\t\1\1\1\1    \1   \1\1\1\1\1  \1    \1\1   \1\1 \1\1\1\1\1 \1   \1          \2\n";
		cout<<"\t\2\t\1   \1  \1 \1    \1   \1 \1   \1 \1 \1 \1 \1      \1 \1           \2  \n";
		cout<<"\t\2\t\1   \1 \1\1\1\1\1   \1  \1\1\1\1\1  \1  \1  \1 \1\1\1     \1            \2 \n";
		cout<<"\t\2\t\1   \1\1     \1  \1 \1     \1 \1     \1 \1      \1 \1           \2\n";
		cout<<"\t\2\t\1\1\1\1\1       \1 \1\1       \1\1     \1 \1\1\1\1\1 \1   \1          \2\n";
		cout<<"\t\2\t          GRADING SYSTEM PROJECT                     \2\n\t ";
		for(int a =0 ; a <= 11 ; a++)
		cout<<"\4\4\4\4\4";
		cout<<endl;
		cout<<"\nPress Any Key To Begin This Program ...";
		getche();
		system("COLOR 07");
		system("CLS");
}
int view_all_records(int r)
{system("CLS");system("COLOR F0");
cout<<"\t       view_all_records ID# and Name of the Student"<<endl;
	int display;
	bool l=false;
	cout<<"\n ALL ID# RECORDS  Of The Student \n";
	head();
	for(display=0 ; display <= r ; display++)
{
			if(info[display].id != 0)
			{
			l=true;
			cout<<"> "<<info[display].id;
			cout<<setw(15)<<"> "<<info[display].name;	
			cout<<setw(15)<<"> ";cout<<info[display].surname;
			if(formulaB(display) >= 75)
				{
					cout<<setw(15)<<"PASSED "<<formula_B[display].OverallGrade<<"%"<<endl;
				}
			else
				{
					cout<<setw(15)<<"FAILED "<<formula_B[display].OverallGrade<<"%"<<endl;
				}
			}
}

	if(l == false)
		{
			cout<<"This list is already Empty. \n";
		}
	cout<<"\nPress Any Key To Continue... ";
getche();
}
double longquiz()
{
	int l=1,sum2=0,ave2=0,lq;
	double longquiz;
	
	cout<<"Enter Long Quiz 0 to 20 Item Only\n";
while(l <= 2)
{
	cout<<"Long Quiz"<<l<<": ";
	cin>>lq;
	if(lq >= 0 && lq <= 20)
	{
		l++;
		sum2+=lq;
	}
	else
	{
		cout<<"Try Again !\n 0 to 20 Item Only :\n";
	}
}
ave2=sum2 / 2;
	switch(ave2)
	{
		case 1:
		case 2:
		case 3:longquiz=71;break;
		case 4:
		case 5:longquiz=72;break;
		case 6:
		case 7:longquiz=73;break;
		case 8:
		case 9:longquiz=74;break;
		case 10:longquiz=75;break;
		case 11:longquiz=76;break;
		case 12:longquiz=78;break;
		case 13:longquiz=80;break;
		case 14:longquiz=82;break;
		case 15:longquiz=84;break;
		case 16:longquiz=85;break;
		case 17:longquiz=87;break;
		case 18:longquiz=90;break;
		case 19:longquiz=95;break;
		case 20:longquiz=100;break;
		default:longquiz=70;break;
	}
	return longquiz;
}
double shortquiz()
{
	int q=1,sum=0,quiz,ave=0;
	double all=0,QuizGrade;
	cout<<"\nEnter Quiz Grade ";
	cout<<"0 to 10 Item Only\n";
	while(q <= 5)
	{
	cout<<"quiz"<<q<<": ";
		cin>>quiz;
		if(quiz >= 0 && quiz <= 10)
		{
			q++;
			sum+=quiz;
		}
		else
		{
			cout<<"Try Again !\n 0 to 10 Item Only\n";
		}
	}
ave = sum / 5;
	switch(ave)
	{
		case 1: QuizGrade=71;break;
		case 2: QuizGrade=72;break;
		case 3: QuizGrade=73;break;
		case 4: QuizGrade=74;break;
		case 5: QuizGrade=75;break;
		case 6: QuizGrade=80;break;
		case 7: QuizGrade=85;break;
		case 8: QuizGrade=90;break;
		case 9: QuizGrade=95;break;
		case 10: QuizGrade=100;break;
		default: QuizGrade=70;break;
	}
	return QuizGrade;
}
double formulaB(int z)
{
	formula_B[z].OverallGrade = (P[z].Grade*.20) + (M[z].Grade*.20) + (SF[z].Grade*.30) + (F[z].Grade*.30);
//	cout<<formula_B[z].OverallGrade;
	return formula_B[z].OverallGrade;
}
void head()
{
	cout<<"_________________________________________________________________\n";
	cout<<"Student_ID#\t\tName\t\tSurName\t\tRemarks\n";
	cout<<"_________________________________________________________________\n";
}
void menu()
{
	cout<<"\t\1====================== BATCH 4 Program =======================\1\n";
	cout<<"     \1+++++\2---------\3-------\3-------\3MENU\3-----\3-----\3-------------\2+++++\1\n";
	cout<<"\t\1======================== Grading System ======================\1\n";
	cout<<"\t-->Press 1 to Create or Add Students "<<endl;
	cout<<"\t-->Press 2 to Search Id & see All Records of the Student"<<endl;
	cout<<"\t-->Press 3 to view_all_records ID# and Name of the Student"<<endl;
	cout<<"\t-->Press 4 to Search id & Edit Personal_info Records"<<endl;
	cout<<"\t-->Press 5 to EXIT The Program"<<endl;
	cout<<"\tOPTIONAL\n";
	cout<<"\t-->Press 6 to Remove Student in the Data"<<endl;
}
int findID(int x)
{
system("CLS");
cout<<"\t\tSearch Id & see All Records of the Student"<<endl;
system("COLOR 0B"); 
	bool l=false;
	int z;
	double rating;
	cout<<"\nPLEASE Enter ID Number Of The Student : ";
	cin>>z;
	for(int i=0 ; i <= x; i++ )
	{
		if(info[i].id == z && info[i].id != 0)
		{	l=true;
			cout<<"\n\4\2\1============================= RESULT =============================\1\2\4"<<endl;
			cout<<"Your Name : "<<info[i].name;
			cout<<"\nYour ID#  : "<<info[i].id;
			cout<<"\nSurname   : "<<info[i].surname<<endl;
			cout<<"Gender    : "<<info[i].gender<<endl;
			cout<<"Course    : "<<info[i].course<<endl;
			cout<<"\n\n########################## 1st Semester Grade 2014-2015 ######################\n";
			head2(i);
			cout<<"Prelim Grade : "<<P[i].Grade<<endl;
			cout<<"Midtern Grade : "<<M[i].Grade<<endl;
			cout<<"Semifinal Grade : "<<SF[i].Grade<<endl;
			cout<<"Finals Grade : "<<F[i].Grade<<endl;
			//cout<<"\nOfficial Grade : "<<formula_B[i].OverallGrade<<endl;
			
			
	if(formulaB(i) <= 100 && 97 <= formulaB(i))
	rating=1.00;
	if(formulaB(i) <= 96 && 95 <= formulaB(i))
	rating=1.25;
	if(formulaB(i) <= 94 && 92 <= formulaB(i))
	rating=1.50;
	if(formulaB(i) <=91  && 89 <= formulaB(i))
	rating=1.75;
	if(formulaB(i) <= 88 && 86 <= formulaB(i))
	rating=2.00;
	if(formulaB(i) <= 85 && 83 <= formulaB(i))
	rating=2.25;
	if(formulaB(i) <= 82 && 80 <= formulaB(i))
	rating=2.50;
	if(formulaB(i) <= 79 && 76 <= formulaB(i))
	rating=2.75;
	if(formulaB(i) == 75)
	rating=3.00;
	if(formulaB(i)< 75)
	rating=5.00;
			
			if(formulaB(i) >= 75)
				{
				//	cout<<"\1\1\1Remark : PASSED\n";
					cout<<"\n\n "<<info[i].id<<" "<<info[i].surname<<"  "<<info[i].name<<" write the final of \n";
					cout<<"*"<<formula_B[i].OverallGrade<<"percent* with the rating of * ";printf("%.2f",rating);
					cout<<"* has *passed* \nthe subject of formulation in \n1st sem 2014 - 2015 *MR. All SABIAGA*\n\n";
				}else
				{
					cout<<"Remark : FAILED \n";
				}
			cout<<"\nPress Any Key To Continue... ";
			getche();
			system("COLOR 07");                                           
		}
	}
	/*logic formulation

prelim grade = 90
midterm = 90
prefinal = 90
final = 90

*std no* *std name* write the final of *90percent* with the rating of *1.25* has *passed* the subject of formulation in 1st sem 2014-2015 *MR. AL SABIAGA*
*/
	if(l == false)
	{
		cout<<"Sorry !!!No Records Found!\n";
		cout<<"Press Any Key to continue . . .\n";
		getche();
		system("COLOR FC");
	}
	system("CLS");
return 0;
}
void end()
{
		cout<< "\n\t\t\t\a !@! GOODBYE !@!\n\t\t\3\3\3Thanks For Using This Program\3\3\3\n\t\t\t\1\1\1\1Created By Benj\1\1\1\1\n";
		cout<<setw(45)<<"Evening Batch 4 room 201"<<endl;
		cout<<"\nPROGRAMERS\n";
		cout<<">Benjie Tawi\n";
		cout<<">Danilo Lasam\n";
		cout<<">Lerica Sacido\n";
		cout<<">Mico Ocasla\n";
		cout<<">Aina Ayo\n";
}
int editP(int z)
{system("CLS");system("COLOR F8");
bool l=false,w=true;
int id,editchoice;
cout<<"Enter ID number of The Student to Edit ;";
cin>>id;
	for(int i = 0 ; i < z ; i++)
		{
			if(info[i].id == id && info[i].id != 0)
			{	l=true;
				do{editmenu();
					cout<<"Enter Your Choice :";
					cin>>editchoice;
					switch(editchoice)
					{
						case 1:change_personal_info(i);break;
						case 2:
	system("CLS");
	cout<<"Old Records\n";
	cout<<"\n_________________________________ PRELIM ______________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  PrelimExam  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<P[i].Quiz<<setw(12)<<P[i].Longquiz<<setw(11)<<P[i].Assignment<<setw(12)<<P[i].Project<<setw(10)<<P[i].Character<<setw(10)<<P[i].Prelim<<setw(14)<<P[i].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
						prelim(i);break;
						case 3:
	system("CLS");
	cout<<"Old Records\n";
	cout<<"\n_________________________________ MEDTERM _____________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  MidtermExam OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<M[i].Quiz<<setw(12)<<M[i].Longquiz<<setw(11)<<M[i].Assignment<<setw(12)<<M[i].Project<<setw(10)<<M[i].Character<<setw(10)<<M[i].Prelim<<setw(14)<<M[i].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
						midterm(i);break;
						case 4:
	system("CLS");
	cout<<"Old Records\n";
	cout<<"\n_________________________________ SEMI-FINAL __________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  Pre-final  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<SF[i].Quiz<<setw(12)<<SF[i].Longquiz<<setw(11)<<SF[i].Assignment<<setw(12)<<SF[i].Project<<setw(10)<<SF[i].Character<<setw(10)<<SF[i].Prelim<<setw(14)<<SF[i].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
						semifinal(i);break;
						case 5:
	system("CLS");
	cout<<"Old Records\n";
	cout<<"\n_________________________________ FINAL _______________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  FinalExam  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<F[i].Quiz<<setw(12)<<F[i].Longquiz<<setw(11)<<F[i].Assignment<<setw(12)<<F[i].Project<<setw(10)<<F[i].Character<<setw(10)<<F[i].Prelim<<setw(14)<<F[i].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
						final(i);
						break;
						case 6:w=false;break;
						default:cout<<"\nInvalid Input !!\n";
					}
				}while (w == true);
			}
		}
	if(l == false)
	{
		cout<<"Sorry !!!No Records Found! To Edit\n";
	}
	else
	{
	cout<<"Edit Complete\n";

			cout<<"D o n e   E d i t i n g\n";
			cout<<"\n\nPress An Key to Continue ...\n";
			getche();
	}
return 0;
}
int RemoveStudent(int x)
{system("CLS");system("COLOR FC");
	bool l = false;
	int id;
	cout<<"Enter ID number of The Student to To DELETE : ";
	cin>>id;
	for(int i = 0 ; i <= x ; i++)
		{
			if(info[i].id == id)
			{	 l=true;
				printf("This ID# %d Has been Deleted \n",info[i].id);
				info[i].id = 0;
			
			}
		}
		if(l == false)
	{
		cout<<"Sorry !!!No Records Found! To Delete\n";
	}
		cout<<"\nPress Any Key To Continue... ";
			getche();
		return 0;
}
int head2(int x)
{                      
	cout<<"\n_________________________________ PRELIM ______________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  PrelimExam  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<P[x].Quiz<<setw(12)<<P[x].Longquiz<<setw(11)<<P[x].Assignment<<setw(12)<<P[x].Project<<setw(10)<<P[x].Character<<setw(10)<<P[x].Prelim<<setw(14)<<P[x].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"\n_________________________________ MEDTERM _____________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  MidtermExam OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<M[x].Quiz<<setw(12)<<M[x].Longquiz<<setw(11)<<M[x].Assignment<<setw(12)<<M[x].Project<<setw(10)<<M[x].Character<<setw(10)<<M[x].Prelim<<setw(14)<<M[x].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"\n_________________________________ SEMI-FINAL __________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  Pre-final  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<SF[x].Quiz<<setw(12)<<SF[x].Longquiz<<setw(11)<<SF[x].Assignment<<setw(12)<<SF[x].Project<<setw(10)<<SF[x].Character<<setw(10)<<SF[x].Prelim<<setw(14)<<SF[x].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"\n_________________________________ FINAL _______________________________________\n";
	cout<<"ShortQuiz  LongQuiz    Assignment  Project  Character  FinalExam  OverALLGrade\n";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<F[x].Quiz<<setw(12)<<F[x].Longquiz<<setw(11)<<F[x].Assignment<<setw(12)<<F[x].Project<<setw(10)<<F[x].Character<<setw(10)<<F[x].Prelim<<setw(14)<<F[x].Grade<<endl;
	cout<<"-------------------------------------------------------------------------------\n";
	return 0;
}
void database()
{
	info[0].id=201400433;
	info[0].gender = "Male";
	info[0].surname = "Tawi";
	info[0].name = "Benjie";
	info[0].course="BSIT-1";
	P[0].Quiz = 80;
	P[0].Longquiz = 95;
	P[0].Assignment = 98;
	P[0].Project = 89;
	P[0].Character =99;
	P[0].Prelim = 95;
P[0].Grade =calculatePrelim(0);
	M[0].Quiz = 78;
	M[0].Longquiz = 80; 
	M[0].Assignment = 90;
	M[0].Project =87;
	M[0].Character =78;
	M[0].Prelim  = 91;
M[0].Grade =calculateMidterm(0);
	SF[0].Quiz = 75;
	SF[0].Longquiz = 78;
	SF[0].Assignment = 89;
	SF[0].Project =78; 
	SF[0].Character =76;
	SF[0].Prelim = 78;
SF[0].Grade =calculateSemiFinal(0);
	F[0].Quiz = 76;
	F[0].Longquiz =95;
	F[0].Assignment= 88;
	F[0].Project = 79;
	F[0].Character = 90;
	F[0].Prelim = 76;
F[0].Grade = calculateFinal(0);
formulaB(0);
}

void access_denied()
{
	system("COLOR 0C");
	cout<<"\a\t ";
	for(int a =0 ; a <= 17 ; a++)
	cout<<"\1\1\1";
	cout<<"\n";
	cout<<"\t\1     \2     \2\2\2\2   \2\2\2\2  \2\2\2\2\2  \2\2\2\2   \2\2\2\2       \1\1\1\1\1\1"<<endl;
	cout<<"\t\1    \2 \2   \2    \2 \2    \2 \2     \2      \2            \1\1\1\1\1"<<endl;
	cout<<"\t\1   \2\2\2\2\2  \2      \2      \2\2\2    \2\2\2    \2\2\2          \1\1\1\1"<<endl;
	cout<<"\t\1  \2     \2 \2    \2 \2    \2 \2         \2      \2          \1\1\1"<<endl;
	cout<<"\t\1 \2       \2 \2\2\2\2   \2\2\2\2  \2\2\2\2\2 \2\2\2\2   \2\2\2\2            \1\1"<<endl;
	cout<<"\t\1\t\t\2\2\2\2  \2\2\2\2\2 \2   \2 \2\2\2\2\2 \2\2\2\2\2 \2\2\2\2     \1"<<endl;
	cout<<"\t\1\t\t\2   \2 \2     \2\2  \2   \2   \2     \2   \2    \1"<<endl;
	cout<<"\t\1\t\t\2   \2 \2\2\2   \2 \2 \2   \2   \2\2\2   \2   \2    \1"<<endl;
	cout<<"\t\1\t\t\2   \2 \2     \2  \2\2   \2   \2     \2   \2    \1"<<endl;
	cout<<"\t\1\t\t\2\2\2\2  \2\2\2\2\2 \2   \2 \2\2\2\2\2 \2\2\2\2\2 \2\2\2\2     \1"<<endl<<"\t ";
	for(int a =0 ; a <= 17 ; a++)
	cout<<"\1\1\1";
}
void access_granted()
{	system("COLOR 0A");
	cout<<"\t ";
		for(int a =0 ; a <= 17 ; a++)
	cout<<"\1\1\1";
	cout<<"\n";
	cout<<"\t\1     \2     \2\2\2\2   \2\2\2\2  \2\2\2\2\2  \2\2\2\2   \2\2\2\2       \1\1\1\1\1\1"<<endl;
	cout<<"\t\1    \2 \2   \2    \2 \2    \2 \2     \2      \2            \1\1\1\1\1"<<endl;
	cout<<"\t\1   \2\2\2\2\2  \2      \2      \2\2\2    \2\2\2    \2\2\2          \1\1\1\1"<<endl;
	cout<<"\t\1  \2     \2 \2    \2 \2    \2 \2         \2      \2          \1\1\1"<<endl;
	cout<<"\t\1 \2       \2 \2\2\2\2   \2\2\2\2  \2\2\2\2\2 \2\2\2\2   \2\2\2\2            \1\1"<<endl;
	cout<<"\t\2\t \1\1\1 \1\1\1\1      \1     \1   \1 \1\1\1\1\1 \1\1\1\1\1 \1\1\1\1    \2"<<endl;
	cout<<"\t\2\t\1    \1   \1    \1 \1    \1\1  \1   \1   \1     \1   \1   \2"<<endl;
	cout<<"\t\2\t\1 \1\1 \1\1\1\1    \1\1\1\1\1   \1 \1 \1   \1   \1\1\1   \1   \1   \2"<<endl;
	cout<<"\t\2\t\1  \1 \1  \1   \1     \1  \1  \1\1   \1   \1     \1   \1   \2"<<endl;
	cout<<"\t\2\t \1\1  \1   \1 \1       \1 \1   \1   \1   \1\1\1\1\1 \1\1\1\1    \2"<<endl<<"\t ";
	for(int a =0 ; a <= 17 ; a++)
	cout<<"\2\2\2";
	cout<<"\n\n";
	cout<<"Press Any key to Continue ..."<<endl;
	getche();
}

void editmenu()
{cout<<"Integer Only In The choices\n";
	cout<<"\t\1====================== --------------- =======================\1\n";
	cout<<"     	        E D I T I N G          S E C T I O N\n";
	cout<<"\t\1====================== --------------- =======================\1\n";
	cout<<"\t-->Press 1 to Change Name & Surname "<<endl;
	cout<<"\t-->Press 2 to Change Prelim"<<endl;
	cout<<"\t-->Press 3 to Change MidTerm"<<endl;
	cout<<"\t-->Press 4 to Change Semi-Final"<<endl;
	cout<<"\t-->Press 5 to Change Final"<<endl;
	cout<<"\tOPTIONAL\n";
	cout<<"\t-->Press 6 to Done Editing"<<endl;
}

int change_personal_info(int i)
{
	cout<<"\nStart Edit\n";
				cout<<"Enter Your Name : ";
				cin>>info[i].name;
				cout<<"Surname : ";
				cin>>info[i].surname;
	cout<<"Edit Complete\n";
			cout<<"\n\2\1New Data\1\2 : "<<endl;
			cout<<"Your ID# : "<<info[i].id;
			cout<<"\nName : "<<info[i].name;
			cout<<"\nSurname : "<<info[i].surname<<endl;
}                      
