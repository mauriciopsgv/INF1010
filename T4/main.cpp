#include <iostream>
#include "mod1_lista4.h"

int main(void)
{
	Avl* arvore = new Avl();

	arvore->insert(17);
	arvore->insert(10);
	arvore->insert(30);
	arvore->insert(8);
	arvore->insert(2);
	arvore->insert(9);
	arvore->insert(10);
	arvore->insert(12);
	arvore->insert(11);
	arvore->insert(13);
	arvore->insert(23);
	arvore->insert(20);
	arvore->insert(25);
	arvore->insert(35);
	arvore->insert(28);
	arvore->insert(40);

	arvore->show("Arvore Ta tarde ja");

	arvore->remove(20);
	arvore->show("Arvore Pos remocao 20");
	arvore->remove(17);
	arvore->show("Arvore Pos Remocao 17");
	arvore->remove(12);
	arvore->show("Arvore Pos Remocao 12");
	arvore->remove(13);
	arvore->show("Arvore Pos remocao 13");

	return 0;
}