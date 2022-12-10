#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <clocale>
#include <ctime>
#include <fstream>
#include <string>
#include <tuple>  
#include <vector>
using namespace std;

#define WIN  6
#define DRAW 3
#define LOSE 0

#define ENEMY_ROCK    'A'
#define ENEMY_PAPER   'B'
#define ENEMY_SCISSOR 'C'

#define ROCK          'X'
#define PAPER         'Y'
#define SCISSOR       'Z'

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	std::ifstream file("test.txt");

	// A(ROCK) B(PAPER) C(SCISSORS)

	std::vector<std::tuple<char,char>> pairs;
	std::string line;
	while(std::getline(file,line))
	{
		char S[2];
		int i = 0;
		for(std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			if (*it != ' ' && *it != '\n')
			{
				S[i++] = *it;
			}
		}
		pairs.emplace_back(std::make_tuple(S[0], S[1]));
	}

	unsigned int total_score = 0;

	for(std::vector<std::tuple<char,char>>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		char enemy_move = std::get<0>(*it);
		char my_move = std::get<1>(*it);

		total_score += my_move - 'X' + 1;
		if ((enemy_move == ENEMY_ROCK && my_move == PAPER) || (enemy_move == ENEMY_PAPER) && (my_move == SCISSOR) || (enemy_move == ENEMY_SCISSOR) && (my_move == ROCK))
		{
			total_score += WIN;
			continue;
		}
		if(enemy_move == ENEMY_SCISSOR && my_move == SCISSOR || enemy_move == ENEMY_ROCK && my_move == ROCK || enemy_move == ENEMY_PAPER && my_move == PAPER)
		{
			total_score += DRAW;
		}
	}

	std::cout << "Total score: " << total_score << std::endl;

	std::cin.get();

	return 0;
}
