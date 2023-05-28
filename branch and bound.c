#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N] = {0};
int minCost = INT_MAX;

void branchAndBoundTSP(int currCity, int cost, int count) {
    visited[currCity] = 1;

    if (count == N - 1) {
        if (graph[currCity][0] != 0 && cost + graph[currCity][0] < minCost) {
            minCost = cost + graph[currCity][0];
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i] && graph[currCity][i] != 0 && cost + graph[currCity][i] < minCost) {
                branchAndBoundTSP(i, cost + graph[currCity][i], count + 1);
            }
        }
    }

    visited[currCity] = 0;
}

int main() {
    branchAndBoundTSP(0, 0, 0);
    printf("Minimum cost for TSP: %d\n", minCost);
    return 0;
}
