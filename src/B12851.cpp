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
int n,k;
bool vis[100002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    queue<pair<int,int>> q;//{위치,시간}
    q.push({n,0});
    int fastTime = 0x7f7f7f7f;
    int way = 0;
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        vis[now] = true;

        if(fastTime < time) break;

        if(now==k){
            fastTime = time;
            way++;
            continue;
        }
        if(now-1>=0 && !vis[now-1]) q.push({now-1,time+1});
        if(now+1<=100000 && !vis[now+1]) q.push({now+1,time+1});
        if(2*now<=100000 && !vis[2*now]) q.push({2*now,time+1});
    }
    cout << fastTime << '\n';
    cout << way;
    return 0;
}