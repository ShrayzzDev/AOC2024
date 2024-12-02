#include <iostream>
#include <list>
#include <fstream>
#include <set>
#include <map>

using namespace std;

int main()
{
    set<int> first;
    list<int> second;
    ifstream file;
    file.open("./dataset.txt");
    if (!file.is_open())
    {
        cerr << "File could not be opened" << endl;
        return 1;
    }
    while(!file.eof())
    {
        string line;
        getline(file, line, '\n');
        first.insert(stoi(line.substr(0, 6)));
        second.push_back(stoi(line.substr(8, 6)));
    }
    map<int, int> found;
    for(int value : second)
    {
        if (first.find(value) != first.end())
        {
            if (found.find(value) != found.end()) found[value]++;
            else found[value] = 1;
        }
    }
    long total = 0;
    for (auto tuple : found)
        total += tuple.first * tuple.second;
    cout << total << endl;;
    return 0;
}
