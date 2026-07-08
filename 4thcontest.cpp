#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q;
    cin >> n >> q;

    vector<long long> diff(n + 2, 0);

    for (int i = 0; i < q; i++){
        int l, r;
        long long v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }

    long long cur = 0;
    for (int i = 1; i <= n; i++){
        cur += diff[i];
        cout << cur;
        if (i < n) cout << " ";
    }

    cout << endl;

    return 0;
}