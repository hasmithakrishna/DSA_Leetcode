class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==m-1 || j == 0 || j==n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        board[i][j] = 'Y';
                    } 
                }
            }
        }
        while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow >=0 && newrow <m && newcol >=0 && newcol <n && board[newrow][newcol] == 'O'){
                board[newrow][newcol] = 'Y';
                q.push({newrow, newcol});
            }
        }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
        
    }
};