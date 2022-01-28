## [백준 2751 : 수 정렬하기 2](https://www.acmicpc.net/problem/2751)
### 접근 과정
💡수의 개수 N이 1,000,000개 이므로 시간복잡도 O(N^2)인 정렬 방법을 사용하면 시간 초과가 날 가능성이 있다.  
💡**O(NlogN)**의 시간복잡도를 가지는 병합 정렬을 이용해 수를 정렬한다.  
💡[병합 정렬](https://github.com/euichanhwang/CS_study/tree/main/data-structure/%EC%A0%95%EB%A0%AC%20%EB%B0%8F%20%ED%83%90%EC%83%89)은 일단 정확히 반으로 쪼개고 나중에 정렬하는 방식이다.  
```c++
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
```
