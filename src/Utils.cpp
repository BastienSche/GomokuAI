/*
** EPITECH PROJECT, 2021
** B-CPP-500-MAR-5-1-babel-xavier.gimeno
** File description:
** Funcs hpp file
*/

#include "../includes/Header.hpp"

void displayError(std::string msg, int exitValue)
{
    std::cout << msg << std::endl;
    exit(exitValue);
}

void displayVectorLists(std::vector<std::string> list)
{
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << "\t" << *it << std::endl;
    }
}

bool checkFloat(std::string s)
{
    std::smatch m;
    std::regex reg = std::regex("^\\-?\\d+(\\.?\\d+)?$");

    if (!std::regex_match(s, m, reg)) return false;

    return true;
}

bool checkRegex(std::string s, std::regex reg)
{
    std::smatch m;

    if (!std::regex_match(s, m, reg)) return false;
    return true;
}

bool checkInt(std::string s)
{
    std::smatch m;
    std::regex reg = std::regex("^\\d+$");

    if (!std::regex_match(s, m, reg)) return false;

    return true;
}

bool checkName(std::string s)
{
    std::smatch m;
    std::regex reg = std::regex("^([a-zA-Z]( [a-zA-Z])*)+$");

    if (!std::regex_match(s, m, reg)) return false;

    return true;
}

std::deque<float> split(std::string s)
{
    std::deque<float> list;
    std::stringstream ss(s);
    std::string word;

    // Fill vector list
    while (ss >> word) {
        list.push_back(atof(word.c_str()));
    }
    return list;
}

std::vector<std::string> splitVecStr(std::string s)
{
    std::vector<std::string> list;
    std::stringstream ss(s);
    std::string word;

    while (ss >> word) {
        list.push_back(word.c_str());
    }
    return list;
}

std::vector<std::string> fileReader(std::string fileName)
{    
    std::vector<std::string> lines;
    std::ifstream ifs(fileName, std::ios::ate);
    std::ifstream infile(fileName);
    if (infile.fail()) displayError("", 84);
    if (ifs.tellg() == 0) displayError("", 84);

    std::string line;
    while (getline(infile, line))
        lines.push_back(line);

    return lines;
}