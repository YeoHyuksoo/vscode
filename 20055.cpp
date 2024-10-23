#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int belt[202][2]={0}; //내구도, 로봇 인덱스
int zero=0;
int robot=1;
int robots[300000][2]={0};

void rotate(){
    int s1 = belt[n*2-1][0];
    int s2 = belt[n*2-1][1];
    for(int i=n*2-1;i>0;i--){
        belt[i][0] = belt[i-1][0];
        belt[i][1] = belt[i-1][1];
    }
    for(int i=1;i<=robot;i++){
        robots[i][1]++;
    }
    belt[0][0] = s1;
    belt[0][1] = s2;
}

void work(){
    for(int i=1;i<robot;i++){
        if(robots[i][0]==1){
            if(belt[robots[i][1]+1][1]==0 && belt[robots[i][1]+1][0]>=1){
                belt[robots[i][1]][1] = 0;
                belt[robots[i][1]+1][1] = i;
                belt[robots[i][1]+1][0]--;
                if(belt[robots[i][1]+1][0]==0){
                    zero++;
                    if(zero>=k){
                        return;
                    }
                }
                robots[i][1]++;
            }
        }
    }
    if(zero>=k){
        return;
    }
    if(belt[0][0]!=0){
        robots[robot][0]=1;
        robots[robot][1]=0;
        belt[0][1] = robot;
        belt[0][0]--;
        if(belt[0][0]==0){
            zero++;
        }
        robot++;
    }
    /*for(int i=0;i<n*2;i++){
        printf("(%d, %d) ", belt[i][0], belt[i][1]);
    }
    printf("\n");*/
}

int main(void){
    cin >> n >> k;
    for(int i=0;i<n*2;i++){
        cin >> belt[i][0];
    }
    int level = 1;
    while(1){
        //printf("#%d\n", level);
        rotate();
        if(belt[n-1][1]!=0){
            robots[belt[n-1][1]][0] = 0;
            belt[n-1][1] = 0;
        }
        work();
        if(zero>=k){
            break;
        }
        if(belt[n-1][1]!=0){
            robots[belt[n-1][1]][0] = 0;
            belt[n-1][1] = 0;
        }
        level++;
    }
    printf("%d\n", level);
}