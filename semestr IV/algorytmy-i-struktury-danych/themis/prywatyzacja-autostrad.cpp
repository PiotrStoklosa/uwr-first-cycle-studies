#include <iostream>
#include <vector>
#include <queue>

int main() {

    int n, m;

    scanf("%d %d",&n, &m);

    std :: vector<std :: pair <int,int>> highway[n+1];
    int result[n+1];

    int a,b,c;

    for (int i = 0; i < m; i++){

        scanf("%d %d %d", &a, &b, &c);

        highway[a].emplace_back(std :: make_pair(b,c));
        highway[b].emplace_back(std :: make_pair(a,c));

    }

    result[1]=0;

    for (int i = 2; i <= n; i++)
        result[i] = 2147483647;

    std :: priority_queue <std :: pair < int, int>, std::vector<std :: pair < int, int>>, std :: greater<>> queue;

    queue.push(std :: make_pair(0,1));

    int v, u, w;

    while(!queue.empty()){

        u = queue.top().second;
        queue.pop();

        for (int i = 0; i < highway[u].size(); i++){

            v = highway[u][i].first;
            w = highway[u][i].second;

            if (result[v] > result[u] + w){

                result[v] = result[u] + w;
                queue.push(std :: make_pair(result[v], v));

            }

        }

    }

    printf("%d", result[2]);

    for (int i = 3; i <= n; i++)
        printf(" %d", result[i]);

    return 0;

}