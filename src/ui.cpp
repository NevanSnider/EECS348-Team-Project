#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//Checks if the input given is valid
bool isValidInput(string s){
    return true;
}


int main() {

    //Try is here in case of passed error
    try {
        string userInput = "";
        vector<string> history{};
        vector<int> answerList{};
        int answer = 0;
        bool enteredLoop = false;
        
        //The user can end the program by typing "END"
        while (userInput != "END"){

            //Clears the screen at the beginning of every loop
            //ifdef is here because there has to be a different
            //solution for both windows and linux
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            //Adds a line at the top of every run
            cout << "----------------" << endl;

            //prints the  one by one
            for (int i = 0; i < history.size(); i++){
                cout << history[i] << endl;
            }

            //Only runs after the first run
            //Will print the answer to the most recent
            //line in the history
            if (enteredLoop == true){
                cout << answerList.back() << endl;
            }
            enteredLoop = true;

            //Takes input from user.
            //If its BACK it removes the most recent
            //index in the history
            cin >> userInput;
            if (userInput == "BACK"){
                history.pop_back();
            }
            //If the input is valid, its added to the history
            if (isValidInput(userInput)){
                history.push_back(userInput);
                answerList.push_back(answer);
                
            }

            }
        }
    
    //Will print whatever error is thrown the ui.
    catch(const exception& error){
        cout << "Error: " << error.what() << endl;
    }
    
}
