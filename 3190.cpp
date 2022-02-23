#include <iostream>
#include <queue>

using namespace std;

int n;
int board[101][101] = {0};
int board_apple[101][101] = {0};
int rotate[10001][2] = {0};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int t=1;

queue<pair<int, int>> snake;

int turn_left(int dir){
    if(dir==0){
        return 3;
    }
    else {
        return dir-1;
    }
}

int turn_right(int dir){
    if (dir==3){
        return 0;
    }
    else{
        return dir+1;
    }
}

void cut_tail(){
    int sx = snake.front().first;
    int sy = snake.front().second;

    snake.pop();
    board[sx][sy] = 0;
    return;
}

void game(int dir, int x, int y){

    if(board[x+dx[dir]][y+dy[dir]]==1 || x+dx[dir]<0 || x+dx[dir]>=n || y+dy[dir]<0 || y+dy[dir]>=n){
        return;
    }

    if(board_apple[x+dx[dir]][y+dy[dir]]==1){
        board[x+dx[dir]][y+dy[dir]] = 1;
        snake.push(make_pair(x+dx[dir], y+dy[dir]));
        board_apple[x+dx[dir]][y+dy[dir]] = 0;
    }

    else{
        board[x+dx[dir]][y+dy[dir]] = 1;
        snake.push(make_pair(x+dx[dir], y+dy[dir]));
        cut_tail();
    }
    
    x+=dx[dir];
    y+=dy[dir];

    if(rotate[t][1] == 1){
        dir = turn_left(dir);
    }

    else if (rotate[t][1] == 2){
        dir = turn_right(dir);
    }

    t++;
    game(dir, x, y);
}

int main(void){
    cin >> n;
    int K, L;
    cin >> K;
    int apple_x, apple_y;
    for(int i=0;i<K;i++){
        cin >> apple_x >> apple_y;
        board_apple[apple_x-1][apple_y-1] = 1;
    }
    cin >> L;
    int time;
    char d;
    for(int i=0;i<L;i++){
        cin >> time >> d;
        if (d=='L'){
            rotate[time][1] = 1;
        }
        else{
            rotate[time][1] = 2;
        }
    }
    board[0][0] = 1;
    snake.push(make_pair(0, 0));
    game(0, 0, 0);

    cout << t;
    return 0;
}