#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

// ����� � �������
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
    // ���� ���������� ������ � ����
    int n, m;
    cout << "������� ���������� ������ �����: ";
    cin >> n;
    cout << "������� ���������� ���� �����: ";
    cin >> m;

    // ������������� ������� ���������
    vector<vector<int>> adMatrix(n, vector<int>(n, 0));

    // ���� ����
    cout << "������� ���� �����(���������� � 0):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "����� " << i + 1 << ": ";
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "������: ������� ������ ���� � ��������� �� 0 �� " << n - 1 << endl;
            i--; 
            continue;
        }
        adMatrix[u][v] = 1;
        adMatrix[v][u] = 1; 
    }

    // ����� ������� ���������
    cout << endl << "������� ��������� �����:" << endl;
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

    vector<int> component(n, -1); // ������ ��� �������� �������� ���������
    int componentId = 0;

    // ������ DFS ��� ���������� ���� ��������� ���������
    for (int i = 0; i < n; i++) {
        if (component[i] == -1) { 
            dfs(i, componentId, adMatrix, component);
            componentId++;
        }
    }

    // ����� ����������
    cout << endl << "����������:" << endl;
    cout << "���� �������� " << componentId << " ���������(�) ���������." << endl;
    cout << "������� � �� ������� ��������� ���������:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "������� " << i << " ����������� ���������� " << component[i] + 1 << endl;
    }

    return 0;
}



