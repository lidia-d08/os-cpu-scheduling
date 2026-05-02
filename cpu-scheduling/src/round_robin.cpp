#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int at, bt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    vector<int> rem_bt(n), wt(n);

    cout << "Arrival times:\n";
    for (int i = 0; i < n; i++) cin >> p[i].at;

    cout << "Burst times:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].bt;
        rem_bt[i] = p[i].bt;
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0, completed = 0;

    while (completed < n) {
        bool progress = false;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && rem_bt[i] > 0) {
                progress = true;

                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - p[i].bt - p[i].at;
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }

        if (!progress) time++;
    }

    float avg_wt = 0, avg_tat = 0;

    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += p[i].bt + wt[i];
    }

    cout << "\n--- Round Robin Results ---";
    cout << "\nAvg WT: " << avg_wt / n;
    cout << "\nAvg TAT: " << avg_tat / n << endl;

    return 0;
}
