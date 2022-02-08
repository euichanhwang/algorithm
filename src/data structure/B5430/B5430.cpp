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
typedef pair<char,int > pci;
#define X first
#define Y second
void parse(string &tmp,deque<int> &d) //[1,2,3,4] -> 1 2 3 4로 deque 에 넣기
{
    int cur=0;
    for(int i=1;i+1<tmp.size();i++)
    {
        if(tmp[i]==',')
        {
            d.push_back(cur);
            cur=0;
        }
        else
            cur=10*cur+(tmp[i]-'0');
    }
    //[44] 같은 경우에는, 나중에 deque에 넣어준다. 
    if(cur!=0)
        d.push_back(cur);

}
void print(deque<int>&d) // 1 2 3 4를 [1,2,3,4] 형식으로 출력
{
    cout << '[';
    for(int i=0;i<d.size();i++)
    {
        cout <<d[i];
        if(i+1!=d.size())
            cout << ',';
    }
    cout << ']' <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number;
    cin >> number;

    while(number--)
    {
        deque<int> d;
        string func;
        string repeatNum;
        string tmp;
        bool flag=false;
        cin >> func;
        cin >> repeatNum;
        cin >> tmp;
        int rev=0;
        parse(tmp,d);
        for(auto c:func)
        {
            if(c=='R') //REVERSE
                rev=1-rev;
            else //D . DELETE
            {
                if(d.empty()) // 비어있다면 error 출력
                {
                    flag=true;
                    break;
                }
                else
                {

                    if(!rev) d.pop_front(); //안뒤집어져 있다면 맨처음에서 뺀다.
                    else d.pop_back(); //뒤집힌 상태라면 뒤에서 뺀다.
                }
            }
        }

        if(flag) cout << "error" << '\n';
        else
        {
            if(rev)reverse(d.begin(),d.end());
            print(d);
        }
    }



    return 0;
}