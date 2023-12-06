#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    string line;
    ifstream file("day5input.txt");
    vector<long long int> seed_nums;
    getline(file, line);
    istringstream scan(line);
    scan.ignore(6, ':');
    long long int seed_n;
    long long int seed_range;
    long long int origin_start;
    long long int origin_end;
    long long int destination_start;
    long long int destination_end;
    while (scan >> seed_n >> seed_range) {
        for (int i = 0; i < seed_range; i++) {
            seed_nums.push_back(seed_n + i);
        }
    }
    vector<bool> updated(seed_nums.size(), false);
    while (getline(file, line)) {
        if (line.find("map") != string::npos) {
            continue;
        } else if (line.size() == 0) {
            for (long long int i = 0; i < seed_nums.size(); i++) {
                updated[i] = false;
            }
        } else {
            istringstream map(line);
            vector<long long int> ranges;
            long long int range_value;
            map >> range_value;
            ranges.push_back(range_value);
            map >> range_value;
            ranges.push_back(range_value);
            map >> range_value;
            ranges.push_back(range_value);
            origin_start = ranges.at(1);
            origin_end = ranges.at(1) + ranges.at(2) - 1;
            destination_start = ranges.at(0);
            destination_end = ranges.at(0) + ranges.at(2) -1;
            for (long long int i = 0; i < seed_nums.size(); i++) {
                if (!updated[i] && seed_nums[i] >= origin_start && seed_nums[i] <= origin_end) {
                    seed_nums[i] = destination_start + seed_nums[i] - origin_start;
                    updated[i] = true;
                }
            }
        }
    }
    long long int nearest = seed_nums[0];
    for (int j = 0; j < seed_nums.size(); j++) {
        if (seed_nums.at(j) < nearest) {
            nearest = seed_nums.at(j);
        }
    }
    cout << nearest << endl;
}