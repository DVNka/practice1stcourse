#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dangerous(n);
    for (int i = 0; i < n; i++){
        cin >> dangerous[i];
    }
    sort(dangerous.begin(), dangerous.end());

    int q;
    cin >> q;

    while (q--){
        long long s, f;
        cin >> s >> f;

        long long left = min(s, f) + 1;
        long long right = max(s, f) - 1;

        auto it_left = lower_bound(dangerous.begin(), dangerous.end(), left);
        auto it_right = upper_bound(dangerous.begin(), dangerous.end(), right);

        int count = it_right - it_left;

        cout << count << "\n";
    }

    return 0;
}