#include <iostream>

using namespace std;

int space[21][21]={0};
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
int sx, sy, siz=2;
int mind = 400;
int visit[21][21]={0};

void eat(int dist, int n, int x, int y){
	if(dist>=mind) return;
	for(int i=0;i<4;i++){
		if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && (visit[x+dx[i]][y+dy[i]]==0 || visit[x+dx[i]][y+dy[i]]>dist+1)){
			if(space[x+dx[i]][y+dy[i]]<=siz){
				visit[x+dx[i]][y+dy[i]] = dist+1;
				if(space[x+dx[i]][y+dy[i]]!=0 && space[x+dx[i]][y+dy[i]]!=siz){
					if(dist+1==mind){
						if(sx>x+dx[i]){
							sx = x+dx[i];
							sy = y+dy[i];
						}
						else if(sx==x+dx[i]){
							if(sy>y+dy[i]){
								sx = x+dx[i];
								sy = y+dy[i];
							}
						}
					}
					else{
						mind = dist+1;
						sx = x+dx[i];
						sy = y+dy[i];
					}
				}
				else{
					eat(dist+1, n, x+dx[i], y+dy[i]);
				}
			}
		}
	}
}

int main(void){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> space[i][j];
			if(space[i][j]==9){
				sx = i;
				sy = j;
			}
		}
	}
	int exp=0, total=0;
	while(1){
		int tx=sx, ty=sy;
		space[sx][sy]=0;
		visit[sx][sy]=1;
		eat(0, n, sx, sy);
		exp++;
		if(exp==siz){
			siz++;
			exp = 0;
		}
		if(tx==sx && ty==sy){
			break;
		}
		space[sx][sy] = 9;
		total+=mind;
		mind=400;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visit[i][j]=0;
			}
		}
	}
	cout << total;
	return 0;
}
