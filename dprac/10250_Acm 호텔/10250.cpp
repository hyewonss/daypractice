#include<iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        vector<int>v;
        vector<int>::iterator p;
        int h,w,n,floor,room;
        cin >> h;
        cin >> w;
        cin >> n; //n나누기h의 몫은 호수, 나머지는 층

        if (n%h == 0) {
            room = n/h;
            floor = h;
        }
        else {
            room = n/h+1;
            floor = n%h;
        }
        v.push_back(floor);
        if (room < 10) v.push_back(0);
        v.push_back(room);
        
        for (p = v.begin(); p != v.end(); p++){
            cout << *p;
        }
        cout << '\n';
    }
}