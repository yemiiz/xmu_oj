#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int V, N, best;

// min_vol[k] = minimal volume for top k layers: Σ i³ (i=1..k)
int min_vol[25];

void init() {
    min_vol[0] = 0;
    for (int i = 1; i <= 20; i++)
        min_vol[i] = min_vol[i-1] + i * i * i;
}

// Maximum volume achievable with k upper layers,
// given max radius `r` and max height `h` for the lowest of those k layers.
inline int max_vol_upper(int r, int h, int k) {
    int total = 0;
    for (int i = 1; i <= k; i++, r--, h--) {
        if (r <= 0 || h <= 0) break;
        total += r * r * h;
    }
    return total;
}

void dfs(int layer, int remV, int area, int prev_r, int prev_h) {
    if (layer == 0) {
        if (remV == 0) best = min(best, area);
        return;
    }

    // ===== Pruning =====

    // [P1] Remaining volume too small for the minimum-possible layers
    if (remV < min_vol[layer]) return;

    // [P2] Already worse than best found
    if (area >= best) return;

    // [P3] ★ Future-side lower bound ★
    // Side = 2*vol/r. Future layers have r ≤ prev_r-1 < prev_r,
    // so each vol unit contributes ≥ 2/prev_r area.
    // Total future side area ≥ 2 * remV / prev_r.
    if (area + 2 * remV / prev_r >= best) return;

    // Max radius: tightly bounded by volume + minimum layer count
    // r² * h + min_vol[upper] ≤ remV, with h ≥ layer → r² * layer ≤ remV - min_vol[layer-1]
    int max_r = (int)sqrt((remV - min_vol[layer - 1]) / layer);
    max_r = min(max_r, prev_r - 1);
    if (max_r < layer) return;

    for (int r = max_r; r >= layer; r--) {
        int max_h = min(prev_h - 1,
                        (remV - min_vol[layer - 1]) / (r * r));
        if (max_h < layer) continue;

        for (int h = max_h; h >= layer; h--) {
            int vol  = r * r * h;
            int left = remV - vol;

            // [P4] Upper layers: remaining volume too small
            if (left < min_vol[layer - 1]) continue;

            // [P5] Upper layers: remaining volume too large
            if (left > max_vol_upper(r - 1, h - 1, layer - 1)) continue;

            int new_area = area + 2 * r * h;
            // Bottom layer: add the base area
            if (layer == N) new_area += r * r;

            if (new_area >= best) continue;

            // [P6] Even with the best possible packing of remaining volume
            // (i.e. all in one cylinder with max radius r-1), can't beat best
            if (r > 1 && new_area + 2 * left / (r - 1) >= best) continue;

            dfs(layer - 1, left, new_area, r, h);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin >> V >> N;

    // Quick check: impossible?
    if (V < min_vol[N]) {
        cout << "0\n";
        return 0;
    }

    best = 1e9;  // will be tightened by the first feasible solution

    // For N=1 only, compute a tighter start bound
    if (N == 1) {
        for (int r0 = 1; r0 * r0 <= V; r0++)
            if (V % (r0 * r0) == 0)
                best = min(best, r0 * r0 + 2 * r0 * (V / (r0 * r0)));
    }

    dfs(N, V, 0, (int)sqrt(V) + 2, V + 2);

    cout << (best == (int)1e9 ? 0 : best) << "\n";
    return 0;
}
