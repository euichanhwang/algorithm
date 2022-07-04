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
vector<pii> v;
int number;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> number;
    pair<int,int> temp;
    for(int i=0;i<number;i++)
    {
        cin>>temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<number;i++)
    {
        cout <<v[i].first << " " << v[i].second << '\n';
    }
    

    return 0;
}
