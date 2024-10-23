#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int M;
vector<int> grid[5][5];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> grid_copy[5][5];
int fish_smell[5][5] = {0};
int sx, sy;
int first_dict = 999, max_kill = 0;
int dict_value[8] = {2, 0, 1, 0, 4, 0, 3, 0};
int visit[5][5] = {0};

void copy_magic(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            grid_copy[i][j] = {grid[i][j].begin(), grid[i][j].end()};
        }
    }
}

void fish_move(){
    vector<int> grid_temp[5][5];

    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=0;k<grid[i][j].size();k++){
                int prev_dir = grid[i][j][k];
                int dir = grid[i][j][k];
                int cant_move = 0;
                while((i+dx[dir] == sx && j+dy[dir] == sy) || fish_smell[i+dx[dir]][j+dy[dir]] >= 1 || !(i+dx[dir] >= 1 && i+dx[dir] <= 4 && j+dy[dir] >= 1 && j+dy[dir] <= 4)){
                    dir--;
                    if(dir == -1){
                        dir = 7;
                    }
                    if(dir == prev_dir){
                        cant_move = 1;
                        break;
                    }
                }
                if(cant_move == 0){
                    grid_temp[i+dx[dir]][j+dy[dir]].push_back(dir);
                }
            }
        }
    }

    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            grid[i][j] = {grid_temp[i][j].begin(), grid_temp[i][j].end()};
        }
    }
}

void shark_move(int cur_move, int cur_dict, int kill_fish, int x, int y){
    if(cur_move == 3){
        if(max_kill <= kill_fish){
            if(max_kill == kill_fish){
                if(first_dict > cur_dict){
                    first_dict = cur_dict;
                }
            }
            else{
                max_kill = kill_fish;
                first_dict = cur_dict;
            }
        }
    }

    for(int i=0;i<8;i+=2){
        if(x+dx[i] >= 1 && x+dx[i] <= 4 && y+dy[i] >= 1 && y+dy[i] <= 4 && visit[x+dx[i]][y+dy[i]] == 0){
            visit[x+dx[i]][y+dy[i]] = 1;
            shark_move(cur_move+1, cur_dict+dict_value[i]*pow(10, 2-cur_move), kill_fish+grid[x+dx[i]][y+dy[i]].size(), x+dx[i], y+dy[i]);
        }
    }
}

void smell_update(){
    
}

int main(void){
    int S;
    cin >> M >> S;

    int x, y, d;
    for(int i=0;i<M;i++){
        cin >> x >> y >> d;
        grid[x][y].push_back(d-1);
    }

    cin >> sx >> sy;
    for(int i=0;i<S;i++){
        copy_magic();
        fish_move();
        first_dict = 999;
        max_kill = 0;
        for(int j=1;j<=4;j++){
            for(int k=1;k<=4;k++){
                visit[j][k] = 0;
            }
        }
        shark_move(0, 0, 0, sx, sy);
        smell_update();
    }

}