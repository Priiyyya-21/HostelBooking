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