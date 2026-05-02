#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int at, bt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i].at;

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i].bt;

    vector<bool> done(n, false);

    int time = 0, completed = 0;
    float wt = 0, tat = 0;

    while (completed < n) {
        int idx = -1, mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].bt < mn) {
                mn = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        wt += time - p[idx].at;
        time += p[idx].bt;
        tat += time - p[idx].at;

        done[idx] = true;
        completed++;
    }

    cout << "\n--- SJF Results ---";
    cout << "\nAvg WT: " << wt / n;
    cout << "\nAvg TAT: " << tat / n << endl;

    return 0;
}
