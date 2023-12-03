#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
  ifstream infile("day1input.txt");
  int total = 0;
  int nums[1000];
  int idx = 0;
  string line;
  int temp = 0;
  if (infile.is_open()) {
    while (getline(infile, line)) {
      for (int i = 0; i < line.length(); i++) {
        if (isdigit(line.at(i))) {
          temp = line.at(i) - '0';
        } else if (line.substr(i, 3) == "one") {
          temp = 1;
        } else if (line.substr(i, 3) == "two") {
          temp = 2;
        } else if (line.substr(i, 5) == "three") {
          temp = 3;
        } else if (line.substr(i, 4) == "four") {
          temp = 4;
        } else if (line.substr(i, 4) == "five") {
          temp = 5;
        } else if (line.substr(i, 3) == "six") {
          temp = 6;
        } else if (line.substr(i, 5) == "seven") {
          temp = 7;
        } else if (line.substr(i, 5) == "eight") {
          temp = 8;
        } else if (line.substr(i, 4) == "nine") {
          temp = 9;
        }
        nums[idx] = temp;
        idx++;
      }
      total += (nums[0] * 10) + nums[idx-1];
    }
    cout << "Total: " << total << endl;
    }
  }
