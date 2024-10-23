#include <iostream>

using namespace std;

int space[5][30]={
    {-1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {10, 13, 16, 19, 25, 30, 35, 40},
    {20, 22, 24, 25, 30, 35, 40},
    {30, 28, 27, 26, 25, 30, 35, 40}
};
int dice[10];
int max_score = 0;

void game_dfs(int d, int score, int horse[][2]){
    if(d==10){
        if(score>max_score){
            max_score = score;
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(space[horse[i][0]][horse[i][1]] == 0) continue;
        int flag=0;
        for(int j=0;j<4;j++){
            if(i!=j){
                if(horse[i][0] == horse[j][0] && horse[i][1]+dice[d] == horse[j][1] && space[horse[i][0]][horse[i][1]+dice[d]] != 0){
                    flag=1;
                }
                else if(space[horse[i][0]][horse[i][1]+dice[d]] == space[horse[j][0]][horse[j][1]]){
                    if(space[horse[j][0]][horse[j][1]]>=25 && space[horse[j][0]][horse[j][1]]%5==0){
                        if(space[horse[j][0]][horse[j][1]]==30){
                            if(horse[i][0]+horse[j][0]==0 || horse[i][0]==horse[j][0]){
                                flag=1;
                            }
                        }
                        else
                            flag=1;
                    }
                }
            }
        }
        if(flag){
            continue;
        }
        if(horse[i][0]==0 && horse[i][1]%5==0){
            horse[i][0]+=horse[i][1]/5;
            horse[i][1] = 0;
        }
        horse[i][1]+=dice[d];
        game_dfs(d+1, score+space[horse[i][0]][horse[i][1]], horse);
    }
}

int main(void){
    for(int i=0;i<10;i++){
        cin >> dice[i];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<30;j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }
    int horse[4][2] = {0};
    game_dfs(0, 0, horse);
    printf("%d\n", max_score);
    return 0;
}