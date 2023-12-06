#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream file("day6input.txt");
    string line;
    int value = 0;
    int part_a = 0;
    long int part_b = 0;
    long double distance_traveled = 0;
    long int product = 1;
    vector<int> times;
    vector<int> distances;
    string v;
    long double time;
    long double distance;
    getline(file, line);
    //part 1
    istringstream st(line);
    st.ignore(5, ':');
    while (st >> value) {
        times.push_back(value);
    }
    //part 2
    for (char c : line) {
        if (isdigit(c)) {
            v += c;
        }
    }
    time = stod(v);
    v = "";
    getline(file, line);
    //part 1
    istringstream sd(line);
    sd.ignore(11, ':');
    value = 0;
    while (sd >> value) {
        distances.push_back(value);
    }
    // part 2 
    for (char c : line) {
        if (isdigit(c)) {
            v += c;
        }
    }
    distance = stod(v);
    for (int i = 0; i < times.size(); i++) {
        part_a = 0;
        for (int j = 0; j < times.at(i); j++) {
            distance_traveled = j * (times.at(i) - j); // j = hold button time/speed    times,at(i) - j = time to move
            if (distance_traveled > distances.at(i)) {
                part_a++;
            }
        }
        product *= part_a;
    }
    for (int j = 0; j < time; j++) {
        distance_traveled = j * (time - j);
        if (distance_traveled > distance) {
            part_b++;
        }
    }
    cout << "part a: " << product << endl;
    cout << "part b: " << part_b << endl;
}