#include <iostream>
#include <fstream>
#include "mod2_lista6.h"

#define TABLESIZE 1024

void countWords(const std::string& inputPath, const std::string& outputPath)
{
	std::ifstream input;
	input.open(inputPath);

	if (input.is_open())
	{
		Hash wordCounter(TABLESIZE);

		std::string word;
		while (input >> word)
		{
			wordCounter.insert(word);
		}
		input.close();

		wordCounter.writeCSV(outputPath);
	}
	else
	{
		std::cout << "deu problema para abrir o arquivo de entrada" << std::endl;
	}
}

int main(void)
{
	std::string inputPath = "C:\\code\\INF1010\\T6\\texto2.txt";
	std::string outputPath = "C:\\code\\INF1010\\T6\\output.csv";

	countWords(inputPath, outputPath);
	return 0;
}