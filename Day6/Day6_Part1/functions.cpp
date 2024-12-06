#include "functions.hpp"

using namespace std;

Direction LineHasGuard(const string & line, int & x_pos)
{
    for (int i = 0; i < line.length(); ++i)
    {
        switch (line[i])
        {
        case '^':
            x_pos = i;
            return Up;
            break;

        case '>':
            x_pos = i;
            return Right;
            break;

        case '<':
            x_pos = i;
            return Left;
            break;

        case 'v':
            x_pos = i;
            return Left;
            break;
        }
    }
    return None;
}

Direction NextDir(Direction curr, char chr)
{
    if (chr == '#')
    {
        switch (curr)
        {
        case Up:
            return Right;

        case Right:
            return Down;

        case Down:
            return Left;

        case Left:
            return Up;

        case None:
            return None;
        }
    }
    return curr;
}

void NextPos(int & x_pos, int & y_pos, Direction curr_dir)
{
    switch(curr_dir)
    {
        case Up:
            y_pos--;
            break;

        case Right:
            x_pos++;
            break;

        case Down:
            y_pos++;
            break;

        case Left:
            x_pos--;
            break;

        case None:
            break;
    }
}
