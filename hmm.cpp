#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void cuttingBrownie(int h, int w, int num, const vector<vector<int>>& pieces) {
    // 최대매출
    vector<vector<int>> cost(h + 1, vector<int>(w + 1, 0));
    // ixj인 브라우니 조각의 사용횟수 저장
    vector<vector<vector<int>>> piececnt(h + 1, vector<vector<int>>(w + 1, vector<int>(num, 0)));

    // 입력받은 조각의 가격, 값 저장
    for (int i = 0; i < num; ++i) {
        int ph = pieces[i][0];
        int pw = pieces[i][1];
        int price = pieces[i][2];
        cost[ph][pw] = price;
        piececnt[ph][pw][i] = 1; //사용됨 기록
    }

    // 최대 매출 계산
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            // 세로
            for (int k = 1; k < i; ++k) { // k:분할 할 높이, i:현재 브라우니 높이
                if (cost[k][j] + cost[i - k][j] > cost[i][j]) {
                    cost[i][j] = cost[k][j] + cost[i - k][j];
                    piececnt[i][j] = piececnt[k][j]; // 조각 별 사용횟수 갱신
                    for (int x = 0; x < num; ++x) { // [i-k][j]마저 갱신
                        piececnt[i][j][x] += piececnt[i - k][j][x];
                    }
                }
            }
            // 가로
            for (int k = 1; k < j; ++k) { // 분할 할 너비
                if (cost[i][k] + cost[i][j - k] > cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[i][j - k];
                    piececnt[i][j] = piececnt[i][k];
                    for (int x = 0; x < num; ++x) {
                        piececnt[i][j][x] += piececnt[i][j - k][x];
                    }
                }
            }
            // 동일한 최대 매출일 때 조각 개수기 더 많은 경우를 선택
            // 세로
            for (int k = 1; k < i; ++k) { 
                if (cost[k][j] + cost[i - k][j] == cost[i][j]) {
                    vector<int> tcnt = piececnt[k][j]; // 조각 별 사용횟수 복사, 벡터 통째로 복사
                    for (int x = 0; x < num; ++x) {
                        tcnt[x] += piececnt[i - k][j][x];
                    }
                    // tcnt: 현재 세로 분할로 인해 생긴 두 조각에서 사용된 조각 수의 합
                    // piececnt: 기존 기록된 최대 매출을 낸 분할에서 사용된 조각 수의 합
                    if (accumulate(tcnt.begin(), tcnt.end(), 0) > 
                        accumulate(piececnt[i][j].begin(), piececnt[i][j].end(), 0)) { 
                        piececnt[i][j] = tcnt;
                    }
                }
            }
            // 가로
            for (int k = 1; k < j; ++k) { 
                if (cost[i][k] + cost[i][j - k] == cost[i][j]) {
                    vector<int> tcnt = piececnt[i][k];
                    for (int x = 0; x < num; ++x) {
                        tcnt[x] += piececnt[i][j - k][x];
                    }
                    if (accumulate(tcnt.begin(), tcnt.end(), 0) > 
                        accumulate(piececnt[i][j].begin(), piececnt[i][j].end(), 0)) {
                        piececnt[i][j] = tcnt;
                    }
                }
            }
        }
    }

    // 결과 출력
    cout << cost[h][w] << endl; // 최대 매출
    for (int i = 0; i < num; ++i) {
        cout << piececnt[h][w][i] << ' '; // 각 조각의 판매 수량
    }
    cout << endl;
}

int main() {
    // 입력
    int h, w, num;
    cin >> h >> w;
    cin >> num;
    vector<vector<int>> pieces(num, vector<int>(3));
    for (int i = 0; i < num; ++i) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    // 문제 해결
    cuttingBrownie(h, w, num, pieces);
    return 0;
}
