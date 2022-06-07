#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
using namespace std;
bool adj[81][81] = { false };
bool nt[81] = { false };
int to_int(char a) {
    return a - '0';
}
void dfs(int k) {
    nt[k] = true;
    for (int v = 0; v < 80; v++) {
        if (adj[k][v] && !nt[v])
            dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        stringstream ss;
        int node[2];
        int node_ct = 0, edge_ct = 0;
        set<int> tree;

        memset(adj, 0, sizeof(adj));
        memset(nt, 0, sizeof(nt));

        getline(cin, s);
        ss << s;
        while (ss >> s) {
            edge_ct++;
            if (s[1] == ',') {
                node[0] = to_int(s[0]);
                if (s.size() == 3) node[1] = to_int(s[2]);
                else node[1] = 10 * to_int(s[2]) + to_int(s[3]);
            }
            else {
                node[0] = 10 * to_int(s[0]) + to_int(s[1]);
                if (s.size() == 4) node[1] = to_int(s[3]);
                else node[1] = 10 * to_int(s[3]) + to_int(s[4]);
            }
            for (int i = 0; i < 2; i++) {
                if (!tree.count(node[i])) {
                    tree.insert(node[i]);
                    node_ct++;
                }
            }
            adj[node[0]][node[1]] = true;
            adj[node[1]][node[0]] = true;
        }

        if (node_ct != edge_ct + 1) cout << "F\n";
        else {
            int check = *tree.begin();
            bool flag = true;
            dfs(check);
            for (int g = 0; g < 81; g++) {
                if (tree.count(g) && !nt[g]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) cout << "F\n";
            else cout << "T\n";
        }
        ss.str("");
        ss.clear();
    }
    return 0;
};
