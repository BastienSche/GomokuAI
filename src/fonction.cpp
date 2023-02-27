/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Gomoku hpp file
*/

#include "../includes/Gomoku.hpp"

bool Gomoku::checkStart()
{
    bool st = _st;
    if (!_st) start(20);
    return st;
}

void Gomoku::start(int size)
{
    _st = true;

    std::vector<int> line;
    _size = size;

    _board.clear();

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++) {
			line.push_back(NONE);
        }
		_board.push_back(line);
        line.clear();
	}
    std::cout << "OK" << std::endl;
}

Pos Gomoku::getBestPosition()
{
    int x = 0;
    int y = 0;
    Pos pos{x, y};
    ialgo *_algo;
    _algo = new ialgo(_board, _size);
    pos = _algo->gomokuAnalyse();
    return (pos);
}

int Gomoku::updateBoard(Pos x_y, int player)
{
    if (_board.at(x_y.y).at(x_y.x) == NONE)
        _board.at(x_y.y).at(x_y.x) = player;
    else {
        sendErrorMess("Can't place token on already taken box");
        return (84);
    }
        std::cout << "---------- POS inter -----------" << std::endl;
    for (size_t y = 0; y < _board.size() ; y++) {
        for (size_t x = 0; x < _board.at(y).size(); x++) {
            std::cout << _board.at(y).at(x) << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}

int Gomoku::turn(Pos x_y)
{
    int errr = 0;
    Pos bestPosition;
    if (errr = updateBoard(x_y, YOU) != 0)
        return (84);
    bestPosition = getBestPosition();
    std::cout << bestPosition.x << "," << bestPosition.y << std::endl;
    updateBoard(bestPosition, ME);
}

void Gomoku::begin()
{
    checkStart();
    
    int s = _size / 2;
    _board.at(s).at(s) = ME;
    std::cout << s << "," <<  s << std::endl;
}

int Gomoku::board(std::vector<std::string> arg)
{
    checkStart();
    std::vector<int> line;

    if (_bd == false) {
        _board.clear();
        for (int x = 0; x < _size; x++)
        {
            for (int y = 0; y < _size; y++) {
                line.push_back(NONE);
            }
            _board.push_back(line);
            line.clear();
        }
        _bd = true;
        return 0;
    }

    int player, x, y = 0;
    Pos pos;

    if ((arg.at(0)).size() == 0 || (arg.at(1)).size() == 0 || (arg.at(2)).size() == 0) {
        sendErrorMess("x,y,who or DONE expected after BOARD");
        return 1;
    }

    x = atoi(arg.at(0).c_str());
    y = atoi(arg.at(1).c_str());
    player = atoi(arg.at(2).c_str());

    pos.x = x;
    pos.y = y;

    updateBoard(pos, player);
    _last = pos;
    _player = player;

    return 0;
}

void Gomoku::info()
{
    // Parsing
}

void Gomoku::end()
{
    _board.clear();
}

void Gomoku::about()
{
    std::cout << _about << std::endl;
}