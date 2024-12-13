#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <memory>
#include <iomanip> // For formatted output
#include "lexer.hpp"
#include "parser.hpp"
#include "evaluator.hpp"

using namespace std;

// Checks if the input given is valid
bool isValidInput(const string& s){
    set<char> validChars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                            '+', '-', '*', '/', '(', ')', '^', '%', ' '};
    for (size_t i = 0; i < s.length(); i++){
        if (validChars.count(s[i]) == 0){
            return false;
        }

    }
    return true;
}

int main() {
    //Try is here in case of passed error
    try {
        string userInput = "";
        vector<string> history{};
        vector<double> answerList{};
        double answer = 0.0;
        bool enteredLoop = false;
        while (userInput != "END"){
            // Clear the screen
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            // Display header
            cout << "===============================" << endl;
            cout << "       Calculator     " << endl;
            cout << "===============================\n" << endl;
            // Display history
            if (!history.empty()){
                cout << "History:" << endl;
                for (size_t i = 0; i < history.size(); i++){
                    cout << "  " << i + 1 << ": " << history[i] << " = " 
                         << fixed << setprecision(5) << answerList[i] << endl;
                }
                cout << endl;
            }
            // Display result of the most recent calculation
            if (enteredLoop && !answerList.empty()){
                cout << "Last Result: " << fixed << setprecision(5) << answerList.back() << endl;
            }
            enteredLoop = true;

            // Prompt the user
            cout << "\nEnter expression or command (END to exit, BACK to undo): ";
            getline(cin, userInput);
            // Handle commands
            if (userInput == "BACK"){
                if (!history.empty()){
                    history.pop_back();
                    answerList.pop_back();
                    cout << "Last entry removed." << endl;
                } else {
                    cout << "No history to go back to." << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (userInput.empty()){
                cout << "No input detected. Please enter a valid expression." << endl;
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // If the input is valid, process it
            if (isValidInput(userInput)){
                try {
                    Lexer lexer(vector<string>{userInput});
                    vector<Token> tokens = lexer.tokenization();
                    shared_ptr<ExpressionTree> exprTree = parse_expression(tokens);
                    answer = evaluate(exprTree);
                    history.push_back(userInput);
                    answerList.push_back(answer);
                }
                catch (const std::exception& e){
                    cout << "Error: " << e.what() << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } else {
                cout << "Invalid input. Please try again." << endl;
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cout << "Exiting Calculator. Goodbye!" << endl;
    }
    catch(const std::domain_error& e){
        cout << "Domain error: " << e.what() << endl;
    }
    catch(const std::exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}


  
