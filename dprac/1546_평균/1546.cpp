#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    float sum = 0;
    float av;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int size = sizeof(arr) / sizeof(*arr);
    int max = *max_element(arr,arr+size);
    for (int i = 0; i < n; i++){
        arr[i] = (arr[i]/max)*100;
        sum += arr[i];
    }
    av = sum/n;
    cout << av;
}