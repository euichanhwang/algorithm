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
int t;
int h,w; //h는 헹, w는 열
char board[102][102];
bool vis[102][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t ;
    while(t--){
        for(int i=0;i<h;i++) fill(vis[i],vis[i]+w,0);
        cin >> h >> w;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> board[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]=='.'||vis[i][j]) continue;
                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0||ny<0||nx>=h||ny>=w) continue;
                        if(board[nx][ny]=='.'||vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}