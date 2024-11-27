
#include <iostream>   
#include <ctime>     
#include <cstdlib>  

using namespace std;  
//These are global variables
int tries = 4;    
string message = "You have 4 chances!";  // Arrays/Multiple of characters

void hang_man(char state);   //Prototype of funtions  Void will return nothing
int checkGuess(char guess, string real_sport, string &hidden_sport);

int main()  
{
    
    char letter;  
    string sport;   
    string sports[] = {
        "football",
        "basketball",
        "tennis",
        "swimming",
        "baseball",
        "volleyball",
        "cricket",
        "rugby",
        "cycling",
        "golf"
    };

    srand(time(NULL));  //Current time
    int sport_name = rand() % 10;   
    sport = sports[sport_name]; 

    string hide_sport(sport.length(), 'X');

    // To clear the screen
    system("cls");

    while (tries != 0) {
        hang_man('n');  //nuetral state
        cout << "\t\t\t\tLife: " << tries << endl;
        cout << hide_sport << endl;
        cout << "\t\t\t\tGuess a letter: ";
        cin >> letter;

        system("cls");

        if (checkGuess(letter, sport, hide_sport) == 0) {
            message = "Incorrect Letter! ";
            tries--;
        } else {
            message = "Well done! Correct Guess";
            if (hide_sport == sport) {
                message = "You are free to go!";
                hang_man('f');
                cout << "\t\t\t\tLife: " << tries << endl;
                cout << "\t\t\t\t The sport is: " << sport << endl;
                break;
            }
        }
    }

    if (tries == 0) {
        message = "You are hanged!";
        hang_man('h');
        cout << "\t\t\t\tLife: " << tries << endl;
        cout << "\t\t\t\t The sport is: " << sport << endl;
    }

    return 0;
}
    int checkGuess(char guess, string real_sport, string &hidden_sport)
{
    int matches = 0;
    int len = real_sport.length();
    for (int i = 0; i < len; i++) {
        if (guess == hidden_sport[i]) {
            return 0;
        }
        if (guess == real_sport[i]) {
            hidden_sport[i] = guess;
            matches++;
        }
    }
    return matches;
}

    //Two main funtions in this game Hang_man and Guess Character
void hang_man(char state){
    string head_string = "|";
    string stage="=";
    string handle= "|";
    if(state == 'f'){
        head_string="   ";
        handle="\\";
    }
    else if (state == 'h'){
        stage= " ";
        handle="/";
    }
    
    cout << "\t\t\t\t___________________" << endl;
    cout << "\t\t\t\t         "<< head_string <<"        "  << endl;
    cout << "\t\t\t\t         O        |"  << endl;
    cout << "\t\t\t\t        / \\       |"  << "\t     " <<message << endl;
    cout << "\t\t\t\t         |        |"  << "\t            " << endl;
    cout << "\t\t\t\t        / \\       |          O "  << endl;
    cout << "\t\t\t\t     =="<<stage<< stage << stage << stage << stage <<"==    |         / \\ " << endl;
    cout << "\t\t\t\t      |     |     |   "<< handle <<"      | "  << endl;
    cout << "\t\t\t\t      |     |     |  ===    / \\ "  << endl;
    cout << "\t\t\t\t=====================|=| =======================    "  << endl;
}