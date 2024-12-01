
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isValidInput(string s){
    set<char> validChars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')', ' '};
    for (int i = 0; i < s.length(); i++){
        if (validChars.count(s[i]) == 0){
            return false;
        }
    }
    return true;
}


int main() {
    cout << "Welcome to the Compiler Expression Parser!" << endl;
    cout << "Enter your mathematical expression:" << endl;
    string userInput = "";
    vector<string> history{};
    vector<int> answerList{};
    int answer = 0;
    bool enteredLoop = false;
    

    while (userInput != "END"){
        system("cls");

        cout << "----------------" << endl;
        for (int i = 0; i < history.size(); i++){
            cout << history[i] << endl;
        }
        if (enteredLoop == true){
            cout << answerList.back() << endl;
        }
        enteredLoop = true;
        cin >> userInput;
        if (userInput == "BACK"){
            history.pop_back();
        }
        if (isValidInput(userInput)){
            history.push_back(userInput);
            answerList.push_back(answer);
            
        }

    }
    
}
