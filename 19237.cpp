#include <iostream>

using namespace std;

int space[21][21][2]={0};
int shark[401][3]={0};
int move_priority[401][16]={0};
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int die[401]={0};
int stop=0;
int n, m, k;

void move(){
    for(int i=1;i<=m;i++){
        int j;
        for(j=0;j<4;j++){
            if(die[i] == 1 || shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]<0 || shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]>=n || shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]<0 || shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]>=n){
                continue;
            }
            if(space[shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]][shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]][1]==0){
                //no smell find
                
                space[shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]][shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]][0] = i;
                //space[shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]][shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]][1] = k+1;
                shark[i][0]+=dx[move_priority[i][4*shark[i][2]+j]];
                shark[i][1]+=dy[move_priority[i][4*shark[i][2]+j]];
                shark[i][2] = move_priority[i][4*shark[i][2]+j];
                break;
            }
        }
        if(j==4){
            for(j=0;j<4;j++){
                if(die[i] == 1 || shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]<0 || shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]>=n || shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]<0 || shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]>=n){
                    continue;
                }
                if(space[shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]][shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]][0]==i){
                    //near smell of itself find
                    //space[shark[i][0]+dx[move_priority[i][4*shark[i][2]+j]]][shark[i][1]+dy[move_priority[i][4*shark[i][2]+j]]][1] = k+1;
                    shark[i][0]+=dx[move_priority[i][4*shark[i][2]+j]];
                    shark[i][1]+=dy[move_priority[i][4*shark[i][2]+j]];
                    shark[i][2] = move_priority[i][4*shark[i][2]+j];
                    break;
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("(%d, %d) ", space[i][j][0], space[i][j][1]);
            }
            printf("\n");
        }
        printf("\n");*/
    }
    //collision check
    for(int i=1;i<m;i++){
        if(die[i]!=1){
            for(int j=i+1;j<=m;j++){
                if(die[j]!=1){
                    if(shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1]){
                        //collision
                        die[j] = 1;
                    }
                }
            }
        }
    }
    //smell update
    for(int i=1;i<=m;i++){
        if(die[i]==0){
            space[shark[i][0]][shark[i][1]][0] = i;
            space[shark[i][0]][shark[i][1]][1] = k+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(space[i][j][1]!=0){
                space[i][j][1]--;
                if(space[i][j][1]==0){
                    space[i][j][0] = 0;
                }
            }
        }
    }
}

int main(void){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> space[i][j][0];
            if(space[i][j][0]!=0){
                shark[space[i][j][0]][0] = i;
                shark[space[i][j][0]][1] = j;
                space[i][j][1] = k;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin >> shark[i][2];
        shark[i][2]--;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<16;j++){
            cin >> move_priority[i][j];
            move_priority[i][j]--;
        }
    }
    int t;
    for(t=0;t<1000;t++){
        //printf("in %d sec\n", t+1);
        move();
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("(%d, %d) ", space[i][j][0], space[i][j][1]);
            }
            printf("\n");
        }
        printf("\n");*/
        int s;
        for(s=2;s<=m;s++){
            if(die[s]==0){
                break;
            }
        }
        if(s==m+1) stop = 1;

        if(stop){
            break;
        }
    }
    if(t==1000){
        printf("-1");
    }
    else{
        printf("%d", t+1);
    }
}