#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<pair<pair<int, int>, int>> warmer;
int room[21][21] = {0};
vector<pair<int, int>> inspect;
int walls[21][21][4] = {0};
int visit[21][21] = {0};
int visit_temp[21][21][4] = {0};
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};


void wind_dfs(int x, int y, int dir, int t){
    if(t == 0) return;
    
    int go_straight = dir, go_left, go_right;
    if(dir == 0){
        go_left = 2;
        go_right = 3;
    }
    else if(dir == 1){
        go_left = 3;
        go_right = 2;
    }
    else if(dir == 2){
        go_left = 1;
        go_right = 0;
    }
    else if(dir == 3){
        go_left = 0;
        go_right = 1;
    }

    int cant_straight = 0, cant_left = 0, cant_right = 0;

    if(visit[x+dx[go_straight]][y+dy[go_straight]] == 1 || !(x+dx[go_straight] >= 1 && x+dx[go_straight] <= R && y+dy[go_straight] >= 1 && y+dy[go_straight] <= C)){
        cant_straight = 1;
    }
    if(visit[x+dx[go_left]+dx[go_straight]][y+dy[go_left]+dy[go_straight]] == 1 || !(x+dx[go_left]+dx[go_straight] >= 1 && x+dx[go_left]+dx[go_straight] <= R && y+dy[go_left]+dy[go_straight] >= 1 && y+dy[go_left]+dy[go_straight] <= C)){
        cant_left = 1;
    }
    if(visit[x+dx[go_right]+dx[go_straight]][y+dy[go_right]+dy[go_straight]] == 1 || !(x+dx[go_right]+dx[go_straight] >= 1 && x+dx[go_right]+dx[go_straight] <= R && y+dy[go_right]+dy[go_straight] >= 1 && y+dy[go_right]+dy[go_straight] <= C)){
        cant_right = 1;
    }

    if(cant_straight == 0 && walls[x][y][go_straight] == 0){
        visit[x+dx[go_straight]][y+dy[go_straight]] = 1;
        room[x+dx[go_straight]][y+dy[go_straight]] += t;
        wind_dfs(x+dx[go_straight], y+dy[go_straight], dir, t-1);
    }
    if(cant_left == 0 && walls[x][y][go_left] == 0 && walls[x+dx[go_left]][y+dy[go_left]][go_straight] == 0){
        visit[x+dx[go_left]+dx[go_straight]][y+dy[go_left]+dy[go_straight]] = 1;
        room[x+dx[go_left]+dx[go_straight]][y+dy[go_left]+dy[go_straight]] += t;
        wind_dfs(x+dx[go_left]+dx[go_straight], y+dy[go_left]+dy[go_straight], dir, t-1);
    }
    if(cant_right == 0 && walls[x][y][go_right] == 0 && walls[x+dx[go_right]][y+dy[go_right]][go_straight] == 0){
        visit[x+dx[go_right]+dx[go_straight]][y+dy[go_right]+dy[go_straight]] = 1;
        room[x+dx[go_right]+dx[go_straight]][y+dy[go_right]+dy[go_straight]] += t;
        wind_dfs(x+dx[go_right]+dx[go_straight], y+dy[go_right]+dy[go_straight], dir, t-1);
    }
}

void temper_adjust(){
    int room_temp[21][21] = {0};
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            for(int k=0;k<4;k++){
                if(visit_temp[i][j][k] == 0 && i+dx[k] >= 1 && i+dx[k] <= R && j+dy[k] >= 1 && j+dy[k] <= C && walls[i][j][k] == 0){
                    int gap;
                    if(k%2 == 0){
                        visit_temp[i][j][k] = 1;
                        visit_temp[i+dx[k]][j+dy[k]][k+1] = 1;
                    }
                    else{
                        visit_temp[i][j][k] = 1;
                        visit_temp[i+dx[k]][j+dy[k]][k-1] = 1;
                    }
                    if(room[i][j] > room[i+dx[k]][j+dy[k]]){
                        gap = room[i][j] - room[i+dx[k]][j+dy[k]];
                        room_temp[i][j] -= gap/4;
                        room_temp[i+dx[k]][j+dy[k]] += gap/4;
                    }
                    else if(room[i][j] < room[i+dx[k]][j+dy[k]]){
                        gap = room[i+dx[k]][j+dy[k]] - room[i][j];
                        room_temp[i][j] += gap/4;
                        room_temp[i+dx[k]][j+dy[k]] -= gap/4;
                    }
                }
            }
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            room[i][j] += room_temp[i][j];
        }
    }
}

void decrease_outside(){
    for(int i=1;i<=R;i++){
        if(room[i][1] > 0){
            room[i][1]--;
        }
        if(room[i][C] > 0){
            room[i][C]--;
        }
    }
    for(int i=2;i<=C-1;i++){
        if(room[1][i] > 0){
            room[1][i]--;
        }
        if(room[R][i] > 0){
            room[R][i]--;
        }
    }
}

int main(void){
    int K;
    cin >> R >> C >> K;

    int num;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> num;
            if(num >= 1 && num <= 4){
                warmer.push_back(make_pair(make_pair(i, j), num-1));
            }
            else if(num == 5){
                inspect.push_back(make_pair(i, j));
            }
        }
    }
    int W;
    cin >> W;
    int x, y, t;
    for(int i=0;i<W;i++){
        cin >> x >> y >> t;
        if(t == 0){
            walls[x][y][2] = 1;
            walls[x-1][y][3] = 1;
        }
        else{
            walls[x][y][0] = 1;
            walls[x][y+1][1] = 1;
        }
    }

    int chocolate = 0;
    while(chocolate <= 100){
        for(int i=0;i<warmer.size();i++){
            if(walls[warmer[i].first.first][warmer[i].first.second][warmer[i].second] == 1){
                continue;
            }
            for(int j=1;j<=R;j++){
                for(int k=1;k<=C;k++){
                    visit[j][k] = 0;
                }
            }
            visit[warmer[i].first.first+dx[warmer[i].second]][warmer[i].first.second+dy[warmer[i].second]] = 1;
            room[warmer[i].first.first+dx[warmer[i].second]][warmer[i].first.second+dy[warmer[i].second]] += 5;
            wind_dfs(warmer[i].first.first+dx[warmer[i].second], warmer[i].first.second+dy[warmer[i].second], warmer[i].second, 4);
        }
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                for(int k=0;k<4;k++){
                    visit_temp[i][j][k] = 0;
                }
            }
        }
        temper_adjust();
        decrease_outside();

        chocolate++;
        
        int restart = 0;
        for(int i=0;i<inspect.size();i++){
            if(room[inspect[i].first][inspect[i].second] < K){
                restart = 1;
                break;
            }
        }
        if(restart == 0){
            break;
        }
    }
    cout << chocolate;
}