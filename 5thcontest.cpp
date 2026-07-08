#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    long long result = 1;
    for (int i = 0; i < n; i++){
        long long t;
        cin >> t;
        result = lcm(result, t);
    }

    cout << result << endl;

    return 0;
}