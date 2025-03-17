#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void cuttingBrownie(int h, int w, int num, const vector<vector<int>>& pieces) {
	//조각별 가격
	vector<vector<int>> cost(h+1, vector<int>(w+1, 0)); 
	// 조각별 판매량 저장 (입력된 순서대로 판매량 기록)
    vector<int> salesCount(num, 0);
	//입력받은 조각 모양 
	// vector<vector<int>> piececnt(h + 1, vector<int>(w + 1, 0));
	//조각별 판매수량
	// unordered_map<int, int> cnt;
	//입력받은 조각의 가격저장
	for (int i = 0; i < num; ++i){
		int ph = pieces[i][0];
		int pw = pieces[i][1];
		int price = pieces[i][2];
		cost[ph][pw] = price;
		// piececnt[ph][pw] = 1;
	}
	
	for (int i = 1; i <= h; ++i){
		for (int j = 1; j <= w; ++j){
			//가로
			for (int k = 1; k < i; ++k){  //나눌 높이 설정
				if(cost[k][j] + cost[i-k][j] > cost[i][j]){
					cost[i][j] = cost[k][j]+cost[i-k][j];
					// piececnt[i][j] = piececnt[k][j]+piececnt[i-k][j];
				} else if(cost[k][j]+cost[i-k][j] == cost[i][j]){
					// piececnt[i][j] = max(piececnt[i][j], piececnt[k][j] + piececnt[i - k][j]);
				}
			}
			for (int k = 1; k < j; ++k){
				if(cost[i][k]+cost[i][j-k] > cost[i][j]){
					cost[i][j] = cost[i][k]+cost[i][j-k];
					// piececnt[i][j] = piececnt[i][k] + piececnt[i][j - k];
				} else if(cost[i][k]+cost[i][j-k] == cost[i][j]){
					// piececnt[i][j] = max(piececnt[i][j], piececnt[i][k] + piececnt[i][j - k]);
				}
			}
			// cout << piececnt[i][j] << ". ";
			// cout << "\n";
			// cout << cost[i][j] << ",, ";
		}
	}

    // 판매 수량 계산
    int remainingCost = cost[h][w];
    for (int i = 0; i < num; ++i) {
        int ph = pieces[i][0];
        int pw = pieces[i][1];
        int price = pieces[i][2];
        // 해당 조각이 현재 크기 내에서 얼마나 사용되었는지 계산
        if (ph <= h && pw <= w && price > 0) {
            int count = remainingCost / price;
            salesCount[i] += count;
            remainingCost -= count * price; // 사용한 금액을 차감
        }
    }
													
	// 판매 수량 계산
//   for (int i = 0; i < num; ++i){
//     int ph = pieces[i][0];
//     int pw = pieces[i][1];
//     if (ph<=h && pw<=w) {
//   	int count = cost[h][w] / cost[ph][pw];
//         cnt[i] += count;
//     }
//   }
	cout << cost[h][w] << endl;
	for (int i = 0; i < num; ++i) {
        cout << salesCount[i] << ' '; // 각 조각의 판매 수량 출력
    }
    cout << endl;
	// for (int idx = 0; idx < num; ++idx){
	// 	cout << cnt[idx] << ' ';
	// }
}

int main() {
    // Input
    int h, w, num;
    cin >> h >> w;
    cin >> num;
    vector<vector<int>> pieces(num, vector<int>(3));
    for (int i = 0; i < num; ++i) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    // Solve
    cuttingBrownie(h, w, num, pieces);
    return 0;
}