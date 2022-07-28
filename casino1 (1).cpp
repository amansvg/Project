#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
class game{
    string name;
    int amount;
    int bet;
    int choice;
    int computer;
    char option;
    public:
    void restart(){
        int asd;
        cout<<"Enter amount to add to your account\n";
        cin>>asd;
        amount+=asd;
    }
    void input(){
        cout<<"                           Enter your name                                \n";
        cin>>name;
        cout<<"                Enter amount to deposit in your account                   \n";
        cin>>amount;
    }
    void instructions();
    void start();
};
void game::instructions(){
    system("CLS");
        cout<<"-----------------------------------------------------------------------------\n";
        cout<<"                              Casino Guess Game                              \n";
        cout<<"-----------------------------------------------------------------------------\n";
        cout<<"                          Instructions for Game:-                            \n";
        cout<<"-----------------------------------------------------------------------------\n";
        cout<<"1:             First you need to deposit amount in your account              \n";
        cout<<"2:                     Now you have to bet some amount                       \n";
        cout<<"3:              Now you have to select number between 1 and 10               \n";
        cout<<"4: If you win then your bet will get double and will be added to your account\n";
        cout<<"5:   If you loose then your bet amount will get deducted from your account   \n";
        cout<<"-----------------------------------------------------------------------------\n";
        cout<<"                                Press Any key                                \n";
        cout<<"-----------------------------------------------------------------------------\n";
        getche();
}
void game::start(){
    system("CLS");
    instructions();
    system("CLS");
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"                           Casino Guess Game                             \n";
    cout<<"-------------------------------------------------------------------------\n";
    input();
    do{
        system("CLS");
        cout<<"Name : "<<name<<endl;
        cout<<"Amount : "<<amount<<endl;
        do{
            cout<<"Enter amount to bet\n";
            cin>>bet;
            if(bet>amount){
                cout<<"You do not have enough maoney in your account\n";
            }
        }while(bet>amount);
        do{
            cout<<"Enter any number\n";
            cin>>choice;
            if(choice<1||choice>10){
                cout<<"You can only choose number between 1 and 10\n";
            }
        }while(choice<1||choice>10);
        computer=rand()%10+1;
        if(computer==choice){
            amount+=(bet*2);
            cout<<"Congratulation You have won Rs."<<(bet*2)<<endl;
        }
        else{
            cout<<"You have loss Rs."<<bet<<endl;
            amount-=bet;
        }
        cout<<"Winning number : "<<computer<<endl;
        cout<<name<<" ,Your account balance : "<<amount<<endl;
        if(amount==0){
            cout<<"You do not have money\n";
            cout<<"Do you want to add money\n";
            char d=getche();
            if(d=='y'||d=='Y')
            restart();
            else
            break;
        }
        cout<<"Do you want to continue(Y/N)\n";
        option=getch();
    }while(option=='Y'||option=='y');
    cout<<"---------------------------------------------------------------\n";
    cout<<"   Thanks for playing.You account balance is : "<<amount<<endl;
    cout<<"---------------------------------------------------------------\n";
    cout<<"                Press any key to go back to menu               \n";
    cout<<"---------------------------------------------------------------\n";
    getche();
}
int main(){
    game g;
    srand((unsigned)time(NULL));
    do{
        system("CLS");
        cout<<"------------------------------------------------------------\n";
        cout<<"                  Casino Guess Game                         \n";
        cout<<"------------------------------------------------------------\n";
        cout<<"1.                     Instrucions                          \n";
        cout<<"2.                        Play                              \n";
        cout<<"3.                        Exit                              \n";
        cout<<"------------------------------------------------------------\n";
        cout<<"                  Press the given numbers                   \n";
        cout<<"------------------------------------------------------------\n";
        char o=getche();
        if(o=='1')
        g.instructions();
        else if(o=='2')
        g.start();
        else if(o=='3')
        exit(0);
    }while(1);
    return 0;
}