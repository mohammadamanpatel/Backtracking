class Solution {
public:
      bool isSafe(vector<vector<char>>& board,int i,int j,char &value){
        int n = board.size();
        for(int x=0;x<n;x++)
        {
            if(board[i][x]==value)
                return false;
            if(board[x][j]==value)
                return false;
            if(board[3*(i/3)+(x/3)][3*(j/3)+(x%3)]==value)           
                return false;           
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(char val = '1';val<='9';val++)
                    {
                        if(isSafe(board,i,j,val))
                        {
                            board[i][j] = val;
                            bool remainingSoln = solve(board);
                            if(remainingSoln == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.'; 
                            }
                        }
                    }
                    return false;
                }
            }
        }



        //means me sab no place kar chuka hun saara board 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }
};
