#include <iostream>

using namespace std;

int n;
int space[510][510]={0};
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};

void tornado(int x, int y, int dir){
    int sand = space[x+dx[dir]][y+dy[dir]];
    if(sand==0) return;
    space[x+dx[dir]][y+dy[dir]] = 0;
    int s1 = sand*0.01;
    int s2 = sand*0.02;
    int s3 = sand*0.07;
    int s4 = sand*0.1;
    int s5 = sand*0.05;
    int rest = sand-(2*s1)-(2*s2)-(2*s3)-(2*s4)-s5;
    if(dir%2==1){
        
        space[x+dx[0]][y+dy[0]]+=s1;
    
        space[x+dx[2]][y+dy[2]]+=s1;
    
        space[x+dx[dir]+dx[0]][y+dy[dir]+dx[0]]+=s3;
    
        space[x+dx[dir]+dx[2]][y+dy[dir]+dx[2]]+=s3;
    
        space[x+dx[dir]+dx[0]*2][y+dy[dir]+dx[0]*2]+=s2;
    
        space[x+dx[dir]+dx[2]*2][y+dy[dir]+dx[2]*2]+=s2;
    
        space[x+dx[dir]*2+dx[0]][y+dy[dir]*2+dx[0]]+=s4;
    
        space[x+dx[dir]*2+dx[2]][y+dy[dir]*2+dx[2]]+=s4;
    
        space[x+dx[dir]*3][y+dy[dir]*3]+=s5;
    
        space[x+dx[dir]*2][y+dy[dir]*2]+=rest;
        
    }
    else{
        
        space[x+dx[1]][y+dy[1]]+=s1;
    
        space[x+dx[3]][y+dy[3]]+=s1;
    
        space[x+dx[dir]+dx[1]][y+dy[dir]+dx[1]]+=s3;
    
        space[x+dx[dir]+dx[3]][y+dy[dir]+dx[3]]+=s3;
    
        space[x+dx[dir]+dx[1]*2][y+dy[dir]+dx[1]*2]+=s2;
    
        space[x+dx[dir]+dx[3]*2][y+dy[dir]+dx[3]*2]+=s2;
    
        space[x+dx[dir]*2+dx[1]][y+dy[dir]*2+dx[1]]+=s4;
    
        space[x+dx[dir]*2+dx[3]][y+dy[dir]*2+dx[3]]+=s4;
    
        space[x+dx[dir]*3][y+dy[dir]*3]+=s5;
    
        space[x+dx[dir]*2][y+dy[dir]*2]+=rest;
        
    }
    
}

int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> space[i+3][j+3];
        }
    }
    int dir = 0;
    int sx = (n+1)/2 + 2, sy = (n+1)/2 + 2;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<i;k++){
                tornado(sx, sy, dir);
                sx+=dx[dir];
                sy+=dy[dir];
            }
            dir++;
            if(dir==4) dir=0;
        }
    }
    for(int k=0;k<n-1;k++){
        tornado(sx, sy, dir);
        sx+=dx[dir];
        sy+=dy[dir];
    }
    int out = 0;
    for(int i=0;i<=n+7;i++){
        for(int j=0;j<=n+7;j++){
            out+=space[i][j];
        }
    }
    for(int i=3;i<n+3;i++){
        for(int j=3;j<n+3;j++){
            out-=space[i][j];
        }
    }
    printf("%d", out);
}