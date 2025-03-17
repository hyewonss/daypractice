#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >>c;

    if (a == b && b == c) {
        cout << a;
        return 0;
    }
    else if (a == b && a<c){
        cout << a;
        return 0;
    } 
    else if (a == c && a<b){
        cout << a;
        return 0;
    }
    else if (b == c && b<a){
        cout << b;
        return 0;
    }
    else{
        int arr[3] = {a,b,c};
        sort(arr, arr+3);
        cout << arr[1];
        return 0;
    }
}