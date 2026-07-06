#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;

    set<int> dangerous;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        dangerous.insert(a);
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long window_sum = 1;

    for (int i = 1; i <= n; i++){
        if (dangerous.count(i)){
            dp[i] = 0;
        } else {
            dp[i] = window_sum;
        }
        window_sum = (window_sum + dp[i]) % MOD;
        if (i - k >= 0){
            window_sum = (window_sum - dp[i - k] + MOD) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}