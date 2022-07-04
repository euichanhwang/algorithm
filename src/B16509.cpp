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
int dist[12][12];
int s1,s2; //상의 위치
int k1,k2; //왕의 위치
int dx[8]={3,2,-2,-3,-3,-2,2,3};
int dy[8]={2,3,3,2,-2,-3,-3,-2};
bool check(int index,int nx,int ny){ //경로에 왕이 있으면 0, 없으면 1 반환
    if(index==0||index==1){
        for(int i=1;i<=2;i++){
            if (nx - i == k1 && ny - i == k2) return 0;
        }
    }
    if(index==2||index==3){
        for(int i=1;i<=2;i++){
            if (nx + i == k1 && ny - i == k2) return 0;
        }
    }
    if(index==4||index==5){
        for(int i=1;i<=2;i++){
            if (nx + i == k1 && ny + i == k2) return 0;
        }
    }
    if(index==6||index==7){
        for(int i=1;i<=2;i++){
            if (nx - i == k1 && ny + i == k2) return 0;
        }
    }
    return 1; // 경로에 기물이 없을 때
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    cin >> k1 >> k2;
    memset(dist,-1,sizeof(dist));
    queue<pii> q;
    q.push({s1,s2});
    dist[s1][s2]=0;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<8;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=10||ny<0||ny>=9) continue;
            if(dist[nx][ny]!=-1) continue;
            if(check(dir,nx,ny)){
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout << dist[k1][k2];
    return 0;
}