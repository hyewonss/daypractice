#include <iostream>
#include <vector>

using namespace std;

// #include <>



struct Block {
    int rows;
    int cols;
};

int cuttingBrownie(int h, int w, int num,vector<vector<int>> pieces) {
    
    //조각별 가격 저장할 배열 
    vector<vector<int>> price(h+1, vector<int>(w+1, 0));

    //입력받은 조각 모양 저장
    vector<Block> blockList;
    
    //입력받은 조각의 가격 저장
    for (int i = 0; i < num; i++) {
        int height = pieces[i][0];
        int width = pieces[i][1];
        int value = pieces[i][2];

        price[height][width] = value; //가격 저장
        blockList.push_back({ height,width });
    }


    //모양별 개수 저장할 배열
    vector<vector<vector<int>>> count(h + 1, vector<vector<int>>(w + 1, vector<int>(blockList.size(), 0)));

    for (int i = 0; i < num; i++) {
        int height = pieces[i][0];
        int width = pieces[i][1];

        if ((blockList[i].rows == height) & (blockList[i].cols == width)) {
            count[height][width][i] = 1;
        }
    }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
					
					//세로로 자르기
					for (int k = 0; k < i; k++) {
								int new_price = price[i - k][j] + price[k][j];
								if (new_price > price[i][j]) {
										price[i][j] = new_price; //가격 업데이트
										//조각 수 업데이트
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												count[i][j][idx] = count[i - k][j][idx] + count[k][j][idx];
										}
								}

								else if (new_price == price[i][j]) { //가격이 동일한 경우
										//조각이 더 많은 것 선택
										int new_cnt = 0;
										int curr_cnt = 0;
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												new_cnt += count[i - k][j][idx] + count[k][j][idx];
												curr_cnt += count[i][j][idx];              
										}
										if (new_cnt > curr_cnt)
												price[i][j] = new_price;
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												count[i][j][idx] = count[i-k][j][idx] + count[k][j][idx];
										}
								}
						}


				//가로로 자르기
						for (int k = 0; k < j; k++) {
								int new_price = price[i][j - k] + price[i][k];
								if (new_price > price[i][j]) {
										price[i][j] = new_price;
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												count[i][j][idx] = count[i][j - k][idx] + count[i][k][idx];                            
										}
								}
								else if (new_price == price[i][j]) {
										int new_cnt = 0;
										int curr_cnt = 0;
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												new_cnt += count[i][j - k][idx] + count[i][k][idx];
												curr_cnt += count[i][j][idx];
										}

										if (new_cnt > curr_cnt) {
												price[i][j] = new_price;
										}
										for (size_t idx = 0; idx < blockList.size(); idx++) {
												count[i][j][idx] = count[i][j - k][idx] + count[i][k][idx];
										}

								}

						} 
				}
					
					
			
						
		}

    cout << price[h][w] << endl;
		for (size_t idx = 0; idx < blockList.size(); idx++) {
        cout << count[h][w][idx]<<" ";
    }
    return 0;
}

int main(){
    // input
    int h, w, price, num;
    cin >> h >> w;
    cin >> num;
    vector<vector<int>> pieces;
    for(int i=0; i<num; ++i){
        vector<int> piece(3);
        cin >> piece[0] >> piece[1] >> piece[2];
			  pieces.push_back(piece);
    }


	
 // cout << cuttingBrownie(h,w,num,pieces) << endl;
	cuttingBrownie(h,w,num,pieces);
}