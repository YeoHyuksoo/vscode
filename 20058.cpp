#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n, q;
int space[70][70]={0};
int temp[70][70]={0};
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int temp2[2525][2]={0};
int biggest=0, temp_big=0;

void rotate(int x, int y, int rad){
    for(int i=0;i<rad;i++){
        for(int j=0;j<rad;j++){
            temp[j][rad-i-1] = space[x+i][y+j];
        }
    }
    for(int i=0;i<rad;i++){
        for(int j=0;j<rad;j++){
            space[x+i][y+j] = temp[i][j];
        }
    }
}

void melt(){
    int N = pow(2, n);
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(space[i][j]==0) continue;
            int zero=0;
            for(int k=0;k<4;k++){
                if(space[i+dx[k]][j+dy[k]]==0){
                    zero++;
                }
            }
            if(zero>=2){
                temp2[cnt][0] = i;
                temp2[cnt++][1] = j;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        space[temp2[i][0]][temp2[i][1]]--;
    }
}

void firestorm(int Q){
    int p = pow(2, Q);
    int N = pow(2, n);
    for(int i=1;i<=N;i+=p){
        for(int j=1;j<=N;j+=p){
            rotate(i, j, p);
        }
    }
    melt();
}

void find_dfs(int x, int y){
    for(int i=0;i<4;i++){
        if(temp[x+dx[i]][y+dy[i]]==0 && space[x+dx[i]][y+dy[i]]!=0){
            temp_big++;
            temp[x+dx[i]][y+dy[i]] = 1;
            find_dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main(void){
    cin >> n >> q;
    int p = pow(2, n);
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            cin >> space[i][j];
        }
    }
    int Q;
    for(int i=0;i<q;i++){
        cin >> Q;
        firestorm(Q);
    }
    int total=0;
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            total+=space[i][j];
        }
    }
    printf("%d\n", total);
    memset(temp, 0, sizeof(temp));
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            if(temp[i][j]==0 && space[i][j]!=0){
                temp_big=1;
                temp[i][j] = 1;
                find_dfs(i, j);
                if(biggest<temp_big){
                    biggest = temp_big;
                }
            }
        }
    }
    if(biggest<=1){
        printf("0\n");
    }
    else{
        printf("%d\n", biggest);
    }
    return 0;
}