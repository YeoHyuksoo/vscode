#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int favorite[404][4];
int classroom[21][21] = {0};
int location[404][2] = {0};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void take_seat(int n){
    int temp[21][21] = {0};
    for(int i=0;i<4;i++){
        int x = location[favorite[n][i]][0];
        int y = location[favorite[n][i]][1];
        if(x*y != 0){
            for(int j=0;j<4;j++){
                if(x+dx[j] >= 1 && x+dx[j] <= N && y+dy[j] >= 1 && y+dy[j] <= N && classroom[x+dx[j]][y+dy[j]] == 0){
                    temp[x+dx[j]][y+dy[j]]++;
                }
            }
        }
    }
    
    int max_near = 1;
    vector<pair<int, int>> cand;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(temp[i][j] >= max_near){
                if(temp[i][j] > max_near){
                    cand.clear();
                    max_near = temp[i][j];
                }
                cand.push_back({i, j});
            }
        }
    }
    int max_empty = -1, sx, sy;
    if(cand.size() == 1){
        sx = cand[0].first;
        sy = cand[0].second;
    }
    else if(cand.size() == 0){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(classroom[i][j] == 0){
                    int empty = 0;
                    for(int k=0;k<4;k++){
                        if(i+dx[k] >= 1 && i+dx[k] <= N && j+dy[k] >= 1 && j+dy[k] <= N){
                            if(classroom[i+dx[k]][j+dy[k]] == 0){
                                empty++;
                            }
                        }
                    }
                    if(max_empty < empty){
                        sx = i;
                        sy = j;
                        max_empty = empty;
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<cand.size();i++){
            if(classroom[cand[i].first][cand[i].second] == 0){
                int empty = 0;
                for(int k=0;k<4;k++){
                    if(cand[i].first+dx[k] >= 1 && cand[i].first+dx[k] <= N && cand[i].second+dy[k] >= 1 && cand[i].second+dy[k] <= N){
                        if(classroom[cand[i].first+dx[k]][cand[i].second+dy[k]] == 0){
                            empty++;
                        }
                    }
                }
                if(max_empty < empty){
                    sx = cand[i].first;
                    sy = cand[i].second;
                    max_empty = empty;
                }
            }
        }
    }
    location[n][0] = sx;
    location[n][1] = sy;
    classroom[sx][sy] = n;
}

int main(void){
    cin >> N;
    int n;
    for(int i=0;i<N*N;i++){
        cin >> n;
        cin >> favorite[n][0] >> favorite[n][1] >> favorite[n][2] >> favorite[n][3];
        take_seat(n);
    }

    int total = 0;
    for(int i=1;i<=N*N;i++){
        int score = 0;
        for(int j=0;j<4;j++){
            if(location[i][0]+dx[j] >= 1 && location[i][0]+dx[j] <= N && location[i][1]+dy[j] >= 1 && location[i][1]+dy[j] <= N){
                for(int k=0;k<4;k++){
                    if(classroom[location[i][0]+dx[j]][location[i][1]+dy[j]] == favorite[i][k]){
                        score++;
                    }
                }
            }
        }
        if(score != 0){
            total += pow(10, score-1);
        }
    }
    cout << total;
}