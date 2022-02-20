#include <iostream>

using namespace std;

char board[10][10];

int blue[2], red[2];
int temp[4];
int min_move = 11;

int go_left(int bx, int by, int rx, int ry){
    int ret = 0;
    if (bx==rx){
        if(by<ry){
            while(board[bx][by-1]=='.'){
                by--;
            }
            if (board[bx][by-1]=='O'){
                ret += 2;
            }
            else{
                board[bx][by] = 'B';
            }
            while(board[rx][ry-1]=='.'){
                ry--;
            }
            if (board[rx][ry-1]=='O'){
                ret += 1;
            }
            board[bx][by] = '.';
        }
        else{
            while(board[rx][ry-1]=='.'){
                ry--;
            }
            if (board[rx][ry-1]=='O'){
                ret += 1;
            }
            else{
                board[rx][ry] = 'R';
            }
            while(board[bx][by-1]=='.'){
                by--;
            }
            if (board[bx][by-1]=='O'){
                ret += 2;
            }
            board[rx][ry] = '.';
        }
    }
    else{
        while(board[bx][by-1]=='.'){
            by--;
        }
        if (board[bx][by-1]=='O'){
            ret += 2;
        }
        while(board[rx][ry-1]=='.'){
            ry--;
        }
        if (board[rx][ry-1]=='O'){
            ret += 1;
        }
    }
    temp[0] = bx;
    temp[1] = by;
    temp[2] = rx;
    temp[3] = ry;
    return ret;
}

int go_right(int bx, int by, int rx, int ry){
    int ret = 0;
    if (bx==rx){
        if(by>ry){
            while(board[bx][by+1]=='.'){
                by++;
            }
            if (board[bx][by+1]=='O'){
                ret += 2;
            }
            else{
                board[bx][by] = 'B';
            }
            while(board[rx][ry+1]=='.'){
                ry++;
            }
            if (board[rx][ry+1]=='O'){
                ret += 1;
            }
            board[bx][by] = '.';
        }
        else{
            while(board[rx][ry+1]=='.'){
                ry++;
            }
            if (board[rx][ry+1]=='O'){
                ret += 1;
            }
            else{
                board[rx][ry] = 'R';
            }
            while(board[bx][by+1]=='.'){
                by++;
            }
            if (board[bx][by+1]=='O'){
                ret += 2;
            }
            board[rx][ry] = '.';
        }
    }
    else{
        while(board[bx][by+1]=='.'){
            by++;
        }
        if (board[bx][by+1]=='O'){
            ret += 2;
        }
        while(board[rx][ry+1]=='.'){
            ry++;
        }
        if (board[rx][ry+1]=='O'){
            ret += 1;
        }
    }
    temp[0] = bx;
    temp[1] = by;
    temp[2] = rx;
    temp[3] = ry;
    return ret;
}

int go_up(int bx, int by, int rx, int ry){
    int ret = 0;
    if (by==ry){
        if(by<ry){
            while(board[bx-1][by]=='.'){
                bx--;
            }
            if (board[bx-1][by]=='O'){
                ret += 2;
            }
            else{
                board[bx][by] = 'B';
            }
            while(board[rx-1][ry]=='.'){
                rx--;
            }
            if (board[rx-1][ry]=='O'){
                ret += 1;
            }
            board[bx][by] = '.';
        }
        else{
            while(board[rx-1][ry]=='.'){
                rx--;
            }
            if (board[rx-1][ry]=='O'){
                ret += 1;
            }
            else{
                board[rx][ry] = 'R';
            }
            while(board[bx-1][by]=='.'){
                bx--;
            }
            if (board[bx-1][by]=='O'){
                ret += 2;
            }
            board[rx][ry] = '.';
        }
    }
    else{
        while(board[bx-1][by]=='.'){
            bx--;
        }
        if (board[bx-1][by]=='O'){
            ret += 2;
        }
        while(board[rx-1][ry]=='.'){
            rx--;
        }
        if (board[rx-1][ry]=='O'){
            ret += 1;
        }
    }
    temp[0] = bx;
    temp[1] = by;
    temp[2] = rx;
    temp[3] = ry;
    return ret;
}

int go_down(int bx, int by, int rx, int ry){
    int ret = 0;
    if (by==ry){
        if(by>ry){
            while(board[bx+1][by]=='.'){
                bx++;
            }
            if (board[bx+1][by]=='O'){
                ret += 2;
            }
            else{
                board[bx][by] = 'B';    
            }
            while(board[rx+1][ry]=='.'){
                rx++;
            }
            if (board[rx+1][ry]=='O'){
                ret += 1;
            }
            board[bx][by] = '.';
        }
        else{
            while(board[rx+1][ry]=='.'){
                rx++;
            }
            if (board[rx+1][ry]=='O'){
                ret += 1;
            }
            else{
                board[rx][ry] = 'R';
            }
            while(board[bx+1][by]=='.'){
                bx++;
            }
            if (board[bx+1][by]=='O'){
                ret += 2;
            }
            board[rx][ry] = '.';
        }
    }
    else{
        while(board[bx+1][by]=='.'){
            bx++;
        }
        if (board[bx+1][by]=='O'){
            ret += 2;
        }
        while(board[rx+1][ry]=='.'){
            rx++;
        }
        if (board[rx+1][ry]=='O'){
            ret += 1;
        }
    }
    temp[0] = bx;
    temp[1] = by;
    temp[2] = rx;
    temp[3] = ry;
    return ret;
}

void dfs(int move, int bx, int by, int rx, int ry){
    if (min_move<=move || move>=11){
        return;
    }

    int ret;

    ret = go_left(bx, by, rx, ry);
    if (ret==0){
        dfs(move+1, temp[0], temp[1], temp[2], temp[3]);
    }
    else if (ret==1){
        min_move = move+1;
        return;
    }

    ret = go_right(bx, by, rx, ry);
    if (ret==0){
        dfs(move+1, temp[0], temp[1], temp[2], temp[3]);
    }
    else if (ret==1){
        min_move = move+1;
        return;
    }

    ret = go_up(bx, by, rx, ry);
    if (ret==0){
        dfs(move+1, temp[0], temp[1], temp[2], temp[3]);
    }
    else if (ret==1){
        min_move = move+1;
        return;
    }
    
    ret = go_down(bx, by, rx, ry);
    if (ret==0){
        dfs(move+1, temp[0], temp[1], temp[2], temp[3]);
    }
    else if (ret==1){
        min_move = move+1;
        return;
    }
    
}

int main(void){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if (board[i][j]=='B'){
                blue[0] = i;
                blue[1] = j;
                board[i][j] = '.';
            }
            else if(board[i][j]=='R'){
                red[0] = i;
                red[1] = j;
                board[i][j] = '.';
            }
        }
    }

    dfs(0, blue[0], blue[1], red[0], red[1]);

    if (min_move==11){
        cout << "-1";
    }
    else{
        cout << min_move;
    }
}