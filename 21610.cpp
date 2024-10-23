#include <iostream>
#include <vector>

using namespace std;

int n;
int space[51][51]={0};
vector <pair<int, int>> cloud;
int dx[8]={0, -1, -1, -1, 0, 1, 1, 1}, dy[8]={-1, -1, 0, 1, 1, 1, 0, -1};

void move_rain_clear_cloud(int dir, int dist){
    for(int i=0;i<cloud.size();i++){
        for(int j=0;j<dist;j++){
            cloud[i].first+=dx[dir];
            cloud[i].second+=dy[dir];
            if (cloud[i].first==-1){
                cloud[i].first = n-1;
            }
            else if (cloud[i].first==n){
                cloud[i].first = 0;
            }
            if (cloud[i].second==-1){
                cloud[i].second = n-1;
            }
            else if(cloud[i].second==n){
                cloud[i].second = 0;
            }
        }
        space[cloud[i].first][cloud[i].second]++;
    }
    for(int i=0;i<cloud.size();i++){
        int water = 0;
        printf("after get_water:\n");
        vector<pair<int, int>> get_water;
        if (!(cloud[i].first-1<0 || cloud[i].second-1<0)){
            if(space[cloud[i].first-1][cloud[i].second-1]>0){
                printf("%d %d\n", cloud[i].first-1, cloud[i].second-1);
                water++;
                get_water.push_back(make_pair(cloud[i].first-1, cloud[i].second-1));
            }
        }
        if (!(cloud[i].first-1<0 || cloud[i].second+1>=n)){
            if(space[cloud[i].first-1][cloud[i].second+1]>0){
                printf("%d %d\n", cloud[i].first-1, cloud[i].second+1);
                water++;
                get_water.push_back(make_pair(cloud[i].first-1, cloud[i].second+1));
            }
        }
        if (!(cloud[i].first+1>=n || cloud[i].second+1>=n)){
            if(space[cloud[i].first+1][cloud[i].second+1]>0){
                printf("%d %d\n", cloud[i].first+1, cloud[i].second+1);
                water++;
                get_water.push_back(make_pair(cloud[i].first+1, cloud[i].second+1));
            }
        }
        if (!(cloud[i].first+1>=n || cloud[i].second-1<0)){
            if(space[cloud[i].first+1][cloud[i].second-1]>0){
                printf("%d %d\n", cloud[i].first+1, cloud[i].second-1);
                water++;
                get_water.push_back(make_pair(cloud[i].first+1, cloud[i].second-1));
            }
        }
        for(int j=0;j<get_water.size();j++){
            space[get_water[j].first][get_water[j].second]+=water;
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                printf("%d ", space[j][k]);
            }
            printf("\n");
        }
    }
    vector<pair<int, int>> cloud_temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (space[i][j]>=2){
                int impossible = 0;
                for(int k=0;k<cloud.size();k++){
                    if(cloud[k].first == i && cloud[k].second == j){
                        impossible = 1;
                        break;
                    }
                }
                if (!impossible){
                    cloud_temp.push_back(make_pair(i, j));
                    space[i][j]-=2;
                }
            }
        }
    }
    cloud = cloud_temp;
}

int main(void){
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> space[i][j];
        }
    }
    int dir, dist;
    cloud.push_back(make_pair(n-1, 0));
    cloud.push_back(make_pair(n-1, 1));
    cloud.push_back(make_pair(n-2, 0));
    cloud.push_back(make_pair(n-2, 1));
    for(int i=0;i<m;i++){
        cin >> dir >> dist;
        move_rain_clear_cloud(dir-1, dist);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                printf("%d ", space[j][k]);
            }
            printf("\n");
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            total+=space[i][j];
        }
    }
    printf("%d\n", total);
}