#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int i, int j, int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &arr)
{
   if (((i >= 0 && i < row) && (j >= 0 && j < col)) &&
       (arr[i][j] == 1) &&
       (visited[i][j] == false))
   {
      return true;
   }
   else
   {
      return false;
   }
}
void maze(vector<vector<int>> &arr, vector<string> &path, vector<vector<bool>> &visited, int row, int col, int i, int j, string output)
{
   if (i == row - 1 and j == col - 1)
   {
      path.push_back(output);
      return;
   }
   // down
   if (isSafe(i + 1, j, row, col, visited, arr))
   {
      visited[i + 1][j] = true;
      maze(arr, path, visited, row, col, i + 1, j, output + 'D');
      visited[i + 1][j] = false;
   }
   // up
   if (isSafe(i - 1, j, row, col, visited, arr))
   {
      visited[i - 1][j] = true;
      maze(arr, path, visited, row, col, i - 1, j, output + 'U');
      visited[i - 1][j] = false;
   }
   // left
   if (isSafe(i, j - 1, row, col, visited, arr))
   {
      visited[i][j - 1] = true;
      maze(arr, path, visited, row, col, i, j - 1, output + 'L');
      visited[i][j - 1] = false;
   }
   // right
   if (isSafe(i, j + 1, row, col, visited, arr))
   {
      visited[i][j + 1] = true;
      maze(arr, path, visited, row, col, i, j + 1, output + 'R');
      visited[i][j + 1] = false;
   }
}
int main()
{
   vector<vector<int>> arr = { {1,0,1,0}, 
                 {1,1,0, 0},
                 {0,1,1,0},
                 {0,1,1,1},
                 {0,1,1,1}};
   if(arr[0][0] == 0)
   {
      cout<<"no path exist"<<endl;
   }              
   int row = arr.size();
   int col = arr[0].size();
   vector<vector<bool>> visited(row, vector<bool>(col, false));
   visited[0][0] = true;
   vector<string> path;
   string output;
   maze(arr, path, visited, row, col, 0, 0, output);
   for (auto v : path)
   {
      cout << v << " ";
   }
   if(path.size()==0)
   {
      cout<<"no path exist"<<endl;
   }
   cout << endl;
   return 0;
}
