#include <iostream>
#include "mod1_lista2.h"

using namespace std;

void teste(bool deuBom)
{
	if (!deuBom)
	{
		cout << "DEU MERDA BENDEM BENDEM BENDEM" << endl;
		cout << "DEU MERDA BENDEM BENDEM BENDEM" << endl;
		cout << "DEU MERDA BENDEM BENDEM BENDEM" << endl;
	}
}

void TestaInsertAndMin()
{
	cout << "----- TESTE INSERT -------" << endl;

	Abb* arvoreTeste = new Abb();
	string vazia("Arvore vazia");
	string root("so um no");
	string dir("so no na direita");
	string mult("varios nos");

	arvoreTeste->show(vazia);
	teste(arvoreTeste->min() == 0);
	
	arvoreTeste->insert(10);
	arvoreTeste->show(root);
	teste(arvoreTeste->min() == 10);

	arvoreTeste->insert(15);
	arvoreTeste->show(root);
	teste(arvoreTeste->min() == 10);

	arvoreTeste->insert(2);
	arvoreTeste->show(mult);
	teste(arvoreTeste->min() == 2);

	arvoreTeste->insert(1);
	arvoreTeste->insert(5);
	arvoreTeste->insert(20);
	arvoreTeste->insert(17);
	arvoreTeste->insert(4);
	arvoreTeste->show(mult);
	arvoreTeste->order(mult);
	teste(arvoreTeste->min() == 1);

	cout << "------------------------" << endl;
}

void TestaMoveCursorAndDelete()
{
	cout << "----- TESTE MOVE CURSOR -----" << endl;
	Abb * arvoreTesteOrig = new Abb();
	Abb * arvoreTeste = new Abb(*arvoreTesteOrig);
	string arvTesteName("Arvore de Teste");
	arvoreTeste->insert(24);
	arvoreTeste->insert(14);
	arvoreTeste->insert(9);
	arvoreTeste->insert(17);
	arvoreTeste->insert(15);
	arvoreTeste->insert(58);
	arvoreTeste->insert(32);
	arvoreTeste->insert(43);
	arvoreTeste->insert(103);
	arvoreTeste->insert(70);
	arvoreTeste->show(arvTesteName);
	arvoreTeste->order(arvTesteName);

	cout << "O teste itself" << endl;
	arvoreTeste->first();
	cout << arvoreTeste->value() << ",";
	while (arvoreTeste->next())
	{
		cout << arvoreTeste->value() << ",";
	}
	cout << endl;
	while (arvoreTeste->prev())
	{
		cout << arvoreTeste->value() << ",";
	}
	cout << endl;
	arvoreTeste->last();
	cout << "last ->" << arvoreTeste->value() << endl;

	Abb * arvorePraDarMerda = new Abb();
	teste(!arvorePraDarMerda->next());
	teste(!arvorePraDarMerda->prev());
	teste(!arvorePraDarMerda->first());
	teste(!arvorePraDarMerda->last());
	arvorePraDarMerda->insert(10);
	teste(!arvorePraDarMerda->next());
	teste(!arvorePraDarMerda->prev());
	teste(arvorePraDarMerda->first());
	teste(!arvorePraDarMerda->next());
	teste(!arvorePraDarMerda->prev());
	teste(arvorePraDarMerda->first());
	teste(arvorePraDarMerda->last());
	teste(!arvorePraDarMerda->next());
	teste(!arvorePraDarMerda->prev());
	teste(arvorePraDarMerda->last());
	teste(arvorePraDarMerda->last());
	
	delete arvorePraDarMerda;
	delete arvoreTeste;
	
	cout << "-----------------------" << endl;
}

void TestarRemove()
{
	cout << "------ TESTAR REMOVE ------" << endl;

	Abb * arvoreTeste = new Abb();
	string arvTesteName("Arvore de Teste");
	arvoreTeste->insert(24);
	arvoreTeste->insert(14);
	arvoreTeste->insert(9);
	arvoreTeste->insert(17);
	arvoreTeste->insert(15);
	arvoreTeste->insert(58);
	arvoreTeste->insert(32);
	arvoreTeste->insert(43);
	arvoreTeste->insert(103);
	arvoreTeste->insert(70);
	arvoreTeste->show(arvTesteName);
	arvoreTeste->order(arvTesteName);

	arvoreTeste->remove(70);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(17);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(24);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(103);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(103);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(14);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(9);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(32);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(43);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(58);
	arvoreTeste->show(arvTesteName);

	arvoreTeste->remove(15);
	arvoreTeste->show(arvTesteName);

	cout << "---------------------------" << endl;
}

void TestarConstrutorCopia()
{
	cout << "------ TESTAR CONSTRUTOR ------" << endl;

	Abb * arvoreTeste = new Abb();
	string original("Arvore Original");
	string copia("Arvore Copia");
	arvoreTeste->insert(24);
	arvoreTeste->insert(14);
	arvoreTeste->insert(9);
	arvoreTeste->insert(17);
	arvoreTeste->insert(15);
	arvoreTeste->insert(58);
	arvoreTeste->insert(32);
	arvoreTeste->insert(43);
	arvoreTeste->insert(103);
	arvoreTeste->insert(70);

	Abb * arvoreCopia = new Abb(*arvoreTeste);
	arvoreTeste->show(original);
	arvoreCopia->show(copia);
	arvoreTeste->order(original);
	arvoreCopia->order(copia);

	Abb * arvoreTeste2 = new Abb();
	Abb * arvoreCopia2 = new Abb(*arvoreTeste2);
	arvoreTeste2->show(original);
	arvoreCopia2->show(copia);
	
	Abb * arvoreTeste3 = new Abb(3);
	Abb * arvoreCopia3 = new Abb(*arvoreTeste3);
	arvoreTeste3->show(original);
	arvoreCopia3->show(copia);

	arvoreCopia->remove(24);
	arvoreCopia->show(copia);

	cout << "-------------------------------" << endl;
}

int main() 
{
	TestaInsertAndMin();
	TestaMoveCursorAndDelete();
	TestarRemove();
	TestarConstrutorCopia();
	return 0;
}