#ifndef __ENUM_H_
#define __ENUM_H_

enum Direction
{
    UP = 1,
    DOWN = 3,
    LEFT = 0,
    RIGHT = 2
};

enum Option
{
    OPTION_NONE = -1,
    OPTION_NEWGAME = 0,
    OPTION_HOWTOPLAY = 1,
    OPTION_QUIT = 2
};

enum EnemyType
{
    SLIME = 'o',
    GOON = 'B',
    BAT = '^',
    WORM = 'O',
    WIZARD = 'W'
};

enum WeaponType
{
    SWORD = 0,
    BOW = 1
};

#endif