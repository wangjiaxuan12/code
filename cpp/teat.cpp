#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    vector<string> cities = {"北京", "上海", "广州", "成都", "武汉", "西安"};
    vector<vector<int>> dist = {{0, 1000, INF, INF, INF, 1000},
                                {1000, 0, INF, INF, 750, INF},
                                {INF, INF, 0, 1400, INF, INF},
                                {INF, INF, 1400, 0, 800, 600},
                                {INF, 750, INF, 800, 0, 1000},
                                {1000, INF, INF, 600, 1000, 0}};
    int n = cities.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cities[i] << "到" << cities[j] << "的最短距离为：";
            if (dist[i][j] == INF) {
                cout << "error" << endl;
            } else {
                cout << dist[i][j] << "km" << endl;
            }
        }
    }

    return 0;
}
