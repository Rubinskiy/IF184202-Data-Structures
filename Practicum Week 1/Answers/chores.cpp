#include <iostream>
#include <stack>
#include <queue>

using namespace std;
#define lld long long

// quicksort algo in c++
// partition the deque
int partition(deque<pair<int, string>>& arr, int low, int high) {
    int pivot = arr[high].first;    // pivot
    int i = low - 1;                // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].first <= pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// quicksort function to recursively sort the deque
void quicksort(deque<pair<int, string>>& arr, int low, int high) {
    if (low < high) {
        // partition index
        int pi = partition(arr, low, high);

        // recursively sort elements before and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int e, n;
    deque<pair<int, string>> tasks;
    cin >> e >> n;

    for (int i = 0; i < n; i++) {
        int priority;
        string name;
        cin >> priority >> name;
        tasks.push_front(make_pair(priority, name));
    }

    // quicksort the array based on priority
    quicksort(tasks, 0, tasks.size() - 1);

    /*for (int i = 0; i < n; i++) {
        // print tasks
        cout << tasks.front().first << " " << tasks.front().second << endl;
        tasks.pop_front();
    }*/

    int sum = 0;
    for (auto i = 0; i < n; i++) {
        if (e >= tasks.front().first) {
            cout << tasks.front().second << endl;
            e -= tasks.front().first;
            sum++;
            tasks.pop_front();
        }
    }
    if (sum  == 0) {
        cout << "Pak Aya will do the rest" << endl;
    }
    cin.ignore();
    return 0;
}