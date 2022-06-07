#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    unsigned long long int f[51];

    f[1] = 3;
    f[2] = 7;
    for (int i = 3; i < 51; i++)
        f[i] = 2 * f[i - 1] + f[i - 2];

    cin >> n;
    cout << f[n];
};
