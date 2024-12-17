#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

// Поиск в глубину
void dfs(int node, int componentId, const vector<vector<int>>& adMatrix, vector<int>& component) {
    component[node] = componentId; 
    for (int neighbor = 0; neighbor < adMatrix.size(); neighbor++) {
        if (adMatrix[node][neighbor] == 1 && component[neighbor] == -1) {
            dfs(neighbor, componentId, adMatrix, component);
        }
    }
}

int main() {
    system("chcp 1251");
    // Ввод количества вершин и рёбер
    int n, m;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    cout << "Введите количество рёбер графа: ";
    cin >> m;

    // Инициализация матрицы смежности
    vector<vector<int>> adMatrix(n, vector<int>(n, 0));

    // Ввод рёбер
    cout << "Введите рёбра графа(индексация с 0):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Ребро " << i + 1 << ": ";
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Ошибка: вершины должны быть в диапазоне от 0 до " << n - 1 << endl;
            i--; 
            continue;
        }
        adMatrix[u][v] = 1;
        adMatrix[v][u] = 1; 
    }

    // Вывод матрицы смежности
    cout << endl << "Матрица смежности графа:" << endl;
    cout << "   "; 
    for (int i = 0; i < n; i++) {
        cout << setw(2) << i << " "; 
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(2) << i << " "; 
        for (int j = 0; j < n; j++) {
            cout << setw(2) << adMatrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> component(n, -1); // Массив для хранения индексов компонент
    int componentId = 0;

    // Запуск DFS для нахождения всех компонент связности
    for (int i = 0; i < n; i++) {
        if (component[i] == -1) { 
            dfs(i, componentId, adMatrix, component);
            componentId++;
        }
    }

    // Вывод результата
    cout << endl << "Результаты:" << endl;
    cout << "Граф содержит " << componentId << " компонент(ы) связности." << endl;
    cout << "Вершины и их индексы компонент связности:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << " принадлежит компоненте " << component[i] + 1 << endl;
    }

    return 0;
}



