#include <iostream>
#include <queue>
#include "ABB.h"

using namespace std;

ABB::ABB()
{
	raiz = NULL;
}

ABB::~ABB()
{
	destroiArvore();
}

bool ABB::vazia()
{
	return raiz == NULL;
}

void ABB::insere(int valor)
{
	if (raiz == NULL)
		raiz = new NoABB(valor);
	else
		raiz->insere(valor);
}

NoABB* ABB::busca(int valor)
{
	if (raiz == NULL) return NULL;
	return raiz->busca(valor);
}

void ABB::remove(int valor)
{
	if (raiz != NULL)
		raiz = raiz->remove(raiz, valor);
}

void ABB::imprimeOrdemCrescente()
{
	if (raiz != NULL)
		raiz->imprimeOrdemCrescente();
	cout << endl;
}

void ABB::imprimeVisualizacao()
{
	if (raiz != NULL)
		raiz->imprimeVisualizacao(0);
}

void ABB::destroiArvore()
{
	delete raiz;
	raiz = NULL;
}

int ABB::soma()
{
	return somaRec(raiz);
}

int ABB::somaRec(NoABB* no)
{
	if (no == NULL) return 0;
	return no->getValor() + somaRec(no->getEsq()) + somaRec(no->getDir());
}

int ABB::media()
{
	int total = contaNos(raiz);
	if (total == 0) return 0;
	return soma() / total;
}

int ABB::contaNos(NoABB* no)
{
	if (no == NULL) return 0;
	return 1 + contaNos(no->getEsq()) + contaNos(no->getDir());
}

bool ABB::ehCheia()
{
	return ehCheiaRec(raiz);
}

bool ABB::ehCheiaRec(NoABB* no)
{
	if (no == NULL) return true;

	if ((no->getEsq() == NULL && no->getDir() == NULL) ||
		(no->getEsq() != NULL && no->getDir() != NULL))
	{
		return ehCheiaRec(no->getEsq()) && ehCheiaRec(no->getDir());
	}
	else
		return false;
}

bool ABB::ehCompleta()
{
	if (raiz == NULL) return true;

	queue<NoABB*> fila;
	fila.push(raiz);
	bool encontrouFolha = false;

	while (!fila.empty())
	{
		NoABB* atual = fila.front();
		fila.pop();

		if (atual->getEsq() != NULL)
		{
			if (encontrouFolha) return false;
			fila.push(atual->getEsq());
		}
		else
			encontrouFolha = true;

		if (atual->getDir() != NULL)
		{
			if (encontrouFolha) return false;
			fila.push(atual->getDir());
		}
		else
			encontrouFolha = true;
	}

	return true;
}

void ABB::imprimeIntervalo(int x, int y)
{
	imprimeIntervaloRec(raiz, x, y);
	cout << endl;
}

void ABB::imprimeIntervaloRec(NoABB* no, int x, int y)
{
	if (no == NULL) return;

	if (no->getValor() > x)
		imprimeIntervaloRec(no->getEsq(), x, y);

	if (no->getValor() >= x && no->getValor() <= y)
		cout << no->getValor() << " ";

	if (no->getValor() < y)
		imprimeIntervaloRec(no->getDir(), x, y);
}

bool ABB::estritamenteBinaria()
{
	return estritamenteBinariaRec(raiz);
}

bool ABB::estritamenteBinariaRec(NoABB* no)
{
	if (no == NULL) return true;

	if ((no->getEsq() == NULL && no->getDir() == NULL) ||
		(no->getEsq() != NULL && no->getDir() != NULL))
	{
		return estritamenteBinariaRec(no->getEsq()) && estritamenteBinariaRec(no->getDir());
	}
	else
		return false;
}

int ABB::maioresQue(int val)
{
	return maioresQueRec(raiz, val);
}

int ABB::maioresQueRec(NoABB* no, int val)
{
	if (no == NULL) return 0;

	int count = 0;
	if (no->getValor() > val)
		count = 1;

	return count + maioresQueRec(no->getEsq(), val) + maioresQueRec(no->getDir(), val);
}

float ABB::mediaNivel(int nivel)
{
	int soma = 0, count = 0;
	mediaNivelRec(raiz, 0, nivel, soma, count);
	if (count == 0) return 0;
	return (float)soma / count;
}

void ABB::mediaNivelRec(NoABB* no, int atual, int alvo, int& soma, int& count)
{
	if (no == NULL) return;

	if (atual == alvo)
	{
		soma += no->getValor();
		count++;
	}
	else
	{
		mediaNivelRec(no->getEsq(), atual + 1, alvo, soma, count);
		mediaNivelRec(no->getDir(), atual + 1, alvo, soma, count);
	}
}

void ABB::alturaNos()
{
	calculaAltura(raiz);
}

int ABB::calculaAltura(NoABB* no)
{
	if (no == NULL) return -1;

	int alturaEsq = calculaAltura(no->getEsq());
	int alturaDir = calculaAltura(no->getDir());
	int altura = 1 + max(alturaEsq, alturaDir);

	no->setAltura(altura);
	return altura;
}

void ABB::imprimeEmLargura()
{
	if (raiz == NULL)
	{
		cout << "Arvore vazia." << endl;
		return;
	}

	queue<NoABB*> fila;
	fila.push(raiz);

	cout << "Arvore em largura: ";
	while (!fila.empty())
	{
		NoABB* atual = fila.front();
		fila.pop();

		cout << atual->getValor() << " ";

		if (atual->getEsq() != NULL)
			fila.push(atual->getEsq());
		if (atual->getDir() != NULL)
			fila.push(atual->getDir());
	}
	cout << endl;
}
