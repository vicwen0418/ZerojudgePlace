#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    unsigned long long int cn;
    unordered_set<unsigned long long int> set;
    for (int i = 1; i < 66; i++) {
        int a = i;
        for (int j = 1; j < 66; j++) {
            int b = j;
            if (a != b) {
                for (int k = 1; k < 66; k++) {
                    int c = k;
                    if (a != c && b != c) {
                        cn = a * b + a * c + b * c;
                        set.insert(cn);
                    }
                }
            }
        }
    }
    cin >> n;
    int count = 0;
    unsigned long long int num = 1;
    while (count < n) {
        if (!set.count(num))
            count++;
        num++;
    }
    cout << num - 1;
};