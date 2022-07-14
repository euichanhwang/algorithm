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
int n,m;
int board[52][52];
int tmp[52][52];
int dist[52][52];
bool sel[13];
int combinationCount = 0, bfsCount = 0;
vector<pair<int,int>> virus;
vector<pair<int,int>> virus2;
int ans = 1e9;
void copyArray(int des[52][52],int src[52][52]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            des[i][j] = src[i][j];
        }
    }
}
int spreadVirus(){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = -1;
        }
    }
    for(int i=0;i<(int)virus2.size();i++) {
        q.push({virus2[i].first,virus2[i].second});
        dist[virus2[i].first][virus2[i].second] = 0;
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || ny<0 || nx>=n || ny >=n) continue;
            if (board[nx][ny]==1) continue;
            if (dist[nx][ny] >=0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    bool flag = false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j]==0 && dist[i][j]==-1){ // 바이러스를 전파했으나 도달하지 못한 부분이 존재
                bfsCount++;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    int maxTime = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxTime = max(maxTime,dist[i][j]);
        }
    }
    if (flag) return 0x7f7f7f7f;
    return maxTime;
}
void selectVirus(int cur,int idx) {
    if (cur==m) {
        combinationCount++;
        ans = min(ans,spreadVirus());
        return;
    }
    for(int i=idx; i < (int)virus.size(); i++) {
        if(!sel[i]) {
            sel[i] = 1;
            virus2.push_back(virus[i]);
            selectVirus(cur+1,i);
            virus2.pop_back();
            sel[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]==2) virus.push_back({i,j});
        }
    }
    copyArray(tmp,board);
    selectVirus(0,0);
    if (combinationCount == bfsCount) cout << -1;
    else cout << ans;
    return 0;
}