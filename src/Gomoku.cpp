/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Gomoku hpp file
*/

#include "../includes/Gomoku.hpp"

Gomoku::Gomoku()
{
    _st = false;
    _bd = false;
    _size = 20;
    _x = 0;
    _y = 0;
    _player = 0;
    _about = R"(name="GomoBrain", version="2.0", author="G.X, B.S, A.M", country="FR")";
}

int Gomoku::start_engine()
{
    for (; 1; ) {
        std::vector<std::string> cmds;
        std::vector<std::string> args;
        std::string command;
        std::getline(std::cin, command);

        cmds = ssplits(command, " ");    //parser
        command = cmds.at(0);           //function
        for (int i = 1; i < cmds.size(); i++) {         //args
            args.push_back(cmds.at(i));
        }
        if (interpreter(command, args)) break;
    }
    return 0;
}

int Gomoku::listCommand(std::string command)
{
    int ret = 0;
    std::vector<std::string> commandList
    {"START", "TURN", "BEGIN", "BOARD", "DONE", "INFO","ABOUT", "END"};

    for (; ret < commandList.size(); ret++)
        if (commandList[ret].compare(command) == 0) break;
    return ret;
}

std::vector<std::string> Gomoku::ssplits(std::string s, std::string delim) {
    std::string given_str(s);

    size_t pos = 0;  
    std::string token1;
    std::vector<std::string> elements;
    while (( pos = given_str.find (delim)) != std::string::npos)  
    {  
        token1 = given_str.substr(0, pos); // store the substring   
        elements.push_back(token1);
        given_str.erase(0, pos + delim.length());  /* erase() function store the current positon and move to next token. */   
    }  
        elements.push_back(given_str);
    return (elements);
}

void Gomoku::endBoard()
{
    if (_player == ME) return;
    int iy = 1;
    int ix = 1;
    std::string x = std::to_string(_last.x);
    std::string y = std::to_string(_last.y);
    std::vector<std::string> args {x + "," + y};

    for (auto it = _board.begin(); it != _board.end(); it++, iy++) {
        for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++, ix++) {
            if (ix == _last.x && iy == _last.y)
                *it2 = NONE;
        }
        ix = 1;
    }

    interpreter("TURN", args);
}


int Gomoku::interpreter(std::string command, std::vector<std::string> args)
{
    bool end = false;
    std::vector<std::string> args_split;
    int arg_a;
    Commands cmd = (Commands)listCommand(command);
    if (_bd == true && cmd != DONE) cmd = BOARD;

    switch (cmd)
    {
    case START:
        if (args.size() == 0) {
            sendErrorMess("bad START parameter");
            break;
        }

        arg_a = atoi(args.at(0).c_str());
        if (arg_a == 0)
            sendErrorMess("bad START parameter");
        else
            start(arg_a);
        break;

    case TURN:
        checkStart();
        if (args.size() == 0)
            sendErrorMess("bad coordinates");
        else {
            args_split = ssplits(args.at(0), ",");
            Pos x_y;
            x_y.x = atoi(args_split.at(0).c_str());
            x_y.y = atoi(args_split.at(1).c_str());
            turn(x_y);
        }
        break;

    case BEGIN:
        begin();
        break;
        
    case BOARD:
        if (command.size() != 0)
            args_split = ssplits(command, ",");
        if (board(args_split) == 1)
            interpreter("DONE", args);
        break;
    
    case DONE:
        if (_bd == false) sendUnknowMess(command);
        _bd = false;
        endBoard();
        break;
        
    case INFO:
        info();
        break;
        
    case ABOUT:
        about();
        break;

    case END:
        _board.clear();
        end = true;
        break;

    default:
        if (_bd) break;
        sendUnknowMess(command);
        break;
    }
    if (end) return end;
    else return false;
}

std::string Gomoku::getName()
{
    if (_name.size() == 0) return "";
    return _name;
}