#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter processes and resources: ";
    cin >> n >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> maxm(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);

    cout << "Allocation matrix:\n";
    for (auto &row : alloc)
        for (auto &x : row) cin >> x;

    cout << "Max matrix:\n";
    for (auto &row : maxm)
        for (auto &x : row) cin >> x;

    cout << "Available resources:\n";
    for (auto &x : avail) cin >> x;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> safe;

    for (int count = 0; count < n;) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool ok = true;

                for (int j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) ok = false;

                if (ok) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            cout << "System is NOT safe\n";
            return 0;
        }
    }

    cout << "Safe sequence: ";
    for (int x : safe) cout << "P" << x << " ";
    cout << endl;

    return 0;
}
