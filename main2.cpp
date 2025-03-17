// #include <iostream>
// #include <vector>

// using namespace std;

// // void view(int** cost, int h, int w) {
// // 	for (int i=0; i<h; i++) {
// // 		for (int j=0;j<w; i++)
// // 			cout << cost[i][j];
// // 		cout << endl;
// // 	}
// // }

// void cuttingBrownie(int h, int w, int num, vector<vector<int>> pieces) {
// 	//1*2 = max(1*2, 1*1*2)
// 	//2*1 = max(2*1, 1*1*2)
// 	//2*2 = max(2*2, 1*1*4, 2*1*2, 1*2*2) 2*1과 1*2에 이미 1*1*4가 반영되어 있음
// 	//-> 초기에 첫 줄(가로, 세로)를 채우고 이후로 가로 기준으로 처음부터 끝까지 dp 후 세로 기준으로 처음부터 끝까지 dp
// 	//를 사용하면 기존 값이랑 새로운 값이랑 max해서 들어가니까 순서 상관없이 계산 가능
// 	//브라우니 사이즈도 지속적으로 기록하면 계산 가능
// 	//max로 하면 브라우니 사이즈를 계산 못 해서 if문으로 대체
	
// 	int cost[h][w];
// 	int count[h][w][num];
	
// 	for (int i=0; i<h; i++) {
// 		for (int j=0; j<w; j++) {
// 			cost[i][j]=0;
// 			for (int k=0; k<num; k++)
// 				count[i][j][k] = 0;
// 		}
// 	}
	
	
// 	for (int i=0; i<num; i++) {
// 		cost[pieces[i][0]-1][pieces[i][1]-1] = pieces[i][2];
// 		count[pieces[i][0]-1][pieces[i][1]-1][i] = 1;
// 	}
		
// 	int temp;
// 	int a;

	
// 	// cout<<endl;
// 	// for (int i=0; i<h; i++) {
// 	// 	for (int j=0; j<w; j++) {
// 	// 		cout<<"[";
// 	// 		for (int k=0; k<num; k++)
// 	// 			cout<<count[i][j][k]<<" ";
// 	// 		cout<<"] ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }
	
// 	// 	cout<<endl;
// 	// for (int i=0; i<h; i++)
// 	// {
// 	// 	for (int j=0;j<w; j++)
// 	// 		cout << cost[i][j] << " ";
// 	// 	cout << endl;
// 	// }
	
		
// 	//세로 dp
// 	for (int m=0; m<3; m++) {
// 		for (int col=0; col<w; col++) {
// 			for (int i=1; i<h; i++) {
// 				temp = cost[i][col];
// 				a=i-1;
// 				while(a >= i/2) {
// 					// temp = max(temp,cost[a][col]+cost[i-a-1][col]);
// 					if (temp <= cost[a][col]+cost[i-a-1][col]) {
// 							temp = cost[a][col]+cost[i-a-1][col];
// 							for (int k=0; k<num; k++)
// 								count[i][col][k]=count[a][col][k]+count[i-a-1][col][k];
// 					}
// 					a--;
// 				}
// 				cost[i][col] = temp;
// 			}
// 		}

// 		//가로 dp	
// 		for (int row=0; row<h; row++) {
// 			for (int i=1; i<w; i++) {
// 				temp = cost[row][i];
// 				a = i-1;
// 				while(a >= i/2) {
// 					// temp = max(temp,cost[row][a]+cost[row][i-a-1]);
// 					if (temp <= cost[row][a]+cost[row][i-a-1]) {
// 						temp = cost[row][a]+cost[row][i-a-1];
// 						for (int k=0; k<num; k++)
// 							count[row][i][k]=count[row][a][k]+count[row][i-a-1][k];
// 					}
// 					a--;
// 				}
// 			cost[row][i] = temp;
// 			}
// 		}
// 	}
	
// 	int y=h-1;
// 	int x=w-1;
// 	int y_sum=0, x_sum=0;
// 	int y_cost=0, x_cost=0;	
	
// 	cout<< cost[h-1][w-1] << endl;
	
// 	for (int k=0; k<num; k++)
// 		cout<<count[y][x][k]<<" ";
// }
// int main(){
//     // input
//     int h, w, num;
//     cin >> h >> w;
//     cin >> num;
//     vector<vector<int>> pieces;
//     for (int i = 0; i < num; ++i) {
//         vector<int> piece(3);
//         cin >> piece[0] >> piece[1] >> piece[2];
//         pieces.push_back(piece);
//     }


// 	cuttingBrownie(h,w,num,pieces);
// 	// cout << cuttingBrownie() << endl;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;

// void cuttingBrownie(int h, int w, int num, const vector<vector<int>>& pieces) {
//     // DP 배열 초기화
//     vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
//     vector<vector<int>> pieceCount(h + 1, vector<int>(w + 1, 0));
//     unordered_map<int, int> salesCount; // 조각별 판매 수량

//     // 조각 정보 저장
//     for (int i = 0; i < num; ++i) {
//         int ph = pieces[i][0];
//         int pw = pieces[i][1];
//         int price = pieces[i][2];
//         dp[ph][pw] = max(dp[ph][pw], price); // 초기 가격 설정
//         pieceCount[ph][pw] = 1;             // 초기 조각 수량 설정
//     }

//     // DP 계산
//     for (int i = 1; i <= h; ++i) {
//         for (int j = 1; j <= w; ++j) {
//             for (int k = 1; k < i; ++k) { // 가로로 자르기
//                 if (dp[k][j] + dp[i - k][j] > dp[i][j]) {
//                     dp[i][j] = dp[k][j] + dp[i - k][j];
//                     pieceCount[i][j] = pieceCount[k][j] + pieceCount[i - k][j];
//                 } else if (dp[k][j] + dp[i - k][j] == dp[i][j]) {
//                     pieceCount[i][j] = max(pieceCount[i][j], pieceCount[k][j] + pieceCount[i - k][j]);
//                 }
//             }
//             for (int k = 1; k < j; ++k) { // 세로로 자르기
//                 if (dp[i][k] + dp[i][j - k] > dp[i][j]) {
//                     dp[i][j] = dp[i][k] + dp[i][j - k];
//                     pieceCount[i][j] = pieceCount[i][k] + pieceCount[i][j - k];
//                 } else if (dp[i][k] + dp[i][j - k] == dp[i][j]) {
//                     pieceCount[i][j] = max(pieceCount[i][j], pieceCount[i][k] + pieceCount[i][j - k]);
//                 }
//             }
//         }
//     }

//     // 판매 수량 계산
//     for (int i = 0; i < num; ++i) {
//         int ph = pieces[i][0];
//         int pw = pieces[i][1];
//         if (ph <= h && pw <= w) {
//             int count = dp[h][w] / dp[ph][pw];
//             salesCount[i] += count;
//         }
//     }

//     // 결과 출력
//     cout << dp[h][w] << endl; // 최대 판매 금액
//     for (int i = 0; i < num; ++i) {
//         cout << salesCount[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     // Input
//     int h, w, num;
//     cin >> h >> w;
//     cin >> num;
//     vector<vector<int>> pieces(num, vector<int>(3));
//     for (int i = 0; i < num; ++i) {
//         cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
//     }

//     // Solve
//     cuttingBrownie(h, w, num, pieces);
//     return 0;
// }
