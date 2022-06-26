#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
int drum(int& drum, int i, int a[], const int SIZE)
{
	int number = 0;
	int count = 0;
	while (drum != count)
	{
		if (i == SIZE)
			i = 0;
		else
		{
			i++;
			count++;
		}
	}
	if (i == 0 || a[i - 1] == 0)
	{
		number = a[i];
		a[i] = 0;
	}
	else
	{
		number = a[i - 1];
		a[i - 1] = 0;
	}
	return number;
}
bool game()
{
	const int SIZE = 13;
	int a[SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int numQ = 0;
	int numA = 0;
	int shift = 0;
	int aExperts = 0;
	int aViewers = 0;
	std::string answ;
	std::string answer;
	std::ifstream questions;
	std::ifstream answers;
	std::string text;
	std::string text1;
	bool win = true;
	while (win)
	{
		std::cout << "Spin the drum :";
		std::cin >> shift;
		int b = drum(shift, numQ, a, SIZE);
		questions.open("questions.txt");
		answers.open("answers.txt");
		while (numQ != b)
		{
			if (!questions.is_open() || !answers.is_open())
			{
				std::cout << "The file is not open" << std::endl;
			}
			else
			{
				std::getline(questions, text, '|');
				std::stringstream qves(text);
				qves >> numQ;
				std::getline(answers, text1, '|');
				std::stringstream aves(text1);
				aves >> numA >> answ;
			}
		}
		std::cout << text << std::endl;
		std::cout << "Answer : ";
		std::cin >> answer;
		std::cout<<std::endl;
		(answer == answ) ? aExperts++ : aViewers++;
		if (aExperts == 6 || aViewers == 6)
			win = false;
		questions.close();
		answers.close();
	}
	if (aExperts == 6)
		return true;
	else
		return false;
}
int main()
{
	if (game())
		std::wcout << "Experts won !!!" << std::endl;
	else
		std::wcout << "The viewers won !!!" << std::endl;
}