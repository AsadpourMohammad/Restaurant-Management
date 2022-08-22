#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;


void go(int x, int y)
{
    COORD coordinates;     // coordinates is declared as COORD
    coordinates.X = x;     // defining x-axis
    coordinates.Y = y;     //defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

bool PressToReturn()
{
    char chk;
    int j;
    chk = getch();
    j = chk;
    for(int i=1 ; i<=256 ; i++)
    {
        if (i==j)
        {
            break;
        }
    }
    return 1;
}
bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
}
int SWAP( string &a , string &b )
{
    string t;
    t = a;
    a = b;
    b = t;
}
int WelcomePanel();
int GoodbyePanel();
int StartPanel();
int ManagerAccountPanel();
int ManagerAccountLogin();
int ManagerAccountMaker();
int ManagerMainPanel();
int ManagerMainPassChange();
int ManagerRestaurantMenu();
int CustomerAccountPanel();
int CustomerAccountLogin();
int ManagerMainPass();
int CustomerAccountMaker();
int CustomerMainPanel();
int CustomerRestaurantMenu();
int CustomerWantsToOrder( int Answer , string PickedNumber , string PickedName);
int CustomerAllOrders();
int CustomerPaying();
int ManagerAllOrders();
int CustomerFileRewrite();
int ReadyMeal( int Placement );
int Earnings();
int PaidList();
int Border();
int BorderLong( int x , int t );
int MakingANewCategory( int HowManyCategory );
int AddingFood();
int ArrangingBasedOnPrice();


string UsersName;
int UsersNum;

int CustomersNumber = 0;


struct FoodMenu
{
    string FoodNumber;
    string Name;
    string Price;
    string Time;
    string AdditionalInfo;
    string UsersAdditionalInfo;
    string IfCooked;
    string IfPaid;
};


struct FoodCategories
{   
    string CategoryNumber;
    string name;
    int NumberOfDishes;
    struct FoodMenu Dish[20];
} Category[10];


struct Info
{
    string Number;
    string UserName;
    string Password;
    int OrderCount = 0;
    struct FoodMenu Order[50];
} Customer[10];


int main()
{
    ArrangingBasedOnPrice();

    string line;
    ifstream HowManyUsersAlready ( "RestaurantFiles//CustomerUsernames.txt" );

    while ( getline( HowManyUsersAlready , line ) )
    {
        stringstream LINE (line);
        
        string str = to_string( Customer[CustomersNumber].OrderCount );
        
        getline( LINE , Customer[CustomersNumber].Number , '-' );
        getline( LINE , Customer[CustomersNumber].UserName , '-' );
        getline( LINE , Customer[CustomersNumber].Password , '-' );
        getline( LINE , str );

        Customer[CustomersNumber].OrderCount = stoi( str );

        CustomersNumber++;
    }

    WelcomePanel();
}


int WelcomePanel()
{
    Border();

    {   //  LOGO
        {   // triangle body
            
            {   // line 3
                SetConsoleTextAttribute(h, 0x04);
                go(48,3);
                cout << "*";
            }

            {   // line 4
                SetConsoleTextAttribute(h, 0x04);
                go(44,4);
                cout << "*";
                go(48,4);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,4);
                cout << "*";
            }

            {   // line 5
                SetConsoleTextAttribute(h, 0x04);
                go(40,5);
                cout << "*";
                go(44,5);
                cout << "*";
                go(48,5);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,5);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,5);
                cout << "*";
            }

            {   // line 6
                SetConsoleTextAttribute(h, 0x07);
                go(36,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,6);
                cout << "*";
                go(44,6);
                cout << "*";
                go(48,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,6);
                cout << "*";
                go(60,6);
                cout << "*";
            }

            {   // line 7
                SetConsoleTextAttribute(h, 0x04);
                go(32,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,7);
                cout << "*";
                go(44,7);
                cout << "*";
                go(48,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,7);
                cout << "*";
                go(60,7);
                cout << "*";
                go(64,7);
                cout << "*";
            }

            {   // line 8
                SetConsoleTextAttribute(h, 0x04);
                go(28,8);
                cout << "*";
                go(32,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,8);
                cout << "*";
                go(44,8);
                cout << "*";
                go(48,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,8);
                cout << "*";
                go(60,8);
                cout << "*";
                go(64,8);
                cout << "*";
                go(68,8);
                cout << "*";
            }

            {   // line 9
                SetConsoleTextAttribute(h, 0x04);
                go(24,9);
                cout << "*";
                go(28,9);
                cout << "*";
                go(32,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,9);
                cout << "*";
                go(44,9);
                cout << "*";
                go(48,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,9);
                cout << "*";
                go(60,9);
                cout << "*";
                go(64,9);
                cout << "*";
                go(68,9);
                cout << "*";
                go(72,9);
                cout << "*";
            }
        
            {   // line 10
                SetConsoleTextAttribute(h, 0x04);
                go(20,10);
                cout << "*";
                go(24,10);
                cout << "*";
                go(28,10);
                cout << "*";
                go(32,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,10);
                cout << "*";
                go(44,10);
                cout << "*";
                go(48,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,10);
                cout << "*";
                go(60,10);
                cout << "*";
                go(64,10);
                cout << "*";
                go(68,10);
                cout << "*";
                go(72,10);
                cout << "*";
                go(76,10);
                cout << "*";
            }
        
            {   // line 11
                SetConsoleTextAttribute(h, 0x04);
                go(16,11);
                cout << "*";
                go(20,11);
                cout << "*";
                go(24,11);
                cout << "*";
                go(28,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(32,11);
                cout << "*";
                go(36,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,11);
                cout << "*";
                go(44,11);
                cout << "*";
                go(48,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,11);
                cout << "*";
                go(60,11);
                cout << "*";
                go(64,11);
                cout << "*";
                go(68,11);
                cout << "*";
                go(72,11);
                cout << "*";
                go(76,11);
                cout << "*";
                go(80,11);
                cout << "*";
            }

            {   // line 12
                SetConsoleTextAttribute(h, 0x04);
                go(12,12);
                cout << "*";
                go(16,12);
                cout << "*";
                go(20,12);
                cout << "*";
                go(24,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(28,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(32,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,12);
                cout << "*";
                go(44,12);
                cout << "*";
                go(48,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,12);
                cout << "*";
                go(60,12);
                cout << "*";
                go(64,12);
                cout << "*";
                go(68,12);
                cout << "*";
                go(72,12);
                cout << "*";
                go(76,12);
                cout << "*";
                go(80,12);
                cout << "*";
                go(84,12);
                cout << "*";
                }      
            
            {   // line 13
                SetConsoleTextAttribute(h, 0x04);
                go(8,13);
                cout << "*";
                go(12,13);
                cout << "*";
                go(16,13);
                cout << "*";
                go(20,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(24,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(28,13);
                cout << "*";
                go(32,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,13);
                cout << "*";
                go(44,13);
                cout << "*";
                go(48,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,13);
                cout << "*";
                go(60,13);
                cout << "*";
                go(64,13);
                cout << "*";
                go(68,13);
                cout << "*";
                go(72,13);
                cout << "*";
                go(76,13);
                cout << "*";
                go(80,13);
                cout << "*";
                go(84,13);
                cout << "*";
                go(88,13);
                cout << "*";
            }
        
        }      
    
        {   // below triangle
            {   
                
                {   // line 14
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,14);
                    cout << "*";
                    go(20,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,14);
                    cout << "*";
                    go(32,14);
                    cout << "*";
                    go(36,14);
                    cout << "*";
                    go(40,14);
                    cout << "*";
                    go(44,14);
                    cout << "*";
                    go(48,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,14);
                    cout << "*";
                    go(60,14);
                    cout << "*";
                    go(64,14);
                    cout << "*";
                    go(68,14);
                    cout << "*";
                }
                
                {   // line 15
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,15);
                    cout << "*";
                    go(20,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,15);
                    cout << "*";
                    go(32,15);
                    cout << "*";
                    go(36,15);
                    cout << "*";
                    go(40,15);
                    cout << "*";
                    go(44,15);
                    cout << "*";
                    go(48,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,15);
                    cout << "*";
                    go(60,15);
                    cout << "*";
                    go(64,15);
                    cout << "*";
                    go(68,15);
                    cout << "*";
                    go(72,15);
                    cout << "*";
                    go(76,15);
                    cout << "*";
                    go(80,15);
                    cout << "*";
                    
                }
                
                {   // line 16    
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,16);
                    cout << "*";
                    go(20,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,16);
                    cout << "*";
                    go(32,16);
                    cout << "*";
                    go(36,16);
                    cout << "*";
                    go(40,16);
                    cout << "*";
                    go(44,16);
                    cout << "*";
                    go(48,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,16);
                    cout << "*";
                    go(60,16);
                    cout << "*";
                    go(64,16);
                    cout << "*";
                    go(68,16);
                    cout << "*";
                    go(72,16);
                    cout << "*";
                    go(76,16);
                    cout << "*";
                    go(80,16);
                    cout << "*";
                }
                
                {   // line 17
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,17);
                    cout << "*";
                    go(20,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,17);
                    cout << "*";
                    go(32,17);
                    cout << "*";
                    go(36,17);
                    cout << "*";
                    go(40,17);
                    cout << "*";
                    go(44,17);
                    cout << "*";
                    go(48,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,17);
                    cout << "*";
                    go(60,17);
                    cout << "*";
                    go(64,17);
                    cout << "*";
                    go(68,17);
                    cout << "*";
                    
                }
                
                {   // line 18
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,18);
                    cout << "*";
                    go(20,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,18);
                    cout << "*";
                    go(32,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(36,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(40,18);
                    cout << "*";
                    go(44,18);
                    cout << "*";
                    go(48,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,18);
                    cout << "*";
                    go(60,18);
                    cout << "*";
                    go(64,18);
                    cout << "*";
                    go(68,18);
                    cout << "*";
                    go(72,18);
                    cout << "*";
                    go(76,18);
                    cout << "*";
                    go(80,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                }
                
                {   // line 19
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,19);
                    cout << "*";
                    go(20,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,19);
                    cout << "*";
                    go(32,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(36,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(40,19);
                    cout << "*";
                    go(44,19);
                    cout << "*";
                    go(48,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,19);
                    cout << "*";
                    go(60,19);
                    cout << "*";
                    go(64,19);
                    cout << "*";
                    go(68,19);
                    cout << "*";
                    go(72,19);
                    cout << "*";
                    go(76,19);
                    cout << "*";
                    go(80,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                }

            } 
        }

        {   // Chimney
            {   
                SetConsoleTextAttribute(h, 0x07);
                go(60,3);
                cout << "*   *   *";
                go(60,4);
                cout << "*   *   *";
                go(60,5);
                cout << "*   *   *";
                go(64,6);
                cout << "*   *";
                go(68,7);
                cout << "*";
            }
        }
    }


    go(26,21);
    cout << "Welcome!  Please Press Anywhere To Continue...";

    if ( PressToReturn() )
    {
        StartPanel();
    }
    

    return 1;
}


int GoodbyePanel()
{
    system("cls");
    
    Border();
    
    {   //  LOGO
        {   // triangle body
            
            {   // line 3
                SetConsoleTextAttribute(h, 0x04);
                go(48,3);
                cout << "*";
            }

            {   // line 4
                SetConsoleTextAttribute(h, 0x04);
                go(44,4);
                cout << "*";
                go(48,4);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,4);
                cout << "*";
            }

            {   // line 5
                SetConsoleTextAttribute(h, 0x04);
                go(40,5);
                cout << "*";
                go(44,5);
                cout << "*";
                go(48,5);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,5);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,5);
                cout << "*";
            }

            {   // line 6
                SetConsoleTextAttribute(h, 0x07);
                go(36,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,6);
                cout << "*";
                go(44,6);
                cout << "*";
                go(48,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,6);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,6);
                cout << "*";
                go(60,6);
                cout << "*";
            }

            {   // line 7
                SetConsoleTextAttribute(h, 0x04);
                go(32,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,7);
                cout << "*";
                go(44,7);
                cout << "*";
                go(48,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,7);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,7);
                cout << "*";
                go(60,7);
                cout << "*";
                go(64,7);
                cout << "*";
            }

            {   // line 8
                SetConsoleTextAttribute(h, 0x04);
                go(28,8);
                cout << "*";
                go(32,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,8);
                cout << "*";
                go(44,8);
                cout << "*";
                go(48,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,8);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,8);
                cout << "*";
                go(60,8);
                cout << "*";
                go(64,8);
                cout << "*";
                go(68,8);
                cout << "*";
            }

            {   // line 9
                SetConsoleTextAttribute(h, 0x04);
                go(24,9);
                cout << "*";
                go(28,9);
                cout << "*";
                go(32,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,9);
                cout << "*";
                go(44,9);
                cout << "*";
                go(48,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,9);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,9);
                cout << "*";
                go(60,9);
                cout << "*";
                go(64,9);
                cout << "*";
                go(68,9);
                cout << "*";
                go(72,9);
                cout << "*";
            }
        
            {   // line 10
                SetConsoleTextAttribute(h, 0x04);
                go(20,10);
                cout << "*";
                go(24,10);
                cout << "*";
                go(28,10);
                cout << "*";
                go(32,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,10);
                cout << "*";
                go(44,10);
                cout << "*";
                go(48,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,10);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,10);
                cout << "*";
                go(60,10);
                cout << "*";
                go(64,10);
                cout << "*";
                go(68,10);
                cout << "*";
                go(72,10);
                cout << "*";
                go(76,10);
                cout << "*";
            }
        
            {   // line 11
                SetConsoleTextAttribute(h, 0x04);
                go(16,11);
                cout << "*";
                go(20,11);
                cout << "*";
                go(24,11);
                cout << "*";
                go(28,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(32,11);
                cout << "*";
                go(36,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,11);
                cout << "*";
                go(44,11);
                cout << "*";
                go(48,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,11);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,11);
                cout << "*";
                go(60,11);
                cout << "*";
                go(64,11);
                cout << "*";
                go(68,11);
                cout << "*";
                go(72,11);
                cout << "*";
                go(76,11);
                cout << "*";
                go(80,11);
                cout << "*";
            }

            {   // line 12
                SetConsoleTextAttribute(h, 0x04);
                go(12,12);
                cout << "*";
                go(16,12);
                cout << "*";
                go(20,12);
                cout << "*";
                go(24,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(28,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(32,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,12);
                cout << "*";
                go(44,12);
                cout << "*";
                go(48,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,12);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,12);
                cout << "*";
                go(60,12);
                cout << "*";
                go(64,12);
                cout << "*";
                go(68,12);
                cout << "*";
                go(72,12);
                cout << "*";
                go(76,12);
                cout << "*";
                go(80,12);
                cout << "*";
                go(84,12);
                cout << "*";
                }      
            
            {   // line 13
                SetConsoleTextAttribute(h, 0x04);
                go(8,13);
                cout << "*";
                go(12,13);
                cout << "*";
                go(16,13);
                cout << "*";
                go(20,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(24,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(28,13);
                cout << "*";
                go(32,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(36,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(40,13);
                cout << "*";
                go(44,13);
                cout << "*";
                go(48,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x07);
                go(52,13);
                cout << "*";
                SetConsoleTextAttribute(h, 0x04);
                go(56,13);
                cout << "*";
                go(60,13);
                cout << "*";
                go(64,13);
                cout << "*";
                go(68,13);
                cout << "*";
                go(72,13);
                cout << "*";
                go(76,13);
                cout << "*";
                go(80,13);
                cout << "*";
                go(84,13);
                cout << "*";
                go(88,13);
                cout << "*";
            }
        
        }      
    
        {   // below triangle
            {   
                
                {   // line 14
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,14);
                    cout << "*";
                    go(20,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,14);
                    cout << "*";
                    go(32,14);
                    cout << "*";
                    go(36,14);
                    cout << "*";
                    go(40,14);
                    cout << "*";
                    go(44,14);
                    cout << "*";
                    go(48,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,14);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,14);
                    cout << "*";
                    go(60,14);
                    cout << "*";
                    go(64,14);
                    cout << "*";
                    go(68,14);
                    cout << "*";
                }
                
                {   // line 15
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,15);
                    cout << "*";
                    go(20,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,15);
                    cout << "*";
                    go(32,15);
                    cout << "*";
                    go(36,15);
                    cout << "*";
                    go(40,15);
                    cout << "*";
                    go(44,15);
                    cout << "*";
                    go(48,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,15);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,15);
                    cout << "*";
                    go(60,15);
                    cout << "*";
                    go(64,15);
                    cout << "*";
                    go(68,15);
                    cout << "*";
                    go(72,15);
                    cout << "*";
                    go(76,15);
                    cout << "*";
                    go(80,15);
                    cout << "*";
                    
                }
                
                {   // line 16    
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,16);
                    cout << "*";
                    go(20,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,16);
                    cout << "*";
                    go(32,16);
                    cout << "*";
                    go(36,16);
                    cout << "*";
                    go(40,16);
                    cout << "*";
                    go(44,16);
                    cout << "*";
                    go(48,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,16);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,16);
                    cout << "*";
                    go(60,16);
                    cout << "*";
                    go(64,16);
                    cout << "*";
                    go(68,16);
                    cout << "*";
                    go(72,16);
                    cout << "*";
                    go(76,16);
                    cout << "*";
                    go(80,16);
                    cout << "*";
                }
                
                {   // line 17
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,17);
                    cout << "*";
                    go(20,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,17);
                    cout << "*";
                    go(32,17);
                    cout << "*";
                    go(36,17);
                    cout << "*";
                    go(40,17);
                    cout << "*";
                    go(44,17);
                    cout << "*";
                    go(48,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,17);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,17);
                    cout << "*";
                    go(60,17);
                    cout << "*";
                    go(64,17);
                    cout << "*";
                    go(68,17);
                    cout << "*";
                    
                }
                
                {   // line 18
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,18);
                    cout << "*";
                    go(20,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,18);
                    cout << "*";
                    go(32,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(36,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(40,18);
                    cout << "*";
                    go(44,18);
                    cout << "*";
                    go(48,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,18);
                    cout << "*";
                    go(60,18);
                    cout << "*";
                    go(64,18);
                    cout << "*";
                    go(68,18);
                    cout << "*";
                    go(72,18);
                    cout << "*";
                    go(76,18);
                    cout << "*";
                    go(80,18);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                }
                
                {   // line 19
                    SetConsoleTextAttribute(h, 0x04);
                    go(16,19);
                    cout << "*";
                    go(20,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(24,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(28,19);
                    cout << "*";
                    go(32,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(36,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(40,19);
                    cout << "*";
                    go(44,19);
                    cout << "*";
                    go(48,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                    go(52,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x04);
                    go(56,19);
                    cout << "*";
                    go(60,19);
                    cout << "*";
                    go(64,19);
                    cout << "*";
                    go(68,19);
                    cout << "*";
                    go(72,19);
                    cout << "*";
                    go(76,19);
                    cout << "*";
                    go(80,19);
                    cout << "*";
                    SetConsoleTextAttribute(h, 0x07);
                }

            } 
        }

        {   // Chimney
            {   
                SetConsoleTextAttribute(h, 0x07);
                go(60,3);
                cout << "*   *   *";
                go(60,4);
                cout << "*   *   *";
                go(60,5);
                cout << "*   *   *";
                go(64,6);
                cout << "*   *";
                go(68,7);
                cout << "*";
            }
        }
    }


    go(26,21);
    cout << "We hope you enjoyed your time here.  Goodbye!";
    go(0,25);
    abort();
}


int StartPanel()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Start Panel Menu

            system("cls");
            Border();
            go(42,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Start Panel";
            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Log in as:";
            go(3,5);
            SetConsoleTextAttribute(h, 0x07);
            cout << "1. Manager";
            go(3,6);
            cout << "2. Customer";
            go(3,7);
            cout << "3. EXIT";
            go(3,9);
        }   

        {   // Start Panel Login

            string Login;
            cin >> Login;

            if ( Login == "1" || Login == "Manager" || Login == "manager" )
            {
                ManagerAccountPanel();
            }
            else if ( Login == "2" || Login == "Customer" || Login == "customer" )
            {
                CustomerAccountPanel();
            }
            else if ( Login == "3" || Login == "EXIT" || Login == "exit" )
            {
                GoodbyePanel();
                return 0;
            } 
        }
    }
    
    return 1;
}   


int ManagerAccountPanel()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Manager Account Panel Menu

            system("cls");
            Border();
            go(39,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager Account Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager";

            go(3,5);
            cout << "1. Manager Account Login";
            go(3,6);
            cout << "2. Create a Manager Account";
            go(3,7);
            cout << "3. Return to Start Panel";
            go(3,9);
        }
    
        {   // Manager Account Panel Input

            string Answer;
            cin >> Answer;

            if ( Answer == "1" )
            {
                ManagerAccountLogin();
            }
            else if ( Answer == "2" )
            {
                ManagerMainPass();
            }
            else if ( Answer == "3" )
            {
                StartPanel();
            }
        }
    }

    return 1;
}


int ManagerAccountLogin()
{
    int checking = 0;
    while ( checking == 0 )
    {
        {   // Manager Account Login Menu
            system("cls");
            Border();
            go(40,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager Login Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager"; 
            go(3,4);
            cout << "To go back, type RETURN.";
        }

        {   // Manager Account Login Input

            ifstream ManagerUsername ("RestaurantFiles//ManagerUsernames.txt");
        
            // Username Check
            go(3,6);
            cout << "Username: ";

            string InputedUsername;
            cin >> InputedUsername;

            if ( InputedUsername == "RETURN" )
            {
                return 1;
            }
            
            string line;
            string Username;
            string Password;
            bool check = false;
            while ( getline( ManagerUsername , line ) )
            {
                stringstream LINE (line);
                
                getline ( LINE , Username , '-' );
                getline ( LINE , Password );  
                if ( InputedUsername == Username )
                {
                    check = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
        
            if ( check == false )
            {
                cin.ignore();
                go(3,7);
                cout << "No such Username found.";
                go(3,8);
                cout << "Press ENTER to try again.";
                cin.ignore();
                continue;
            }
            

            // Password Check

            go(3,7);
            cout << "Password: ";

            string InputedPassword;
            cin >> InputedPassword;

            if ( InputedPassword == "RETURN" )
            {
                return 1;;
            }


            InputedPassword = Username + InputedPassword;
            
            check = false;
            if ( InputedPassword == Password )
            {
                check = true;
            }
            else
            {
                check = false;
            }
        
        
            if ( check == false )
            {
                cin.ignore();
                go(3,7);
                cout << "Password Incorrect.";
                go(3,8);
                cout << "Press ENTER to try again.";
                cin.ignore();
                continue;               
            }
            
            UsersName = Username;
            ManagerMainPanel();
        }
    } 

    return 1;
}


int ManagerMainPass()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Manager Main Pass Panel

            system("cls");
            Border();
            go(37,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager's Main Pass Panel";

            go(3,2);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager";
            go(3,4);
            cout << "In order to acces Manager Sign Up, you must enter the Manager's Main Pass.";
            go(3,5);
            cout << "To Return, type RETURN";
        }

        {   // Manager Main Pass Input
        
            ifstream ManagerUsername ("RestaurantFiles//ManagerMainPass.txt");
        
            go(3,7);
            cout << "What is the Manager's Main Pass?\t";

            string Answer;
            cin >> Answer;

            if ( Answer == "RETURN" )
            {
                return 1;
            }

            string Pass;
            getline ( ManagerUsername , Pass );

            if ( Answer == Pass )
            {
                go(3,9);
                cout<< "Congratulations! Press any key to continue.";
                if ( PressToReturn() )
                {
                    ManagerAccountMaker();
                }
            }
            else
            {
                go(3,9);
                cout << "Sorry. Your answer was incorrect. Press ENTER to try again.";
                if ( PressToReturn() )
                {
                    continue;
                }
            }  
        }

    }
    
    return 1;

}


int ManagerAccountMaker()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Manager Account Maker Menu

            system("cls");
            Border();
            go(39,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager Sign up Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager";
            go(3,4);
            cout << "To go back, type RETURN.";
        }

        {   // Manager Account Maker Input
        
            ofstream ManagerUsername ("RestaurantFiles//ManagerUsernames.txt" , ios::app);
        
            go(3,6);
            cout << "Username: ";

            string Username;
            cin >> Username;

            if ( Username == "RETURN" )
            {
                ManagerAccountPanel();
            }

            ManagerUsername << Username << "-";

            go(3,7);
            cout << "Password: ";

            string Password;
            cin >> Password;

            if ( Password == "RETURN" )
            {
                ManagerAccountPanel();
            }

            ManagerUsername << Username << Password << endl;
        }

        ManagerAccountPanel();
    }
    
    return 1;
}


int ManagerMainPanel()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Manager Main Panel Menu
        
            system("cls");
            Border();
            go(40,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager Main Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager: " << UsersName;

            go(3,5);
            cout << "1. Restaurant Menu";
            go(3,6);
            cout << "2. All Orders";
            go(3,7);
            cout << "3. Change Manager's Main Pass";
            go(3,8);
            cout << "4. Return to Start Panel";
            go(3,10);
        }

        {   // Manager Main Panel Input

            string Answer;
            cin >> Answer;

            if ( Answer == "1" )
            {
                ManagerRestaurantMenu();
            }
            else if ( Answer == "2" )
            {
                ManagerAllOrders();
            }
            else if ( Answer == "3" )
            {
                ManagerMainPassChange();
            }
            else if ( Answer == "4" )
            {
                StartPanel();
            }
        }
    }

    return 1;
}


int ManagerMainPassChange()
{
    int check = 0;
    while( check == 0)
    {   
        
        {   // Manager Main Pass Change Panel header
            system("cls");
            Border();
            go(35,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Manager Main Pass Change Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager: " << UsersName;
        }

        {   // Manager Main Pass Change Input
        
            go(3,5);
            cout << "What is your current Main Pass?";
            go(3,6);
            cout << "To return, type 'RETURN'.";
            go(3,7);

            ifstream ManagerUsername ("RestaurantFiles//ManagerMainPass.txt");
        
            string Answer;
            cin >> Answer;

            if ( Answer == "RETURN" )
            {
                return 1;
            }

            string Pass;
            getline ( ManagerUsername , Pass );

            if ( Answer == Pass )
            {
                go(3,9);
                cout<< "What do you want to change it to?";
                go(3,10);
                
                string ChangeTo;
                cin >> ChangeTo;

                {   //  Cleaning the file before rewriting
                    ofstream ofs;
                    ofs.open( "RestaurantFiles//ManagerMainPass.txt", ofstream::out | ofstream::trunc);
                    ofs.close();
                }

                ofstream MainPass ( "RestaurantFiles//ManagerMainPass.txt" , ios::app );

                MainPass << ChangeTo;

                go(3,12);
                cout << "Done! Press any key to return.";

                if ( PressToReturn() )
                {
                    return 1;
                }
                
            }
            else
            {
                go(3,8);
                cout << "Sorry. Your answer was incorrect. Press ENTER to try again.";
                if ( PressToReturn() )
                {
                    continue;
                }
            }  
        }

    }

    return 1;
}


int ManagerRestaurantMenu()
{
    int check = 0, ReturnNumber, temp;
    string Answer;
    string PickedNumber, PickedName;
    
    while ( check == 0 )
    {
        while ( check == 0 )    // Categories List
        {   
            {   //  'Manager Restaurant Menu' Header
        
                system("cls");
                Border();
                go(34,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Manager's Restaurant Menu Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Manager: " << UsersName;
            }
            
            int count = 0;

            {   //  'Manager Restaurant Menu' Category List
            
                string line;
                ifstream RestaurantCategories( "RestaurantFiles//ManagerRestaurantMenuCategories.txt" );

                while ( getline( RestaurantCategories, line ) )
                {
                    stringstream LINE (line);
                    
                    getline( LINE , Category[count].CategoryNumber , '-' );
                    getline( LINE , Category[count].name , '-' );
                    count++;
                }
        
                go(3,5);
                int i = 0;
                for (; i < count; i++)
                {
                    cout << Category[i].CategoryNumber << ". " << Category[i].name;
                    go(3,6+i);
                }

                ReturnNumber = i+3;

                go(3,5+i);
                cout << i + 1 << ". Making a new Category";
                go(3,6+i);
                cout << i + 2 << ". Adding a new food to an old Category";
                go(3,7+i);
                cout << ReturnNumber << ". Return to Manager Main Panel.";
                go(3,9+i);
            }

            {   // 'Manager Restaurant Menu' Input

                cin >> Answer;

                if ( isNumber( Answer ) == true )
                {
                    temp = stoi( Answer );
                }
                else
                {
                    continue;
                }

                if ( temp == ReturnNumber - 2 )
                {
                    MakingANewCategory( count );
                    continue;
                }

                if ( temp == ReturnNumber - 1 )
                {
                    AddingFood();
                    continue;
                }
                
                
                
                if ( temp > count+3 )
                {
                    continue;
                }

                if ( temp == ReturnNumber )
                {
                    return 1;
                }
                else
                {
                    PickedNumber = Category[temp-1].CategoryNumber;
                    PickedName = Category[temp-1].name;
                    break;
                }   
            }
        }
    
        while ( check == 0 )    //  Category's List
        {
            {   //  'Manager Restaurant Menu' Header with picked Category
        
                system("cls");
                Border();
                go(34,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Manager's Restaurant Menu Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Manager: " << UsersName;
                go(3,4);
                SetConsoleTextAttribute(h, 0x03);
                cout << "Category: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << PickedName;

                SetConsoleTextAttribute(h, 0x0D);
                go(3,6);
                cout << "Number:";
                go(14,6);
                cout << "Name:";
                go(33,6);
                cout << "Price:";
                go(48,6);
                cout << "Time:";
                go(63,6);
                cout << "Additional Info:";
                SetConsoleTextAttribute(h, 0x07);
            }
            
            {   //  'Manager Restaurant Menu' Dishes in the Category

                int count = 0;
                
                PickedName += ".txt";
                PickedName = "RestaurantFiles//" + PickedName;

                ifstream CategoriesDishes( PickedName.c_str() );
                
                string line;

                while ( getline( CategoriesDishes , line ) )
                {
                    stringstream LINE (line);
                    getline( LINE , Category[temp-1].Dish[count].FoodNumber , '-' );
                    getline( LINE , Category[temp-1].Dish[count].Name , '-' );
                    getline( LINE , Category[temp-1].Dish[count].Price , '-' );
                    getline( LINE , Category[temp-1].Dish[count].Time , '-' );
                    getline( LINE , Category[temp-1].Dish[count].AdditionalInfo , '-' );
                    count++;
                }
            
                for (int i = 0 ; i < count; i++)
                {
                    go(3, 8 + i );
                    cout << Category[temp-1].Dish[i].FoodNumber;
                    go(14, 8 + i );
                    cout << Category[temp-1].Dish[i].Name;
                    go(33, 8 + i );
                    cout << Category[temp-1].Dish[i].Price;
                    go(48, 8 + i );
                    cout << Category[temp-1].Dish[i].Time;
                    go(63, 8 + i );
                    cout << Category[temp-1].Dish[i].AdditionalInfo;
                }

                go(3 , 9 + count);
                cout << "Press any key to return to the Category Menu...";
                bool CheckingIt = PressToReturn();
                if ( CheckingIt )
                {
                    break;
                }
            }
        }

    }
    
    return 1;
}


int CustomerAccountPanel()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Customer Account Panel Menu

            system("cls");
            Border();
            go(38,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer Account Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer";

            go(3,5);
            cout << "1. Customer Account Login";
            go(3,6);
            cout << "2. Create a Customer Account";
            go(3,7);
            cout << "3. Return to Start Panel";
            go(3,9);
        }
    
        {   // Customer Account Panel Input

            string Answer;
            cin >> Answer;

            if ( Answer == "1" )
            {
                CustomerAccountLogin();
            }
            else if ( Answer == "2" )
            {
                CustomerAccountMaker();
            }
            else if ( Answer == "3" )
            {
                return 1;
            }
        }
    }

    return 1;
}


int CustomerAccountLogin()
{
    int checking = 0;
    while ( checking == 0 )
    {
        {   // Customer Account Login Menu
            system("cls");
            Border();
            go(39,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer Login Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer"; 
            go(3,4);
            cout << "To go back, type RETURN.";
        }

        {   // Password reading;

            ifstream CustomerUsername ("RestaurantFiles//CustomerUsernames.txt");

            string line;
            
            for (int i = 0; i < CustomersNumber ; i++)
            {
                getline( CustomerUsername , line );
                stringstream LINE (line);
                getline( LINE , Customer[i].Number , '-');
                getline( LINE , Customer[i].UserName , '-');
                getline( LINE , Customer[i].Password , '-');
            }
        }

        {   // Customer Account Login Input
        
            {   // Username Check
                go(3,6);
                cout << "Username: ";

                string InputedUsername;
                cin >> InputedUsername;

                if ( InputedUsername == "RETURN" )
                {
                    return 1;
                }
                
                bool check = false;
                int i = 0;
                for (; i < CustomersNumber ; i++)
                {
                    if ( InputedUsername == Customer[i].UserName )
                    {
                        check = true;
                        break;
                    }
                }
                
                if ( check == false )
                {
                    cin.ignore();
                    go(3,7);
                    cout << "No such Username found.";
                    go(3,8);
                    cout << "Press ENTER to try again.";
                    cin.ignore();
                    continue;
                }

                UsersNum = i;
            }

            {   // Password Check

                go(3,7);
                cout << "Password: ";

                string InputedPassword;
                cin >> InputedPassword;

                if ( InputedPassword == "RETURN" )
                {
                    return 1;;
                }

                bool check = false;
                
                if ( InputedPassword == Customer[UsersNum].Password )
                {
                    check = true;
                }
                
                if ( check == false )
                {
                    cin.ignore();
                    go(3,7);
                    cout << "Password Incorrect.";
                    go(3,8);
                    cout << "Press ENTER to try again.";
                    cin.ignore();
                    continue;               
                }
                
                UsersName = Customer[UsersNum].UserName;
                CustomerMainPanel();
            }
        }
    } 

    return 1;
}


int CustomerAccountMaker()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Customer Account Maker Menu

            system("cls");
            Border();
            go(38,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer Sign up Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer";
            go(3,4);
            cout << "To go back, type RETURN.";
        }

        {   // Customer Account Maker Input
        
            ofstream CustomerUsername ("RestaurantFiles//CustomerUsernames.txt" , ios::app);
        
            go(3,5);
            cout << "Username: ";

            string Username;
            cin >> Username;

            if ( Username == "RETURN" )
            {
                return 1;
            }

            CustomerUsername << CustomersNumber << "-" << Username;
            CustomersNumber++;

            go(3,6);
            cout << "Password: ";

            string Password;
            cin >> Password;

            if ( Password == "RETURN" )
            {
                return 1;
            }

            CustomerUsername << "-" << Password << "-" << Customer[UsersNum].OrderCount << endl;
        }

        return 1;
    }
    
    return 1;
}


int CustomerMainPanel()
{
    int check = 0;
    while ( check == 0 )
    {
        {   // Customer Main Panel Menu
        
            system("cls");
            Border();
            go(40,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer Main Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer: " << UsersName;

            go(3,5);
            cout << "1. Restaurant Menu";
            go(3,6);
            cout << "2. All Orders";
            go(3,7);
            cout << "3. Return to Start Panel";
            go(3,8);
        }

        {   // Customer Main Panel Input

            string Answer;
            cin >> Answer;

            if ( Answer == "1" )
            {
                CustomerRestaurantMenu();
            }
            else if ( Answer == "2" )
            {
                CustomerAllOrders();
            }
            else if ( Answer == "3" )
            {
                StartPanel();
            }
        }
    }

    return 1;
}


int CustomerRestaurantMenu()
{
    int check = 0, ReturnNumber, temp;
    string Answer;
    string PickedNumber, PickedName;
    
    while ( check == 0 )
    {
        while ( check == 0 )    // Categories List
        {   
            {   //  'Customer Restaurant Menu' Header
        
                system("cls");
                Border();
                go(33,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Customer's Restaurant Menu Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Customer: " << UsersName;
            }

            int count = 0;

            {   //  'Customer Restaurant Menu' Category List
              
                string line;
                ifstream RestaurantCategories( "RestaurantFiles//ManagerRestaurantMenuCategories.txt" );

                while ( getline( RestaurantCategories, line ) )
                {
                    stringstream LINE (line);
                    
                    getline( LINE , Category[count].CategoryNumber , '-' );
                    getline( LINE , Category[count].name , '-' );
                    count++;
                }
        
                go(3,5);
                int i = 0;
                for (; i < count; i++)
                {
                    cout << Category[i].CategoryNumber << ". " << Category[i].name;
                    go(3,6+i);
                }

                ReturnNumber = i+1;

                go(3,5+i);
                cout << ReturnNumber << ". Return to Customer Main Panel";
                go(3,7+i);
            }

            {   // 'Customer Restaurant Menu' Input
            
                cin >> Answer;

                if ( isNumber( Answer ) == true )
                {
                    temp = stoi( Answer );
                }
                else
                {
                    continue;
                }

                if ( temp > count+1 )
                {
                    continue;
                }
                

                if ( temp == ReturnNumber )
                {
                    return 1;
                }
                else
                {
                    PickedNumber = Category[temp-1].CategoryNumber;
                    PickedName = Category[temp-1].name;
                    break;
                }   
            }
        }

        string tempted = PickedName;
        PickedName += ".txt";
        PickedName = "RestaurantFiles//" + PickedName;

        while ( check == 0 )    //  Category's List
        {
            {   //  'Customer Restaurant Menu' Header with picked Category
        
                system("cls");
                Border();
                go(33,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Customer's Restaurant Menu Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Customer: " << UsersName;
                go(3,4);
                SetConsoleTextAttribute(h, 0x03);
                cout << "Category: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << tempted;

                SetConsoleTextAttribute(h, 0x0D);
                go(3,6);
                cout << "Number:";
                go(14,6);
                cout << "Name:";
                go(33,6);
                cout << "Price:";
                go(48,6);
                cout << "Time:";
                go(63,6);
                cout << "Additional Info:";
                SetConsoleTextAttribute(h, 0x07);
            }
            
            {   //  'Customer Restaurant Menu' Dishes in the Category

                Category[temp-1].NumberOfDishes = 0;

                ifstream CategoriesDishes( PickedName.c_str() );
                
                string line;

                while ( getline( CategoriesDishes , line ) )
                {
                    stringstream LINE (line);
                    getline( LINE , Category[temp-1].Dish[Category[temp-1].NumberOfDishes].FoodNumber , '-' );
                    getline( LINE , Category[temp-1].Dish[Category[temp-1].NumberOfDishes].Name , '-' );
                    getline( LINE , Category[temp-1].Dish[Category[temp-1].NumberOfDishes].Price , '-' );
                    getline( LINE , Category[temp-1].Dish[Category[temp-1].NumberOfDishes].Time , '-' );
                    getline( LINE , Category[temp-1].Dish[Category[temp-1].NumberOfDishes].AdditionalInfo , '-' );
                    Category[temp-1].NumberOfDishes++;
                }
            
                for (int i = 0 ; i < Category[temp-1].NumberOfDishes; i++)
                {
                    go(3, 8 + i );
                    cout << Category[temp-1].Dish[i].FoodNumber;
                    go(14, 8 + i );
                    cout << Category[temp-1].Dish[i].Name;
                    go(33, 8 + i );
                    cout << Category[temp-1].Dish[i].Price;
                    go(48, 8 + i );
                    cout << Category[temp-1].Dish[i].Time;
                    go(63, 8 + i );
                    cout << Category[temp-1].Dish[i].AdditionalInfo;
                }

                go(3 , 9 + Category[temp-1].NumberOfDishes);
                cout << "To begin to Order, type 'ORDER'.";
                go(3 , 11 + Category[temp-1].NumberOfDishes);
                cout << "To Return to Category Menu, type 'RETURN'.";
                go(3 , 13 + Category[temp-1].NumberOfDishes);
                string WhatNext;
                cin >> WhatNext;

                if ( WhatNext == "ORDER" )
                {
                    CustomerWantsToOrder( temp , PickedNumber , PickedName);
                    break;
                }
                else if ( WhatNext == "RETURN" )
                {
                    break;
                }
            }
        }

    }
    
    return 1;
}


int CustomerWantsToOrder( int Answer , string PickedNumber , string PickedName)
{   
    int checkcheck = 0;
    while( checkcheck == 0 )
    {
        {   //  'Customer Restaurant Menu' Header with picked Category
            system("cls");
            BorderLong( Customer[UsersNum].OrderCount , 0 );
            go(33,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer's Restaurant Menu Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer: " << UsersName;
            go(3,4);
            SetConsoleTextAttribute(h, 0x03);
            cout << "Category: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << PickedName;

            SetConsoleTextAttribute(h, 0x0D);
            go(3,6);
            cout << "Number:";
            go(14,6);
            cout << "Name:";
            go(33,6);
            cout << "Price:";
            go(48,6);
            cout << "Time:";
            go(63,6);
            cout << "Additional Info:";
            SetConsoleTextAttribute(h, 0x07);
        }
        
        {   //  'Customer Restaurant Menu' Dishes in the Category

            
            for (int i = 0 ; i < Category[Answer-1].NumberOfDishes; i++)
            {
                go(3, 8 + i );
                cout << Category[Answer-1].Dish[i].FoodNumber;
                go(14, 8 + i );
                cout << Category[Answer-1].Dish[i].Name;
                go(33, 8 + i );
                cout << Category[Answer-1].Dish[i].Price;
                go(48, 8 + i );
                cout << Category[Answer-1].Dish[i].Time;
                go(63, 8 + i );
                cout << Category[Answer-1].Dish[i].AdditionalInfo;
            }
        }
    
        Customer[UsersNum].OrderCount = 0;

        {   //  Header
            go(3 , 9 + Category[Answer-1].NumberOfDishes);
            cout << "Type in the number of the food you want to order.";
            go(3 , 11 + Category[Answer-1].NumberOfDishes);
            cout << "If you have no info to add, just type 'None'.";
            go(3 , 13 + Category[Answer-1].NumberOfDishes);
            cout << "When done, type RETURN.";

            SetConsoleTextAttribute(h, 0x0E);
            go(3 , 15 + Category[Answer-1].NumberOfDishes);
            cout << "Number:";
            go(14 , 15 + Category[Answer-1].NumberOfDishes);
            cout << "Name:";
            go(33 , 15 + Category[Answer-1].NumberOfDishes);
            cout << "Price:";
            go(48 , 15 + Category[Answer-1].NumberOfDishes);
            cout << "Time:";
            go(63 , 15 + Category[Answer-1].NumberOfDishes);
            cout << "Additional Info:";
            SetConsoleTextAttribute(h, 0x07);
        }

        {   //  Reading Orders
            string UsernameOrder = "RestaurantFiles//" + UsersName + "Orders.txt";

            ifstream UsersOrders ( UsernameOrder.c_str() );

            string line;
            
            while ( getline( UsersOrders , line ) )
            {
                stringstream LINE (line);
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber , '-');
                go(3 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
                cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber;
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name , '-');
                go(14 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
                cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name;
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price , '-');
                go(33 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
                cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price;
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time , '-');
                go(48 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
                cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time;
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo , '-');
                go(63 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
                cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo;
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfPaid, '-');
                getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfCooked);

                Customer[UsersNum].OrderCount++;
            }


            CustomerFileRewrite();
        }

        int checking = 0;

        while ( checking == 0 ) // Taking Orders
        {
            CustomerFileRewrite();

            string UsernameOrder = "RestaurantFiles//" + UsersName + "Orders.txt";

            go(3 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);

            int temp = stoi( PickedNumber );


            ofstream UsersOrders( UsernameOrder.c_str() , ios::app );
            
            string Order;
            cin >> Order;


            if ( Order == "RETURN" )
            {
                return 1;
            }
            
            if ( isNumber(Order) == false )
            {
                temp = true;
                break;
            }
            int tempted = stoi(Order);

            if ( tempted > Category[Answer-1].NumberOfDishes )
            {
                break;
            }
            
            bool check = false;
            int i = 0;
            for (; i < Category[Answer-1].NumberOfDishes; i++)
            {
                if ( Order == Category[temp-1].Dish[i].FoodNumber )
                {
                    check = true;
                    break;
                }
            }
            
            if ( check == true )
            {
                string str = to_string( Customer[UsersNum].OrderCount+1 );
                Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber = str;
                UsersOrders << str << "-";
                Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name = Category[temp-1].Dish[i].Name;
                UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name << "-";
                Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price = Category[temp-1].Dish[i].Price;
                UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price << "-";
                Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time = Category[temp-1].Dish[i].Time;
                UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time << "-";
            }

            go(3 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
            cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber;
            go(14 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
            cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name;
            go(33 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
            cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price;
            go(48 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
            cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time;
            
            go(63 , 17 + Customer[UsersNum].OrderCount + Category[Answer-1].NumberOfDishes);
            string AddInfo;
            cin.ignore();
            getline(cin , AddInfo , '\n');
            Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo = AddInfo;
            UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo << "-";

            Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfPaid = "Not Paid Yet";
            UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfPaid << "-";

            Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfCooked = "Not Cooked Yet";
            UsersOrders << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfCooked << endl;

            Customer[UsersNum].OrderCount++;

            break;
        }
        
        CustomerFileRewrite();
    }
    
    return 1;
}


int CustomerAllOrders()
{
    bool HasTheCustomerPaid = false;
    int check = 0;
    while ( check == 0 )
    { 
    
        {   //  'Customer Restaurant Menu' Header
        
            system("cls");
            BorderLong( Customer[UsersNum].OrderCount/2 - 5 , 13 );
            go(47,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Customer's All Orders Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Customer: " << UsersName;
        } 


        Customer[UsersNum].OrderCount = 0;

        {   //  Header
            go(3 , 5);
            cout << "Your orders are:";
            SetConsoleTextAttribute(h, 0x0E);
            go(3 , 6);
            cout << "Number:";
            go(14 , 6);
            cout << "Name:";
            go(33 , 6);
            cout << "Price:";
            go(48 , 6);
            cout << "Time:";
            go(63 , 6);
            cout << "Paid:";
            go(83 , 6);
            cout << "Cooked:";
            go(103 , 6);
            cout << "Additional Info:";
            SetConsoleTextAttribute(h, 0x07);
        }

        {   //  Showing Orders and asking to pay
            
            {   //  Reading Orders
                string UsernameOrder = "RestaurantFiles//" + UsersName + "Orders.txt";

                ifstream UsersOrders ( UsernameOrder.c_str() );

                string line;
                
                while ( getline( UsersOrders , line ) ) // Showing Orders
                {
                    stringstream LINE (line);
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber , '-');
                    go(3 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].FoodNumber;
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name , '-');
                    go(14 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Name;
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price , '-');
                    go(33 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Price;
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time , '-');
                    go(48 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].Time;

                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo , '-');
                    
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfPaid, '-');
                    go(63 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfPaid;
                    getline( LINE , Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfCooked);
                    go(83 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].IfCooked;

                    go(103 , 8 + Customer[UsersNum].OrderCount);
                    cout << Customer[UsersNum].Order[Customer[UsersNum].OrderCount].UsersAdditionalInfo;
                    Customer[UsersNum].OrderCount++;
                }
            }

            CustomerFileRewrite();

            {   //  Printing Time and Price

                int Time = 0;
                for (int i = 0; i < Customer[UsersNum].OrderCount ; i++)  // Counting Time For Order
                {
                    if ( Customer[UsersNum].Order[i].IfCooked == "Cooked" )
                    {
                        continue;
                    }
                    
                    string temping = Customer[UsersNum].Order[i].Time.substr(0,2);
                    int temptemp = stoi(temping);
                    Time += temptemp;
                }
                
                int Price = 0;
                for (int i = 0; i < Customer[UsersNum].OrderCount ; i++)  // Counting Price For Order
                {
                    string temping = Customer[UsersNum].Order[i].Price.substr(Customer[UsersNum].Order[i].Price.find("$") + 1);
                    int temptemp = stoi(temping);
                    
                    Price += temptemp;
                }

                int PriceNotPaid = 0;
                for (int i = 0; i < Customer[UsersNum].OrderCount ; i++)  // Counting Unpaid Price For Order
                {
                    if ( Customer[UsersNum].Order[i].IfPaid == "Paid" )
                    {
                        continue;
                    }

                    string temping = Customer[UsersNum].Order[i].Price.substr(Customer[UsersNum].Order[i].Price.find("$") + 1);
                    int temptemp = stoi(temping);
                    
                    PriceNotPaid += temptemp;
                }

                int PricePaid = 0;
                for (int i = 0; i < Customer[UsersNum].OrderCount ; i++)  // Counting Paid Price For Order
                {
                    if ( Customer[UsersNum].Order[i].IfPaid == "Not Paid Yet" )
                    {
                        continue;
                    }

                    string temping = Customer[UsersNum].Order[i].Price.substr(Customer[UsersNum].Order[i].Price.find("$") + 1);
                    int temptemp = stoi(temping);
                    
                    PricePaid += temptemp;
                }


                go(3 , 9 + Customer[UsersNum].OrderCount);

                SetConsoleTextAttribute(h, 0x09);
                cout << "Total Price:\t";
                SetConsoleTextAttribute(h, 0x07);
                cout << "$" << Price;

                SetConsoleTextAttribute(h, 0x09);
                cout << "\tPaid:\t";
                SetConsoleTextAttribute(h, 0x07);
                cout << "$" << PricePaid;

                SetConsoleTextAttribute(h, 0x09);
                cout << "\tRemaining:\t";
                SetConsoleTextAttribute(h, 0x07);
                cout << "$" << PriceNotPaid;                

                SetConsoleTextAttribute(h, 0x09);
                cout << "\tRemain Time:\t";
                SetConsoleTextAttribute(h, 0x07);
                cout << Time << " min"; 
            }


            if ( HasTheCustomerPaid == true )   //  Cheking after the CustomerPaying function
            {
                go( 3 , 11 + Customer[UsersNum].OrderCount);
                cout << "Thanks For Paying!";
                go( 3 , 12 + Customer[UsersNum].OrderCount);
                cout << "Press any key to return to the Category Menu...";
                bool CheckingIt = PressToReturn();
                if ( CheckingIt )
                {
                    return 1;
                }
            }
            
            {   //  Pay or Return
                go(3 , 11 + Customer[UsersNum].OrderCount);
                cout << "If you want to pay now, type 'PAY'. If not, type 'RETURN' to return to Category Menu.";
                go(3 , 13 + Customer[UsersNum].OrderCount);
                string WantToPay;
                cin >> WantToPay;

                if ( WantToPay == "PAY")
                {
                    CustomerPaying( );
                    HasTheCustomerPaid = true;
                    continue;
                }
                else if ( WantToPay == "RETURN" )
                {
                    return 1;
                }
            }
        }
    }

    return 1;
}


int CustomerPaying( )
{
    string UsernameOrder = "RestaurantFiles//" + UsersName + "Orders.txt";

    {   //  Cleaning the file before rewriting
        ofstream ofs;
        ofs.open( UsernameOrder.c_str(), ofstream::out | ofstream::trunc);
        ofs.close();
    }

    for (int i = 0; i < Customer[UsersNum].OrderCount ; i++)    //  Rewriting the file as 'Paid'
    {   
        Customer[UsersNum].Order[i].IfPaid = "Paid";

        ofstream UsersOrders2 ( UsernameOrder.c_str() , ios::app);

        UsersOrders2 << Customer[UsersNum].Order[i].FoodNumber << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].Name << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].Price << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].Time << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].UsersAdditionalInfo << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].IfPaid << "-";
        UsersOrders2 << Customer[UsersNum].Order[i].IfCooked << endl;
    }
    
    return 1;
}


int ManagerAllOrders()
{
    int checkcheck = 0;
    while ( checkcheck == 0 )
    {
        bool CoockedCheck = false;

        {   // Password reading;

            ifstream CustomerUsername ("RestaurantFiles//CustomerUsernames.txt");

            string line;

            for (int i = 0; i < CustomersNumber ; i++)
            {
                string str;
                
                getline( CustomerUsername , line );
                stringstream LINE (line);
                getline( LINE , Customer[i].Number , '-');
                getline( LINE , Customer[i].UserName , '-');
                getline( LINE , Customer[i].Password , '-');
                getline( LINE , str);

                Customer[i].OrderCount = stoi( str );
            }
        }

        {   // Reading Orders Before Showing
            for (int i = 0; i < CustomersNumber ; i++)
            {
                string PickedCustomer = "RestaurantFiles//" + Customer[i].UserName + "Orders.txt";

                ifstream PickedCustomerList ( PickedCustomer.c_str() );

                string line;

                for (int j = 0 ; j < Customer[i].OrderCount ; j++)
                {
                    getline( PickedCustomerList , line );

                    stringstream LINE (line);
                    
                    getline( LINE , Customer[i].Order[j].FoodNumber , '-');

                    getline( LINE , Customer[i].Order[j].Name , '-');

                    getline( LINE , Customer[i].Order[j].Price , '-');

                    getline( LINE , Customer[i].Order[j].Time , '-');

                    getline( LINE , Customer[i].Order[j].UsersAdditionalInfo , '-');

                    getline( LINE , Customer[i].Order[j].IfPaid , '-');

                    getline( LINE , Customer[i].Order[j].IfCooked);

                }
            }
        }


        int check = 0;
        while ( check == 0 )
        { 
            
            int t = 0;
            for (int i = 0; i < CustomersNumber; i++)   //  Counting Border Placement
            {
                t += Customer[i].OrderCount;
            }
            
            
            {   //  'Manager All Orders' Header
            
                system("cls");
                BorderLong( t - 8 , 13 );
                go(47,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Manager's All Orders Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Manager: " << UsersName;
            } 

            {   //  Header
                go(3 , 5);
                cout << "Today's Orders are:\t      ";

                SetConsoleTextAttribute(h, 0x09);
                cout << "   Today's Earnings:\t$" << Earnings();

                SetConsoleTextAttribute(h, 0x0E);
                go(3 , 6);
                cout << "Number:";
                go(14 , 6);
                cout << "Name:";
                go(33 , 6);
                cout << "Price:";
                go(48 , 6);
                cout << "Time:";
                go(63 , 6);
                cout << "Paid:";
                go(83 , 6);
                cout << "Cooked:";
                go(103 , 6);
                cout << "Additional Info:";
                SetConsoleTextAttribute(h, 0x07);
            }

            int Placement = 0;

            {   //  Showing All Orders By All Customers

                for (int i = 0; i < CustomersNumber ; i++)
                {
                    for (int j = 0; j < Customer[i].OrderCount ; j++)
                    {
                        go(3 , 8 + Placement);
                        cout << Customer[i].Number << " " << Customer[i].Order[j].FoodNumber;
                        go(14 , 8 + Placement);
                        cout << Customer[i].Order[j].Name;
                        go(33 , 8 + Placement);
                        cout << Customer[i].Order[j].Price;
                        go(48 , 8 + Placement);
                        cout << Customer[i].Order[j].Time;
                        go(63 , 8 + Placement);
                        cout << Customer[i].Order[j].IfPaid;
                        go(83 , 8 + Placement);
                        cout << Customer[i].Order[j].IfCooked;
                        go(103 , 8 + Placement);
                        cout << Customer[i].Order[j].UsersAdditionalInfo;

                        Placement++;
                    }
                    Placement++;
                }
            }
            
            {   //  Cooked Input
                
                go(3 , 10 + Placement);
                cout << "If a meal is ready, type 'READY' to change it to 'Cooked'.";
                go(3 , 11 + Placement);
                cout << "To view only the paid for meals, type 'PAID'.";
                go(3 , 12 + Placement);
                cout << "To go back, type 'RETURN'.";
                go(3 , 14 + Placement);

                string Answer;
                cin >> Answer;

                if ( Answer == "READY" ) 
                {
                    ReadyMeal( Placement );
                    CoockedCheck = true;
                    break;
                }
                else if ( Answer == "PAID" )
                {
                    PaidList();
                }
                else if ( Answer == "RETURN" )
                {
                    return 1;
                }
            }
        }

        if ( CoockedCheck == true )
        {
            continue;
        }
        
        return 1;
    }
    
    return 1;
}


int CustomerFileRewrite()
{
    {   // Rewriting Costumers With New Count Number For User
        
        {   //  Cleaning the file before rewriting
            ofstream ofs;
            ofs.open( "RestaurantFiles//CustomerUsernames.txt" , ofstream::out | ofstream::trunc);
            ofs.close();
        }

        for (int i = 0; i < CustomersNumber ; i++) //Rewriting the file as 'Paid'
        {   
            ofstream RewritingUsers ( "RestaurantFiles//CustomerUsernames.txt" , ios::app);

            RewritingUsers << Customer[i].Number << "-";
            RewritingUsers << Customer[i].UserName << "-";
            RewritingUsers << Customer[i].Password << "-";
            RewritingUsers << Customer[i].OrderCount << endl;
        }
    }

    return 1;
}


int ReadyMeal( int Placement )
{   
    string CustomersID , OrdersID;
    int CustomersIDtemp , OrdersIDtemp;
    int checking = 0;
    bool Real = false;
    
    go(3 , 10 + Placement);
    cout << "                                                                                        ";
    go(3 , 11 + Placement);
    cout << "                                                                                        ";
    go(3 , 12 + Placement);
    cout << "                                                                                        ";
    go(3 , 13 + Placement);
    cout << "                                                                                        ";
    go(3 , 14 + Placement);
    cout << "If you want to return, type 'RETURN'.                                                   ";
    go(3 , 10 + Placement);
    cout << "Type in the Customer's ID.\t";
    
    while ( checking == 0 )
    { 
        int check = 0;
        while ( check == 0 )    //  Taking Info
        {  
            cin >> CustomersID;

            go(3 , 12 + Placement);

            if ( CustomersID == "RETURN" )
            {
                return 1;
            }
            
            
            if ( isNumber( CustomersID ) == true )
            {
                CustomersIDtemp = stoi( CustomersID );
            }
            else
            {
                go(3 , 14 + Placement);
                cout << "Only numbers must be entered. Please press any key to try again.";
                if ( PressToReturn() )
                {
                    return 1;
                }
            }

            cout << "Type in the order's ID.\t";
            cin >> OrdersID;

            if ( CustomersID == "RETURN" )
            {
                return 1;
            }

            if ( isNumber( OrdersID ) == true )
            {
                OrdersIDtemp = stoi( OrdersID );
                Real = true;
                break;
            }
            else
            {
                go(3 , 14 + Placement);
                cout << "Only numbers must be entered. Please press any key to try again.";
                if ( PressToReturn() )
                {
                    return 1;
                }
            }
        }

        while ( Real == true )  //  Rewriting
        {
            string UsernameOrder = "RestaurantFiles//" + Customer[CustomersIDtemp].UserName+ "Orders.txt";

            {   //  Cleaning the file before rewriting
                ofstream ofs;
                ofs.open( UsernameOrder.c_str(), ofstream::out | ofstream::trunc);
                ofs.close();
            }    

            Customer[CustomersIDtemp].Order[OrdersIDtemp-1].IfCooked = "Cooked";

            for (int i = 0; i < Customer[CustomersIDtemp].OrderCount ; i++) //Rewriting the file with the OrdersID as 'Cooked' 
            {
                ofstream UsersOrders2 ( UsernameOrder.c_str() , ios::app);

                UsersOrders2 << Customer[CustomersIDtemp].Order[i].FoodNumber << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].Name << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].Price << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].Time << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].UsersAdditionalInfo << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].IfPaid << "-";
                UsersOrders2 << Customer[CustomersIDtemp].Order[i].IfCooked << endl;

                
            }
            
            return 1;
        }
    }

    return 1;
}


int Earnings()
{
    int Earning = 0;
    for (int i = 0; i < CustomersNumber; i++)  // Counting Paid Price For Order
    {
        for (int j = 0; j < Customer[i].OrderCount ; j++)
        {
            if ( Customer[i].Order[j].IfPaid == "Not Paid Yet" )
            {
                continue;
            }

            string temping = Customer[i].Order[j].Price.substr(Customer[i].Order[j].Price.find("$") + 1);
            int temptemp = stoi(temping);
            
            Earning += temptemp;
        }
    }

    return Earning;
}


int PaidList()
{
    int checkcheck = 0;
    while ( checkcheck == 0 )
    {

        {   // Password reading;

            ifstream CustomerUsername ("RestaurantFiles//CustomerUsernames.txt");

            string line;

            
            for (int i = 0; i < CustomersNumber ; i++)
            {
                string str;
                
                getline( CustomerUsername , line );
                stringstream LINE (line);
                getline( LINE , Customer[i].Number , '-');
                getline( LINE , Customer[i].UserName , '-');
                getline( LINE , Customer[i].Password , '-');
                getline( LINE , str);

                Customer[i].OrderCount = stoi( str );
            }
        }

        {   // Reading Orders Before Showing
            for (int i = 0; i < CustomersNumber ; i++)
            {
                string PickedCustomer = "RestaurantFiles//" + Customer[i].UserName + "Orders.txt";

                ifstream PickedCustomerList ( PickedCustomer.c_str() );

                string line;

                for (int j = 0 ; j < Customer[i].OrderCount ; j++)
                {
                    getline( PickedCustomerList , line );

                    stringstream LINE (line);
                    
                    getline( LINE , Customer[i].Order[j].FoodNumber , '-');

                    getline( LINE , Customer[i].Order[j].Name , '-');

                    getline( LINE , Customer[i].Order[j].Price , '-');

                    getline( LINE , Customer[i].Order[j].Time , '-');

                    getline( LINE , Customer[i].Order[j].UsersAdditionalInfo , '-');

                    getline( LINE , Customer[i].Order[j].IfPaid , '-');

                    getline( LINE , Customer[i].Order[j].IfCooked);

                }
            }
        }


        int check = 0;
        while ( check == 0 )    //  Showing
        { 
            int t = 0;
            for (int i = 0; i < CustomersNumber; i++)   //  Border Count
            {
                for (int j = 0; j < Customer[i].OrderCount ; j++)
                {
                    if ( Customer[i].Order[j].IfPaid != "Paid" )
                    {
                        continue;
                    }
                    t++;
                }
            }

            {   //  'Manager Paid Orders' Header
            
                system("cls");
                BorderLong( t - 13 , 13);
                go(47,1);
                SetConsoleTextAttribute(h, 0x04);
                cout << "Manager's Paid Orders Panel";

                go(3,3);
                SetConsoleTextAttribute(h, 0x02);
                cout << "Logged in as: ";
                SetConsoleTextAttribute(h, 0x07);
                cout << "Manager: " << UsersName;
            } 

            {   //  Titles Headers
                go(3 , 5);
                cout << "Today's Orders are:\t      ";

                SetConsoleTextAttribute(h, 0x09);
                cout << "   Today's Earnings:\t$" << Earnings();

                SetConsoleTextAttribute(h, 0x0E);
                go(3 , 6);
                cout << "Number:";
                go(14 , 6);
                cout << "Name:";
                go(33 , 6);
                cout << "Price:";
                go(48 , 6);
                cout << "Time:";
                go(63 , 6);
                cout << "Paid:";
                go(83 , 6);
                cout << "Cooked:";
                go(103 , 6);
                cout << "Additional Info:";
                SetConsoleTextAttribute(h, 0x07);
            }

            int Placement = 0;

            {   //  Showing Paid Orders By All Customers

                for (int i = 0; i < CustomersNumber ; i++)
                {
                    for (int j = 0; j < Customer[i].OrderCount ; j++)
                    {
                        if ( Customer[i].Order[j].IfPaid != "Paid" )
                        {
                            continue;
                        }
                        
                        go(3 , 8 + Placement);
                        cout << Customer[i].Number << " " << Customer[i].Order[j].FoodNumber;
                        go(14 , 8 + Placement);
                        cout << Customer[i].Order[j].Name;
                        go(33 , 8 + Placement);
                        cout << Customer[i].Order[j].Price;
                        go(48 , 8 + Placement);
                        cout << Customer[i].Order[j].Time;
                        go(63 , 8 + Placement);
                        cout << Customer[i].Order[j].IfPaid;
                        go(83 , 8 + Placement);
                        cout << Customer[i].Order[j].IfCooked;
                        go(103 , 8 + Placement);
                        cout << Customer[i].Order[j].UsersAdditionalInfo;

                        Placement++;
                    }
                    Placement++;
                }
            }
            
            {   //  Return Input
                
                go(3 , 9 + Placement);
                cout << "Press any key to return...";
                bool CheckingIt = PressToReturn();
                if ( CheckingIt )
                {
                    return 1;
                }
            }
        }
    }
    
    return 1;
}


int Border()
{   
    SetConsoleTextAttribute(h, 0x0B);

    go(1,0);
    for (int i = 0; i < 48 ; i++)   //  Top
    {
        cout << "* ";
    }

    go(1,24);
    for (int i = 0; i < 48 ; i++)   //  Bottom
    {
        cout << "* ";
    }

    for (int i = 0; i < 23 ; i++)   //  Left
    {
        go(1,i+1);
        cout << "*";
    }

    for (int i = 0; i < 23 ; i++)   //  Right
    {
        go(95,i+1);
        cout << "*";
    }

    return 1;
}


int BorderLong( int x , int t )
{
    SetConsoleTextAttribute(h, 0x0B);
    
    go(1,0);
    for (int i = 0; i < 48 + t ; i++)   //  Top
    {
        cout << "* ";
    }

    go(1,26 + x );
    for (int i = 0; i < 48 + t  ; i++)   //  Bottom
    {
        cout << "* ";
    }

    for (int i = 0; i < 25 + x ; i++)   //  Left
    {
        go(1, i + 1 );
        cout << "*";
    }

    for (int i = 0; i < 25 + x ; i++)   //  Right
    {
        go(95 + 2*t , i + 1);
        cout << "*";
    }
    SetConsoleTextAttribute(h, 0x07);
    return 1;
}


int MakingANewCategory( int HowManyCategory )
{
    string NewCategoryName;
    int count = 1;

    {   //  New Categroy Header
        system("cls");
        Border();
        go(34,1);
        SetConsoleTextAttribute(h, 0x04);
        cout << "Making a new Category Panel";

        go(3,3);
        SetConsoleTextAttribute(h, 0x02);
        cout << "Logged in as: ";
        SetConsoleTextAttribute(h, 0x07);
        cout << "Manager: " << UsersName;
        go(3,4);
        SetConsoleTextAttribute(h, 0x03);
        cout << "New Category's Name: \t\t\t\t\tType 'RETURN' to go back.";
        SetConsoleTextAttribute(h, 0x07);
        go(25,4);
        cin.ignore();

        getline( cin , NewCategoryName , '\n' );

        if ( NewCategoryName == "RETURN" )
        {
            return 1;
        }

        ofstream CategoryNew ( "RestaurantFiles//ManagerRestaurantMenuCategories.txt" , ios::app );
        
        CategoryNew << HowManyCategory + 1 << "-" <<  NewCategoryName << endl;
    }

    string temptemptemp = NewCategoryName;
    temptemptemp += ".txt";

    temptemptemp = "RestaurantFiles//" + temptemptemp;

    ofstream CategoriesDishes( temptemptemp.c_str() , ios::app );
    

    int check = 0;
    while ( check == 0 )    //  Category's List
    {
        {   //  header
            system("cls");
            Border();
            go(34,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Making a new Category Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager: " << UsersName;
            go(3,4);
            SetConsoleTextAttribute(h, 0x03);
            cout << "New Category's Name: \t\t\t\t\tType 'RETURN' to go back.";
            SetConsoleTextAttribute(h, 0x07);
            go(25,4);
            cout << NewCategoryName;
        }

        int j = 0;

        {   //  Reading All Categories
        
            ifstream ReadingCategories ( temptemptemp.c_str() );

            string line;
            
            while ( getline ( ReadingCategories , line ) )
            {
                stringstream LINE (line);
                getline ( LINE , Category[HowManyCategory].Dish[j].FoodNumber , '-' );
                getline ( LINE , Category[HowManyCategory].Dish[j].Name , '-' );
                getline ( LINE , Category[HowManyCategory].Dish[j].Price , '-' );
                getline ( LINE , Category[HowManyCategory].Dish[j].Time , '-' );
                getline ( LINE , Category[HowManyCategory].Dish[j].AdditionalInfo);
                j++;
            }
        }

        {   //  showing foods

            for (int i = 0; i < j ; i++)
            {
                go(3,8+i);
                cout << Category[HowManyCategory].Dish[i].FoodNumber;
                go(14,8+i);
                cout << Category[HowManyCategory].Dish[i].Name;
                go(33,8+i);
                cout << Category[HowManyCategory].Dish[i].Price;
                go(48,8+i);
                cout << Category[HowManyCategory].Dish[i].Time;
                go(63,8+i);
                cout << Category[HowManyCategory].Dish[i].AdditionalInfo;

            }
            
        }

        SetConsoleTextAttribute(h, 0x0D);
        go(3,6);
        cout << "Number:";
        go(14,6);
        cout << "Name:";
        go(33,6);
        cout << "Price:";
        go(48,6);
        cout << "Time:";
        go(63,6);
        cout << "Additional Info:";
        SetConsoleTextAttribute(h, 0x07);
        go(3,8);
        
        {   //  New Category Dishes


            go(3, 7 + count );
            cout << count;

            go(14, 7 + count );
            string FoodName;
            getline( cin , FoodName , '\n' );

            if ( FoodName == "RETURN" )
            {
                return 1;
            }
            
            CategoriesDishes << count << "-" << FoodName << "-";

            go(33, 7 + count );
            string FoodPrice;
            getline( cin , FoodPrice , '\n' );
            CategoriesDishes << FoodPrice << "-";

            go(48, 7 + count );
            string FoodTime;
            getline( cin , FoodTime , '\n' );
            CategoriesDishes << FoodTime << "-";

            go(63, 7 + count );
            string FoodInfo;
            getline( cin , FoodInfo , '\n' );
            CategoriesDishes << FoodInfo << endl;

            count++;
        }

        ArrangingBasedOnPrice();
    }

    return 1;
}


int AddingFood()
{
    
    string ChosenCategory;
    int check = 0;
    
    {   //  Asking for Category header
        system("cls");
        Border();
        go(34,1);
        SetConsoleTextAttribute(h, 0x04);
        cout << "Adding Food to a new Panel";

        go(3,3);
        SetConsoleTextAttribute(h, 0x02);
        cout << "Logged in as: ";
        SetConsoleTextAttribute(h, 0x07);
        cout << "Manager: " << UsersName;
        go(3,4);
        SetConsoleTextAttribute(h, 0x03);
        cout << "The Category's Name: \t\t\t\t\tType 'RETURN' to go back.";
        SetConsoleTextAttribute(h, 0x07);
        go(25,4);
        cin.ignore();
    
        getline( cin , ChosenCategory , '\n' );

        if ( ChosenCategory == "RETURN" )
        {
            return 1;
        }
    }

    while( check == 0 ) //  Writing
    {   
        int count = 0;
        {   // Category header
            system("cls");
            Border();
            go(34,1);
            SetConsoleTextAttribute(h, 0x04);
            cout << "Adding Food to a new Panel";

            go(3,3);
            SetConsoleTextAttribute(h, 0x02);
            cout << "Logged in as: ";
            SetConsoleTextAttribute(h, 0x07);
            cout << "Manager: " << UsersName;
            go(3,4);
            SetConsoleTextAttribute(h, 0x03);
            cout << "The Category's Name: \t\t\t\t\tType 'RETURN' to go back.";
            SetConsoleTextAttribute(h, 0x07);
            go(25,4);
            cout << ChosenCategory;
        }

        {   //  Category's header

            string temptemp = ChosenCategory;
            ChosenCategory += ".txt";

            ChosenCategory = "RestaurantFiles//" + ChosenCategory;

            ifstream ChosenOne ( ChosenCategory.c_str());

            ChosenCategory = temptemp;

            SetConsoleTextAttribute(h, 0x0D);
            go(3,6);
            cout << "Number:";
            go(14,6);
            cout << "Name:";
            go(33,6);
            cout << "Price:";
            go(48,6);
            cout << "Time:";
            go(63,6);
            cout << "Additional Info:";
            SetConsoleTextAttribute(h, 0x07);
            
            string line , temp ;
            
            while ( getline( ChosenOne , line ) )
            {
                stringstream LINE (line);

                
                getline( LINE , temp , '-' );
                go(3,8+count);
                cout << temp;
                getline( LINE , temp , '-' );
                go(14,8+count);
                cout << temp;
                getline( LINE , temp , '-' );
                go(33,8+count);
                cout << temp;
                getline( LINE , temp , '-' );
                go(48,8+count);
                cout << temp;
                getline( LINE , temp );
                go(63,8+count);
                cout << temp;
                
                count++;
            }
            count++;
        }

        string temptemp = ChosenCategory;
        ChosenCategory += ".txt";

        ChosenCategory = "RestaurantFiles//" + ChosenCategory;

        ofstream AddingFood ( ChosenCategory.c_str() , ios::app );

        ChosenCategory = temptemp;

        go(3,8+count);
        cout << count;

        go(14,8+count);
        string NewName;
        cin >> NewName;
        
        if ( NewName == "RETURN" )
        {
            ArrangingBasedOnPrice();
            return 1;
        }
        AddingFood << count << "-" << NewName << "-";
        
        go(33,8+count);
        string NewPrice;
        cin >> NewPrice;
        AddingFood << NewPrice << "-";

        go(48,8+count);
        string NewTime;
        cin >> NewTime;
        AddingFood << NewTime << "-";

        go(63,8+count);
        string NewInfo;
        cin >> NewInfo;
        AddingFood << NewInfo << endl;
        
        ArrangingBasedOnPrice();
    }

    return 1;
}   


int ArrangingBasedOnPrice()
{
    int count = 0;

    {   //  Reading All Categories
        
        ifstream ReadingCategories ( "RestaurantFiles//ManagerRestaurantMenuCategories.txt" );

        string line;

        while ( getline ( ReadingCategories , line ) )
        {
            stringstream LINE (line);
            getline ( LINE , Category[count].CategoryNumber , '-' );
            getline ( LINE , Category[count].name );
            
            count++;
        }
    }

    {   //  Reading All Dishes From All Categories
        
        for (int i = 0 ; i < count ; i++)
        {
            string temp = Category[i].name;
            temp += ".txt";
            temp = "RestaurantFiles//" + temp;
            ifstream ReadingDishes ( temp.c_str() );

            string line;
            Category[i].NumberOfDishes = 0;
            int j = 0;
            while( getline ( ReadingDishes , line ) )
            {
                stringstream LINE (line);
                getline ( LINE , Category[i].Dish[j].FoodNumber , '-' );
                getline ( LINE , Category[i].Dish[j].Name , '-' );
                getline ( LINE , Category[i].Dish[j].Price , '-' );
                getline ( LINE , Category[i].Dish[j].Time , '-' );
                getline ( LINE , Category[i].Dish[j].AdditionalInfo);
                j++;
                Category[i].NumberOfDishes++;
            }
        }
    }
    
    for (int i = 0 ; i < count ; i++)   //  Arranging
    {
        for (int j = 0; j < Category[i].NumberOfDishes ; j++)
        {
            for (int q = j+1 ; q < Category[i].NumberOfDishes; q++)
            {  
                if ( Category[i].Dish[j].Price.substr(Category[i].Dish[j].Price.find("$") + 1) > Category[i].Dish[q].Price.substr(Category[i].Dish[q].Price.find("$") + 1) )
                {
                    SWAP( Category[i].Dish[j].Name , Category[i].Dish[q].Name );
                    SWAP( Category[i].Dish[j].Price , Category[i].Dish[q].Price );
                    SWAP( Category[i].Dish[j].Time , Category[i].Dish[q].Time );
                    SWAP( Category[i].Dish[j].AdditionalInfo , Category[i].Dish[q].AdditionalInfo );
                }
            }
        }
    }

    for (int i = 0; i < count ; i++)    //  Rewriting The File
    {
        string temp = Category[i].name;
        temp += ".txt";
        temp = "RestaurantFiles//" + temp;

        {   //  Cleaning the file before rewriting
            ofstream ofs;
            ofs.open( temp.c_str() , ofstream::out | ofstream::trunc);
            ofs.close();
        }

        ofstream WritingANew ( temp.c_str() , ios::app );
        
        for (int j = 0; j < Category[i].NumberOfDishes ; j++)   //  Rewriting
        {
            WritingANew << Category[i].Dish[j].FoodNumber << "-";
            WritingANew << Category[i].Dish[j].Name << "-";
            WritingANew << Category[i].Dish[j].Price << "-";
            WritingANew << Category[i].Dish[j].Time << "-";
            WritingANew << Category[i].Dish[j].AdditionalInfo << endl;
        }
    }
    
    
    return 1;
}


