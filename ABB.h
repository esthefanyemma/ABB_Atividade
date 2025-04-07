#ifndef ABB_H
#define ABB_H

#include "NoABB.h"

class ABB
{
private:
    NoABB* raiz;

    // Métodos auxiliares recursivos
    int somaRec(NoABB* no);
    int contaNos(NoABB* no);
    bool ehCheiaRec(NoABB* no);
    void imprimeIntervaloRec(NoABB* no, int x, int y);
    bool estritamenteBinariaRec(NoABB* no);
    int maioresQueRec(NoABB* no, int val);
    void mediaNivelRec(NoABB* no, int atual, int alvo, int& soma, int& count);
    int calculaAltura(NoABB* no);

public:
    ABB();
    ~ABB();

    bool vazia();
    void insere(int valor);
    NoABB* busca(int valor);
    void remove(int valor);
    void imprimeEmLargura();
    void imprimeOrdemCrescente();
    void imprimeVisualizacao();
    void destroiArvore();

    // Exercícios
    int soma();                              // soma de todos os nós
    int media();                             // média dos valores
    bool ehCheia();                          // se é cheia
    bool ehCompleta();                       // se é completa
    void imprimeIntervalo(int x, int y);     // imprime valores entre x e y
    bool estritamenteBinaria();              // se cada nó tem 0 ou 2 filhos
    int maioresQue(int val);                 // quantos nós têm valor maior que val
    float mediaNivel(int nivel);             // média dos nós em certo nível
    void alturaNos();                        // calcula e armazena a altura de cada nó
};

#endif
