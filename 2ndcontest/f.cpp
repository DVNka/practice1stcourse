#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

long long power(long long base, long long exp){
    long long result = 1;
    base %= MOD;

    while (exp > 0){
        if (exp % 2 == 1){
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a0;
    cin >> n >> a0;

    long long ticket_n_minus1 = (a0 * power(5, n - 1)) % MOD;
    long long ticket_n = (a0 * power(5, n)) % MOD;

    if (ticket_n_minus1 < ticket_n){
        cout << ticket_n_minus1 << " " << ticket_n << "\n";
    } else {
        cout << ticket_n << " " << ticket_n_minus1 << "\n";
    }

    return 0;
}