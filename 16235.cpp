#include <iostream>
#include <vector>

using namespace std;

short winter_feed[11][11] = {0};
vector<short> trees[12][12];
int feeds[11][11];
short N;
char dx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

void spring_summer(){
    vector<int> temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            //if(!trees[i][j].empty()){
            int trees_siz = trees[i][j].size();
            temp.clear();
            for(int k=trees_siz-1;k>=0;k--){
                if(feeds[i][j]<trees[i][j][k]){
                    int feed;
                    for(int l=0;l<k;l++){
                        feed += trees[i][j][l]/2;
                    }
                    feeds[i][j] += feed;
                    trees[i][j].clear();
                    //if(!temp.empty()){
                    for(int l=0;l<temp.size();l++){
                        trees[i][j].push_back(temp[l]);
                    }
                    //}
                    break;
                }
                else{
                    feeds[i][j]-=trees[i][j][k];
                    trees[i][j][k]++;
                    temp.push_back(trees[i][j][k]);
                }
            }
            //}
        }
    }
}

void fall_winter(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            //if(!trees[i][j].empty()){
            for(int k=0;k<trees[i][j].size();k++){
                if(trees[i][j][k]%5 == 0){
                    for(int l=0;l<8;l++){
                        trees[i+dx[l]][j+dy[l]].push_back(1);
                    }
                }
            }
            //}
            feeds[i][j]+=winter_feed[i][j];
        }
    }
}

int main(void){
    int M, K;
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> winter_feed[i][j];
        }
    }
    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            feeds[i][j] = 5;
        }
    }
    
    for(int i=0;i<K;i++){
        spring_summer();
        fall_winter();
    }

    int res = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            //if(!trees[i][j].empty()){
            res+=trees[i][j].size();
            //}
        }
    }
    cout << res;
    return 0;
}