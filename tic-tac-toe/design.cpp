#include<iostream>

using namespace std;

char arr[3][3]={{'0','1','2'},{'3','4','5'},{'6','7','8'}};
string p1,p2; 
int row;
int col;
char token='X';
bool draw=false;
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string RESET = "\033[0m"; 

void structure(){
    cout<<"Player 1 is X and Player 2 is O"<<endl;
    //structure of tic tac toe
    
    cout<<"    |       |   \n";
    cout<<"  "<<arr[0][0]<<" |   "<<arr[0][1]<<"   | "<<arr[0][2]<<" \n";
    cout<<"____|_______|___\n";
    cout<<"    |       |   \n";
    cout<<"  "<<arr[1][0]<<" |   "<<arr[1][1]<<"   | "<<arr[1][2]<<" \n";
    cout<<"____|_______|___\n";
    cout<<"    |       |   \n";
    cout<<"  "<<arr[2][0]<<" |   "<<arr[2][1]<<"   | "<<arr[2][2]<<" \n";
    cout<<"    |       |   \n";
    
}

void checkCondition(){
    int i;
    if (token=='X'){
        cout<< p1 <<" your turn"<<endl;
        cin>>i;
    }
    else if (token=='O'){
        cout<< p2 <<" your turn"<<endl;
        cin>> i;
    }
    switch(i)
    {
        case 0:
            row=0;
            col=0;
            break;
        case 1:
            row=0;
            col=1;
            break;
        case 2:
            row=0;
            col=2;
            break;
        case 3:
            row=1;
            col=0;
            break;
        case 4:
            row=1;
            col=1;
            break;
        case 5:
            row=1;
            col=2;
            break;
        case 6:
            row=2;
            col=0;
            break;
        case 7:
            row=2;
            col=1;
            break;
        case 8:
            row=2;
            col=2;
            break;
        default:
            cout<<"Invalid input"<<endl;
            checkCondition();
            return;
    }
    if (arr[row][col] != 'X' && arr[row][col] != 'O') {
        arr[row][col] = token;  
        token = (token == 'X') ? 'O' : 'X';  
    } else {
        cout << "Cell already taken! Please choose an empty cell." << endl;
        checkCondition(); 
    }

}

// Function to check the winning condition
// and if the game is a draw
bool decision(){
    for (int i=0;i<3;i++){
        if (arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]){
            return true;
        }
        if (arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0]){
            return true;
        }
    }
    for (int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]!='X' && arr[i][j]!='O')
            {
                return false;
            }
        }
    }
    cout<<"Game is draw"<<endl;
    draw=true;
    return false;
}

// Main function
int main()
{
    cout<<"Enter player 1 name: ";
    getline(cin,p1);
    cout<<"Enter player 2 name: ";
    getline(cin,p2);
    while(!decision())
    {
        structure();
        checkCondition();
    }
    structure();
    if (!draw) {
        if (token == 'X') {
            cout << p2 << " wins!" << endl;  
        } else {
            cout << p1 << " wins!" << endl; 
        }
    }
}