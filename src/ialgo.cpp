/*
** EPITECH PROJECT, 2021
** MAT
** File description:
** Gomoku hpp file
*/

#include "../includes/Gomoku.hpp"

ialgo::ialgo(std::vector<std::vector<int> > board, int size)
{
    _board = board;
    _size = size;
}

ialgo::~ialgo()
{
}

int ialgo::getGomokuScore(PosValue tempPosValue, int count, int openEnd, bool current_turn)
{
    // std::cout << "COUNT : " << count<< std::endl;
    if (openEnd == 0 && count < 5)
		return 0;
    switch (count) {
		case 4:
			switch (openEnd) {
				case 1:
					if (current_turn)
						return 400000000;
					return 200;
				case 2:
					if (current_turn)
						return 400000000;
					return 2000000;
			}
		case 3:
			switch (openEnd) {
				case 1:
					if (current_turn)
						return 32;
					return 24;
				case 2:
					if (current_turn)
						return 40000;
					return 200;
			}
		case 2:
			switch (openEnd) {
				case 1:
					return 10;
				case 2:
					return 20;
			}
		case 1:
			switch (openEnd) {
				case 1:
					return 3;
				case 2:
					return 5;
			}
		default:
            switch (openEnd) {
                case 1:
			        return 1;
                case 2:
                    return 2;
            }
	}
}

int ialgo::ConsecutiveCompterHor_r(size_t y, size_t x, int count, int player)
{
    if (x < (_size - 1) && _board.at(y).at(x + 1) == player) {
        return ConsecutiveCompterHor_r(y, x+1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterHor_l(size_t y, size_t x, int count, int player)
{
    if (x > 0 && _board.at(y).at(x - 1) == player) {
        return ConsecutiveCompterHor_l(y, x-1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterHor(size_t y, size_t x, int count, int player)
{
    int max = 0;
    // std::cout << "1" << std::endl;
    int r = ConsecutiveCompterHor_r(y, x, 0, player);
    // std::cout << "r" << r << std::endl;
    int l = ConsecutiveCompterHor_l(y, x, 0, player);
    // std::cout << "Count : " << r << " et " << l << std::endl;
    if (r > max)
        max = r;
    if (l > max)
        max = l;
    // std::cout << "Count :  r = " << r << " et l = " << l << " et MAX = " << max << std::endl;
    return (max);
}

int ialgo::ConsecutiveCompterVer_h(size_t y, size_t x, int count, int player)
{
    if (y > 0 && _board.at(y - 1).at(x) == player) {
        return ConsecutiveCompterVer_h(y-1, x, count + 1, player);
    } else
        return (count);
}
int ialgo::ConsecutiveCompterVer_b(size_t y, size_t x, int count, int player)
{
    if (y < (_size - 1) && _board.at(y + 1).at(x) == player) {
        return ConsecutiveCompterVer_b(y+1, x, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterVer(size_t y, size_t x, int count, int player)
{
    int max = 0;
    // std::cout << "1" << std::endl;
    int r = ConsecutiveCompterVer_h(y, x, 0, player);
    // std::cout << "1,5" << std::endl;
    int l = ConsecutiveCompterVer_b(y, x, 0, player);
    if (r > max)
        max = r;
    if (l > max)
        max = l;
    return (max);
}


int ialgo::ConsecutiveCompterDiag2_l(size_t y, size_t x, int count, int player)
{
    if (y < (_size - 1) && x > 0 && _board.at(y + 1).at(x - 1) == player) {
        return ConsecutiveCompterDiag2_l(y+1, x-1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterDiag2_r(size_t y, size_t x, int count, int player)
{
    if (y > 0 && x < (_size - 1) && _board.at(y - 1).at(x + 1) == player) {
        return ConsecutiveCompterDiag2_r(y-1, x+1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterDiag2(size_t y, size_t x, int count, int player)
{
    int max = 0;
    // std::cout << "1" << std::endl;
    int r = ConsecutiveCompterDiag2_r(y, x, 0, player);
    // std::cout << "1,5" << std::endl;
    int l = ConsecutiveCompterDiag2_l(y, x, 0, player);
    if (r > max)
        max = r;
    if (l > max)
        max = l;
    return (max);
}

int ialgo::ConsecutiveCompterDiag1_l(size_t y, size_t x, int count, int player)
{
    if (y > 0 && x > 0 && _board.at(y - 1).at(x - 1) == player) {
        return ConsecutiveCompterDiag1_l(y-1, x-1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterDiag1_r(size_t y, size_t x, int count, int player)
{
    if (y < (_size - 1) && x < (_size - 1) && _board.at(y + 1).at(x + 1) == player) {
        return ConsecutiveCompterDiag1_r(y+1, x+1, count + 1, player);
    } else
        return (count);
}

int ialgo::ConsecutiveCompterDiag1(size_t y, size_t x, int count, int player)
{
    int max = 0;
    // std::cout << "1" << std::endl;
    int r = ConsecutiveCompterDiag1_r(y, x, 0, player);
    // std::cout << "1,5" << std::endl;
    int l = ConsecutiveCompterDiag1_l(y, x, 0, player);
    if (r > max)
        max = r;
    if (l > max)
        max = l;
    return (max);
}

std::vector<std::vector<PosValue> > ialgo::gomokuAnalyseCheck(bool current_turn, int player)
{
    std::vector<PosValue> PosValueTab;
    std::vector<std::vector<PosValue> > PosValueTabTab;
    PosValue tempPosValue{};

    std::vector<PosValue> PosValueTabVer;
    std::vector<std::vector<PosValue> > PosValueTabTabVer;
    PosValue tempPosValueVer{};

    int countConsecutiveHor = 0;
    int openEndHor = 0;
    int countConsecutiveVer = 0;
    int openEndVer = 0;

    for (size_t y = 0; y < _board.size(); y++) {
        for (size_t x = 0; x < _board.at(y).size(); x++) {
            tempPosValue.value = 0;
            tempPosValue.x = x;
            tempPosValue.y = y;
            countConsecutiveHor = 0;
            openEndHor = 0;
			if (_board[y][x] == NONE) {
                // std::cout << "STATUE = " << _board.at(y).at(x) <<"  -- Pos : x = " << x << ", y = " << y << " " <<std::endl;
                countConsecutiveHor = ConsecutiveCompterHor(y, x, 0, player);
                // std::cout<< " COUNT HOR : " << countConsecutiveHor << std::endl;
                // std::cout << "COUNT HOR : " << countConsecutiveHor << std::endl;
                // std::cout << "COUNT : " << countConsecutiveHor << std::endl;
                if (x < (_size - 1) && (_board.at(y).at(x + 1) == NONE || _board.at(y).at(x + 1) == player))
                    openEndHor++;
                if (x > 0 && (_board.at(y).at(x - 1) == NONE || _board.at(y).at(x - 1) == player))
                    openEndHor++;
                // std::cout << "pos x :" << x << " et y : " << y << " et size :" << _size << " et " << openEndHor << std::endl;
				tempPosValue.value = getGomokuScore(tempPosValue, countConsecutiveHor, openEndHor, current_turn);
			}
            PosValueTab.push_back(tempPosValue);
            // std::cout << "3" << std::endl;
		}
        PosValueTabTab.push_back(PosValueTab);
        PosValueTab.clear();
	}
    for (size_t y = 0; y < _board.size() ; y++) {
        for (size_t x = 0; x < _board.at(y).size(); x++) {
            tempPosValueVer.value = 0;
            tempPosValueVer.x = x;
            tempPosValueVer.y = y;
            countConsecutiveVer = 0;
            openEndVer = 0;
			if (_board[y][x] == NONE) {
                //  std::cout << "STATUE = " << _board.at(y).at(x) <<"  -- Pos : x = " << x << ", y = " << y << " " <<std::endl;
                countConsecutiveVer = ConsecutiveCompterVer(y, x, 0, player);
                // std::cout<< " COUNT VER : " << countConsecutiveVer << std::endl;
                if (y < (_size - 1) && (_board.at(y + 1).at(x) == NONE || _board.at(y + 1).at(x) == player))
                    openEndVer++;
                if (y > 0 && (_board.at(y - 1).at(x) == NONE || _board.at(y - 1).at(x) == player))
                    openEndVer++;
                // std::cout << "pos x :" << x << " et y : " << y << " et size :" << _size << " et " << openEndHor << std::endl;
				tempPosValueVer.value = getGomokuScore(tempPosValueVer, countConsecutiveVer, openEndVer, current_turn);
			}
            PosValueTabVer.push_back(tempPosValueVer);
            // std::cout << "3" << std::endl;
		}
        PosValueTabTabVer.push_back(PosValueTabVer);
        PosValueTabVer.clear();
	}
    for (int p = 0; p < PosValueTabTab.size() || p < PosValueTabTabVer.size(); p++) {
        for (int l = 0; l < PosValueTabTab.at(p).size() || l < PosValueTabTabVer.at(p).size(); l++) {
            // if (PosValueTabTabVer.at(p).at(l).value == 0 || PosValueTabTab.at(p).at(l).value == 0)
            //     PosValueTabTab.at(p).at(l).value = 0;
            //if (PosValueTabTabVer.at(p).at(l).value > PosValueTabTab.at(p).at(l).value)
            PosValueTabTab.at(p).at(l).value = PosValueTabTab.at(p).at(l).value + PosValueTabTabVer.at(p).at(l).value;
        }
    }
    return (PosValueTabTab);
}

std::vector<std::vector<PosValue> > ialgo::gomokuAnalyseCheckDiag(bool current_turn, int player)
{

    // DIAG 1 = "/"
    // DIAG 2 = "\"
    std::vector<PosValue> PosValueTabDiag1;
    std::vector<std::vector<PosValue> > PosValueTabTabDiag1;
    PosValue tempPosValueDiag1{};

    std::vector<PosValue> PosValueTabDiag2;
    std::vector<std::vector<PosValue> > PosValueTabTabDiag2;
    PosValue tempPosValueDiag2{};

    int countConsecutiveDiag1 = 0;
    int openEndDiag1 = 0;
    int countConsecutiveDiag2 = 0;
    int openEndDiag2 = 0;

    for (size_t y = 0; y < _board.size(); y++) {
        for (size_t x = 0; x < _board.at(y).size(); x++) {
            tempPosValueDiag1.value = 0;
            tempPosValueDiag1.x = x;
            tempPosValueDiag1.y = y;
            countConsecutiveDiag1 = 0;
            openEndDiag1 = 0;

            tempPosValueDiag2.value = 0;
            tempPosValueDiag2.x = x;
            tempPosValueDiag2.y = y;
            countConsecutiveDiag2 = 0;
            openEndDiag2 = 0;

			if (_board[y][x] == NONE) {
                // std::cout << "STATUE = " << _board.at(y).at(x) <<"  -- Pos : x = " << x << ", y = " << y << " " <<std::endl;
                countConsecutiveDiag1 = ConsecutiveCompterDiag1(y, x, 0, player);
                countConsecutiveDiag2 = ConsecutiveCompterDiag2(y, x, 0, player);
                // std::cout<< " COUNT HOR : " << countConsecutiveHor << std::endl;
                // std::cout << "COUNT HOR : " << countConsecutiveHor << std::endl;
                // std::cout << "COUNT : " << countConsecutiveHor << std::endl;

                if ( y < (_size - 1) && x < (_size - 1) && (_board.at(y + 1).at(x + 1) == NONE ||  _board.at(y + 1).at(x + 1) == player))
                    openEndDiag1 += 1;
                if (y < (_size - 1) && x > 0 && (_board.at(y + 1).at(x - 1) == NONE || _board.at(y + 1).at(x - 1) == player))
                    openEndDiag2 += 1;
                if (y > 0 && x < (_size - 1) && (_board.at(y - 1).at(x + 1) == NONE || _board.at(y - 1).at(x + 1) == player))
                    openEndDiag2 += 1;
                if (y > 0 && x > 0 && (_board.at(y - 1).at(x - 1) == NONE || _board.at(y - 1).at(x - 1) == player))
                    openEndDiag1 += 1;
                // std::cout << "pos x :" << x << " et y : " << y << " et size :" << _size << " et " << openEndHor << std::endl;
				tempPosValueDiag1.value = getGomokuScore(tempPosValueDiag1, countConsecutiveDiag1, openEndDiag1, current_turn);
                tempPosValueDiag2.value = getGomokuScore(tempPosValueDiag2, countConsecutiveDiag2, openEndDiag2, current_turn);
			}
            PosValueTabDiag1.push_back(tempPosValueDiag1);
            PosValueTabDiag2.push_back(tempPosValueDiag2);
            // std::cout << "3" << std::endl;
		}
        PosValueTabTabDiag1.push_back(PosValueTabDiag1);
        PosValueTabTabDiag2.push_back(PosValueTabDiag2);
        PosValueTabDiag1.clear();
        PosValueTabDiag2.clear();
	}
    for (int p = 0; p < PosValueTabTabDiag1.size() || p < PosValueTabTabDiag2.size(); p++) {
        for (int l = 0; l < PosValueTabTabDiag1.at(p).size() || l < PosValueTabTabDiag2.at(p).size(); l++) {
            // if (PosValueTabTabVer.at(p).at(l).value == 0 || PosValueTabTab.at(p).at(l).value == 0)
            //     PosValueTabTab.at(p).at(l).value = 0;
            //if (PosValueTabTabVer.at(p).at(l).value > PosValueTabTab.at(p).at(l).value)
            PosValueTabTabDiag1.at(p).at(l).value = PosValueTabTabDiag1.at(p).at(l).value + PosValueTabTabDiag2.at(p).at(l).value;
        }
    }
    return (PosValueTabTabDiag1);
}

Pos ialgo::gomokuAnalyse()
{
    PosValue posValue{};
    Pos pos{};
    int max = 0;
    std::vector<std::vector<PosValue> > tabtabME = gomokuAnalyseCheck(true, ME);
    std::vector<std::vector<PosValue> > tabtabYOU = gomokuAnalyseCheck(true, YOU);
    std::vector<std::vector<PosValue> > tabtabdiagME = gomokuAnalyseCheckDiag(true, ME);
    std::vector<std::vector<PosValue> > tabtabdiagYOU = gomokuAnalyseCheckDiag(true, YOU);
    for (int p = 0; p < tabtabME.size() || p < tabtabYOU.size(); p++) {
        for (int l = 0; l < tabtabME.at(p).size() || l < tabtabYOU.at(p).size(); l++) {
            tabtabME.at(p).at(l).value = tabtabME.at(p).at(l).value + tabtabYOU.at(p).at(l).value;
        }
    }
    for (int p = 0; p < tabtabdiagME.size() || p < tabtabdiagYOU.size(); p++) {
        for (int l = 0; l < tabtabdiagME.at(p).size() || l < tabtabdiagYOU.at(p).size(); l++) {
            tabtabdiagME.at(p).at(l).value = tabtabdiagME.at(p).at(l).value + tabtabdiagYOU.at(p).at(l).value;
        }
    }
    for (int p = 0; p < tabtabME.size() || p < tabtabdiagME.size(); p++) {
        for (int l = 0; l < tabtabME.at(p).size() || l < tabtabdiagME.at(p).size(); l++) {
            tabtabME.at(p).at(l).value = tabtabME.at(p).at(l).value + tabtabdiagME.at(p).at(l).value;
        }
    }
    // std::cout << "---------- POS VALUE -----------" << std::endl;
    // for (size_t y = 0; y < tabtabME.size() ; y++) {
    //     for (size_t x = 0; x < tabtabME.at(y).size(); x++) {
    //         std::cout << tabtabME.at(y).at(x).value << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << "---------- FIN -----------" << std::endl;
    for (int i = 0; i < tabtabME.size(); i++) {
        for (int a = 0; a < tabtabME.at(i).size(); a++)
        {
            if (tabtabME.at(i).at(a).value > max && _board.at(i).at(a) == NONE) {
                // std::cout << "x : " << a << " y : "<< i << " value : " << std::endl;
                // std::cout << "x : " << a << " y : " << i << " value : " << tabtab.at(i).at(a).value << " vs max : " << max << std::endl;
                max = tabtabME.at(i).at(a).value;
                posValue = tabtabME.at(i).at(a);
            }
        }
    }
    pos.x = posValue.x;
    pos.y = posValue.y;
    return pos;
}