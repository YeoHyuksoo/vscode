#include <iostream>

using namespace std;

int green[6][4];
int blue[4][6];
int score = 0;
int t, x, y;

void get_score_row(int x1, int x2){
    if(x1 == -1){
        if(green[x2][0]==1 && green[x2][1]==1 && green[x2][2]==1 && green[x2][3]==1){
            score++;
            green[x2][0] = 0;
            green[x2][1] = 0;
            green[x2][2] = 0;
            green[x2][3] = 0;
            for(int i=x2;i>=1;i--){
                green[i][0] = green[i-1][0];
                green[i][1] = green[i-1][1];
                green[i][2] = green[i-1][2];
                green[i][3] = green[i-1][3];
            }
            green[0][0] = 0;
            green[0][1] = 0;
            green[0][2] = 0;
            green[0][3] = 0;
        }
    }
    else{
        if(green[x1][0]==1 && green[x1][1]==1 && green[x1][2]==1 && green[x1][3]==1){
            score++;
            green[x1][0] = 0;
            green[x1][1] = 0;
            green[x1][2] = 0;
            green[x1][3] = 0;
            if(green[x2][0]==1 && green[x2][1]==1 && green[x2][2]==1 && green[x2][3]==1){
                score++;
                green[x2][0] = 0;
                green[x2][1] = 0;
                green[x2][2] = 0;
                green[x2][3] = 0;
                for(int i=x1;i>=2;i--){
                    green[i][0] = green[i-2][0];
                    green[i][1] = green[i-2][1];
                    green[i][2] = green[i-2][2];
                    green[i][3] = green[i-2][3];
                }
                green[0][0] = 0;
                green[0][1] = 0;
                green[0][2] = 0;
                green[0][3] = 0;
                green[1][0] = 0;
                green[1][1] = 0;
                green[1][2] = 0;
                green[1][3] = 0;
            }
            else{
                for(int i=x1;i>=1;i--){
                    green[i][0] = green[i-1][0];
                    green[i][1] = green[i-1][1];
                    green[i][2] = green[i-1][2];
                    green[i][3] = green[i-1][3];
                }
                green[0][0] = 0;
                green[0][1] = 0;
                green[0][2] = 0;
                green[0][3] = 0;
            }
        }
        else{
            if(green[x2][0]==1 && green[x2][1]==1 && green[x2][2]==1 && green[x2][3]==1){
                score++;
                green[x2][0] = 0;
                green[x2][1] = 0;
                green[x2][2] = 0;
                green[x2][3] = 0;
                for(int i=x2;i>=1;i--){
                    green[i][0] = green[i-1][0];
                    green[i][1] = green[i-1][1];
                    green[i][2] = green[i-1][2];
                    green[i][3] = green[i-1][3];
                }
                green[0][0] = 0;
                green[0][1] = 0;
                green[0][2] = 0;
                green[0][3] = 0;
            }
        }
    }
}

void get_score_col(int y1, int y2){
    if(y1==-1){
        if(blue[0][y2] == 1 && blue[1][y2] == 1 && blue[2][y2] == 1 && blue[3][y2] == 1){
            score++;
            blue[0][y2] = 0;
            blue[1][y2] = 0;
            blue[2][y2] = 0;
            blue[3][y2] = 0;
            for(int i=y2;i>=1;i--){
                blue[0][i] = blue[0][i-1];
                blue[1][i] = blue[1][i-1];
                blue[2][i] = blue[2][i-1];
                blue[3][i] = blue[3][i-1];
            }
            blue[0][0] = 0;
            blue[1][0] = 0;
            blue[2][0] = 0;
            blue[3][0] = 0;
        }
    }
    else{
        if(blue[0][y1]==1 && blue[1][y1]==1 && blue[2][y1]==1 && blue[3][y1]==1){
            score++;
            blue[0][y1] = 0;
            blue[1][y1] = 0;
            blue[2][y1] = 0;
            blue[3][y1] = 0;
            if(blue[0][y2]==1 && blue[1][y2]==1 && blue[2][y2]==1 && blue[3][y2]==1){
                score++;
                blue[0][y2] = 0;
                blue[1][y2] = 0;
                blue[2][y2] = 0;
                blue[3][y2] = 0;
                for(int i=y2;i>=2;i--){
                    blue[0][i] = blue[0][i-2];
                    blue[1][i] = blue[1][i-2];
                    blue[2][i] = blue[2][i-2];
                    blue[3][i] = blue[3][i-2];
                }
                blue[0][0] = 0;
                blue[1][0] = 0;
                blue[2][0] = 0;
                blue[3][0] = 0;
                blue[0][1] = 0;
                blue[1][1] = 0;
                blue[2][1] = 0;
                blue[3][1] = 0;
            }
            else{
                for(int i=y1;i>=1;i--){
                    blue[0][i] = blue[0][i-1];
                    blue[1][i] = blue[1][i-1];
                    blue[2][i] = blue[2][i-1];
                    blue[3][i] = blue[3][i-1];
                }
                blue[0][0] = 0;
                blue[1][0] = 0;
                blue[2][0] = 0;
                blue[3][0] = 0;
            }
        }
        else{
            if(blue[0][y2]==1 && blue[1][y2]==1 && blue[2][y2]==1 && blue[3][y2]==1){
                score++;
                blue[0][y2] = 0;
                blue[1][y2] = 0;
                blue[2][y2] = 0;
                blue[3][y2] = 0;
                for(int i=y2;i>=1;i--){
                    blue[0][i] = blue[0][i-1];
                    blue[1][i] = blue[1][i-1];
                    blue[2][i] = blue[2][i-1];
                    blue[3][i] = blue[3][i-1];
                }
                blue[0][0] = 0;
                blue[1][0] = 0;
                blue[2][0] = 0;
                blue[3][0] = 0;
            }
        }
    }
}

void check_special(){
    int remove = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(green[i][j] == 1){
                remove++;
                break;
            }
        }
    }
    for(int i=5;i>=remove;i--){
        green[i][0] = green[i-remove][0];
        green[i][1] = green[i-remove][1];
        green[i][2] = green[i-remove][2];
        green[i][3] = green[i-remove][3];
    }
    green[0][0] = 0;
    green[0][1] = 0;
    green[0][2] = 0;
    green[0][3] = 0;
    green[1][0] = 0;
    green[1][1] = 0;
    green[1][2] = 0;
    green[1][3] = 0;

    remove = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(blue[j][i] == 1){
                remove++;
                break;
            }
        }
    }
    for(int i=5;i>=remove;i--){
        blue[0][i] = blue[0][i-remove];
        blue[1][i] = blue[1][i-remove];
        blue[2][i] = blue[2][i-remove];
        blue[3][i] = blue[3][i-remove];
    }
    blue[0][0] = 0;
    blue[1][0] = 0;
    blue[2][0] = 0;
    blue[3][0] = 0;
    blue[0][1] = 0;
    blue[1][1] = 0;
    blue[2][1] = 0;
    blue[3][1] = 0;
}

void domino(int type, int x, int y){
    int temp = 0;
    if(type==1){
        while(temp<5 && green[temp+1][y] == 0){
            temp++;
        }
        green[temp][y] = 1;
        get_score_row(-1, temp);
        temp = 0;
        while(temp<5 && blue[x][temp+1] == 0){
            temp++;
        }
        blue[x][temp] = 1;
        get_score_col(-1, temp);
    }
    else if(type==2){
        while(temp<5 && green[temp+1][y] == 0 && green[temp+1][y+1] == 0){
            temp++;
        }
        green[temp][y] = 1;
        green[temp][y+1] = 1;
        get_score_row(-1, temp);
        temp = 0;
        while(temp<5 && blue[x][temp] == 0 && blue[x][temp+1] == 0){
            temp++;
        }
        blue[x][temp-1] = 1;
        blue[x][temp] = 1;
        get_score_col(temp, temp-1);
    }
    else{
        while(temp<5 && green[temp][y] == 0 && green[temp+1][y] == 0){
            temp++;
        }
        green[temp-1][y] = 1;
        green[temp][y] = 1;
        get_score_row(temp, temp-1);
        temp = 0;
        while(temp<5 && blue[x][temp+1] == 0 && blue[x+1][temp+1] == 0){
            temp++;
        }
        blue[x][temp] = 1;
        blue[x+1][temp] = 1;
        get_score_col(-1, temp);
    }
    check_special();
}

int main(void){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> t >> x >> y;
        domino(t, x, y);
    }
    cout << score << endl;
    int tile = 0;
    for(int i=0;i<24;i++){
        if(green[i/4][i%4] == 1){
            tile++;
        }
        if(blue[i/6][i%6] == 1){
            tile++;
        }
    }
    cout << tile;
}