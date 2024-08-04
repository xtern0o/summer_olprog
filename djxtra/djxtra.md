# Алгоритм Дейкстры
Алгоритм, позволяющий находить кратчайший путь от данной вершины взвешенного графа до всех остальных.
### Коротко об особенностях
 - при ссчитывании списка смежности будет недостаточно указать лишь два конца данного ребра. Нужно добавить расстояние между вершинами (weight) 
 - для реализации такого подхода удобно использовать тот же список смежности, но вместо вершин, с которыми связана эта вершина будем хранить пару вида `{vertex, weight}`, где vertex - вершина, а weight - расстояние между ними.
 > В случае, если граф ориентированый, то второй раз добавлять ссчитанные данные в список смежности не нужно (в данном фрагменте в случае ориентированого графа следует убрать строчку `graph[b].push_back({a, weight});`)
```cpp
int vertexCount, edgeCount; 
cin >> vertexCount >> edgeCount;
vector<vector<pair<int, int>>> graph(vertexCount + 1);
for (int i = 0; i < edgeCount; i++) {
    int a, b, weight; 
    cin >> a >> b >> weight;
    graph[a].push_back({b, weight});
    graph[b].push_back({a, weight});
}
```
### Реализация (базовый вариант)
```cpp
const int INF = 1e9;

vector<int> dxtra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), INF);    // массив расстояний до вершин (по умолчанию расстояния до вершин равны беск.)
    vector<bool> visited(graph.size());     // массив посещений

    dist[start] = 0;                        // расстояние до стартовой вершины равно нулю

    for (int i = 0; i < graph.size(); i++) {
        int nearest = -1;
        for (int v = 0; v < graph.size(); v++) 
            if (!visited[v] && (nearest == -1 || dist[v] < dist[nearest]))
                nearest = v;                // находим ближайшую вершину
        
        visited[nearest] = true;            // помечаем ее посещенной
        
        for (auto p : graph[nearest]) {
            int to = p.first;
            int weight = p.second;
            if (dist[to] > dist[nearest] + weight)  // проводим релаксацию (ищем более оптимальные пути, которые менее очевидны)
                dist[to] = dist[nearest] + weight;
        }
    }

    return dist;
}
```
#### Сложность алгоритма
В алгоритме требуется V раз определять ближайшую вершину и не более 2E раз (в сумме по всем вершинам) производить релаксации.

Для массива расстояний:
 - сложность определения ближайшей вершины O(V)
 - сложность одной релаксации O(1)
> Таким образом, общая сложность алгоритма составляет **O(V^2 + E)**

### Реализация (с использованием set)
```cpp
const int INF = 1e9;

vector<int> dxtra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    set<pair<int, int>> q; // 1 - weight, 2 - vertex !!!!!! (важно)
    q.insert({dist[start], start});

    while (!q.empty()) {
        int nearest = q.begin()->second;
        q.erase(q.begin());
        
        for (auto p : graph[nearest]) {
            int to = p.first;
            int weight = p.second;
            if (dist[to] > dist[nearest] + weight) {
                q.erase({dist[to], to});
                dist[to] = dist[nearest] + weight;
                q.insert({dist[to], to});
            }
            
        }
    }

    return dist;
}
```
#### Сложность алгоритма
 - сложность определения ближайшей вершины **O(log V)**
 - сложность одной релаксации **O(log V)**
 > Итоговая сложность: **O((V + E) log V)**