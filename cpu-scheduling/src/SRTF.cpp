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
    vector<int> rem_bt(n);

    cout << "Arrival times:\n";
    for (int i = 0; i < n; i++) cin >> p[i].at;

    cout << "Burst times:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].bt;
        rem_bt[i] = p[i].bt;
    }

    int time = 0, completed = 0;
    float wt = 0, tat = 0;

    while (completed < n) {
        int idx = -1, mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && rem_bt[i] > 0 && rem_bt[i] < mn) {
                mn = rem_bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        rem_bt[idx]--;
        time++;

        if (rem_bt[idx] == 0) {
            completed++;
            int finish = time;
            wt += finish - p[idx].bt - p[idx].at;
            tat += finish - p[idx].at;
        }
    }

    cout << "\n--- SRTF Results ---";
    cout << "\nAvg WT: " << wt / n;
    cout << "\nAvg TAT: " << tat / n << endl;

    return 0;
}
