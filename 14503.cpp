#include <iostream>

using namespace std;

int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int space[51][51]={0};
int res = 0;

int check_back(int rx, int ry, int dir){
    int back_dir;
    back_dir = (dir+2)%4;
    if(space[rx+dx[dir]][ry+dy[dir]] == 1){
        return -1;
    }
    else{
        return 1;
    }
}

int search_dir(int rx, int ry, int dir){
    int tx, ty;
    tx = rx;
    ty = ry;
    dir = (dir+3)%4;
    
    tx+=dx[dir];
    ty+=dy[dir];
    if(space[tx][ty] == 0){
        return dir;
    }

    tx = rx;
    ty = ry;
    dir = (dir+3)%4;

    tx+=dx[dir];
    ty+=dy[dir];
    if(space[tx][ty] == 0){
        return dir;
    }
    
    tx = rx;
    ty = ry;
    dir = (dir+3)%4;

    tx+=dx[dir];
    ty+=dy[dir];
    if(space[tx][ty] == 0){
        return dir;
    }
    
    tx = rx;
    ty = ry;
    dir = (dir+3)%4;
    
    tx+=dx[dir];
    ty+=dy[dir];
    if(space[tx][ty] == 0){
        return dir;
    }
    
    if (check_back(rx, ry, dir)==-1){
        return -1;
    }
    else{
        return -2;
    }
}

void clean(int rx, int ry, int dir){
    int rotate_dir = dir;
    int temp_dir;
    while(rotate_dir!=-1){
        if (space[rx][ry]!=2){
            res++;
            cout << "clean" << rx << " " << ry << endl;
        }
        space[rx][ry] = 2;
        temp_dir = rotate_dir;
        rotate_dir = search_dir(rx, ry, temp_dir);
        if(rotate_dir>=0){
            rx+=dx[rotate_dir];
            ry+=dy[rotate_dir];
        }
        else if (rotate_dir==-2){
            rx+=dx[(temp_dir+2)%4];
            ry+=dy[(temp_dir+2)%4];
            rotate_dir = temp_dir;
        }
        cout << "robot goes to " << rx << " " << ry << endl;
    }
}

int main(void){
    int n, m;
    cin >> n >> m;

    int rx, ry, dir;
    cin >> rx >> ry >> dir;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> space[i][j];
        }
    }
    
    clean(rx, ry, dir);

    cout << res;

}