#include <iostream>

using namespace std;

int N, M;
int grid[21][21] = {0};
int visit[21][21] = {0};
int rainbow_visit[202][21][21] = {0};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int group_n, group_scale, rainbow_n;
int max_group = 0, max_rainbow, max_group_num;
int score = 0;

void dfs(int x, int y, int color){
    for(int i=0;i<4;i++){
        if(x+dx[i] >= 1 && x+dx[i] <= N && y+dy[i] >= 1 && y+dy[i] <= N){
            if(grid[x+dx[i]][y+dy[i]] == color){
                if(visit[x+dx[i]][y+dy[i]] == 0){
                    visit[x+dx[i]][y+dy[i]] = group_n;
                    group_scale++;
                    dfs(x+dx[i], y+dy[i], color);
                }
            }
            else if(grid[x+dx[i]][y+dy[i]] == 0){
                if(rainbow_visit[group_n][x+dx[i]][y+dy[i]] == 0){
                    rainbow_visit[group_n][x+dx[i]][y+dy[i]] = 1;
                    rainbow_n++;
                    group_scale++;
                    dfs(x+dx[i], y+dy[i], color);
                }
            }
        }
    }
}

void find_group(){
    group_n = 1;
    max_group = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(visit[i][j] == 0 && grid[i][j] >= 1){
                visit[i][j] = group_n;
                group_scale = 1;
                rainbow_n = 0;
                for(int i=1;i<=N;i++){
                    for(int j=1;j<=N;j++){
                        rainbow_visit[group_n][i][j] = 0;
                    }
                }
                dfs(i, j, grid[i][j]);

                if(max_group <= group_scale){
                    if(max_group == group_scale){
                        if(max_rainbow <= rainbow_n){
                            //update
                            max_rainbow = rainbow_n;
                            max_group_num = group_n;
                        }
                    }
                    else{
                        //update
                        max_group = group_scale;
                        max_rainbow = rainbow_n;
                        max_group_num = group_n;
                    }
                }

                group_n++;
            }
        }
    }
}

void remove_group(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(visit[i][j] == max_group_num || rainbow_visit[max_group_num][i][j] == 1){
                grid[i][j] = -2;
            }
        }
    }
    score += max_group * max_group;
}

void gravity(){
    for(int i=N-1;i>=1;i--){
        for(int j=1;j<=N;j++){
            if(grid[i][j] >= 0){
                int temp = i;
                while(temp+1 <= N && grid[temp+1][j] == -2){
                    temp++;
                }
                if(temp != i){
                    grid[temp][j] = grid[i][j];
                    grid[i][j] = -2;
                }
            }
        }
    }
}

void rotate(){
    int temp[21][21] = {0};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            temp[N-j+1][i] = grid[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            grid[i][j] = temp[i][j];
        }
    }
}

int main(void){
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> grid[i][j];
        }
    }

    while(1){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                visit[i][j] = 0;
            }
        }
        find_group();
        if(max_group <= 1){
            break;
        }
        remove_group();
        gravity();
        rotate();
        gravity();
    }

    cout << score;
}