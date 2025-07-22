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
