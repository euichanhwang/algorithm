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

int number;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    list<char> L;
    string input;
    cin >> input;
    for(auto e:input)
        L.push_back(e);
    
    auto cursor=L.end();
    cin >> number;
    while(number--)
    {   
        char ch;
        cin >> ch;
        if(ch=='P')
        {
            char add;
            cin >> add;
            L.insert(cursor,add);

        }
        else if(ch=='L')
        {
            if(cursor!=L.begin()) cursor--;
        }
        else if(ch=='D')
        {
             if(cursor!=L.end()) cursor++;
        }
         else //B
        {
             if(cursor!=L.begin())
             {
                cursor--;
                cursor=L.erase(cursor);
             }
        }
    }
    for (auto e:L)
        cout << e;

    return 0;
}
