#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
  const int MAX_RED = 12;
  const int MAX_GREEN = 13;
  const int MAX_BLUE = 14;
  int part1 = 0, part2 = 0;
  int game = 1;
  int value;
  string color;
  bool total;
  ifstream file("day2input.txt");
  for (string line; getline(file, line); ++game) {
    istringstream scan(line);
    scan.ignore(9, ':');
    map<char, int> counter;
    while (scan >> value >> color) {
      counter[color[0]] = max(counter[color[0]], value);
    }
    total = counter['r'] <= MAX_RED && counter['g'] <= MAX_GREEN && counter['b'] <= MAX_BLUE;
    if (total) {
      part1 += game;
    }
    part2 += counter['r'] * counter['g'] * counter['b'];
  }
  cout << part1 << endl;
  cout << part2 << endl;
}
