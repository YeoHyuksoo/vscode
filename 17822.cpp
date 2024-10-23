#include <iostream>
#include <cstring>

using namespace std;

int round[51][51] = {0};
int n, m;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int visit[51][51] = {0};

void spin(int x, int d, int k){
    for(int i=x;i<=n;i+=x){
        int temp[51]={0};
        int s;
        if(d==0){
            s = -1*k + m;
        }
        else{
            s = k;
        }
        for(int j=0;j<m;j++){
            temp[j] = round[i-1][(s+j)%m];
        }
        for(int j=0;j<m;j++){
            round[i-1][j] = temp[j];
        }
    }
}

void remove(){
    int temp[51][51]={0};
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(round[i][j]==-1 || visit[i][j]==1) continue;
            visit[i][j] = 1;
            for(int k=0;k<4;k++){
                if(i+dx[k]<0 || i+dx[k]>=n) continue;
                int j_next = (j+dy[k]+m)%m;
                if(round[i][j] == round[i+dx[k]][j_next]){
                    visit[i+dx[k]][j_next] = 1;
                    temp[i][j] = -1;
                    temp[i+dx[k]][j_next] = -1;
                    flag = 1;
                }
            }
        }
    }
    if(flag==0){
        float total = 0.0, cnt = 0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(round[i][j]!=-1){
                    total+=round[i][j];
                    cnt++;
                }
            }
        }
        float mean = total/cnt;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(round[i][j]!=-1){
                    if(round[i][j]>mean){
                        round[i][j]--;
                    }
                    else if(round[i][j]<mean){
                        round[i][j]++;
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==-1){
                    round[i][j] = -1;
                }
            }
        }
    }
}

int main(void){
    int t;
    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> round[i][j];
        }
    }
    int x, d, k;
    for(int i=0;i<t;i++){
        cin >> x >> d >> k;
        spin(x, d, k);
        remove();
        memset(visit, 0, sizeof(visit));
    }
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(round[i][j]!=-1){
                total+=round[i][j];
            }
        }
    }
    printf("%d\n", total);
    return 0;
}