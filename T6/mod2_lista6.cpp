#include "mod2_lista6.h"

#include <fstream>
#include <utility>

Hash::Hash( int tableSize )
    : _table( new std::pair< std::string, int >[tableSize] ), _tableSize(tableSize)
{
    //Inicializa cada posicao com <"",0>
    for( int i = 0; i < tableSize; ++i )
        _table[i] = std::make_pair("",0);
}


Hash::~Hash()
{
    delete[] _table;
}


void Hash::insert(const std::string& word)
{
	int shouldInsertHere = hash(word);

	while ( _table[shouldInsertHere].first != "" && 
			_table[shouldInsertHere].first != word)
	{
		shouldInsertHere++;
	}
	
	if (_table[shouldInsertHere].first != word)
		_table[shouldInsertHere].first = word;
	_table[shouldInsertHere].second++;
}


int Hash::getCount(const std::string& word)
{
	int shouldBeHere = hash(word);
	
	while (_table[shouldBeHere].first != word)
	{
		shouldBeHere++;
	}
	return _table[shouldBeHere].second;
}


bool Hash::writeCSV(const std::string& filePath)
{
	std::ofstream output;
	output.open(filePath);

	if (!output.is_open())
		return false;

	for (int i = 0; i < _tableSize; i++)
	{
		if (_table[i].first != "")
		{
			output << _table[i].first << "," << _table[i].second;
		}
	}
	output.close();
	return true;
}


int Hash::hash(const std::string& word)
{
	int index = 0;
	for (int i = 0; i < word.size(); i++)
	{
		index += (int)word[i] * (i + 1);
	}
    return index%_tableSize;
}
