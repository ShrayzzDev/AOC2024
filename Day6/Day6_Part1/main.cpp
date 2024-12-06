#include <iostream>
#include <fstream>
#include <vector>

#include "functions.hpp"

using namespace std;

ostream& operator<<(ostream & os, vector<string> map)
{
    for (auto & line : map)
        os << line << endl;
    return os;
}

int main()
{
    ifstream file;
    file.open("./dataset.txt");
    if (!file.is_open())
    {
        cerr << "ERROR : File could not be openned" << endl;
        return 1;
    }
    vector<string> maze;
    string line;
    int guard_x_pos = 0, guard_y_pos = 0;
    Direction guard_dir;
    while (!file.eof())
    {
        getline(file, line);
        Direction dir = LineHasGuard(line, guard_x_pos);
        maze.push_back(line);
        if (dir != None)
        {
            guard_dir = dir;
            guard_y_pos = maze.size() - 1;
        }
    }
    cout << guard_x_pos << ", " << guard_y_pos << endl;
    cout << guard_dir << endl;
    char next_pos;
    int result = 0;
    int max_length = maze.front().size() - 1;
    int max_height = maze.size() - 1;
    while (guard_x_pos >= 0 && guard_x_pos < max_length + 1
           && guard_y_pos >= 0 && guard_y_pos < max_height + 1)
    {
        if (maze[guard_y_pos][guard_x_pos] != 'X')
        {
            result++;
            maze[guard_y_pos][guard_x_pos] = 'X';
        }
        switch(guard_dir)
        {
            case Up:
                if (guard_y_pos == 0)
                {
                    cout << "hatsune" << endl;
                    break;
                }
                next_pos = maze[guard_y_pos - 1][guard_x_pos];
                break;

            case Right:
                if (guard_x_pos == max_length)
                {
                    cout << "caca" << endl;
                    break;
                }
                next_pos = maze[guard_y_pos][guard_x_pos + 1];
                break;

            case Left:
                if (guard_x_pos == 0)
                {
                    cout << "prout" << endl;
                    break;
                }
                next_pos = maze[guard_y_pos][guard_x_pos - 1];
                break;

            case Down:
                if (guard_y_pos == max_height)
                {
                    cout << "miku" << endl;
                    break;
                }
                next_pos = maze[guard_y_pos + 1][guard_x_pos];
                break;

            case None:
                cerr << "ERROR : Guard should not have direction" << endl;
                return 2;
        };
        guard_dir = NextDir(guard_dir, next_pos);
        NextPos(guard_x_pos, guard_y_pos, guard_dir);
    }
    cout << result << endl;
    return 0;
}
