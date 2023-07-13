#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, string> ip_name;
    unordered_map<string, string> name_ip;
    vector<string> list_of_ips;
    unordered_map<string, unordered_map<string, vector<string>>> msg_list;
    unordered_map<string, vector<string>> receiveOrder;
    unordered_map<string, unordered_set<string>> received;

	lld clientCount; cin >> clientCount;
	lld messageCount; cin >> messageCount;

	for (lld i = 0; i < clientCount; ++i) {
		string input; getline(cin, input);
		for (lld j = 0; j < 3; ++j) {

		}
		string inputIp; cin >> inputIp;
		string inputName; cin >> inputName;

		ip_name[inputIp] = inputName;
		name_ip[inputName] = inputIp;
		list_of_ips.push_back(inputIp);
	}

	for (lld i = 0; i < messageCount; ++i) {
		string sender; cin >> sender;
		string receiver; cin >> receiver;
		string message; getline(cin, message);
		if (sender == "0" || receiver == "0" || message == "") {
			continue;
		}
		if (ip_name.find(sender) == ip_name.end()) {
			continue;
		}

		if (received[receiver].find(sender) == received[receiver].end()) {
			received[receiver].insert(sender);
			receiveOrder[receiver].push_back(sender);
		}

		msg_list[receiver][sender].push_back(message);
	}

	sort(list_of_ips.begin(), list_of_ips.end());
	for (auto it : list_of_ips) {
		if (msg_list[it].size() == 0) {
            continue;
        }
		cout << "===========" << endl;
		cout << "Mail: " << ip_name[it] << endl;
		for (auto jt : list_of_ips) {
			if (msg_list[it][jt].size() > 0) {
				cout << "From: " << ip_name[jt] << endl;
				for (auto kt : msg_list[it][jt]) {
					cout << ">>" << kt << endl;
				}
			}
		}
	}
}