#include <bits/stdc++.h>

using namespace std;

bool is_valid_arrangement(vector<pair<int, int>> &pairs)
{
  for (int i = 0; i < pairs.size() - 1; i++)
  {
    if (pairs[i].second != pairs[i + 1].first)
    {
      return false;
    }
  }
  return true;
}

vector<pair<int, int>> construct_arrangement(vector<pair<int, int>> &pairs)
{
  vector<pair<int, int>>
      arrangement(pairs);
  return arrangement;
}

int main()
{
  int num_pairs;

  cout << "Enter the number of pairs: ";
  cin >> num_pairs;

  vector<pair<int, int>> pairs;

  // Get user input for each pair (element1 element2)
  for (int i = 0; i < num_pairs; i++)
  {
    int element1, element2;
    cout << "Enter pair " << i + 1 << " (element1 element2): ";
    cin >> element1 >> element2;
    pairs.push_back(make_pair(element1, element2));
  }

  if (is_valid_arrangement(pairs))
  {
    vector<pair<int, int>> arrangement = construct_arrangement(pairs);
    cout << "Valid arrangement:" << endl;
    for (auto pair : arrangement)
    {
      cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
  }
  else
  {
    cout << "No valid arrangement possible" << endl;
  }

  return 0;
}
