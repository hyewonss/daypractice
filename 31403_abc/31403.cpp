#include <iostream>>
using namespace std;

int main(){
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << a+b-c << '\n';

    string aa = to_string(a);
    string bb = to_string(b);
    string add = aa + bb;
    int aabb = stoi(add);
    cout << aabb-c;
}