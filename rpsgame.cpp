#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string winrlose(char p1, char p2){
   if(p1 == p2) return "its a TIE";
   else if((p1 == 'R' && p2 == 'S') || (p1 == 'S' && p2 == 'P') || (p1 == 'P' && p2 == 'R')) return "PLAYER 1 WINS";
   else return "PLAYER 2 WINS";
}

string c_to_string(char moved){
    switch(moved){
        case 'R': return "Rock";
        case 'P': return "Paper";
        case 'S': return "Scissors";
    }
}

int isvalid(char move){
    return (move == 'R' || move == 'P' || move == 'S');
}

int option1(){
    char p1, p2;
    cout << "Player 1, enter your move (R for Rock, P for Paper, S for Scissors):" << endl;
    cout << endl;
    cin >> p1;
    cout << "Player 2, enter your move (R for Rock, P for Paper, S for Scissors):" << endl;
    cout << endl;
    cin >> p2;
    p1=toupper(p1);
    p2=toupper(p2);
    if((p1!='R' && p1!='P' && p1!='S') || (p2!='R' && p2!='P' && p2!='S')){
        cout << "Invalid input. Please enter R for Rock, P for Paper, or S for Scissors." << endl;
        return 0;
    }
    cout << "player 1 : choosed  " << c_to_string(p1) << endl;
    cout << "player 2 : choosed  " << c_to_string(p2) << endl; 

    string result = winrlose(p1, p2);
    cout << result << endl;
}

int option2(){
    char move;
    vector<char>moves;
    moves.push_back('R');
    moves.push_back('P');
    moves.push_back('S');
    cout << "Enter Your Move" << endl;
    cin >> move;
    move = toupper(move);
    while(true){
        if(isvalid(move)){
            int randomindex = rand() % moves.size();
            char cmove = moves[randomindex];
            cout << "you chose : " << c_to_string(move) << endl;
            cout << "the computer chosed : " << c_to_string(cmove) << endl;
            if(move == cmove){
                 cout << "its a TIE" << endl;
                 break;
            }
            else if((move == 'R' && cmove == 'S') || (move == 'S' && cmove == 'P') || (move == 'P' && cmove == 'R')){
                 cout << "________YOU WIN_______";
                 break;
            }
            else{
                 cout << "_______YOU LOSE_______" << endl;
                 break;
            }
        }
        else{
            cout << "Enter valid Move" << endl;
            cin >> move;
            move = toupper(move);
        }
    }
}
int main(){
    int opt;
    srand(time(0));
    cout << "ROCK , PAPER , SCISSOR  GAME" << endl;
    cout << endl;
    cout << "Select Any one of the following options:" << endl;
    cout << "1. TWO PLAYER     2.ONE PLAYER" << endl;
    cin >>opt;
    if(opt == 1){
        option1();
    }
    if(opt == 2){
        option2();
    }
    if(opt!=1 || opt!=2){
        cout << "Invalid option. Please choose 1 or 2." << endl;
        exit(0);
    }
    return 0;
}