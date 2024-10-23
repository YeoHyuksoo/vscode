#include <iostream>

using namespace std;

int N, M;
int map[21][21] = {0};
struct DICE{
    int d1 = 1;
    int d2 = 2;
    int d3 = 3;
    int d4 = 4;
    int d5 = 5;
    int d6 = 6;
    int x = 1;
    int y = 1;
    int dir = 0;
};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
DICE dice;
int visit[21][21] = {0};
int C, score = 0;

void roll_dice(){
    if(dice.x+dx[dice.dir] >= 1 && dice.x+dx[dice.dir] <= N && dice.y+dy[dice.dir] >= 1 && dice.y+dy[dice.dir] <= M){
        dice.x += dx[dice.dir];
        dice.y += dy[dice.dir];
    }
    else{
        dice.dir = (dice.dir+2)%4;
        dice.x += dx[dice.dir];
        dice.y += dy[dice.dir];
    }
}

void update_dice(){
    int temp_d[7] = {0};
    temp_d[1] = dice.d1;
    temp_d[2] = dice.d2;
    temp_d[3] = dice.d3;
    temp_d[4] = dice.d4;
    temp_d[5] = dice.d5;
    temp_d[6] = dice.d6;

    if(dice.dir == 0){
        dice.d1 = temp_d[4];
        dice.d3 = temp_d[1];
        dice.d4 = temp_d[6];
        dice.d6 = temp_d[3];
    }
    else if(dice.dir == 1){
        dice.d1 = temp_d[2];
        dice.d2 = temp_d[6];
        dice.d5 = temp_d[1];
        dice.d6 = temp_d[5];
    }
    else if(dice.dir == 2){
        dice.d1 = temp_d[3];
        dice.d3 = temp_d[6];
        dice.d4 = temp_d[1];
        dice.d6 = temp_d[4];
    }
    else if(dice.dir == 3){
        dice.d1 = temp_d[5];
        dice.d2 = temp_d[1];
        dice.d5 = temp_d[6];
        dice.d6 = temp_d[2];
    }
}

void dfs(int B, int x, int y){
    for(int i=0;i<4;i++){
        if(x+dx[i] >= 1 && x+dx[i] <= N && y+dy[i] >= 1 && y+dy[i] <= M){
            if(visit[x+dx[i]][y+dy[i]] == 0 && map[x+dx[i]][y+dy[i]] == B){
                visit[x+dx[i]][y+dy[i]] = 1;
                C++;
                dfs(B, x+dx[i], y+dy[i]);
            }
        }
    }
}

void get_score(){
    int B = map[dice.x][dice.y];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visit[i][j] = 0;
        }
    }

    C = 1;
    visit[dice.x][dice.y] = 1;
    dfs(B, dice.x, dice.y);
    
    score += B*C;
}

void change_dir(){
    if(dice.d6 > map[dice.x][dice.y]){
        dice.dir = (dice.dir+1) % 4;
    }
    else if(dice.d6 < map[dice.x][dice.y]){
        dice.dir--;
        if(dice.dir == -1){
            dice.dir = 3;
        }
    }
}

void dice_play(){
    roll_dice();
    update_dice();
    get_score();
    change_dir();
}

int main(void){

    int K;
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<K;i++){
        dice_play();
    }

    cout << score;
}