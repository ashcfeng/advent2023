#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool adjacent_symbols(vector<string> grid, int i, int j);
bool is_symbol(char s);

int main() {
  vector<string> grid;
  ifstream file("day3input.txt");
  string line;
  int num = 0;
  bool symbol = false;
  int sum = 0;
  while (getline(file, line)) {
    grid.push_back(line);
  }
  for (int i = 0; i < grid.size(); i++) {
    num = 0;
    symbol = false;
    for (int j = 0; j < grid[i].size(); j++) {
      if (isdigit(grid[i][j])) {
        num *= 10;
        num += grid[i][j] - '0';
        symbol = symbol || adjacent_symbols(grid, i, j);
        if (j == grid.size() -1) {
          if (symbol) {
            sum += num;
          }
          num = 0;
          symbol = false;
        }
      } else {
        if (symbol) {
          sum += num;
        }
        num = 0;
        symbol = false;
      }
    }
  }
  cout << sum << endl;
}

bool adjacent_symbols(vector<string> grid, int i, int j) {
  if (i > 0 && is_symbol(grid[i-1][j])) {
    return true;
  } else if (j > 0 && is_symbol(grid[i][j-1])) {
    return true;
  } else if (i < grid.size() - 1 && is_symbol(grid[i+1][j])) {
    return true;
  } else if (j < grid.size() - 1 && is_symbol(grid[i][j+1])) {
    return true;
  } else if (i > 0 && j > 0 && is_symbol(grid[i-1][j-1])) {
    return true;
  } else if (i < grid.size() - 1 && j < grid.size() - 1 && is_symbol(grid[i+1][j+1])) {
    return true;
  } else if (i < grid.size() - 1 && j > 0 && is_symbol(grid[i+1][j-1])) {
    return true;
  }
  else if (i > 0 && j < grid.size() - 1 && is_symbol(grid[i-1][j+1])) {
    return true;
  } else {
    return false;
  }
}

bool is_symbol(char s) {
  return (s != '.'  && !isdigit(s));
}
