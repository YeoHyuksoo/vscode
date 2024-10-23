#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;
int space[51][51] = {0};
int visit[51][51] = {0};
int union_n = -1;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > unions[2500];

void open_dfs(int x, int y, int union_n){
    int gap;
    for(int i=0;i<4;i++){
        if(x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<N && visit[x+dx[i]][y+dy[i]]==0){
            gap = abs(space[x][y]-space[x+dx[i]][y+dy[i]]);
            if(gap>=L && gap<=R){
                unions[union_n].push_back(make_pair(x+dx[i], y+dy[i]));
                visit[x+dx[i]][y+dy[i]] = 1;
                open_dfs(x+dx[i], y+dy[i], union_n);
            }
        }
    }
}

void n_separate(){
    int n=1;
    while(unions[n].size()>0){
        int total = 0;
        int union_siz = unions[n].size();
        for(int i=0;i<union_siz;i++){
            total+=space[unions[n][i].first][unions[n][i].second];
        }
        int sep = total/union_siz;
        for(int i=0;i<union_siz;i++){
            space[unions[n][i].first][unions[n][i].second] = sep;
        }
        n++;
    }
}

int main(void){
    cin >> N >> L >> R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> space[i][j];
        }
    }
    int day = 0;
    while(union_n!=0){
        union_n = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visit[i][j] == 0){
                    unions[union_n+1].push_back(make_pair(i, j));
                    visit[i][j] = 1;
                    open_dfs(i, j, union_n+1);
                    if(unions[union_n+1].size() == 1){
                        unions[union_n+1].clear();
                    }
                    else{
                        union_n++;
                    }
                }
            }
        }
        if(union_n==0){
            break;
        }
        n_separate();
        day++;
        for(int i=0;i<N;i++){
            memset(visit[i], 0, sizeof(visit[i]));
        }
        for(int i=0;i<=union_n+1;i++){
            unions[i].clear();
        }
    }
    cout << day;
    
}