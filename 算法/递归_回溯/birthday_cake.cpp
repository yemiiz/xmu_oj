#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int V, N;
int best = 1e9;

// min_vol[k]: minimum volume for top k layers (used for pruning)
// min_vol[k] = Σ i³ for i=1..k  (r=i, h=i for the i-th layer from top)
int min_vol[25];

void init() {
    min_vol[0] = 0;
    for (int i = 1; i <= 20; i++) {
        min_vol[i] = min_vol[i-1] + i * i * i;
    }
}

// Compute maximum volume achievable with k layers,
// given max radius start_r and max height start_h for the bottom-most of these k layers
int max_possible_vol(int start_r, int start_h, int k) {
    int total = 0;
    for (int i = 1; i <= k; i++) {
        int nr = start_r - i + 1;
        int nh = start_h - i + 1;
        if (nr <= 0 || nh <= 0) break;
        total += nr * nr * nh;
    }
    return total;
}

void dfs(int layers_left, int remaining_vol, int cur_area, int prev_r, int prev_h) {
    // All layers built
    if (layers_left == 0) {
        if (remaining_vol == 0) best = min(best, cur_area);
        return;
    }

    // ---- Pruning ----

    // [Prune 1] Volume too small for remaining layers
    if (remaining_vol < min_vol[layers_left]) return;

    // [Prune 2] Current area already exceeds best
    if (cur_area >= best) return;

    // ---- Try radius and height for the current (bottom-most remaining) layer ----

    // Max radius: bounded by sqrt(remaining_vol) and the layer below
    int max_r = min(prev_r - 1, (int)sqrt(remaining_vol));

    for (int r = max_r; r >= layers_left; r--) {
        // Max height for this radius:
        // r² * h + min_vol[upper] ≤ remaining_vol
        // → h ≤ (remaining_vol - min_vol[layers_left-1]) / r²
        int max_h = min(prev_h - 1,
                        (remaining_vol - min_vol[layers_left - 1]) / (r * r));
        if (max_h < layers_left) continue;

        for (int h = max_h; h >= layers_left; h--) {
            int vol = r * r * h;
            int rem = remaining_vol - vol;

            // [Prune 3] Upper layers can't hold the remaining volume
            if (rem < min_vol[layers_left - 1]) continue;

            // [Prune 4] Upper layers can't hold the remaining volume (too much)
            int max_vol_upper = max_possible_vol(r - 1, h - 1, layers_left - 1);
            if (rem > max_vol_upper) continue;

            // Compute new surface area
            int new_area = cur_area + 2 * r * h;
            if (layers_left == N) new_area += r * r; // bottom area of layer 1

            if (new_area >= best) continue;

            // [Prune 5] Optimal-case future area bound
            // For remaining volume rem, the absolute minimum side area
            // is achieved with the largest possible radius (r-1):
            // min_future_area ≥ 2 * rem / (r-1)
            // Since side = 2*vol/r, and max r for remaining = r-1
            if (r > 1) {
                int min_future = 2 * rem / r;
                if (new_area + min_future >= best) continue;
            }

            dfs(layers_left - 1, rem, new_area, r, h);
        }
    }
}

int main() {
    init();
    cin >> V >> N;

    // Initial call with INF bounds
    dfs(N, V, 0, (int)sqrt(V) + 1, V + 1);

    if (best == (int)1e9) cout << 0 << endl;
    else cout << best << endl;

    return 0;
}
