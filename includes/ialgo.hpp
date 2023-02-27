/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Algorithm hpp file
*/

#pragma once

#ifndef __IALGO_HPP__
#define __IALGO_HPP__

// Includes:
#include "Header.hpp"

struct Pos
{
    int x;
    int y;
};

struct PosValue
{
    int x;
    int y;
    int value;
};

class ialgo
{
private:
    std::vector<std::vector<int> > _board;
    int _size;
public:
    ialgo(std::vector<std::vector<int> > board, int size);
    ~ialgo();
    Pos gomokuAnalyse();
    std::vector<std::vector<PosValue> > gomokuAnalyseCheck(bool current_turn, int player);
    std::vector<std::vector<PosValue> > gomokuAnalyseCheckDiag(bool current_turn, int player);
    void getBestGomokuMove();
    int getGomokuScore(PosValue tempPosValue, int count, int openEnd, bool current_turn);

    int ConsecutiveCompterHor(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterHor_r(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterHor_l(size_t y, size_t x, int count, int player);

    int FindSide(size_t y, size_t x);
    int ConsecutiveCompterVer_h(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterVer_b(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterVer(size_t y, size_t x, int count, int player);

    int ConsecutiveCompterDiag1(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterDiag1_l(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterDiag1_r(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterDiag2(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterDiag2_l(size_t y, size_t x, int count, int player);
    int ConsecutiveCompterDiag2_r(size_t y, size_t x, int count, int player);
};

#endif /* __IALGO_HPP__ */
