#include <iostream>
#include <string>
using namespace std;

// the numbers reperesented in brackets are coloumn numbers and row numbers, we can insert our alphabet into these numbers
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token = 'X'; 
// name of player 1
string player1;
// name of player 2
string player2;
bool game_tie = false;

void print_game_board(){
    // Input of number of players

    cout << "\n----GAME BOARD----\n";
    cout << endl;

    cout << "   |    |   \n";
    cout << " "<<space[0][0] << " | "<<space[0][1]<<"  |  "<<space[0][2]<<"    \n";
    cout << "___|____|___\n";
    cout << "   |    |   \n";
    cout << " "<<space[1][0] << " | "<<space[1][1]<<"  |  "<<space[1][2]<<"    \n";
    cout << "___|____|___\n";
    cout << "   |    |   \n";
    cout << " "<<space[2][0] << " | "<<space[2][1]<<"  |  "<<space[2][2]<<"    \n";
    cout << "   |    |   \n";
}

void check_validity(){
    // we will check for valid and invalid values
    int digit;
    if( token == 'X'){
        cout << player1 <<" please give the input: ";
        cin >> digit;
    }
    if( token == 'O'){
        cout << player2 <<" please give the input: ";
        cin >> digit;
    }
    if(digit == 1){
        row = 0;
        column = 0;
    }
    if(digit == 2){
        row = 0;
        column = 1;
    }
    if(digit == 3){
        row = 0;
        column = 2;
    }
    if(digit == 4){
        row = 1;
        column = 0;
    }
    if(digit == 5){
        row = 1;
        column = 1;
    }
    if(digit == 6){
        row = 1;
        column = 2;
    }
    if(digit == 7){
        row = 2;
        column = 0;
    }
    if(digit == 8){
        row = 2;
        column = 1;
    }
    if(digit == 9){
        row = 2;
        column = 2;
    }
    else if( digit < 1 ||  digit > 9){
        cout <<"WARNING! Invalid input by the user"<<endl;
    }
    // check for empty cell
    // basically its player ones turn, we check for empty cell and assign it
    if(token == 'X' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'X';
        token = 'O';
    }
    else if(token == 'O' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'O';
        token = 'X';
    }
    else {
        cout << "\n--There is no empty space left--\n";
        check_validity();
    }
}

bool declare_result(){
    // horizantal and vertical match
    for(int i=0; i<3; i++)
    {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || (space[0][i]==space[1][i]) && (space[0][i] == space[2][i])){
            // this means the player wins
            return true; 
        }
    }

    // Diagonal match
    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1]==space[2][0]){
        // this is a win
        return true;
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j] != 'X' && space[i][j] != 'O'){
                // the game is not finished yet
                return false;
            }
        }
    }

    game_tie = true;
    return false;
}

int main(){

    cout << "Enter palyer 1: ";
    getline(cin,player1);
    cout << "Enter player 2: ";
    getline(cin,player2);
    
    cout << "\nPlayer 1 will play first according to rules of the game"<< endl;
    cout << player1 <<" should start the 1st move."<<endl;
    // this function returns false until any one of the player wins or game comes to an end
    while(!declare_result()){
         print_game_board();
         check_validity();
         declare_result();
    }
    // player 2 wins the game
    if(token == 'X' && game_tie == false){
        print_game_board();
        cout << player2 << " Won the game!" << endl;
    }
    // player 1 wins the game
    else if(token == 'O' && game_tie == false){
        print_game_board();
        cout << player1 << " Won the game!" << endl;
    }
    // tie between two players
    else{
        print_game_board();
        cout << "--Its a Draw!--" << endl;
    }

    
}
