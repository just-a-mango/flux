#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cctype>
#include <functional>
#include <regex>
#include <sstream>
#include <chrono>
using namespace std;


vector<string> split_string(const string &str, char delimiter) {
    vector<string> result;
    istringstream iss(str);

    for (string token; getline(iss, token, delimiter);)
        result.push_back(token);

    return result;
}

int main() {
    string s = "print -> usr_in -> hey";
    char delimiter = '->';

    vector<string> results = split_string(s, delimiter);

    for(int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
    return 0;
}