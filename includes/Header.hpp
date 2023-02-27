/*
** EPITECH PROJECT, 2021
** B-SYN-400-MAR-4-1-autoCompletion-xavier.gimeno
** File description:
** Header hpp file
*/

#pragma once

#ifndef __HEADER_HPP__
#define __HEADER_HPP__


// Libraries:
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <regex>
#include <cctype>
#include <string>
#include <deque>

// Includes:

// Functions:
void displayError(std::string msg, int exitValue);
void displayVectorLists(std::vector<std::string> list);
std::vector<std::string> fileReader(std::string fileName);
std::deque<float> split(std::string s);
std::vector<std::string> splitVecStr(std::string s);
bool checkFloat(std::string s);
bool checkInt(std::string s);
bool checkName(std::string s);
bool checkRegex(std::string s, std::regex reg);

#endif /* __HEADER_HPP__ */