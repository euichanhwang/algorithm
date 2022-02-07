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

stack<pair<int,int>> st; //height,idx
int number;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    st.push({100000001,0});
    cin >> number;
    for(int i=1;i<=number;i++) //탑의 번호는 1부터 시작
    {
        int height;
        cin >> height;
        while(st.top().X<height)
        {
            st.pop();
        }
        cout << st.top().Y <<" ";
        st.push({height,i});
    }
    
    

 
   


    return 0;
}
