#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> books(N);
        for (int i = 0; i < N; i++) {
            cin >> books[i];
        }
        
        int swaps = 0;
        bool swapped;
        
        // Пузырьковая сортировка с подсчётом обменов
        do {
            swapped = false;
            for (int i = 0; i < N - 1; i++) {
                if (books[i] > books[i + 1]) {
                    // Меняем местами
                    swap(books[i], books[i + 1]);
                    swaps++;
                    swapped = true;
                }
            }
        } while (swapped);
        
        cout << swaps << '\n';
    }
    
    return 0;
}