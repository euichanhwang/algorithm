#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
#define X first
#define Y second
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
int n,k; //n은 수빈이의 위치,k는 동생이 있는 위치
bool vis[100002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    queue<pii> q; //위치,시간
    q.push({n,0});
    int ans=0;//가장 빠른 시간
    int cnt=0;//찾는 방법의 수 
    while(!q.empty())
    {
        int now=q.front().first; //현재 위치
        int time=q.front().second; //시간
        q.pop();
        vis[now]=true;
        //처음 찾았을 때
        if(!cnt&&now==k)
        {
            ans=time;
            cnt++;
        }
        //그 이후에 찾았을 때
        else if(cnt&&now==k&&ans==time)
            cnt++;    


        for(int nxt:{now-1,now+1,2*now})
        {
            if(nxt<0||nxt>100000)continue;
            if(!vis[nxt])
            {
                q.push({nxt,time+1});
            }
        }
    }
    cout << ans << '\n';
    cout << cnt << '\n';
   
  

    
 
   


    return 0;
}
