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