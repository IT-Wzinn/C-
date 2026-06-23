#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;                      // Số lượng đỉnh của đồ thị
    vector<vector<int>> adj;    // Danh sách kề (Mảng động chứa các đỉnh kề)

public:
    // Hàm khởi tạo đồ thị với V đỉnh
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 1. Thêm cạnh (Add Edge): O(1)
    void addEdge(int u, int v) {
        adj[u].push_back(v); 
        adj[v].push_back(u); // Đồ thị vô hướng thì thêm cả 2 chiều, nếu có hướng thì bỏ dòng này
    }

    // 2. Duyệt theo chiều sâu (DFS - Depth First Search): Dùng đệ quy (Stack ẩn), độ phức tạp O(V + E)
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true; // Đánh dấu đỉnh hiện tại đã thăm
        cout << v << " ";

        // Duyệt qua tất cả các đỉnh hàng xóm kề với v
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited); // Đệ quy sâu xuống đỉnh kề chưa thăm
            }
        }
    }

    // Hàm gọi DFS từ một đỉnh bắt đầu
    void DFS(int startVertex) {
        vector<bool> visited(V, false); // Mảng đánh dấu trạng thái các đỉnh
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    // 3. Duyệt theo chiều rộng (BFS - Breadth First Search): Dùng Queue, độ phức tạp O(V + E)
    void BFS(int startVertex) {
        vector<bool> visited(V, false); // Mảng đánh dấu trạng thái các đỉnh
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex); // Đẩy đỉnh gốc vào hàng đợi

        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            // Lấy tất cả các đỉnh kề của v ra, nếu chưa thăm thì đẩy vào queue
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Khởi tạo đồ thị gồm 5 đỉnh (được đánh số từ 0 đến 4)
    Graph g(5);

    // Thêm các cạnh nối giữa các cặp đỉnh
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    // Thử nghiệm duyệt đồ thị
    cout << "Duyet DFS (Chieu sau) tu dinh 0: ";
    g.DFS(0); // Kết quả: 0 1 3 4 2

    cout << "Duyet BFS (Chieu rong) tu dinh 0: ";
    g.BFS(0); // Kết quả: 0 1 2 3 4

    return 0;
}