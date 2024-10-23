#include <iostream>
#include <vector>

using namespace std;

int ladder[31][31] = {0};
int visit[31][31] = {0};
int N, M, H;
int res = -1;
vector<pair<int, int> > temp;

int check(){
    int row, col;
    for(int i=1;i<=N;i++){
        row = 1;
        col = i;
        while(row<=H){
            if(ladder[row][col]==1){
                col--;
            }
            else if(ladder[row][col]==2){
                col++;
            }
            row++;
        }
        if(col != i){
            return -1;
        }
    }
    return 1;
}

void set_lines(int cur, int n, int sr, int sc){
    if(res==1){
        return;
    }
    if(cur==n){
        for(int i=0;i<temp.size();i++){
            ladder[temp[i].first][temp[i].second] = 2;
            ladder[temp[i].first][temp[i].second+1] = 1;
        }
        res = check();
        for(int i=0;i<temp.size();i++){
            ladder[temp[i].first][temp[i].second] = 0;
            ladder[temp[i].first][temp[i].second+1] = 0;
        }
        return;
    }
    for(int c=sr;c<=N-1;c++){
        for(int r=sc;r<=H;r++){
            if(ladder[r][c]==0 && ladder[r][c+1]==0 && visit[r][c]==0 && visit[r][c+1]==0){
                temp.push_back(make_pair(r, c));
                visit[r][c] = 1;
                visit[r][c+1] = 1;
                set_lines(cur+1, n, r+1, c);
                visit[r][c] = 0;
                visit[r][c+1] = 0;
                temp.pop_back();
            }
        }
    }
}

int main(void){
    cin >> N >> M >> H;
    int a, b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        ladder[a][b] = 2; // can go right
        ladder[a][b+1] = 1; // can go left
    }
    res = check();
    if(res==1){
        cout << 0;
        return 0;
    }

    for(int i=1;i<=3;i++){
        set_lines(0, i, 1, 1);
        if(res==1){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}