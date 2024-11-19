#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

string playerSelection(int number) {
    if(number == 1)
        return "paper";
    else if(number == 2)
        return "scissors";
    else
        return "rock";
}

string determineWinner(string userChoice, string computerChoice) {
    if ((userChoice == "rock" && computerChoice == "paper") || 
        (userChoice == "paper" && computerChoice == "scissors") || 
        (userChoice == "scissors" && computerChoice == "rock"))
        return "Computer wins!";
    else if ((userChoice == "rock" && computerChoice == "scissors") || 
             (userChoice == "paper" && computerChoice == "rock") || 
             (userChoice == "scissors" && computerChoice == "paper"))
        return "Player wins!";
    else
        return "It's a tie!";
}

void recordResult(ofstream &fout, string result) {
    fout << result << endl;
}

void displayWinner(int computerWins, int playerWins, int ties) {
    if(computerWins > playerWins && computerWins > ties)
        cout << "The computer had the most wins in the ten-game series." << endl;
    else if(playerWins > computerWins && playerWins > ties)
        cout << "Player had the most victories in the ten-game series." << endl;
    else
        cout << "Most of the matches ended in ties." << endl;
}

int main() {
    string computerChoice, userChoice, result;
    int number, computerWins = 0, playerWins = 0, ties = 0;

    ofstream fout;
    fout.open("rps.txt");

    srand(time(0));
    for(int i = 1; i <= 10; i++) {
        cout << "Please input an integer value between 1 and 3, where 1 corresponds to paper, 2 corresponds to scissors, and 3 corresponds to rock: ";
        cin >> number;
        userChoice = playerSelection(number);

        int compSelection = rand() % 3 + 1;
        computerChoice = playerSelection(compSelection);

        result = determineWinner(userChoice, computerChoice);
        recordResult(fout, result);

        if (result == "Computer wins!")
            computerWins++;
        else if (result == "Player wins!")
            playerWins++;
        else
            ties++;
    }
    fout.close();

    displayWinner(computerWins, playerWins, ties);

    return 0;
}
