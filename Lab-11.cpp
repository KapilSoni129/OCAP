#include <iostream>
#include <vector>

using namespace std;

int countSubgrids(const vector<vector<int>> &grid)
{
  int n = grid.size();
  int count_subgrids = 0;
  vector<int> count_row_black_begin(n, 0); // Stores consecutive black cells at the beginning of each row
  vector<int> count_col_black_end(n, 0);   // Stores consecutive black cells at the end of each column

  for (int row = 0; row < n; ++row)
  {
    for (int col = 0; col < n; ++col)
    {
      if (grid[row][col] == 1)
      {
        count_row_black_begin[col]++;
        count_col_black_end[row]++;
      }
      else
      {
        count_row_black_begin[col] = 0;
        count_col_black_end[row] = 0;
      }

      if (row > 0 && col > 0)
      {
        count_subgrids += count_row_black_begin[col] * count_col_black_end[row];
      }
    }
  }

  return count_subgrids;
}

int main()
{
  int n;
  cout << "Enter the size of the grid (n x n): ";
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  cout << "Enter the elements of the grid (0 for white, 1 for black):\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> grid[i][j];
    }
  }

  int total_subgrids = countSubgrids(grid);
  cout << "Total number of subgrids with all four corners black: " << total_subgrids << endl;

  return 0;
}
