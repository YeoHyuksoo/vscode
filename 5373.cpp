#include <iostream>
#include <vector>

using namespace std;

char cube[6][3][3];
char cube_cp[6][3][3];
vector<pair<int, int> > cmd;

void rotate(int side, int dir){
    char temp[3][3];
    if(dir==1){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp[i][j] = cube[side][i][j];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cube[side][i][j] = temp[2-j][i];
            }
        }
    }
    else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp[i][j] = cube[side][i][j];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cube[side][i][j] = temp[j][2-i];
            }
        }
    }
}

void rotate2(int side, int dir){
    if(side==0){
        if(dir==1){
            cube[4][0][0] = cube_cp[2][0][0];
            cube[4][0][1] = cube_cp[2][0][1];
            cube[4][0][2] = cube_cp[2][0][2];
            cube[5][0][0] = cube_cp[3][0][0];
            cube[5][0][1] = cube_cp[3][0][1];
            cube[5][0][2] = cube_cp[3][0][2];
            cube[3][0][0] = cube_cp[4][0][0];
            cube[3][0][1] = cube_cp[4][0][1];
            cube[3][0][2] = cube_cp[4][0][2];
            cube[2][0][0] = cube_cp[5][0][0];
            cube[2][0][1] = cube_cp[5][0][1];
            cube[2][0][2] = cube_cp[5][0][2];
        }
        else{
            cube[4][0][0] = cube_cp[2][0][0];
            cube[4][0][1] = cube_cp[2][0][1];
            cube[4][0][2] = cube_cp[2][0][2];
            cube[5][0][0] = cube_cp[3][0][0];
            cube[5][0][1] = cube_cp[3][0][1];
            cube[5][0][2] = cube_cp[3][0][2];
            cube[3][0][0] = cube_cp[4][0][0];
            cube[3][0][1] = cube_cp[4][0][1];
            cube[3][0][2] = cube_cp[4][0][2];
            cube[2][0][0] = cube_cp[5][0][0];
            cube[2][0][1] = cube_cp[5][0][1];
            cube[2][0][2] = cube_cp[5][0][2];
            2(0, 1, 2)->5(0, 1, 2)
            3(0, 1, 2)->4(0, 1, 2)
            4(0, 1, 2)->2(0, 1, 2)
            5(0, 1, 2)->3(0, 1, 2)
        }
    }
    else if(side==1){
        if(dir==1){
            2(7, 8, 9)->4(7, 8, 9)
            3(7, 8, 9)->5(7, 8, 9)
            4(7, 8, 9)->3(7, 8, 9)
            5(7, 8, 9)->2(7, 8, 9)
        }
        else{
            2(7, 8, 9)->5(7, 8, 9)
            3(7, 8, 9)->4(7, 8, 9)
            4(7, 8, 9)->2(7, 8, 9)
            5(7, 8, 9)->3(7, 8, 9)
        }
    }
    else if(side==2){
        if(dir==1){
            0(6, 7, 8)->5(0, 3, 6)
            1(0, 1, 2)->4(2, 5, 8)
            4(2, 5, 8)->0(6, 7, 8)
            5(0, 3, 6)->1(0, 1, 2)
        }
        else{
            0(6, 7, 8)->4(2, 5, 8)
            1(0, 1, 2)->5(0, 3, 6)
            4(2, 5, 8)->1(0, 1, 2)
            5(0, 3, 6)->0(6, 7, 8)
        }
    }
    else if(side==3){
        if(dir==1){
            0(0, 1, 2)->5(2, 5, 8)
            1(6, 7, 8)->4(0, 3, 6)
            4(0, 3, 6)->0(0, 1, 2)
            5(2, 5, 8)->1(6, 7, 8)
        }
        else{
            0(0, 1, 2)->4(0, 3, 6)
            1(6, 7, 8)->5(2, 5, 8)
            4(0, 3, 6)->1(6, 7, 8)
            5(2, 5, 8)->0(0, 1, 2)
        }
    }
    else if(side==4){
        if(dir==1){
            0(0, 3, 6)->2(0, 3, 6)
            1(0, 3, 6)->3(2, 5, 8)
            2(0, 3, 6)->1(0, 3, 6)
            3(2, 5, 8)->0(0, 3, 6)
        }
        else{
            0(0, 3, 6)->3(2, 5, 8)
            1(0, 3, 6)->2(0, 3, 6)
            2(0, 3, 6)->0(0, 3, 6)
            3(2, 5, 8)->1(0, 3, 6)
        }
    }
    else if(side==5){
        if(dir==1){
            0(2, 5, 8)->3(0, 3, 6)
            1(2, 5, 8)->2(2, 5, 8)
            2(2, 5, 8)->0(2, 5, 8)
            3(0, 3, 6)->1(2, 5, 8)
        }
        else{
            0(2, 5, 8)->2(2, 5, 8)
            1(2, 5, 8)->3(0, 3, 6)
            2(2, 5, 8)->1(2, 5, 8)
            3(0, 3, 6)->0(2, 5, 8)
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cube_cp[i][j][k] = cube[i][j][k];
            }
        }
    }
}

void cubing(){
    int side, dir;
    for(int i=0;i<cmd.size();i++){
        side = cmd[i].first;
        dir = cmd[i].second;
        rotate(side, dir);
        rotate2(side, dir);
    }
    return;
}

int main(void){
    int T;
    cin >> T;
    int n;

    for(int i=0;i<6;i++){
        if(i==0){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'w';
                }
            }
        }
        else if(i==1){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'y';
                }
            }
        }
        else if(i==2){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'r';
                }
            }
        }
        else if(i==3){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'o';
                }
            }
        }
        else if(i==4){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'g';
                }
            }
        }
        else if(i==5){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = 'b';
                }
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cube_cp[i][j][k] = cube[i][j][k];
            }
        }
    }

    for(int i=0;i<T;i++){
        cin >> n;
        string c;
        int side, dir;
        for(int j=0;j<n;j++){
            cin >> c;
            if(c[1]=='+'){
                dir = 1;
            }
            else if(c[1] == '-'){
                dir = 2;
            }
            if(c[0]=='U'){
                side = 0;
            }
            else if(c[0]=='D'){
                side = 1;
            }
            else if(c[0]=='F'){
                side = 2;
            }
            else if(c[0]=='B'){
                side = 3;
            }
            else if(c[0]=='L'){
                side = 4;
            }
            else if(c[0]=='R'){
                side = 5;
            }
            cmd.push_back(make_pair(side, dir));
        }

        cubing();
        cmd.clear();
    }
}