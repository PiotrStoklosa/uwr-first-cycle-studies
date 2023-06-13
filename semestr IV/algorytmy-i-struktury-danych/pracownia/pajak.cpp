#include <iostream>
#include <algorithm>
#include <queue>

struct Edge {

    int source;
    int destination;
    int weight;

};

int parent[1'000'001];

int findSet(int v) {

    int parentTemp = v;

    while(parentTemp != parent[parentTemp]) {

        parentTemp = parent[parentTemp];
        parent[v] = parentTemp;

    }

    return parent[v];
}

void joinSets(int v1, int v2){

    parent[findSet(v1)] = findSet(v2);

}

int main() {

    int v;
    int e;
    scanf("%d %d", &v, &e);

    int source;
    int destination;
    int weight;

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    auto compare = [](Edge edge1, Edge edge2) { return edge1.weight < edge2.weight; };
    std::priority_queue<Edge, std::vector<Edge>, decltype(compare) > graph(compare);

    for (int i = 0; i < e; i++){

        scanf("%d %d %d", &source, &destination, &weight);
        graph.push({source, destination, weight});

    }

    Edge top;
    Edge last;

    int tree = 1;

    while(!graph.empty() && tree < v){

        top = graph.top();
        graph.pop();

        if (findSet(top.source) != findSet(top.destination)){

            joinSets(top.source, top.destination);

            tree ++;

            if (tree == v)
                last = top;

        }
    }

    printf("%d", last.weight);

    return 0;
}
