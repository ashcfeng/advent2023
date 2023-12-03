#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

pair<pair<int, int>, int> get_number(vector<string> grid, int x, int y);
void adjacent_numbers(vector<string> grid, map<pair<int,int>, int> numbers, int i, int j);

int main() {
  vector<string> grid;
  ifstream file("input.txt");
  string line;
  int sum = 0;
  int product = 0;
  while (getline(file, line)) {
    grid.push_back(line);
  }
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '*') {
        map<pair<int, int>, int> numbers;
        adjacent_numbers(grid, numbers, i, j);
        if (numbers.size() == 2) {
          product = 1;
          for (auto p = numbers.begin(); p != numbers.end(); p++) {
            product *= p->second;
          }
          sum += product;
        }
      }
    }
  }
  cout << sum << endl;
}

pair<pair<int, int>, int> get_number(vector<string> grid, int x, int y) {
  pair<int, int> begin = make_pair(x, y);
  int num = 0;
  while (y - 1 >= 0 && isdigit(grid[x][y - 1])) {
    y--;
  }
  begin = make_pair(x, y);
  while (isdigit(grid[x][y])) {
    num = num * 10 + (grid[x][y] - '0');
    y++;
  }
  return make_pair(begin, num);
}

void adjacent_numbers(vector<string> grid, map<pair<int,int>, int> numbers, int i, int j) {
  if (i > 0 && isdigit(grid[i-1][j])) {
    numbers.insert(get_number(grid, i-1, j));;
  } 
  if (j > 0 && isdigit(grid[i][j-1])) {
    numbers.insert(get_number(grid, i, j-1));;
  }
  if (i < grid.size() - 1 && isdigit(grid[i+1][j])) {
    numbers.insert(get_number(grid, i+1, j));;
  }
  if (j < grid.size() - 1 && isdigit(grid[i][j+1])) {
    numbers.insert(get_number(grid, i, j+1));;
  }
  if (i > 0 && j > 0 && isdigit(grid[i-1][j-1])) {
    numbers.insert(get_number(grid, i-1, j-1));
  } 
  if (i < grid.size() - 1 && j < grid.size() - 1 && isdigit(grid[i+1][j+1])) {
    numbers.insert(get_number(grid, i+1, j+1));
  }
  if (i < grid.size() - 1 && j > 0 && isdigit(grid[i+1][j-1])) {
    numbers.insert(get_number(grid, i+1, j-1));
  }
  if (i > 0 && j < grid.size() - 1 && isdigit(grid[i-1][j+1])) {
    numbers.insert(get_number(grid, i-1, j+1));
  }
}