// 暴力 O(N^2 + M)
i64 prim() {
    i64 ans = 0;
    vector<bool> vis(n + 1);
    vector<i64> dis(n + 1, INF);
    dis[1] = 0;
    for(int i = 1; i <= n; i++){
        int u = 0;
        i64 mn = INF;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dis[j] < mn){
                u = j, mn = dis[j];
            }
        }
        if(!u)  return -1;
        vis[u] = 1;
        ans += dis[u];
        for(auto j : edge[u]){
            if(dis[j.v] > j.w)
                dis[j.v] = j.w;
        }
    }
    return ans;
}
// 二叉堆优化 O((N + M)LOG N)
i64 prim(){
    i64 ans = 0;
    int cnt = 0;
    vector<bool> vis(n + 1);
    vector<i64> dis(n + 1, INF);
    using PII = pair<i64, i64>;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while(!pq.empty()){
    if(cnt >= n)    break;
        auto [d, u] = pq.top();
        pq.pop();
        if(vis[u])  continue;
        vis[u] = 1;
        ans += d;
        cnt++;
        for(auto i : edge[u]){
            if(!vis[i.v] && i.w < dis[i.v]){
                dis[i.v] = i.w;
                pq.push({dis[i.v], i.v});
            }
        }
    }
    if(cnt < n) return -1;
    else    return ans;
}
