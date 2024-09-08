#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int comparestr(string a, string b){
    if (a.length() == b.length()){
        return a < b; //사전순으로 정렬
    }
    else return a.length() < b.length(); //길이 짧은 순으로 정렬
}

string w[20000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    sort(w, w+n, comparestr);
    for (int i = 0; i < n; i++){
        if (w[i] == w[i+1]) continue;
        cout << w[i] <<'\n';
    }
    return 0;
}