#include <iostream>
using namespace std;
//소수는 약수가 2개인 것을 이용하자.

int main(){
    int n, num;
    int cnt = 0;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        for (int j = 1; j <= num; j++){
            if (num%j == 0) cnt++;
        }
        if (cnt == 2) ans++;
        cnt = 0;
    }
    cout << ans;
}