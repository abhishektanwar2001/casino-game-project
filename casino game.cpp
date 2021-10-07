#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void instructions();
int main()
{
    string Name;
    int balance; // stores player's balance
    int Amount;
    int reckon;
    int number; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nYour Name : ";
    getline(cin, Name);
    cout << "\n\nEnter your balance to start the game :"<<char(156);
    cin >> balance;
    do
    {
        system("cls");
        instructions();
        cout << "\n\nYour current balance is"<<char(156) << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << Name<<", enter amount to bet :" <<char(156);
            cin >> Amount;
            if(Amount > balance)
                cout << "Betting balance can't be more than the current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(Amount > balance);
// Get player's numbers
        do
        {
            cout << "Presume any betting number between 1 & 10 :";
            cin >> reckon;
            if(reckon <= 0 || reckon > 10)
                cout << "\nNumber must lie between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(reckon <= 0 || reckon > 10);
        number = rand()%10 + 1;
        if(number == reckon)
        {
            cout << "\n\nCongratulations!! You have won" <<char(163) << Amount * 10;
            balance = balance + Amount * 10;
        }
        else
        {
            cout << "Sorry, better luck next time !! You lost" <<char(163) << Amount <<"\n";
            balance = balance - Amount;
        }
        cout << "\nThe lucky number was : " << number <<"\n";
        cout << "\n"<<Name<<", You have balance of" <<char(163) << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to move ahead ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing with us. Your balance is" <<char(163)  << balance << "\n\n";
    return 0;
}
void instructions()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

