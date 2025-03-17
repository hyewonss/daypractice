#include <iostream>
#include <string>
using namespace std;

int main(){
    string input, ans;
    cin >> input;
    ans = input;
    

    int s = input.size();
    for (int i = 0; i < s-2; i++){ //mid와 last가 한 단어이상이도록
        for (int j = i+1; j < s-1; j++){ //last가 한 단어이상이도록
            
            string tmp;

            for (int k = i; k >= 0; k--){ //first 반대로 저장
                tmp += input[k];
            }
            for (int k = j; k >= i+1; k--){ //그다음 mid 반대로 저장
                tmp += input[k];
            }
            for (int k = s-1; k >= j+1; k--){ //마지막으로 last 반대로 저장
                tmp += input[k];
            }

            if (ans > tmp) ans = tmp;
        } 
    }
    cout << ans << endl;
}