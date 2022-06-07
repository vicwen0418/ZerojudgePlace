#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
int find(map<int, pair<int, bool>>& tree, int parent, int flag) {
    if (tree[parent].second && tree[parent].first != 99) {
        flag++;
        if (flag == 1) cout << "{";
        cout << parent;
        if (tree[tree[parent].first].first != 99) cout << ',';
        parent = tree[parent].first;
    }
    if (tree[parent].first != 99) flag = find(tree, parent, flag);
    return flag;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        int m, node, parent, flag = 0;
        char buffer;
        map<int, pair<int, bool>> tree;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> node >> buffer >> parent;
            tree[node].first = parent;
            if (parent == 99) tree[node].second = true;
        }
        if (m == 1) {
            cout << "0:N\n";
            continue;
        }
        for (int i = 0; i < m; i++) {
            if (tree[i].first != 99)
                tree[tree[i].first].second = true;
        }
        for (int i = 0; i < m; i++) {
            if (!tree[i].second) {
                cout << i << ':';
                flag = 0;
                parent = tree[i].first;
                if (!tree[i].second && tree[parent].first != 99)
                    flag = find(tree, parent, flag);

                if (!flag) cout << "N\n";
                else cout << "}\n";
            }
        }
    }
    return 0;
}
