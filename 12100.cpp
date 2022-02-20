#include <iostream>

using namespace std;

int n;
int board[21][21]={0};
int board_cp[21][21]={0};
int temp[21]={0};
int max_n = 2;

void push_left(){
    for(int i=0;i<n;i++){
        int partner = -1;
        int cnt = 0;
        for(int j=0;j<n;j++){
            if (board[i][j]!=0){
                if (board[i][j]==partner){
                    temp[cnt++] = board[i][j]*2;
                    partner = -1;
                }
                else{
                    if(partner>0){
                        temp[cnt++] = partner;
                    }
                    partner = board[i][j];
                }
            }
        }
        if(partner>0){
            temp[cnt++] = partner;
        }
        for(int j=cnt;j<n;j++){
            temp[j] = 0;
        }
        for(int j=0;j<n;j++){
            board[i][j] = temp[j];
        }
    }
}

void push_right(){
    for(int i=0;i<n;i++){
        int partner = -1;
        int cnt = 0;
        for(int j=n-1;j>=0;j--){
            if (board[i][j]!=0){
                if (board[i][j]==partner){
                    temp[cnt++] = board[i][j]*2;
                    partner = -1;
                }
                else{
                    if(partner>0){
                        temp[cnt++] = partner;
                    }
                    partner = board[i][j];
                }
            }
        }
        if(partner>0){
            temp[cnt++] = partner;
        }
        for(int j=cnt;j<n;j++){
            temp[j] = 0;
        }
        for(int j=0;j<n;j++){
            board[i][n-1-j] = temp[j];
        }
    }
}

void push_up(){
    for(int j=0;j<n;j++){
        int partner = -1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if (board[i][j]!=0){
                if (board[i][j]==partner){
                    temp[cnt++] = board[i][j]*2;
                    partner = -1;
                }
                else{
                    if(partner>0){
                        temp[cnt++] = partner;
                    }
                    partner = board[i][j];
                }
            }
        }
        if(partner>0){
            temp[cnt++] = partner;
        }
        for(int i=cnt;i<n;i++){
            temp[i] = 0;
        }
        for(int i=0;i<n;i++){
            board[i][j] = temp[i];
        }
    }
}

void push_down(){
    for(int j=0;j<n;j++){
        int partner = -1;
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if (board[i][j]!=0){
                if (board[i][j]==partner){
                    temp[cnt++] = board[i][j]*2;
                    partner = -1;
                }
                else{
                    if(partner>0){
                        temp[cnt++] = partner;
                    }
                    partner = board[i][j];
                }
            }
        }
        if(partner>0){
            temp[cnt++] = partner;
        }
        for(int i=cnt;i<n;i++){
            temp[i] = 0;
        }
        for(int i=0;i<n;i++){
            board[n-1-i][j] = temp[i];
        }
    }
}

void dfs(int t){
    if(t==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (max_n < board[i][j]){
                    max_n = board[i][j];
                }
            }
        }
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board_cp[i][j] = board[i][j];
        }
    }
    push_left();
    dfs(t+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = board_cp[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board_cp[i][j] = board[i][j];
        }
    }
    push_right();
    dfs(t+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = board_cp[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board_cp[i][j] = board[i][j];
        }
    }
    push_up();
    dfs(t+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = board_cp[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board_cp[i][j] = board[i][j];
        }
    }
    push_down();
    dfs(t+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = board_cp[i][j];
        }
    }

}

int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << max_n;
}