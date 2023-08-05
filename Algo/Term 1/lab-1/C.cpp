#include <iostream>

using namespace std;

long long k = 0;

void Merge(int a[], int left, int mid, int right) {
    int c[right - left];
    int d = left, b = mid;
    while (d < mid or b < right) {
        if (d < mid and (b == right or a[d] <= a[b])) {
            c[d + b - left - mid] = a[d];
            d++;
        } else {
            c[d + b - left - mid] = a[b];
            k += (mid - d);
            b++;
        }
    }

    for (int i = left; i < right; i++)
        a[i] = c[i - left];
}
void MergeSort(int a[], int left, int right) {
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    MergeSort(a, left, mid);

    MergeSort(a, mid, right);

    Merge(a, left, mid, right);
}
int main(){
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    MergeSort(mas, 0, n);
    cout << k;
    return 0;
}