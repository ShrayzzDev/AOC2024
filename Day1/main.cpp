#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    list<int> first, second;
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
        first.push_front(stoi(line.substr(0, 6)));
        second.push_front(stoi(line.substr(8, 6)));
    }
    first.sort();
    second.sort();
    long total = 0;
    list<int>::iterator first_it, second_it;
    first_it = first.begin();
    second_it = second.begin();
    cout << first.size() << endl;
    while (first_it != first.end() && second_it != second.end())
    {
        total += (abs((*second_it) - (*first_it)));
        ++first_it;
        ++second_it;
    }
    cout << total << endl;
    return 0;
}
