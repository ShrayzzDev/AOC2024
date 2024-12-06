#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>


enum Direction
{
    Up,
    Right,
    Down,
    Left,
    None
};

Direction LineHasGuard(const std::string & line, int & x_pos);

Direction NextDir(Direction curr, char chr);

void NextPos(int & x_pos, int & y_pos, Direction curr_dir);

#endif // FUNCTIONS_HPP
