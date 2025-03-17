#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int r = 1;
        long long ans = 1;
        int n, m;
        scanf("%d %d", &n, &m);
        while(n--){
            ans *= m--;
            ans /= r++;
        }
        cout << ans << '\n';
    }
}