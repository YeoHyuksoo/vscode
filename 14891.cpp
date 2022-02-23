#include <iostream>
#include <vector>

using namespace std;

int n, m;
int office[8][8] = {0};
vector<pair<int, pair<int, int>> > cctv;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int office_cp[8][8] = {0};
int total = 0, ans;

void dfs(int cctv_n){
    if(cctv_n == cctv.size()){
        int can_see = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(office_cp[i][j]>0 && office[i][j] == 0){
                    can_see++;
                }
            }
        }
        if(ans > total-can_see){
            ans = total-can_see;
        }
        return;
    }
    int x = cctv[cctv_n].second.first;
    int y = cctv[cctv_n].second.second;
    if(cctv[cctv_n].first == 1){
        int tx, ty;
        tx = x;
        ty = y;
        for(int i=0;i<4;i++){
            vector<pair<int, int>> temp;
            x = tx;
            y = ty;
            while(office[x+dx[i]][y+dy[i]] != 6 && x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m){
                office_cp[x+dx[i]][y+dy[i]]++;
                x+=dx[i];
                y+=dy[i];
                temp.push_back(make_pair(x, y));
            }
            dfs(cctv_n+1);
            for(int j=0;j<temp.size();j++){
                office_cp[temp[j].first][temp[j].second]--;
            }
            temp.clear();
        }
    }
    else if(cctv[cctv_n].first == 2){
        int tx, ty;
        tx = x;
        ty = y;
        for(int i=0;i<2;i++){
            vector<pair<int, int>> temp;
            x = tx;
            y = ty;
            while(office[x+dx[i]][y+dy[i]] != 6 && x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m){
                office_cp[x+dx[i]][y+dy[i]]++;
                x+=dx[i];
                y+=dy[i];
                temp.push_back(make_pair(x, y));
            }
            x = tx;
            y = ty;
            while(office[x+dx[i+2]][y+dy[i+2]] != 6 && x+dx[i+2]>=0 && x+dx[i+2]<n && y+dy[i+2]>=0 && y+dy[i+2]<m){
                office_cp[x+dx[i+2]][y+dy[i+2]]++;
                x+=dx[i+2];
                y+=dy[i+2];
                temp.push_back(make_pair(x, y));
            }
            dfs(cctv_n+1);
            for(int j=0;j<temp.size();j++){
                office_cp[temp[j].first][temp[j].second]--;
            }
            temp.clear();
        }
    }
    else if(cctv[cctv_n].first == 3){
        int tx, ty;
        tx = x;
        ty = y;
        for(int i=0;i<4;i++){
            vector<pair<int, int>> temp;
            x = tx;
            y = ty;
            while(office[x+dx[i]][y+dy[i]] != 6 && x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m){
                office_cp[x+dx[i]][y+dy[i]]++;
                x+=dx[i];
                y+=dy[i];
                temp.push_back(make_pair(x, y));
            }
            x = tx;
            y = ty;
            while(office[x+dx[(i+1)%4]][y+dy[(i+1)%4]] != 6 && x+dx[(i+1)%4]>=0 && x+dx[(i+1)%4]<n && y+dy[(i+1)%4]>=0 && y+dy[(i+1)%4]<m){
                office_cp[x+dx[(i+1)%4]][y+dy[(i+1)%4]]++;
                x+=dx[(i+1)%4];
                y+=dy[(i+1)%4];
                temp.push_back(make_pair(x, y));
            }
            dfs(cctv_n+1);
            for(int j=0;j<temp.size();j++){
                office_cp[temp[j].first][temp[j].second]--;
            }
            temp.clear();
        }
    }
    else if(cctv[cctv_n].first == 4){
        int tx, ty;
        tx = x;
        ty = y;
        for(int i=0;i<4;i++){
            vector<pair<int, int>> temp;
            x = tx;
            y = ty;
            while(office[x+dx[i]][y+dy[i]] != 6 && x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m){
                office_cp[x+dx[i]][y+dy[i]]++;
                x+=dx[i];
                y+=dy[i];
                temp.push_back(make_pair(x, y));
            }
            x = tx;
            y = ty;
            while(office[x+dx[(i+1)%4]][y+dy[(i+1)%4]] != 6 && x+dx[(i+1)%4]>=0 && x+dx[(i+1)%4]<n && y+dy[(i+1)%4]>=0 && y+dy[(i+1)%4]<m){
                office_cp[x+dx[(i+1)%4]][y+dy[(i+1)%4]]++;
                x+=dx[(i+1)%4];
                y+=dy[(i+1)%4];
                temp.push_back(make_pair(x, y));
            }
            x = tx;
            y = ty;
            while(office[x+dx[(i+2)%4]][y+dy[(i+2)%4]] != 6 && x+dx[(i+2)%4]>=0 && x+dx[(i+2)%4]<n && y+dy[(i+2)%4]>=0 && y+dy[(i+2)%4]<m){
                office_cp[x+dx[(i+2)%4]][y+dy[(i+2)%4]]++;
                x+=dx[(i+2)%4];
                y+=dy[(i+2)%4];
                temp.push_back(make_pair(x, y));
            }
            dfs(cctv_n+1);
            for(int j=0;j<temp.size();j++){
                office_cp[temp[j].first][temp[j].second]--;
            }
            temp.clear();
        }
    }
    else if(cctv[cctv_n].first == 5){
        int tx, ty;
        tx = x;
        ty = y;
        vector<pair<int, int>> temp;
        while(office[x+dx[0]][y+dy[0]] != 6 && x+dx[0]>=0 && x+dx[0]<n && y+dy[0]>=0 && y+dy[0]<m){
            office_cp[x+dx[0]][y+dy[0]]++;
            x+=dx[0];
            y+=dy[0];
            temp.push_back(make_pair(x, y));
        }
        x = tx;
        y = ty;
        while(office[x+dx[1]][y+dy[1]] != 6 && x+dx[1]>=0 && x+dx[1]<n && y+dy[1]>=0 && y+dy[1]<m){
            office_cp[x+dx[1]][y+dy[1]]++;
            x+=dx[1];
            y+=dy[1];
            temp.push_back(make_pair(x, y));
        }
        x = tx;
        y = ty;
        while(office[x+dx[2]][y+dy[2]] != 6 && x+dx[2]>=0 && x+dx[2]<n && y+dy[2]>=0 && y+dy[2]<m){
            office_cp[x+dx[2]][y+dy[2]]++;
            x+=dx[2];
            y+=dy[2];
            temp.push_back(make_pair(x, y));
        }
        x = tx;
        y = ty;
        while(office[x+dx[3]][y+dy[3]] != 6 && x+dx[3]>=0 && x+dx[3]<n && y+dy[3]>=0 && y+dy[3]<m){
            office_cp[x+dx[3]][y+dy[3]]++;
            x+=dx[3];
            y+=dy[3];
            temp.push_back(make_pair(x, y));
        }
        dfs(cctv_n+1);
        for(int j=0;j<temp.size();j++){
            office_cp[temp[j].first][temp[j].second]--;
        }
        temp.clear();
        
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> office[i][j];
            if (office[i][j] == 0){
                total++;
            }
            else if(office[i][j] != 6){
                cctv.push_back(make_pair(office[i][j], make_pair(i, j)));
            }
        }
    }
    ans = total;
    dfs(0);
    cout << ans;
}