#include <iostream>
using namespace std;
void heapify(int mas[], int n, int i){
    int maximum = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n and mas[l] > mas[maximum]){
        maximum = l;
    }
    if (r < n and mas[r] > mas[maximum]){
        maximum = r;
    }
    if (maximum != i) {
        swap(mas[i], mas[maximum]);
        heapify(mas, n, maximum);
    }
}

void heapSort(int mas[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(mas, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}
int main(){
    int n;
    cin >> n;
    int mas[n];
    for(int i = 0; i < n; i++){
        cin >> mas[i];
    }
    heapSort(mas, n);
    for(int i = 0; i < n; i++){
        cout << mas[i] << " ";
    }
}