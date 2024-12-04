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
        cerr << "ERROR : Could not open file" << endl;
        return 1;
    }
    vector<string> lines;
    string line;
    while(!file.eof())
    {
        getline(file, line);
        lines.push_back(line);
    }
    char word[5] = "XMAS";
    int height = lines.size();
    int length = lines.front().size();
    int k = 0;
    int count = 0;
    bool isFullWord = false;
    bool isTooHigh = false;
    bool isTooLow = false;
    for (int i = 0; i < height; ++i)
    {
        isTooHigh = i <= 3;
        isTooLow = height - i <= 3;
        for (int j = 0; j < length; ++j)
        {
            if (j >= 3)
            {
                for (k = 0; k < 4; ++k)
                {
                    isFullWord = true;
                    if (word[k] != lines[i][j - k])
                    {
                        isFullWord = false;
                        break;
                    }
                }
                if (isFullWord) count++;
                if (!isTooHigh)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        isFullWord = true;
                        if (word[k] != lines[i - k][j - k])
                        {
                            isFullWord = false;
                            break;
                        }
                    }
                    if (isFullWord) count++;
                }
                if (!isTooLow)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        isFullWord = true;
                        if (word[k] != lines[i + k][j - k])
                        {
                            isFullWord = false;
                            break;
                        }
                    }
                    if (isFullWord) count++;
                }
            }
            if (!isTooHigh)
            {
                isFullWord = true;
                for (k = 0; k < 4; ++k)
                {
                    if (word[k] != lines[i - k][j])
                    {
                        isFullWord = false;
                        break;
                    }
                }
                if (isFullWord) count++;
            }
            if (length - j >= 4)
            {
                for (k = 0; k < 4; ++k)
                {
                    isFullWord = true;
                    if (word[k] != lines[i][j + k])
                    {
                        isFullWord = false;
                        break;
                    }
                }
                if (isFullWord) count++;
                if (!isTooHigh)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        isFullWord = true;
                        if (word[k] != lines[i - k][j + k])
                        {
                            isFullWord = false;
                            break;
                        }
                    }
                    if (isFullWord) count++;
                }
                if (!isTooLow)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        isFullWord = true;
                        if (word[k] != lines[i + k][j + k])
                        {
                            isFullWord = false;
                            break;
                        }
                    }
                    if (isFullWord) count++;
                }
            }
            if (!isTooLow)
            {
                isFullWord = true;
                for (k = 0; k < 4; ++k)
                {
                    if (word[k] != lines[i + k][j])
                    {
                        isFullWord = false;
                        break;
                    }
                }
                if (isFullWord) count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
