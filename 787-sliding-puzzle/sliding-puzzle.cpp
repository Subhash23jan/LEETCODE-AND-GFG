class Solution {
    pair<int, int> getIndex(vector<vector<int>>& board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) return make_pair(i, j);
            }
        }
        return make_pair(0, 0);
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>, bool> vis;
        queue<pair<int, vector<vector<int>>>> q;
        q.push({0, board});
        vector<vector<int>> res = {
            {1, 2, 3},
            {4, 5, 0}
        };
        int ans = INT_MAX;
        
        // Get dimensions
        int m = board.size();
        int n = board[0].size();
        
        // Directions for moving 0
        int dp[4][2] = {
            {0, 1}, 
            {1, 0},
            {-1, 0},
            {0, -1}
        };

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            auto cnt = front.first;
            auto matrix = front.second;

            if (matrix == res) {
                ans = min(ans, cnt);
                continue;
            }

            auto p = getIndex(matrix);

            for (int i = 0; i < 4; i++) {
                int x = p.first + dp[i][0];
                int y = p.second + dp[i][1];
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    swap(matrix[x][y], matrix[p.first][p.second]);
                    if (!vis[matrix]) {
                        vis[matrix] = true;
                        q.push({cnt + 1, matrix});
                    }
                    swap(matrix[x][y], matrix[p.first][p.second]);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
