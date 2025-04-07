#ifndef NOABB_H
#define NOABB_H

class NoABB
{
private:
    int valor;
    NoABB* esq;
    NoABB* dir;
    int altura;

public:
    NoABB(int valor);
    ~NoABB();

    int getValor();
    void setValor(int valor);

    NoABB* getEsq();
    void setEsq(NoABB* no);

    NoABB* getDir();
    void setDir(NoABB* no);

    int getAltura();
    void setAltura(int h);

    void insere(int valor);
    NoABB* busca(int valor);
    void imprimeOrdemCrescente();
    void imprimeVisualizacao(int n);
    NoABB* remove(NoABB* no, int valor);
};

#endif
