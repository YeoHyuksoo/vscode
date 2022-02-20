#include <iostream>

using namespace std;

int space[505][505] = {0};
int n, m;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int visit[505][505] = {0};
int maxtotal = 0;
int shapes[4][3][2] = {
    {{0, 1}, {-1, 1}, {0, 2}},
    {{-1, 0}, {0, 1}, {1, 0}},
    {{0, 1}, {1, 1}, {0, 2}},
    {{0, 1}, {-1, 1}, {1, 1}},
};

void dfs(int x, int y, int cur, int total){
    if(cur==4){
        if(maxtotal<total){
            maxtotal = total;
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(visit[x+dx[i]][y+dy[i]]==1 || space[x+dx[i]][y+dy[i]]==0){
            continue;
        }
        visit[x+dx[i]][y+dy[i]]=1;
        dfs(x+dx[i], y+dy[i], cur+1, total+space[x+dx[i]][y+dy[i]]);
        visit[x+dx[i]][y+dy[i]]=0;
    }
}

void getsum(int idx){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            int total = space[i][j];
            for(int k=0;k<3;k++){
                total+=space[i+shapes[idx][k][0]][j+shapes[idx][k][1]];
            }
            if(maxtotal<total){
                maxtotal = total;
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin >> space[i][j];
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            visit[i][j] = 1;
            dfs(i, j, 1, space[i][j]);
            visit[i][j] = 0;
        }
    }
    for(int i=0;i<4;i++){
        getsum(i);
    }
    printf("%d", maxtotal);
    return 0;
}