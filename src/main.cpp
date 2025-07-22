//第一題
#include <iostream>
using namespace std;

int ackermannRecursive(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackermannRecursive(m - 1, 1);
    return ackermannRecursive(m - 1, ackermannRecursive(m, n - 1));
}

int ackermannNonRecursive(int m, int n) {
    while (true) {
        if (m == 0) return n + 1;
        if (n == 0) {
            m--;
            n = 1;
            continue;
        }
        m--;
        n = ackermannNonRecursive(m, n - 1);
    }
}

int main() {
    int m, n;
    cout << "輸入 m 和 n: ";
    cin >> m >> n;
    cout << "遞迴結果: " << ackermannRecursive(m, n) << endl;
    return 0;
}
//第二題
#include <iostream>
#include <vector>
using namespace std;

void powersetRecursive(vector<int>& set, vector<vector<int>>& result, vector<int>& current, int index) {
    result.push_back(current);
    for (int i = index; i < set.size(); i++) {
        current.push_back(set[i]);
        powersetRecursive(set, result, current, i + 1);
        current.pop_back();
    }
}

vector<vector<int>> powerset(vector<int>& set) {
    vector<vector<int>> result;
    vector<int> current;
    powersetRecursive(set, result, current, 0);
    return result;
}

int main() {
    vector<int> set = {1, 2, 3};
    vector<vector<int>> result = powerset(set);
    cout << ": [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
