#include <iostream>
#include "NoABB.h"

using namespace std;

NoABB::NoABB(int valor)
{
	this->valor = valor;
	this->esq = NULL;
	this->dir = NULL;
	this->altura = -1;
}

NoABB::~NoABB()
{
	delete this->esq;
	delete this->dir;
}

int NoABB::getValor()
{
	return this->valor;
}

NoABB* NoABB::getEsq()
{
	return this->esq;
}

NoABB* NoABB::getDir()
{
	return this->dir;
}

void NoABB::setValor(int valor)
{
	this->valor = valor;
}

void NoABB::setEsq(NoABB* no)
{
	this->esq = no;
}

void NoABB::setDir(NoABB* no)
{
	this->dir = no;
}

int NoABB::getAltura()
{
	return this->altura;
}

void NoABB::setAltura(int h)
{
	this->altura = h;
}

void NoABB::insere(int valor)
{
	if (valor < this->valor) {
		if (this->esq == NULL)
			this->esq = new NoABB(valor);
		else
			this->esq->insere(valor);
	} else if (valor > this->valor) {
		if (this->dir == NULL)
			this->dir = new NoABB(valor);
		else
			this->dir->insere(valor);
	}
}

NoABB* NoABB::busca(int valor)
{
	if (this->valor == valor)
		return this;
	else if (valor < this->valor && this->esq != NULL)
		return this->esq->busca(valor);
	else if (valor > this->valor && this->dir != NULL)
		return this->dir->busca(valor);
	else
		return NULL;
}

NoABB* NoABB::remove(NoABB* no, int valor)
{
	if (no == NULL) return NULL;

	if (valor < no->valor) {
		no->esq = remove(no->esq, valor);
	} else if (valor > no->valor) {
		no->dir = remove(no->dir, valor);
	} else {
		// Caso 1: nó sem filhos
		if (no->esq == NULL && no->dir == NULL) {
			delete no;
			return NULL;
		}
		// Caso 2: um filho
		else if (no->esq == NULL) {
			NoABB* temp = no->dir;
			no->dir = NULL;
			delete no;
			return temp;
		}
		else if (no->esq != NULL && no->dir == NULL) {
			NoABB* temp = no->esq;
			no->esq = NULL;
			delete no;
			return temp;
		}
		// Caso 3: dois filhos
		else {
			NoABB* sucessor = no->dir;
			while (sucessor->esq != NULL)
				sucessor = sucessor->esq;

			no->valor = sucessor->valor;
			no->dir = remove(no->dir, sucessor->valor);
		}
	}
	return no;
}

//(esq -> raiz -> dir)
void NoABB::imprimeOrdemCrescente()
{
	if (this->esq != NULL)
		this->esq->imprimeOrdemCrescente();

	cout << this->valor << " ";

	if (this->dir != NULL)
		this->dir->imprimeOrdemCrescente();
}

void NoABB::imprimeVisualizacao(int n)
{
	for (int i = 0; i < n; i++)
		cout << "--";
	cout << "(" << this->valor << ")" << endl;

	if (this->esq != NULL)
		this->esq->imprimeVisualizacao(n + 1);

	if (this->dir != NULL)
		this->dir->imprimeVisualizacao(n + 1);
}
