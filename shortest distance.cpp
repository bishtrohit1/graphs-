class Solution {
public:
    bool check(int i, int j, int n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        int tr[] = {1, 1, -1, -1, 1, -1, 0, 0};
        int tc[] = {1, 0, -1, 0, -1, 1, 1, -1};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n-1 && c == n-1) {
                return dis+1;
            }

            if (visited[r][c] || grid[r][c] == 1) {
                continue;
            }

            visited[r][c] = true;

            for (int i = 0; i < 8; i++) {
                int cr = r + tr[i];
                int cc = c + tc[i];

                if (check(cr, cc, n) && !visited[cr][cc] && grid[cr][cc] == 0) {
                    pq.push({dis + 1, {cr, cc}});
                }
            }
        }

        return -1; 
    }
};
