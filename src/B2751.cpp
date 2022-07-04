#include<iostream>
using namespace std;
//typedef long long ll;
//typedef unsigned long long llu;
//typedef pair<int, int> pii;
//typedef pair<double, double> pdd;
//typedef pair<int, pii> piii;
//typedef pair<ll, ll> pll;
//typedef pair<ll, int> pli;
//typedef pair<int, ll> pil;
//typedef pair<string, int> psi;
//typedef pair<int, char> pic;
int arr[1000001];
int sorted[1000001];
int number;
void merge(int *a,int m,int middle,int n)
{
    int i=m;
    int j=middle+1;
    int k=m; //위치 지정
    while(i<=middle && j<=n)
    {
        if(a[i]<=a[j]) // a[j] 가 더 크다
        {
            sorted[k]=a[i];
            i++;
        }
        else
        {
            sorted[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>middle) // j만 남음
    {
        for(int t=j;t<=n;t++)
        {
            sorted[k]=a[t];
            k++;
        }
    }
    else
    {
        for(int t=i;t<=middle;t++)
        {
            sorted[k]=a[t];
            k++;
        }
    }
    for(int t=m;t<=n;t++)
    {
        a[t]=sorted[t];
    }
}
void mergeSort(int *a,int m,int n)
{
    if(m<n)
    {
        int middle=(m+n)/2;
        mergeSort(a,m,middle);
        mergeSort(a,middle+1,n);
        merge(a,m,middle,n);

    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> number;
    for(int i=0;i<number;i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr,0,number-1);
    for(int i=0;i<number;i++)
    {
        cout << arr[i] <<'\n';
    }



    return 0;
}
