#include <iostream>

using namespace std;

int space[4][4]={0};
int fish[17][2]={0};
int dir[17]={0};
int die[17]={0};

int shark_max = 0;
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[8]={0, -1, -1, -1, 0, 1, 1, 1};

void shark_dfs(int sx, int sy, int sdir, int cur){
    if(cur>shark_max){
        shark_max = cur;
    }
    int vspace[4][4];
    int vfish[17][2];
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            vspace[j][k] = space[j][k];
        }
    }
    for(int j=0;j<17;j++){
        for(int k=0;k<2;k++){
            vfish[j][k] = fish[j][k];
        }
    }
    for(int i=1;i<=16;i++){
        if(die[i]==0){
            for(int j=0;j<8;j++){
                int new_dir = (dir[i]+j+8)%8;
                if(fish[i][0]+dx[new_dir]<0 || fish[i][0]+dx[new_dir]>=4 || fish[i][1]+dy[new_dir]<0 || fish[i][1]+dy[new_dir]>=4){
                    continue;
                }
                if(space[fish[i][0]+dx[new_dir]][fish[i][1]+dy[new_dir]]==-1){
                    continue;
                }
                else if(space[fish[i][0]+dx[new_dir]][fish[i][1]+dy[new_dir]]==0){
                    // can go
                    space[fish[i][0]][fish[i][1]] = 0;
                    fish[i][0] += dx[new_dir];
                    fish[i][1] += dy[new_dir];
                    dir[i] = new_dir;
                    space[fish[i][0]][fish[i][1]] = i;
                }
                else if(space[fish[i][0]+dx[new_dir]][fish[i][1]+dy[new_dir]]>0){
                    // can switch
                    int fidx = space[fish[i][0]+dx[new_dir]][fish[i][1]+dy[new_dir]];
                    space[fish[i][0]+dx[new_dir]][fish[i][1]+dy[new_dir]] = space[fish[i][0]][fish[i][1]];
                    space[fish[i][0]][fish[i][1]] = fidx;
                    dir[i] = new_dir;
                    fish[fidx][0] = fish[i][0];
                    fish[fidx][1] = fish[i][1];
                    fish[i][0] += dx[new_dir];
                    fish[i][1] += dy[new_dir];
                    
                }
                break;
            }
        }
    }
    for(int i=1;i<=3;i++){
        if(sx+dx[sdir]*i<0 || sx+dx[sdir]*i>=4 || sy+dy[sdir]*i<0 || sy+dy[sdir]*i>=4){
            continue;
        }
        if(space[sx+dx[sdir]*i][sy+dy[sdir]*i]>0){
            // can go and eat
            printf("shark dir: %d\n", sdir);
            printf("before eat\n");
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    printf("%d ", space[i][j]);
                }
                printf("\n");
            }
            int tidx = space[sx+dx[sdir]*i][sy+dy[sdir]*i];
            space[sx][sy] = 0;
            space[sx+dx[sdir]*i][sy+dy[sdir]*i] = -1;
            die[tidx]=1;
            printf("eat fish#%d, cur: %d\n", tidx, cur+tidx);
            printf("after eat\n");
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    printf("%d ", space[i][j]);
                }
                printf("\n");
            }
            shark_dfs(sx+dx[sdir]*i, sy+dy[sdir]*i, dir[tidx], cur+tidx);
            die[tidx]=0;
            space[sx+dx[sdir]*i][sy+dy[sdir]*i] = tidx;
            space[sx][sy] = -1;
        }
    }
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            space[j][k] = vspace[j][k];
        }
    }
    for(int j=0;j<17;j++){
        for(int k=0;k<2;k++){
            fish[j][k] = vfish[j][k];
        }
    }
}


int main(void){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> space[i][j];
            fish[space[i][j]][0] = i;
            fish[space[i][j]][1] = j;
            cin >> dir[space[i][j]];
            dir[space[i][j]]--;
        }
    }
    int first = space[0][0];
    die[first] = 1;
    space[0][0] = -1;
    shark_dfs(0, 0, dir[first], 0);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", first + shark_max);

    return 0;
}