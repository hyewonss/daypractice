/* 
"최대한 적은 봉지" -> 5kg부터 나눠보기 나머지가 0 혹은 3이면 출력, 
아니면 5를 하나씩 줄여가면서 3으로 나눠지는지 보기
 */
#include<iostream>
using namespace std;

int main(){
    int n, n5, n3;
    cin >> n;
    n5 = n/5;
    while(1){
        if (n5 < 0){
            cout << "-1";
            return 0;
        }
        if ((n-(5*n5))%3 == 0){
            n3 = (n-(5*n5))/3;
            break;
        }
        n5--;
    }
    cout << n5+n3;
    return 0;
}