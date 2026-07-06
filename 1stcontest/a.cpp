#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int l, r;

    while (cin >> l >> r){
        if (l == 0 && r == 0){
            break;
        }
        reverse(a.begin() + (l - 1), a.begin() + r);
    }

    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}