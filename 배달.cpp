#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 10000000;
int min_time[51];
vector<vector<pair<int,int>>> info;
priority_queue<pair<int, int>> pq;

void find(){
    while(!pq.empty()){
        // 우선순위 큐에서 짧은 거리가 먼저 오게 하기 위해서 음수화를 함
        int time = -pq.top().second;
        int city = pq.top().first;
        
        pq.pop();
        
        // 기존에 구해놓은 값이 더 작으면 진행하지 않고 다음으로 넘어감
        if(min_time[city] < time)
            continue;
        
        // 다음 도시와 연결된 간선들을 하나씩 살펴봄
        for(int i = 0; i < info[city].size(); i++)
        {
            int nextCity = info[city][i].first;
            int nextTime = info[city][i].second + time;
            
            // 만약 위에서 선택된 도시를 거쳐서 다음 도시까지 갈 때 걸린 시간이
            // 이전에 구한 다음 도시까지 갈 때 걸린 시간보다 작으면 update하고 
            // pq에 음수화 시켜서 push
            if(nextTime < min_time[nextCity]){
                min_time[nextCity] = nextTime;
                pq.push({nextCity, -nextTime});
            }
        }
        
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 최소시간을 저장하는 배열 초기화
    for(int i = 0 ; i < 51; i++){
        min_time[i] = INF;
    }
    
    // vector의 크기를 지정
    info.resize(N+1);

    // 인접리스트를 활용
    for(int i = 0 ; i < road.size(); i++){
        // pair -> 인접한 마을, 걸리는 시간
        info[road[i][0]].push_back({road[i][1], road[i][2]});
        info[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    // 1번 마을에 걸리는 시간은 0
    pq.push({1, 0});
    min_time[1] = 0;
    
    find();
   
    for(int i = 1 ; i <= N; i++){
        if(min_time[i] <= K)
            answer++;
    }

    return answer;
}
