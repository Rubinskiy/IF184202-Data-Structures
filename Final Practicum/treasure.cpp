#include <iostream>
#include <bits/stdc++.h>

#define lld long long int
using namespace std;

int main() {
    vector<pair<lld, lld>> treasureMap;
    lld size, treasureNums;
    cin >> size >> treasureNums;
    for (int i = 0; i < treasureNums; i++) {
        lld treasureLocX = 0;
        lld treasureLocY = 0;
        cin >> treasureLocX >> treasureLocY;
        treasureMap.push_back(make_pair(treasureLocY, treasureLocX));
    }

    for (int i = 1; i <= size; i++) {
        // For a map size x size, print \n after size, print 1 in treasureLocX and treasureLocY
        // and 0 otherwise
        // Print 2 next to the next to the treasure point and 3 diagonally
        for (int j = 1; j <= size; j++) {
            bool treasure = false;
            bool nextToTreasure = false;
            bool diagonalToTreasure = false;
            bool twoStepsToTreasure = false;
            bool twoStepsDiagnoalToTreasure = false;
            bool threeStepsToTreasure = false;
            for (int k = 0; k < treasureNums; k++) {
                if (i == treasureMap[k].first && j == treasureMap[k].second) {
                    treasure = true;
                }
                if ((i == treasureMap[k].first && j == treasureMap[k].second + 1) ||
                    (i == treasureMap[k].first && j == treasureMap[k].second - 1) ||
                    (i == treasureMap[k].first + 1 && j == treasureMap[k].second) ||
                    (i == treasureMap[k].first - 1 && j == treasureMap[k].second)) {
                    nextToTreasure = true;
                }
                if ((i == treasureMap[k].first + 1 && j == treasureMap[k].second + 1) ||
                    (i == treasureMap[k].first + 1 && j == treasureMap[k].second - 1) ||
                    (i == treasureMap[k].first - 1 && j == treasureMap[k].second + 1) ||
                    (i == treasureMap[k].first - 1 && j == treasureMap[k].second - 1)) {
                    diagonalToTreasure = true;
                }
                if ((i == treasureMap[k].first && j == treasureMap[k].second + 2) ||
                    (i == treasureMap[k].first && j == treasureMap[k].second - 2) ||
                    (i == treasureMap[k].first + 2 && j == treasureMap[k].second) ||
                    (i == treasureMap[k].first - 2 && j == treasureMap[k].second)) {
                    twoStepsToTreasure = true;
                }
                if ((i == treasureMap[k].first + 1 && j == treasureMap[k].second + 2) ||
                    (i == treasureMap[k].first + 1 && j == treasureMap[k].second - 2) ||
                    (i == treasureMap[k].first - 1 && j == treasureMap[k].second + 2) ||
                    (i == treasureMap[k].first - 1 && j == treasureMap[k].second - 2) ||

                    (i == treasureMap[k].first + 2 && j == treasureMap[k].second + 1) ||
                    (i == treasureMap[k].first + 2 && j == treasureMap[k].second - 1) ||
                    (i == treasureMap[k].first - 2 && j == treasureMap[k].second + 1) ||
                    (i == treasureMap[k].first - 2 && j == treasureMap[k].second - 1)) {
                    twoStepsDiagnoalToTreasure = true;
                }
                if ((i == treasureMap[k].first && j == treasureMap[k].second + 3) ||
                    (i == treasureMap[k].first && j == treasureMap[k].second - 3) ||
                    (i == treasureMap[k].first + 3 && j == treasureMap[k].second) ||
                    (i == treasureMap[k].first - 3 && j == treasureMap[k].second)) {
                    threeStepsToTreasure = true;
                }
            }
            if (treasure) {
                cout << "1 ";
            } else if (nextToTreasure) {
                cout << "2 ";
            } else if (diagonalToTreasure) {
                cout << "3 ";
            } else if (twoStepsToTreasure) {
                cout << "3 ";
            } else if (twoStepsDiagnoalToTreasure) {
                cout << "4 ";
            } else if (threeStepsToTreasure) {
                cout << "4 ";
            } else {
                cout << "0 ";
            }
            if (j == size) {
                cout << "\n";
            }
        }
    }
    return 0;
}