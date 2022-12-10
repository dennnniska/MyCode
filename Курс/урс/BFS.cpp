#include "BFS.h"
int BFS::BFS_cp(int** matr, int kol) {
    distance = new int[kol];
    prevTop = new int[kol];
    for (int i = 0; i < kol; i++) {
        distance[i] = -1;
        prevTop[i] = -1;
    }
    for (int start = 0; start < kol; start++) {
        if (distance[start] == -1) {
            distance[start] = 0;
            Q.push(start);
            while (Q.size()) {
                int u = Q.front();
                Q.pop();
                for (int j = 0; j < kol; j++) {
                    int v = matr[u][j];
                    if (distance[v] == -1) {
                        distance[v] = distance[u] + 1;
                        prevTop[v] = u;
                        Q.push(v);
                    }
                }
            }

            count++;
        }
    }
    delete[] distance;
    delete[] prevTop;
    return count;
}