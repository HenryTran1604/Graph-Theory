# Lý thuyết cơ bản về đồ thị, bao gồm:
1. Chuyển các dạng biểu diễn của đồ thị:
    * Từ danh sách cạnh sang ma trận kề (ngược lại)
    * Từ danh sách cạnh sang danh sách kề (ngược lại)
    * Từ ma trận kề sang danh sách kề (ngược lại)
2. Duyệt theo chiều sâu (Dept first search : DFS)
    * Sử dụng đệ quy (recursive)
    * Sử dụng ngăn xếp (stack)
3. Duyệt theo chiều rộng (Breadth first search : BFS)
4. Ứng dụng của DFS và BFS:

    **Đối với đồ thị VÔ HƯỚNG:**
    * Kiếm tra tồn tại và truy vết đường đi
        * Trên đồ thị (Graph)
        * Trên lưới (Grid)
        > Đường đi với BFS luôn là đường đi với số cạnh ít nhất
    * Đếm số thành phần liên thông
        * Trên đồ thị (Graph)
        * trên lưới (Grid)
    * Kiểm tra chu trình và truy vết
    * Liệt kê các cạnh cầu của đồ thị
        > Cạnh cầu là cạnh mà khi bỏ nó đi, số thành phần liên thông của đồ thị tăng lên
    * Liệt kê các đỉnh trụ
        > Đỉnh trụ là đỉnh mà khi bỏ nó đi, số thành phần liên thông của đồ thị tăng lên
    * Tìm cây khung với DFS và BFS
    * Đồ thị 2 phía
    
    **Đối với đồ thị CÓ HƯỚNG**
    * Kiểm tra chu trình và truy vết
    * Đếm số thành phần liên thông mạnh (Sử dụng BFS và DFS)
    * Sắp xếp Topo (Topological sort)
        * Ứng dụng DFS
        * Thuật toán Kahn
        > Sắp xếp Topo là dãy có thứ tự các đỉnh mà trong đó với mọi cung đi từ u đến v thì u luôn nằm trước v
    * Thuật toán Kosaraju (Đếm số thành phần liên thông mạnh của đồ thị)
5. Disjoin - Set
      > Các tập hợp rời nhau
      * Ứng dụng cho việc kiểm tra tồn tại của chu trình
6. Bài toán tìm đường đi Euler - Hamilton
    * Euler
        > Tìm đường đi sao cho đi qua được tất cả các **CẠNH** đúng 1 lần 
    * Hamilton
        > Tìm đường đi sao cho đi qua được tất cả các **ĐỈNH** đúng 1 lần
7. Các thuật toán trên đồ thị có trọng số

    **CÂY KHUNG CỰC TIỂU**
    * Kruskal
    * Prim
    
    **ĐƯỜNG ĐI NGẮN NHẤT**
    * Dijkstra
        > Tìm đường đi ngắn nhất giữa 2 cặp đỉnh (u, v) trên đồ thị có trong số KHÔNG ÂM
    * Bell-man Ford
        > Tìm đường đi ngắn nhất giữa 2 cặp đỉnh (u, v) trên đồ thị không có chu trình âm
        
        **Ứng dụng trong bài toán tìm chu trình âm**
    * Floyd
        > Tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh (u, v) trên đồ thị không có chu trình âm
 8. Bài toán kinh điển: **Tô màu đồ thị**
 > Trên đây là nội dung danh sách của nhưng source code trong repo này
 
 > Nếu bạn thấy hữu ích, đừng quên thả sao cho mình nhé :fire:
        
