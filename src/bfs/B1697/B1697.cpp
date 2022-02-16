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
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs용
#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,k;
int dist[100002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    fill(dist,dist+100001,-1);
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(dist[k]==-1)
    {
        auto cur=q.front();q.pop();
        for(int nxt:{cur-1,cur+1,2*cur})
        {
            if(nxt<0||nxt>100000)continue;
            if(dist[nxt]!=-1)continue; //이미 방문함.
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
        }
    }
    cout << dist[k];


}