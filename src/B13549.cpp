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
int n,k; // n은 수빈이의 위치, k는 동생이 있는 위치
int dist[200002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int MX=200000;
    fill(dist,dist+MX,-1);
    deque<int> dq;
    dq.push_back(n);//5
    dist[n]=0;
    while(!dq.empty())
    {
        int cur=dq.front();dq.pop_front();
        if(2*cur<MX&&dist[2*cur]==-1){
            dist[2*cur]=dist[cur];
            dq.push_front(2*cur);
        }
        for(int nxt:{cur-1,cur+1}){
            if(nxt<0||nxt>=MX||dist[nxt]!=-1)continue;
            dist[nxt]=dist[cur]+1;
            dq.push_back(nxt);
        }
    }
    cout << dist[k];


    return 0;
}