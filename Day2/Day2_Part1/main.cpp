#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("./dataset.txt");
    if (!file.is_open())
    {
        cerr << "File could not be opened" << endl;
        return 1;
    }
    string line;
    string number;
    int first, second;
    vector<int> numbers;
    int numberOfSafeLines = 0;
    bool isSafe;
    while(!file.eof())
    {
        number = "";
        isSafe = true;
        numbers.clear();
        getline(file, line, '\n');
        while(line.length())
        {
            int pos = line.find(' ');
            if (pos != -1)
            {
                number = line.substr(0, pos);
            }
            else
            {
                pos = line.length() - 1;
                number = line;
            }
            line = line.substr(pos + 1, line.length());
            numbers.push_back(atoi(number.c_str()));
        }
        for (auto numb : numbers)
            cout << numb << " ";
        cout << endl;
        first = numbers[0];
        second = numbers[1];
        if (abs(first - second) > 3 || first == second) isSafe = false;
        if (first > second)
        {
            cout << "vrai" << endl;
            for (unsigned int i = 2; i < numbers.size(); ++i)
            {
                // cout << first << " " << second << endl;
                first = second;
                second = numbers[i];
                if (first < second || abs(first - second) > 3 || first == second)
                {
                    isSafe = false;
                    break;
                }
            }
        }
        else
        {
            cout << "faux" << endl;
            for (unsigned int i = 2; i < numbers.size(); ++i)
            {
                first = second;
                second = numbers[i];
                if (first > second || abs(second - first) > 3 || first == second)
                {
                    isSafe = false;
                    break;
                }
            }
        }
        cout << isSafe << endl;
        if (isSafe)
            numberOfSafeLines++;
    }
    cout << numberOfSafeLines << endl;
    return 0;
}
