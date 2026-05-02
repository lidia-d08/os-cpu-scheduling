#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int at, bt, id;
};

void input_processes(vector<Process> &p, int n) {
    p.resize(n);
    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].at;
        p[i].id = i;
    }
    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i].bt;
}

void fcfs(vector<Process> p) {
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int time = 0;
    float wt = 0, tat = 0;

    for (auto &proc : p) {
        if (time < proc.at) time = proc.at;
        wt += time - proc.at;
        time += proc.bt;
        tat += time - proc.at;
    }

    cout << "\n--- FCFS Results ---";
    cout << "\nFCFS Avg WT: " << wt / p.size();
    cout << "\nFCFS Avg TAT: " << tat / p.size() << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p;
    input_processes(p, n);
    fcfs(p);
    return 0;
}
