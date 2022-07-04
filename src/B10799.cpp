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
ll ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    stack<char> st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            st.push(str[i]);
        else //')'
        {
            if(str[i-1]=='(') //레이저
            {
                st.pop();
                ans+=st.size();
            }
            else //막대의 끝
            {
                st.pop();
                ans++;
            }
    
        }
    }
    cout << ans;
 
   


    return 0;
}
