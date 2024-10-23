#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[21][21]={0};
int visit[21][21]={0};
int n, f;
int p[401][2]={0};
int d[401][2]={0};
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int px, py, mind=400;

void find_bfs(int drx, int dry, int dist){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(drx, dry), 1));

    while(q.empty() == 0){
        drx = q.front().first.first;
        dry = q.front().first.second;
        dist = q.front().second;
        q.pop();
        if(dist>mind){
            continue;
        }
        for(int i=0;i<4;i++){
            if(visit[drx+dx[i]][dry+dy[i]]==1 || drx+dx[i]<=0 || drx+dx[i]>n || dry+dy[i]<=0 || dry+dy[i]>n){
                continue;
            }
            if(map[drx+dx[i]][dry+dy[i]]!=-1){
                if(map[drx+dx[i]][dry+dy[i]]!=0){
                    if(dist<=mind){
                        if(dist==mind){
                            if(px>drx+dx[i]){
                                px = drx+dx[i];
                                py = dry+dy[i];
                            }
                            else if(px==drx+dx[i]){
                                if(py>dry+dy[i]){
                                    px = drx+dx[i];
                                    py = dry+dy[i];
                                }
                            }
                        }
                        else{
                            mind = dist;
                            px = drx+dx[i];
                            py = dry+dy[i];
                        }
                        visit[drx+dx[i]][dry+dy[i]] = 1;
                        q.push(make_pair(make_pair(drx+dx[i], dry+dy[i]), dist+1));
                        
                    }
                }
                else{
                    visit[drx+dx[i]][dry+dy[i]] = 1;
                    q.push(make_pair(make_pair(drx+dx[i], dry+dy[i]), dist+1));
                }
            }
        }
    }
    
}

void work_dfs(int drx, int dry, int pidx, int dist){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(drx, dry), make_pair(pidx, dist)));
    
    while(q.empty() == 0){
        drx = q.front().first.first;
        dry = q.front().first.second;
        pidx = q.front().second.first;
        dist = q.front().second.second;
        q.pop();
        if(dist>mind){
            continue;
        }
        if(drx==d[pidx][0] && dry==d[pidx][1]){
            if(dist<mind){
                mind = dist;
            }
            continue;
        }
        for(int i=0;i<4;i++){
            if(visit[drx+dx[i]][dry+dy[i]]==1 || drx+dx[i]<=0 || drx+dx[i]>n || dry+dy[i]<=0 || dry+dy[i]>n){
                continue;
            }
            if(map[drx+dx[i]][dry+dy[i]]!=-1){
                visit[drx+dx[i]][dry+dy[i]] = 1;
                q.push(make_pair(make_pair(drx+dx[i], dry+dy[i]), make_pair(pidx, dist+1)));
            }
        }
    }
}

int main(void){
    int m;
    cin >> n >> m >> f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                map[i][j] = -1;
            }
        }
    }
    int drx, dry;
    cin >> drx >> dry;
    for(int i=1;i<=m;i++){
        cin >> p[i][0] >> p[i][1] >> d[i][0] >> d[i][1];
        map[p[i][0]][p[i][1]] = i;
    }
    for(int i=0;i<m;i++){
        visit[drx][dry] = 1;
        if(map[drx][dry]>0){
            mind = 0;
            px = drx;
            py = dry;
        }
        else{
            mind = 400;
            find_bfs(drx, dry, 1);
        }
        visit[drx][dry] = 0;
        f-=mind;
        if(f<=0 || mind==400){
            printf("-1");
            return 0;
        }
        memset(visit, 0, sizeof(visit));
        drx = px;
        dry = py;
        int pidx = map[drx][dry];
        map[drx][dry] = 0;
        mind = 400;
        visit[drx][dry] = 1;
        work_dfs(drx, dry, pidx, 0);
        visit[drx][dry] = 0;
        f-=mind;
        if(f<0 || mind==400){
            printf("-1");
            return 0;
        }
        f+=mind*2;
        drx = d[pidx][0];
        dry = d[pidx][1];
        memset(visit, 0, sizeof(visit));
        
    }
    printf("%d", f);
}