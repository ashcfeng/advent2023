#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream file("day4input.txt");
    string line;
    vector<int> win;
    vector<int> nums;
    vector<int> copies(190, 1);
    char value;
    int num = 0;
    int num_wins = 0;
    int points = 0;
    int card = 0;
    while (getline(file, line)) {
        num = 0;
        num_wins = 0;
        win.clear();
        nums.clear();
        istringstream scan(line);
        scan.ignore(9, ':');
        while (scan >> noskipws >> value && (value != '|'))  {
            if (value == ' ') {
                if (num > 0) {
                    win.push_back(num);
                    num = 0;
                }
            } else {
                num *= 10;
                num += (int)value - '0';
            }
        }
        nums.push_back(num);
        num = 0;
        scan.ignore(1, '|');
        while (scan >> noskipws >> value) {
            if (value == ' ') {
                if (num > 0) {
                    nums.push_back(num);
                    num = 0;
                }
            } else {
                num *= 10;
                num += (int)value - '0';
            }
        }
        nums.push_back(num);
        num = 0;
        for (int i = 0; i < win.size(); i++) {
            if (count(nums.begin(), nums.end(), win.at(i))) {
                num_wins++;
            }
        }
        for (int j = 1; j <= num_wins; j++) {
            copies.at(card + j) += copies.at(card);
        }
        points += copies.at(card);
        card++;
    }
    cout << points << endl;
}
