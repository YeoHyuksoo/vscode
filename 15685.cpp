#include <iostream>
#include <vector>

using namespace std;

int grid[111][111] = {0};
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
vector<pair<int, int> > edge;

void dragon_curve(int x, int y, int gen, int cur_gen){
    if(gen == cur_gen){
        return;
    }
    int draw_x, draw_y;
    draw_x = x;
    draw_y = y;
    //cout << "draw_x: " << draw_x << " draw_y: " << draw_y << endl;
    int edge_siz = edge.size()-2;
    for(int i=edge_siz;i>=0;i--){
        for(int j=0;j<4;j++){
            if(edge[i].first-x == dx[j] && edge[i].second-y == dy[j]){
                grid[draw_x+dx[(j-1+4)%4]][draw_y+dy[(j-1+4)%4]] = 1;
                edge.push_back(make_pair(draw_x+dx[(j-1+4)%4], draw_y+dy[(j-1+4)%4]));
                draw_x = draw_x+dx[(j-1+4)%4];
                draw_y = draw_y+dy[(j-1+4)%4];
                break;
            }
        }
        x = edge[i].first;
        y = edge[i].second;
    }
    /*for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';*/
    dragon_curve(draw_x, draw_y, gen, cur_gen+1);
}

int main(void){
    int n;
    cin >> n;
    int x, y, d, g, temp;
    for(int i=0;i<n;i++){
        cin >> x >> y >> d >> g;
        temp = x;
        x = y;
        y = temp;
        grid[x][y] = 1;
        grid[x+dx[d]][y+dy[d]] = 1;
        edge.push_back(make_pair(x, y));
        edge.push_back(make_pair(x+dx[d], y+dy[d]));
        dragon_curve(x+dx[d], y+dy[d], g, 0);
        edge.clear();
    }
    int res = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(grid[i][j] == 1 && grid[i+1][j] == 1 && grid[i][j+1] == 1 && grid[i+1][j+1] == 1){
                res++;
            }
        }
    }
    cout << res;
    return 0;
}