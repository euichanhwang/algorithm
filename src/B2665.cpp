#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
string board[52];
int dist[52][52];
/**
 * 흰 방은 1, 검은 방은 0
 * 검은 방을 흰 방으로 바꿔서 시작 -> 끝 이동
 * 검은 방을 하나도 흰 방으로 바꾸지 않아도 되는 경우는 0이 답.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> board[i];
    memset(dist,-1,sizeof(dist));
    queue<pii> q;
    q.push({0,0});
    dist[0][0]=0;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(board[nx][ny]=='1'){ //다음 방이 흰 방
                if(dist[nx][ny]==-1||dist[nx][ny]>dist[cur.X][cur.Y]){
                    dist[nx][ny]=dist[cur.X][cur.Y];
                    q.push({nx,ny});
                }
            }
            else{ //다음 방이 검은 방
                if(dist[nx][ny]==-1||dist[nx][ny]>dist[cur.X][cur.Y]+1){
                    dist[nx][ny]=dist[cur.X][cur.Y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << dist[n-1][n-1];

    return 0;
}