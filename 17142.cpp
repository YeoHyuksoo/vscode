#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lab[51][51] = {0};
int lab_cp[51][51] = {0};
vector<pair<int, int>> virus;
int N, M, V=0;
vector<pair<int, int>> s_virus;
vector<pair<int, int>> s_virus_cp;
int blank = 0, min_time = 3000;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void spread(int t, int fill){
    int sx, sy;

    if (t==min_time) return;

    for(int i=s_virus_cp.size()-1;i>=0;i--){
        sx = s_virus_cp[i].first;
        sy = s_virus_cp[i].second;
        s_virus_cp.erase(s_virus_cp.begin() + i);
        for(int j=0;j<4;j++){
            if(sx+dx[j]>=0 && sx+dx[j]<N && sy+dy[j]>=0 && sy+dy[j]<N){
                if(lab_cp[sx+dx[j]][sy+dy[j]] == 0){ // 바이러스 복제
                    fill++;
                    lab_cp[sx+dx[j]][sy+dy[j]] = -1;
                    s_virus_cp.push_back(make_pair(sx+dx[j], sy+dy[j]));
                }
                else if(lab_cp[sx+dx[j]][sy+dy[j]] == 2){ // 비활성을 활성으로
                    lab_cp[sx+dx[j]][sy+dy[j]] = -1;
                    s_virus_cp.push_back(make_pair(sx+dx[j], sy+dy[j]));
                }
            }
        }
    }
    if(fill==blank){
        if(min_time>t){
            min_time = t;
        }
        return;
    }
    else if(s_virus_cp.empty()){
        return;
    }
    spread(t+1, fill);
}

void combination(int cur_size, int k){
    if (cur_size == M){
        s_virus_cp = {s_virus.begin(), s_virus.end()};
        for(int i=0;i<N;i++){
            copy(&lab[i][0], &lab[i][0]+N, &lab_cp[i][0]);
        }
        for(int i=0;i<M;i++){
            lab_cp[s_virus[i].first][s_virus[i].second] = -1;
        }
        spread(1, 0);
        s_virus_cp.clear();
        return;
    }
    else if(V>k && V-k >= M-cur_size){
        s_virus.push_back(virus[k]);
        combination(cur_size+1, k+1);
        s_virus.pop_back();
        combination(cur_size, k+1);
    }
    
}

int main(void){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> lab[i][j];
            if(lab[i][j]==2){
                virus.push_back(make_pair(i, j));
                V++;
            }
            else if(lab[i][j]==0){
                blank++;
            }
        }
    }
    if(blank==0){
        cout << 0;
        return 0;
    }
    combination(0, 0);
    
    if(min_time==3000){
        cout << -1;
    }
    else{
        cout << min_time;
    }
    return 0;
}