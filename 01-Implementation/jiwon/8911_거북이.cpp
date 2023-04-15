//
//  main.cpp
//  baekjoon
//
//  Created by 신지원 on 2023/04/14.
//
// 답은 잘 나오는데 자꾸 틀렸대요 ㅠㅠ 도대체 왜 틀렸을까요? 다섯시간 동안 고쳤어요 ㅠㅠ
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

int n,m,x,y,k;
vector<int> dice(7);
//[1] [2] [3] [4] [5] [6]
int MAP[20][20];

void go(int num){
    
    if(num == 1){
        //east
        //array 배열로 할라니까 에러가 난다 할당할 수 없다나 ...
        dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
    }
    if(num == 2){
        //west
        dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
    }
    if(num == 3){
        //book
        dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
    }
    if(num == 4){
        //nam
        dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
    }
    
    if(MAP[y][x] == 0) MAP[y][x] = dice[6];
    else dice[6] = MAP[y][x];
    
    cout << dice[1] << "\n";
    
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> MAP[i][j];
        }
    }
    
    int num[k];
    for(int i=0;i<k;i++){
        cin >> num[i];
    }
    
    for(int i=0;i<k;i++){
        
        if(num[i] == 1){
            if(x+1 < m){
                x++; go(1);
            }
        }
        
        if(num[i] == 2){
            if(x != 0){
                x--; go(2);
            }
        }
        
        if(num[i] == 3){
            if(y != 0){
                y--; go(3);
            }
        }
        
        if(num[i] == 4){
            if(y+1 < n){
                y++; go(4);
            }
        }
        
        //cout <<"k:" << num[i] << " "<< x << " " << y << " " << MAP[y][x] << "\n";
        //for(int i=1;i<7;i++) cout << dice[i] << " ";
        //cout << "\n";
        
    }
    
    return 0;
}
