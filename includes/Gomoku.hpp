/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Algorithm hpp file
*/

#pragma once

#ifndef __GOMOKU_HPP__
#define __GOMOKU_HPP__

// Includes:
#include "ialgo.hpp"

// Regex:
#define REG ""

#define ME 1
#define YOU 2
#define NONE 0

enum Commands
{
    START,
    TURN,
    BEGIN,
    BOARD,
    DONE,
    INFO,
    ABOUT,
    END
};

class Gomoku
{

    private:

        // Variables:
        int _x;
        int _y;
        int _size;
        int _player;
        Pos _last;
        bool _st;
        bool _bd;
        std::string _name;
        std::vector<std::string> map;
        std::vector<std::vector<int> > _board;
        std::string _about;

    public:

        // Ctor & Dtor:
        Gomoku();
        ~Gomoku();

        // Methods:

            // Setters:

            // Getters:
        std::string getName();


            // Object methods:
        int start_engine();
        int interpreter(std::string command, std::vector<std::string> args);
        int listCommand(std::string command);
        void sortList();
        int compareFiles(Gomoku *a, Gomoku *b);
        bool checkStart();
        void endBoard();

        
            // Brain methods:
        void start(int);
        int turn(Pos x_y);
        void begin();
        int board(std::vector<std::string> arg);
        void info();
        void about();
        void end();
        int updateBoard(Pos x_y, int player);
        Pos getBestPosition();

        void sendUnknowMess(std::string mess);
        void sendMess(std::string mess);
        void sendErrorMess(std::string mess);
        void sendDebugMess(std::string mess);
        void sendSuggestMess(Pos pos);
        std::vector<std::string> ssplits(std::string s, std::string delim);

};

#endif /* __GOMOKU_HPP__ */