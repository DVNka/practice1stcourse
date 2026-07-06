#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    cin >> l >> r;

    vector<int> dp(r + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= r; i++){
        for (int j = 2 * i; j <= r; j += i){
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    long long ans = 0;
    for (int i = l; i <= r; i++){
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}