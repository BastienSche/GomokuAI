/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Gomoku hpp file
*/

#include "../includes/Gomoku.hpp"

int print_help(int ret)
{
    std::cout << "USAGE\n\t./pbrain-gomoku-ai\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tpbrain-gomoku-ai\tbinary name" << std::endl;
    return (ret);
}

int main(int ac, char **av)
{
    Gomoku *gomoku = new Gomoku();

    if (ac > 1 && av[1] == "-h") return print_help(0);
    
    return gomoku->start_engine();
}