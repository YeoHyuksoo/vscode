#include <iostream>
#include <vector>

using namespace std;
struct SHARK{
    int r;
    int c;
    int s;
    int d;
    int z;
};

int R, C, M;
vector<SHARK> sharks;
vector<SHARK> space[101][101];
int answer=0;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, 1, -1};

void fishing(int col){
    int row;
    for(int i=1;i<=R;i++){
        if(space[i][col].size()!=0){
            //fishing
            row = i;
            answer+=space[i][col][0].z;
            break;
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            space[i][j].clear();
        }
    }
    for(int i=0;i<sharks.size();i++){
        if(sharks[i].r == row && sharks[i].c == col) continue;
        int go = sharks[i].s;
        while(go>0){
            if(sharks[i].d<2){
                if(sharks[i].d==0){
                    if(sharks[i].r!=1){
                        if(go>=sharks[i].r-1){
                            go -= sharks[i].r-1;
                            sharks[i].r = 1;
                        }  
                        else{
                            sharks[i].r -= go;
                            break;
                        }
                    }
                    else{
                        sharks[i].d++;
                        if(go>=R-sharks[i].r){
                            go -= R-sharks[i].r;
                            sharks[i].r = R;
                        }
                        else{
                            sharks[i].r += go;
                            break;
                        }
                    }
                }
                else{
                    if(sharks[i].r!=R){
                        if(go>=R-sharks[i].r){
                            go -= R-sharks[i].r;
                            sharks[i].r = R;
                        }
                        else{
                            sharks[i].r += go;
                            break;
                        }
                    }
                    else{
                        sharks[i].d--;
                        if(go>=sharks[i].r-1){
                            go -= sharks[i].r-1;
                            sharks[i].r = 1;
                        }
                        else{
                            sharks[i].r -= go;
                            break;
                        }
                    }
                }
            }
            else{
                if(sharks[i].d==3){
                    if(sharks[i].c!=1){
                        if(go>=sharks[i].c-1){
                            go -= sharks[i].c-1;
                            sharks[i].c = 1;
                        }  
                        else{
                            sharks[i].c -= go;
                            break;
                        }
                    }
                    else{
                        sharks[i].d--;
                        if(go>=C-sharks[i].c){
                            go -= C-sharks[i].c;
                            sharks[i].c = C;
                        }
                        else{
                            sharks[i].c += go;
                            break;
                        }
                    }
                }
                else{
                    if(sharks[i].c!=C){
                        if(go>=C-sharks[i].c){
                            go -= C-sharks[i].c;
                            sharks[i].c = C;
                        }
                        else{
                            sharks[i].c += go;
                            break;
                        }
                    }
                    else{
                        sharks[i].d++;
                        if(go>=sharks[i].c-1){
                            go -= sharks[i].c-1;
                            sharks[i].c = 1;
                        }  
                        else{
                            sharks[i].c -= go;
                            break;
                        }
                    }
                }
            }
        }
        space[sharks[i].r][sharks[i].c].push_back({sharks[i].r, sharks[i].c, sharks[i].s, sharks[i].d, sharks[i].z});
    }
    vector<SHARK> temp;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(space[i][j].size()==1){
                temp.push_back({space[i][j][0].r, space[i][j][0].c, space[i][j][0].s, space[i][j][0].d, space[i][j][0].z});
            }
            else if(space[i][j].size()>1){
                int siz = space[i][j].size();
                int biggest = 0, biggest_idx;
                for(int k=0;k<siz;k++){
                    if(space[i][j][k].z>biggest){
                        biggest = space[i][j][k].z;
                        biggest_idx = k;
                    }
                }
                int big_r = space[i][j][biggest_idx].r;
                int big_c = space[i][j][biggest_idx].c;
                int big_s = space[i][j][biggest_idx].s;
                int big_d = space[i][j][biggest_idx].d;
                int big_z = space[i][j][biggest_idx].z;
                temp.push_back({big_r, big_c, big_s, big_d, big_z});
                space[i][j].clear();
                space[i][j].push_back({big_r, big_c, big_s, big_d, big_z});
            }
        }
    }
    sharks = temp;
}

int main(void){
    cin >> R >> C >> M;
    int r, c, s, d, z;
    for(int i=0;i<M;i++){
        cin >> r >> c >> s >> d >> z;
        d--;
        sharks.push_back({r, c, s, d, z});
        space[r][c].push_back({r, c, s, d, z});
    }
    for(int i=1;i<=C;i++){
        fishing(i);
    }
    printf("%d", answer);
}