## [백준 13549 : 숨바꼭질 3](https://www.acmicpc.net/problem/13549)  
### 💡접근 방법 : 0-1 bfs : 가중치가 다른 bfs
- bfs를 사용하기 위해서는 , 모든 간선의 가중치가 동일해야 한다. 
- 이 문제는 순간이동 시, 0초 후에 이동할 수 있고 1초 후에 X-1 혹은 X+1 로 이동하므로 가중치가 다르다.  
- 따라서, 다익스트라 알고리즘 혹은 0-1 bfs를 이용해서 문제를 해결할 수 있다.  
### 0-1 bfs : 0-1 bfs
- 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 맨 앞에 넣는 방법이다. 
- 순간 이동을 할 경우 해당 좌표는 덱의 앞에 넣는다.  
- 걷는 이동을 할 경우 해당 좌표는 덱의 뒤에 넣는다.  
- 좌표를 꺼낼 때, pop_front()를 사용하므로 순간이동의 우선순위를 높게 처리할 수 있다. 
```c++
 while(!dq.empty())
    {
        int cur=dq.front();dq.pop_front();
        if(2*cur<MX&&dist[2*cur]==-1){ //가중치가 0이므로 맨 앞에 넣는다
            dist[2*cur]=dist[cur];
            dq.push_front(2*cur);
        }
        for(int nxt:{cur-1,cur+1}){
            if(nxt<0||nxt>=MX||dist[nxt]!=-1)continue; //걷는 좌표는 덱의 뒤에 넣는다
            dist[nxt]=dist[cur]+1;
            dq.push_back(nxt);
        }
    }

```







