#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int bill_no = 1;

class hostel
{
private:
    int room_no;
    char name[30];
    char address[50];
    char mobile_no[12];
    int roll_no;
    char course[10];
    char branch[10];
    char semester[10];
    char batch[10];

public:
    void main_menu();
    void book_room();
    void search_bar();
    void roll_search();
    void search_roomno();
    void Show_Alloted_Rooms();
    void edit_menu();
    int check(int);
    void modify();
    void delete_room();
    void bill_generate();
    bool check_digit(string x);

} hos;


// Menu for Hotel Management System
void hostel::main_menu()
{
    int option;
    while (option != 6)
    {

        system("cls");
        cout << "\n\t\t****************************************************************************************************************************************";
        cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
        cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
        cout << "\n\t\t****************************************************************************************************************************************";
        cout << "\n\t\t*                                                    * MAIN MENU *                                                                     *";
        cout << "\n\t\t****************************************************************************************************************************************";
        cout << "\n\n\n\t\t\t1.Book A Room";
        cout << "\n\t\t\t2.Display All Alloted Rooms";
        cout << "\n\t\t\t3.Search Room";
        cout << "\n\t\t\t4.Edit/Delete Menu";
        cout << "\n\t\t\t5.Generate Student Bill";
        cout << "\n\t\t\t6.Exit";
        cout << "\n\n\t\t\tEnter Option you want to choose: ";
        cin >> option;

        switch (option)
        {
        case 1:
            book_room();
            break;

        case 2:
            Show_Alloted_Rooms();
            break;

        case 3:
            search_bar();
            break;

        case 4:
            edit_menu();
            break;

        case 5:
            bill_generate();
            break;
        case 6:
            exit(0);

        default:
        {
            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to   continue....!!";
            getch();
        }
        }
    }
}

void hostel::book_room()
{

    system("cls");
    int r, n, flag;
    char ch;
    ofstream fout("Record.dat", ios::app);
    cout << "\n\t\t****************************************************************************************************************************************";
    cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
    cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
    cout << "\n\t\t============================================= Room List is as follows: =================================================================";
    cout << "\n\n\t\t\t\t\t\t Total no. of Rooms present:  \t   700   ";
    cout << "\n\t\t\t\t\t   -------------------------------------------------";
    cout << "\n\t\t\t\t\t   |     Types of room         |    Room Number    |";
    cout << "\n\t\t\t\t\t   -------------------------------------------------";
    cout << "\n\t\t\t\t\t   | FOR BTECH 2ND YEAR             |\t001 - 500  |";
    cout << "\n\t\t\t\t\t   | FOR MCA   1ST YEAR             |\t501 - 600  |";
    cout << "\n\t\t\t\t\t   | FOR MSC   1ST YEAR             |\t601 - 700  |";
    cout << "\n \t\t\t\t\t  -------------------------------------------------";
top:
    cout << "\n\n\t\t\t\t\t Enter the room you want to book:- ";
    cin >> r;
    if (r == 0 || r > 700)
    {
        cout << "\n\t\t\t Room number invalid....!!";
        goto top;
    }
    else
    {
        flag = check(r);
        if (flag)
        {
            cout << "\n Sorry..!!! Room is already booked";
            goto top;
        }
        else
        {
            char space[10], p[10];
            room_no = r;
            cout << "\n\t\t\tThe room is available.........!!" << endl;
            cout << "\n\n\t\t---------------------- enter your details: ----------------------------" << endl;
            gets(space);
            cout << " Name: ";
            gets(name);
            cout << " Course: ";
            gets(course);
            cout << " Branch: ";
            gets(branch);
            cout << " Semester: ";
            gets(semester);
            cout << " Address: ";
            gets(address);
            cout << " Roll number: ";
            cin >> roll_no;
            cout << " mobile_no Number: ";
            cin >> p;
            if (check_digit(p) == true)
            {
                strcpy(mobile_no, p);
                cout << endl;
            }
            else
            {
                cout << "\t\t mobile_no Number you entered is not valid";
                cout << "\n Please enter your mobile_no number again: ";
                cin >> mobile_no;
            }
            cout << "\n\n\t\t Do you want to save the data? (y/n)";
            cin >> ch;
            if (ch == 'y')
            {
                fout.write((char *)this, sizeof(hostel));
                cout << "\n Room booked successfully...!!!";
                cout << "\n You can get your bill from the main menu.........";
                fout.close();
            }
            else
            {
                cout << "Data not entered.. " << endl;
                fout.close();
            }
        }
        cout << "\n Press any key to continue.....!!";
        getch();
        fout.close();
    }
}




void hostel ::search_bar()
{
    system("cls");
    int opt;
    do
    {
        system("cls");
        cout << "\n\t\t****************************************************************************************************************************************";
        cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
        cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
        cout << "\n==================================================== * SEARCH MENU * ===================================================";
        cout << "\n\n 1.Search details by roll no.";
        cout << "\n 2.Search details by room no.";
        cout << "\n 3.Go to Main menu .";
        cout << "\n\n Enter your choice: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            roll_search();
            break;

        case 2:
            search_roomno();
            break;

        case 3:
            main_menu();
            break;
        default:
        {
            cout << "\n Wrong Choice.....!!";
            cout << "\n Press any key to continue....!!!";
            getch();
        }
        }
    } while (opt != 3);
}

void hostel::search_roomno()
{
    int r, flag = 0;
    ifstream fin("Record.dat", ios::in);
    system("cls");
    cout << "\n\t\t****************************************************************************************************************************************";
    cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
    cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
    cout << "\n==================================================== * SEARCH MENU * ===================================================";
    cout << "\n\n Enter room no.to get the student`s details :- ";
    cin >> r;

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(hostel));
        if (room_no == r)
        {
            cout << "\n Student Details";
            cout << "\n ---------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n  Roll Number : " << roll_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Semester: " << semester;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;
            cout << "\n mobile_no number: " << mobile_no;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\n Sorry Room you entered found vacant....!!";
    }

    cout << "\n\n Press any key to continue....!!";
    getch();
    fin.close();
}

void hostel ::roll_search()
{
    int ur, u, flag = 0, temp = 0;
    ifstream fin("Record.dat", ios::in);
    system("cls");
    cout << "\n\t\t****************************************************************************************************************************************";
    cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
    cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
    cout << "\n\t\t========================================================== * SEARCH MENU * =============================================================";
num:
    cout << "\n\n Enter roll no.to get the student`s details :- ";
    cin >> ur;
    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(hostel));
        if (roll_no == ur)
        {
            cout << "\n Student Details";
            cout << "\n ---------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Roll Number : " << roll_no;
            cout << "\n Semester: " << semester;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;
            flag = 1;
            break;
        }
        else if (flag == 0)
        {
            cout << "\n Sorry Room not found....!!";
        }
    }
    cout << "\n\n Press any key to continue....!!";
    getch();
    fin.close();
}



void hostel ::Show_Alloted_Rooms()
{
    system("cls");
    cout << "\n\t\t****************************************************************************************************************************************";
    cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
    cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
    cout << "\n\t\t====================================================== LIST OF ALLOTED ROOMS: ===========================================================";
    ifstream fin("Record.dat", ios::in);
    cout << "\n\n Room No.\tName\t\tRollNO\t\tAddress\t\t\tmobile_no No \t\tSemester\t\tCourse\t\tBranch\n";

    while (fin.read((char *)this, sizeof(hostel)))
    {

        cout << "\n\n " << room_no << "\t\t" << name;
        cout << "\t\t" << roll_no << "\t\t" << address;
        cout << "\t" << mobile_no << "\t\t" << semester;
        cout << "\t\t\t" << course << "\t\t" << branch;
    }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    getch();
    fin.close();
}

int hostel ::check(int r)
{

    int flag = 0;
    ifstream fin("Record.dat", ios::in);

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(hostel));
        if (room_no == r)
        {
            flag = 1;
            break;
        }
    }
    fin.close();
    return (flag);
}

void hostel ::bill_generate()
{
    system("cls");
    int dd, mm, yy, r, flag = 0;
    int grad_fee = 40000, mca_fee = 35000, msc_fee = 34000;
    static int mess = 16000;
    cout << "\n\t\t****************************************************************************************************************************************";
    cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
    cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
    cout << "\n\t\t=========================================================== GENERATE BILL: =============================================================";
    cout << "Enter the date of the bill" << endl;
    cin >> dd >> mm >> yy;
    ifstream rd;
    rd.open("record.dat", ios::in | ios::binary);
    cout << "Enter the room number " << endl;
    cin >> r;

    if (!rd)
    {
        cout << "Error opening file.........!" << endl;
    }
    else
    {
        rd.read((char *)&hos, sizeof(hostel));
        while (rd)
        {
            rd.read((char *)&hos, sizeof(hostel));
        }
        if (hos.room_no == r)
        {
            system("cls");
            cout << "\n\t\t****************************************************************************************************************************************";
            cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
            cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
            cout << "\n================================================== HOSTEL BILL: ========================================================";
            if (hos.room_no >= 1 && hos.room_no <= 500)
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n Roll Number : " << roll_no;
                cout << "\n Semester: " << semester;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t YOU ARE ON 0-4 FLOOR ";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << grad_fee;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + grad_fee);
            }
            else if (hos.room_no >= 501 && hos.room_no <= 600)
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n Roll Number : " << roll_no;
                cout << "\n Semester: " << semester;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t YOU ARE ON 5TH FLOOR";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << mca_fee;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + mca_fee);
            }
            else
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n Roll Number : " << roll_no;
                cout << "\n Semester: " << semester;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t YOU ARE ON 6TH FLOOR";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << msc_fee;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + msc_fee);
            }
            bill_no++;
            cout << "\n\n\t\t\t\t\t THANK YOU...!";
            cout << "\n\n\n========================================================================================================================";
            flag = 1;
            getch();
        }
    }
}
void hostel ::edit_menu()
{

    int choice;
    do
    {
        system("cls");
        cout << "\n\t\t****************************************************************************************************************************************";
        cout << "\n\t\t*                                          WELCOME TO HOSTEL J BOOKING PORTAL                                                          *";
        cout << "\n\t\t****************************************************************************************************************************************\n\n\n";
        cout << "\n=================================================== EDIT MENU: =========================================================\n\n";
        cout << "\n\n 1.Modify Student Record.";
        cout << "\n 2.delete Student Room.";
        cout << "\n 3.Go to Main menu .";
        cout << "\n\n Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            modify();
            break;

        case 2:
            delete_room();
            break;

        case 3:
            main_menu();
            break;
        default:
        {
            cout << "\n Wrong Choice.....!!";
            cout << "\n Press any key to continue....!!!";
            getch();
        }
        }
    } while (choice != 3);
}
