#include<iostream>

using namespace std;

void CountSort(int mas[], int res[], int n, int k){
    int sum[k];
    for(int i  = 0; i <= k+1; i++){
        sum[i] = 0;
    }
    for(int j = 1; j <= n; j++){
        sum[mas[j]]++;
    }
    for(int i = 1; i <= k; i++){
        sum[i] += sum[i - 1];
    }
    for(int j = n; j >= 1; j--){
        res[sum[mas[j]]] = mas[j];
        sum[mas[j]] = sum[mas[j]] - 1;
    }
}
int main(){
    int n, k = 0;
    cin >> n;
    int mas[n], res[n];
    for(int i = 1; i <= n; i++){
        cin >> mas[i];
        if(k < mas[i]) {
            k = mas[i];
        }
    }
    CountSort(mas, res, n, k);
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    return 0;
}