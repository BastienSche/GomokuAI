/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Gomoku hpp file
*/

#include "../includes/Gomoku.hpp"

void Gomoku::sendUnknowMess(std::string mess)
{
    std::cout << "UNKNOW " << mess << std::endl;
}

void Gomoku::sendMess(std::string mess)
{
    std::cout << "MESSAGE " << mess << std::endl;
}

void Gomoku::sendErrorMess(std::string mess)
{
    std::cerr << "ERROR " << mess << std::endl;
}

void Gomoku::sendDebugMess(std::string mess)
{
    std::clog << "DEBUG " << mess << std::endl;
}

void Gomoku::sendSuggestMess(Pos pos)
{
    std::cout << "SUGGEST " << pos.x << "," << pos.y << std::endl;
}