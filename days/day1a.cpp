#include <iostream>
#include <fstream>
#include <cmath> 
#include <ctype.h>
#include <cstdlib>
#include <string>
using namespace std;


int main() {
  ifstream infile;
  string line;
  int sum = 0, idx = 0;
  int nums[1000];
  infile.open("day1input.txt", ifstream::in);
  if (infile.is_open()) {
    while (infile.good()) {
      getline(infile, line, '\n');
      idx = 0;
      for (int i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
          nums[idx] = (int)(line[i]) - '0';
          idx++;
        }
      }
      sum += nums[0]*10 + nums[idx-1];
    }
    cout << sum << endl;
  }
}
