#ifndef MOD1_LISTA3
#define MOD1_LISTA3

#include <string>

struct AvlNode 
{
	int _key;

	//fator de balanceamento = hd-he
	int _balance_factor; 

	AvlNode* _up;
	AvlNode* _left;
	AvlNode* _right;
};

class Avl
{
public:
	//Cria uma arvore vazia
	Avl();

	//Cria uma arvore com um primeiro elemento
	Avl(int key);

	//Cria uma arvore a partir de outra
	Avl(const Avl& orig);

	//Destroi a arvore
	virtual ~Avl();

	//Retorna a altura da arvore
	int height();

	//Insere um elemento na arvore
	void insert(int key);

	//Exibe a arvore no formato
	//<raiz<sub-arvore esquerda><sub-arvore direita>>
	void show(const std::string& title);

	/** Funcoes para percorrer a arvore em ordem: **/  

	//Posiciona o cursor no primeiro elemento
	bool first();

	//Posiciona o cursor no ultimo elemento
	bool last();

	//Atualiza o no cursor para o proximo elemento
	bool next();

	//Atualiza o no cursor para o elemento anterior
	bool prev();

	//Exibe o valor do no cursor atual
	int value();

private:
  
	/* Mantenha as funcoes privadas necessarias 
	* criadas para a Abb e crie as funcoes 
	* (recursivas ou nao) que julgar necessarias
	* para a Avl */

	//Insere um no na arvore
	AvlNode* insert_rec(AvlNode* a, int key);

	//Copia arvore recursivamente
	void copyAvl_rec(AvlNode* node);

	//Passa pela arvore recalculando o fator de balanceamento de cada no
	void recalculateBalanceFactor(AvlNode * node);

	//Checa se a arvore esta balanceada e a balanceia se necessario
	void balanceItself();

	//Checa se a arvore esta balanceada recursivamente
	bool checkBalance_rec(AvlNode* node);

	//Balanceia uma arvore desbalanceada no no que foi passado
	void balanceThis(AvlNode* node);

	//Rotaciona a arvore para esquerda
	void leftRotation(AvlNode* nodeR, AvlNode* nodeT);

	//Rotaciona a arvore para a direita
	void rightRotation(AvlNode* nodeR, AvlNode* nodeT);

	//conserta o ponteiro filho do no pai para o novo filho
	void setParent(AvlNode* node, AvlNode * nodeParent);

	//Funcao recursiva para exibir a arvore
	void show_rec(AvlNode* node);

	//Funcao que acha recursivamente a altura do no que foi passado
	int height_rec(AvlNode * node);

	//Funcao para desalocar a memoria dos nos recursivamente
	void delete_rec(AvlNode * root);
   
private:
	AvlNode* _root;
	AvlNode* _cursor;
};

#endif
