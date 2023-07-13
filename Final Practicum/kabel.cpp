#include <iostream>
#include <deque>
#include <vector>
#include <string>

#define lld long long int
using namespace std;

int main() {
    deque<string> commands;
    lld n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        lld input;
        cin >> input;
        if (input == 0) {
            command = "r";
        } else if (input == 1) {
            command = "s";
        }

        lld dsize = commands.size();
        string commandTop;
        if (dsize > 0) {
            commandTop = commands.back();
        }
        if (dsize == 0) {
            //commands.push_back(command);
            if (command == "r") {
                commands.push_back("r");
            } else if (command == "s") {
                commands.push_back("s");
                commands.push_back("r");
            }
        } else if (dsize == 1) {
            if (commandTop == "r") {
				if (command == "r") {
					commands.pop_back();
				}
				else if (command == "s") {
					//
				}
			}
			else if (commandTop == "s") {
				if (command == "r") {
					commands.push_back("r");
				}
				else if (command == "s") {
					commands.pop_back();
				}
			}
        // else {
        //     if (commands[dsize - 1] == command) {
        //         commands.pop_back();
        //     } else {
        //         commands.push_back(command);
        //     }
        // }
        } else if (dsize > 1) {
			if (commandTop == "r") {
				if (command == "r") {
					commands.pop_back();
				}
				else if (command == "s") {
					commands.pop_back();
					commands.push_back("s");
					commands.push_back("r");
					commands.push_back("s");
					commands.push_back("r");
				}
			}
			else if (commandTop == "s") {
				if (command == "r") {
					commands.push_back("r");
				}
				else if (command == "s") {
					commands.pop_back();
				}
			}
		}
    }
    cout << commands.size() << endl;
    return 0;
}