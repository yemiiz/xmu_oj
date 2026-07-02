#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

// Standard knight moves: (dx, dy) where dx = column change, dy = row change
const int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int p, q;  // p = rows, q = columns
        cin >> p >> q;

        cout << "#" << t << ":" << "\n";

        // ---- Generate all starting squares in lexicographic order ----
        // Square name: column letter + row number (e.g., A1, A2, ..., A10, B1, ...)
        // Lexicographic string comparison: A1 < A10 < A11 < ... < A2 < A20 < ... < B1 < ...
        vector<string> starts;
        for (int col = 0; col < q; col++) {
            for (int row = 0; row < p; row++) {
                starts.push_back(string(1, 'A' + col) + to_string(row + 1));
            }
        }
        sort(starts.begin(), starts.end());

        bool found = false;
        vector<pair<int, int>> ans;

        for (const string& start : starts) {
            if (found) break;

            int sx = start[0] - 'A';           // column
            int sy = stoi(start.substr(1)) - 1; // row

            // visited[row][col]
            vector<vector<bool>> vis(p, vector<bool>(q, false));
            vector<pair<int, int>> path;
            path.reserve(p * q);

            function<bool(int, int, int)> dfs = [&](int x, int y, int step) -> bool {
                path.push_back({ x, y });
                if (step == p * q) return true;

                // Collect valid moves
                vector<pair<int, int>> moves;
                moves.reserve(8);
                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < q && ny >= 0 && ny < p && !vis[ny][nx]) {
                        moves.push_back({ nx, ny });
                    }
                }

                // Sort by target square name (lexicographic order)
                sort(moves.begin(), moves.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                    string sa = string(1, 'A' + a.first) + to_string(a.second + 1);
                    string sb = string(1, 'A' + b.first) + to_string(b.second + 1);
                    return sa < sb;
                });

                for (auto& m : moves) {
                    vis[m.second][m.first] = true;
                    if (dfs(m.first, m.second, step + 1)) return true;
                    vis[m.second][m.first] = false;
                }

                path.pop_back();
                return false;
            };

            vis[sy][sx] = true;
            if (dfs(sx, sy, 1)) {
                found = true;
                ans = move(path);
            }
        }

        if (found) {
            cout << "(";
            for (auto& cell : ans) {
                cout << char('A' + cell.first) << (cell.second + 1);
            }
            cout << ")" << "\n";
        } else {
            // No Hamiltonian path exists for this board
            cout << "(" << ")" << "\n";
        }
    }

    return 0;
}
