#include <iostream>
#include <string>
#include "ABB.h"

using namespace std;

int lerNumero()
{
	string s;
	getline(cin, s);

	int x = 0;
	int n = s.length();
	if (n == 0 || n > 6)
		return -100000;
	for (int i = ((s[0] == '-') ? 1 : 0); i < n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			x = x * 10 + s[i] - '0';
		else
			return -100000;
	}
	if (s[0] == '-')
		x *= -1;
	return x;
}

int filtrarEntrada()
{
	int n = lerNumero();
	while (n == -100000)
	{
		cout << "Numero invalido. Tente novamente: ";
		n = lerNumero();
	}
	return n;
}

int main()
{
	int a[] = {20, 13, 30, 11, 15, 25, 33, 10, 12, 14, 18};
	ABB* arv = new ABB();
	for (int i = 0; i < 11; i++)
		arv->insere(a[i]);
	int op = 0;

	while (true)
	{
		cout << "\033[2J\033[1;1H";
		arv->imprimeEmLargura();
		cout << endl << "Selecione uma operacao:" << endl;
		cout << " 1: Inserir no" << endl;
		cout << " 2: Buscar valor" << endl;
		cout << " 3: Remover no" << endl;
		cout << " 4: Imprimir visualizacao" << endl;
		cout << " 5: Imprimir ordem crescente" << endl;
		cout << " 6: Destruir arvore" << endl;
		cout << " 7: Encerrar o programa" << endl;
		cout << " 8: Soma dos valores" << endl;
		cout << " 9: Media dos valores" << endl;
		cout << "10: Verificar se eh cheia" << endl;
		cout << "11: Verificar se eh completa" << endl;
		cout << "12: Imprimir intervalo [x, y]" << endl;
		cout << "13: Verificar se eh estritamente binaria" << endl;
		cout << "14: Contar nos maiores que X" << endl;
		cout << "15: Media dos nos de um nivel" << endl;
		cout << "16: Calcular altura dos nos" << endl;

		cout << endl << "Digite o numero correspondente: ";
		op = lerNumero();
		while (op < 1 || op > 16)
		{
			cout << "Operacao invalida. Tente novamente: ";
			op = lerNumero();
		}

		switch (op)
		{
			case 1:
				cout << "Digite o valor do no (numero inteiro): ";
				arv->insere(filtrarEntrada());
				cout << "Insercao realizada com sucesso. Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 2:
				cout << "Digite o valor a ser buscado (numero inteiro): ";
				op = filtrarEntrada();
				cout << "O numero " << op << ((arv->busca(op) == NULL) ? " NAO " : " ") << "existe na arvore. Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 3:
				cout << "Digite o valor do no a ser removido (numero inteiro): ";
				op = filtrarEntrada();
				if (arv->busca(op) == NULL)
					cout << "O numero " << op << " NAO existe na arvore. Pressione ENTER para continuar.";
				else
				{
					arv->remove(op);
					cout << "No removido com sucesso. Pressione ENTER para continuar.";
				}
				lerNumero();
				break;

			case 4:
				cout << endl;
				arv->imprimeVisualizacao();
				cout << endl << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 5:
				cout << endl;
				arv->imprimeOrdemCrescente();
				cout << endl << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 6:
				cout << endl;
				arv->destroiArvore();
				cout << "Arvore destruida com sucesso. Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 8:
				cout << "Soma dos valores da arvore: " << arv->soma() << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 9:
				cout << "Media dos valores da arvore: " << arv->media() << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 10:
				cout << "A arvore " << (arv->ehCheia() ? "eh" : "NAO eh") << " cheia." << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 11:
				cout << "A arvore " << (arv->ehCompleta() ? "eh" : "NAO eh") << " completa." << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 12:
			{
				cout << "Digite o limite inferior: ";
				int x = filtrarEntrada();
				cout << "Digite o limite superior: ";
				int y = filtrarEntrada();
				cout << "Valores no intervalo [" << x << ", " << y << "]: ";
				arv->imprimeIntervalo(x, y);
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;
			}

			case 13:
				cout << "A arvore " << (arv->estritamenteBinaria() ? "eh" : "NAO eh") << " estritamente binaria." << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 14:
				cout << "Digite o valor limite: ";
				op = filtrarEntrada();
				cout << "Ha " << arv->maioresQue(op) << " nos maiores que " << op << "." << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 15:
				cout << "Digite o nivel desejado: ";
				op = filtrarEntrada();
				cout << "Media dos valores no nivel " << op << ": " << arv->mediaNivel(op) << endl;
				cout << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 16:
				cout << "Calculando altura dos nos..." << endl;
				arv->alturaNos();
				cout << "Alturas armazenadas com sucesso. Pressione ENTER para continuar.";
				lerNumero();
				break;
		}

		if (op == 7)
			break;
	}

	return 0;
}
