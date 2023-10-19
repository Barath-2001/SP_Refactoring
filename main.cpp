#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<Windows.h>
#include<iomanip>
using namespace std;
//prototyping...
void Menu();
void Display_cars();
//using template input validation...
template<class T>
void Validation(T& a) {
while (cin.fail()) {
cin.clear();
cin.ignore(INT_MAX, '\n');
cout << "Enter Asked Variable : ";
cin >> a;
}
}
//class for cars' Information...
class cars {
private:
string car_name;
string car_number;
string colour;
int model;
double price_per_hour;
double price_per_day;
public:
cars() {
price_per_day = 00.0;
price_per_hour = 00.0;
}
string car() const {
return car_name;
}
string cnum() const {
return car_number;
}
string col() const {
return colour;
}
int mod() const {
return model;
}
double pph() const {
return price_per_hour;
}
double ppd() const {
return price_per_day;
}
void SetData(string cname, string cnum, string col, int mod, double p, double pd) {
car_number = cnum;
car_name = cname;
model = mod;
colour = col;
price_per_hour = p;
price_per_day = pd;
}

string carname() const {
return car_name;
}
};
//class for person's Information...
//who want to rent a car...
class Person :public cars {
private:
string name;
string address;
string CNIC;
string Number;
public:
string n() const {
return name;
}
string add() const {
return address;
}
string Cnic() const {
return CNIC;
}
string no() const {
return Number;
}
void SetData(string n, string ad, string cn, string num) {
name = n;
address = ad;
CNIC = cn;
Number = num;
}
};
void Person_Info(Person& p);
//Information of booked cars...
//only for admins...
class Bookedcar :public cars {
private:
int booked;
public:
Bookedcar() {
booked = 0;
}
void Add() {
booked += 1;
}
void SetBooked(const cars& c, const Person& p) const  {
ofstream Write;
Write.open("Cars Info.txt", ios::app);
if (Write.is_open()) {
Write << "BOOKED CAR : " << endl;
Write << "================" << endl << endl;
Write << "\t\tCAR INFO : " << endl;
Write << "\t\t========== " << endl;
Write << "\t\t\t Car Name : " << c.carname() << "\n\t\t\t Car Model : " << c.mod() << "\n\t\t\t Car Number : " << c.cnum() << "\n\t\t\t Car Color : " << c.col() << "\n\n";
Write << "\t\tCUSTOMER INFO : \n";
Write << "\t\t===============\n";
Write << "\t\t\t Name : " << p.n() << "\n\t\t\t CNIC : " << p.Cnic() << "\n\t\t\t Phone Number : " << p.no() << "\n\t\t\t Address : " << p.add() << endl << endl;
}
}
void GetBooked() const  {
ifstream Read;
Read.open("Cars Info.txt", ios::in);
char data;
if (Read.is_open()) {
while (!Read.eof()) {
Read >> noskipws >> data;
cout << data;
}
Read.close();
}
else {
cout << "File Not Found ! \n";
}
}
};
//calculation of total rent...
//depending on rent days etc...
class TotalRent :public cars {
private:
double total;
int days;
double hours;

public:
TotalRent() {
total = hours = 0;
days = 0;
}
int ret_d() const {
return days;
}
double ret_h() const {
return hours;
}
void SetData1(int d) {
days = d;
}
void SetData2(double h) {
hours = h;
}
double Cal(const cars& obj) {
total = obj.ppd() * days;
return total;
}
double Cal2(const cars& obj) {
total = obj.pph() * hours;
return total;
}
double  GetTotal() const{
return total;
}
};
//new function prototype... Qion k classes pass kr ra hn... aur class ka pehle define hna xruri h...
void Show_Rent(cars& c, Person& p, TotalRent& r, int check);
//main...
int main() {
cars Info;
Person data;
Bookedcar booked;
TotalRent Rent;

int choice ;
int use;
do {
Menu();
cout << "\t Enter 1 for admin \n\t Enter 2 for user  \n\t Enter 3 to Exit.\n";
do {
cin >> use;
Validation(use);
if (use < 1 || use>3) {
cout << "Enter 1 to 3 : ";
}
} while (use < 1 ||  use > 3);

system("cls");

string username;
string pass;
int a = 0;
int bookment;
int nod;
double noh;
int checking;
//switch
switch (use) {
case 1:
Menu();
do {
cout << "Enter your User name ( Minimum 4 Letters... ) : ";
cin >> username;
if (!(username.size() > 3)) {
cout << "Error ! : " << endl;
}
} while (!(username.size() > 3));
do {
cout << "Enter Password ( Minimum 4 Letters... ) : ";
cin >> pass;
if (!(pass.size() > 3)) {
cout << "Error ! : " << endl;
}
} while (!(pass.size() > 3));
system("cls");
Menu();
if (username == "admin") {
a++;
}
if (pass == "pass") {
a++;
}
if (a == 2) {
cout << "Loading the data of Customers who Rented the cars from us... ";
Sleep(4500);
system("cls");
Menu;
cout << endl;
booked.GetBooked();
cout << "Press Any Key to Logout or Go to MAIN menu : ";
}
else {
cout << "Username or Password is Incorrect !!\n\n";
cout << "Press Any Key to go to main menu : ";
}
system("pause");
break;
case 2:
Menu();
Display_cars();
cout << "Enter one of the given Number : ";
do {
cin >> choice;
Validation(choice);
if (choice < 1 || choice>5) {
cout << "Enter Number from 1 to 5 : ";
}
} while (choice < 1 || choice>5);
system("cls");
switch (choice) {
case 1:
Info.SetData("Tesla", "STP-3080", "GREY", 2017, 700, 5000);
Menu();
cout << "\t Enter 1 to BOOK\n\t Enter 2 to exit. \n ";
do {
cin >> bookment;
Validation(bookment);
if (bookment < 1 || bookment>2) {
cout << "Enter 1 or 2 : ";
}
} while (bookment < 1 || bookment>2);
if (bookment == 1) {
booked.Add();
system("cls");
Menu();
cout << "Enter Your Information : \n";
cout << "=========================\n";
Person_Info(data);

booked.SetBooked(Info, data);
system("cls");
Menu();
cout << "Enter 1 if you want to Rent A Car for some Days \n";
cout << "Enter 2 if you want to Rent A Car for some Hours \n\n";
do {
cin >> checking;
Validation(checking);
if (checking != 1 && checking != 2) {
cout << "Error ! : " << endl;
}
} while (checking != 1 && checking != 2);
system("cls");
Menu();
if (checking == 1) {
cout << "Enter Number of Days you want to Rent A Car : ";
cin >> nod;
Validation(nod);
while (nod < 1) {
cout << "Enter Positive Number of Days : ";
cin >> nod;
Validation(nod);
}
Rent.SetData1(nod);
Rent.Cal(Info);
}
else if (checking == 2) {
cout << "Enter Number of Hours you want to Rent A Car : ";
cin >> noh;
Validation(noh);
while (noh < 1) {
cout << "Enter Positive Number of Hours : ";
cin >> noh;
Validation(noh);
}
Rent.SetData2(noh);
Rent.Cal2(Info);
}

system("cls");
Menu();

cout << "\t\t\t\tCalculating and Saving Rent...";
Sleep(3000);
system("cls");
cout << "\t\t\t\t\t\tDisplaying Total Rent...";
Sleep(1000);
system("cls");
Menu();
cout << endl;
Show_Rent(Info, data, Rent, checking);
}
else {
break;
}
break;
case 2:
Info.SetData("Prado", "RIX-6878", "BLACK", 2015, 800, 8000);
Menu();
cout << "\t Enter 1 to BOOK\n\t Enter 2 to exit. \n ";
do {
cin >> bookment;
Validation(bookment);
if (bookment < 1 || bookment>2) {
cout << "Enter 1 or 2 : ";
}
} while (bookment < 1 || bookment>2);
if (bookment == 1) {
booked.Add();
system("cls");
Menu();
cout << "Enter Your Information : \n";
cout << "=========================\n";
Person_Info(data);
booked.SetBooked(Info, data);
system("cls");
Menu();

cout << "Enter 1 if you want to Rent A Car for some Days \n";
cout << "Enter 2 if you want to Rent A Car for some Hours \n\n ";
do {
cin >> checking;
Validation(checking);
if (checking != 1 && checking != 2) {
cout << "Error ! : " << endl;
}
} while (checking != 1 && checking != 2);
system("cls");
Menu();
if (checking == 1) {
cout << "Enter Number of Days you want to Rent A Car : ";
cin >> nod;
Validation(nod);
while (nod < 1) {
cout << "Enter Positive Number of Days : ";
cin >> nod;
Validation(nod);
}
Rent.SetData1(nod);
Rent.Cal(Info);
}
else if (checking == 2) {
cout << "Enter Number of Hours you want to Rent A Car : ";
cin >> noh;
Validation(noh);
while (noh < 1) {
cout << "Enter Positive Number of Hours : ";
cin >> noh;
Validation(noh);
}
Rent.SetData2(noh);
Rent.Cal2(Info);
}

system("cls");
Menu();
cout << "\t\t\t\tCalculating and Saving Rent...";
Sleep(3000);
system("cls");
cout << "\t\t\t\t\t\tDisplaying Total Rent...";
Sleep(1000);
system("cls");
Menu();
Show_Rent(Info, data, Rent, checking);
}
break;
case 3:
Info.SetData("Hillux", "MIK-2724", "WHITE", 2013, 900, 10000);
Menu();
cout << "\t Enter 1 to BOOK\n\t Enter 2 to exit. \n ";
do {
cin >> bookment;
Validation(bookment);
if (bookment < 1 || bookment>2) {
cout << "Enter 1 or 2 : ";
}
} while (bookment < 1 || bookment>2);
if (bookment == 1) {
booked.Add();
system("cls");
Menu();
cout << "Enter Your Information : \n";
cout << "=========================\n";
Person_Info(data);
booked.SetBooked(Info, data);
system("cls");
Menu();
cout << "Enter 1 if you want to Rent A Car for some Days \n";
cout << "Enter 2 if you want to Rent A Car for some Hours \n\n";
do {
cin >> checking;
Validation(checking);
if (checking != 1 && checking != 2) {
cout << "Error ! : " << endl;
}
} while (checking != 1 && checking != 2);
system("cls");
Menu();
if (checking == 1) {
cout << "Enter Number of Days you want to Rent A Car : ";
cin >> nod;
Validation(nod);
while (nod < 1) {
cout << "Enter Positive Number of Days : ";
cin >> nod;
Validation(nod);
}
Rent.SetData1(nod);
Rent.Cal(Info);
}
else if (checking == 2) {
cout << "Enter Number of Hours you want to Rent A Car : ";
cin >> noh;
Validation(noh);
while (noh < 1) {
cout << "Enter Positive Number of Hours : ";
cin >> noh;
Validation(noh);
}
Rent.SetData2(noh);
Rent.Cal2(Info);
}

system("cls");
Menu();
cout << "\t\t\t\tCalculating and Saving Rent...";
Sleep(3000);
system("cls");
cout << "\t\t\t\t\t\tDisplaying Total Rent...";
Sleep(1000);
system("cls");
Menu();
Show_Rent(Info, data, Rent, checking);
}
break;
case 4:
Info.SetData("City", "RIM-5498", "BLUE", 2011, 1000, 8000);
Menu();
cout << "\t Enter 1 to BOOK\n\t Enter 2 to exit. \n ";
do {
cin >> bookment;
Validation(bookment);
if (bookment < 1 || bookment>2) {
cout << "Enter 1 or 2 : ";
}
} while (bookment < 1 || bookment>2);
if (bookment == 1) {
booked.Add();
system("cls");
Menu();
cout << "Enter Your Information : \n";
cout << "=========================\n";
Person_Info(data);
booked.SetBooked(Info, data);
system("cls");
Menu();
cout << "Enter 1 if you want to Rent A Car for some Days \n";
cout << "Enter 2 if you want to Rent A Car for some Hours \n\n ";
do {
cin >> checking;
Validation(checking);
if (checking != 1 && checking != 2) {
cout << "Error ! : " << endl;
}
} while (checking != 1 && checking != 2);
system("cls");
Menu();
if (checking == 1) {
cout << "Enter Number of Days you want to Rent A Car : ";
cin >> nod;
Validation(nod);
while (nod < 1) {
cout << "Enter Positive Number of Days : ";
cin >> nod;
Validation(nod);
}
Rent.SetData1(nod);
Rent.Cal(Info);
}
else if (checking == 2) {
cout << "Enter Number of Hours you want to Rent A Car : ";
cin >> noh;
Validation(noh);
while (noh < 1) {
cout << "Enter Positive Number of Hours : ";
cin >> noh;
Validation(noh);
}
Rent.SetData2(noh);
Rent.Cal2(Info);
}

system("cls");
Menu();
cout << "\t\t\t\tCalculating and Saving Rent...";
Sleep(3000);
system("cls");
cout << "\t\t\t\t\t\tDisplaying Total Rent...";
Sleep(1000);
system("cls");
Menu();
Show_Rent(Info, data, Rent, checking);
}
break;
case 5:

break;
}
}
system("cls");
} while (use != 3);

system("pause");
}
//Menu to show Car rental system Logo...
//at any time...
void Menu() {
cout << "\t\t\t=================================================\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|        -----------------------------          |\n";
cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
cout << "\t\t\t|        -----------------------------          |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t|                                               |\n";
cout << "\t\t\t=================================================\n\n\n";
}
void Person_Info(Person & p) {
bool check = false;
string fname;
string lname;
string name;
string Number;
string nic;
string address;
int a = 0;

do {
a = 0;
cout << "Enter Your First Name ( Minimum 3 Letters... ) : ";
cin.ignore();
getline(cin, fname);
for (int i = 0; i < fname.size(); i++) {
if (!(isalpha(fname[i]))) {
a++;
}
else {
check = false;
}
}

if (a != 0 || !(fname.size()>=3)) {
cout << "Error ! : " << endl;
check = true;
}
} while (!(fname.size() >= 3) || check == true); // first name

do {
a = 0;
cout << "Enter Your last Name ( Minimum 3 Letters... ) : ";
getline(cin, lname);
for (int i = 0; i < lname.size(); i++) {
if (!(isalpha(lname[i]))) {
a++;
}
else {
check = false;
}
}

if (a != 0 || !(lname.size()>=3)) {
cout << "Error ! : " << endl;
check = true;
}
} while (!(lname.size() >= 3) || check == true); // last name
name = fname + " " + lname;

do {
a = 0;
cout << "Enter your CNIC ( 13 Digits without Dashes... ) : ";
getline(cin, nic);
for (int i = 0; i < nic.size(); i++) {
if (!(isdigit(nic[i]))) {
a++;
}
else {
check = false;
}
}
if (a != 0 || nic.size()!=13) {
cout << "Error ! : " << endl;
check = true;
}
} while (!(nic.size() == 13) || check == true); // CNIC

do {
a = 0;
cout << "Enter your Mobile Number ( 11 digits without Dashes... ) : ";
cin >> Number;
for (int i = 0; i < Number.size(); i++) {
if (!(isdigit(Number[i]))) {
a++;
}
else {
check = false;
}
}
if (a != 0 || Number.size() != 11) {
cout << "Error ! : " << endl;
check = true;
}
} while (!(Number.size() == 11) || check == true); // Number

do {
cout << "Enter you Present Address ( Full & Minimum 6 Letters or Digits... ) : ";
cin.ignore();
getline(cin, address);
} while (!(address.size() > 5)); // Address

p.SetData(name, address, nic, Number); // Setting values to person class setdata function
}
//showing the available cars...
void Display_cars() {
cout << "\t\tPlease Select a Car" << endl;
cout << "\t\tEnter 1 for Tesla 2017." << endl;
cout << "\t\tEnter 2 for Prado 2015." << endl;
cout << "\t\tEnter 3 for Hillux 2017." << endl;
cout << "\t\tEnter 4 for City 2017." << endl;
cout << "\t\tEnter 5 to Exit." << endl;
cout << endl;
}
void Show_Rent(const cars & c,const Person & p, const TotalRent & r, int check) {
cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
cout << "\t\t ///////////////////////////////////////////////////////////" << endl;
cout << "\t\t | Invoice No. :" << "------------------|" << setw(18) << "#Cnb81353" << " |" << endl;
cout << "\t\t | Customer Name:" << "-----------------|" << setw(18) << p.n() << " |" << endl;
cout << "\t\t | Car Name  :" << "--------------------|" << setw(18) << c.car() << " |" << endl;
cout << "\t\t | Car Model :" << "--------------------|" << setw(18) << c.mod() << " |" << endl;
cout << "\t\t | Car No. :" << "----------------------|" << setw(18) << c.cnum() << " |" << endl;
if (check == 1) {
cout << "\t\t | Number of days :" << "---------------|" << setw(18) << r.ret_d() << " |" << endl;
}
else if (check == 2) {

cout << "\t\t | Number of hours :" << "--------------|" << setw(18) << r.ret_h() << " |" << endl;
}
cout << "\t\t | Your Rental Amount is :" << "--------|" << setw(18) << r.GetTotal() << " |" << endl;
cout << "\t\t | Caution Money :" << "----------------|" << setw(18) << "00" << " |" << endl;
cout << "\t\t | Advanced :" << "---------------------|" << setw(18) << "00" << " |" << endl;
cout << "\t\t ________________________________________________________" << endl;
cout << "\n";
cout << "\t\t | Total Rental Amount is :" << "-------|" << setw(18) << r.GetTotal() << " |" << endl;
cout << "\t\t ________________________________________________________" << endl;
cout << "\t\t # This is a computer generated invoce and it does not" << endl;
cout << "\t\t require an authorised signture #" << endl;
cout << " " << endl;
cout << "\t\t ///////////////////////////////////////////////////////////" << endl;
cout << "\t\t You are advised to pay up the amount before due date." << endl;
cout << "\t\t Otherwise penelty fee will be applied" << endl;
cout << "\t\t ///////////////////////////////////////////////////////////" << endl;
cout << endl << endl;
cout << "\t\t\t\t\t\t\t\t\t\tThanks for Visiting us... \n";
system("pause");
system("cls");
cout << "\t\t\t\t\t\t Loading Main Menu... ";
Sleep(1500);
system("cls");
}
