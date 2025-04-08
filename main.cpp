/*
IFSP - CAMPUS CUBATÃO
TURMA: ADS 371 - ESTRUTURA DE DADOS
NOME: STIVEN RICHARDY SILVA RODRIGUES
*/

#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

#define BARALHO 2
#define NAIPE 4
#define NUMERO_CARTA 13
#define CARTAS 52
#define TOTAL_CARTAS 104
#define JOGADORES 4
#define CARTAS_JOGADOR 11

void distribuir(string todas[TOTAL_CARTAS], string **mao) 
{
	for (int i = 0; i < TOTAL_CARTAS; ++i) 
	{
		int r = rand() % TOTAL_CARTAS;
		string temp = todas[i];
		todas[i] = todas[r];
		todas[r] = temp;
	}

	int index = 0;
	for (int i = 0; i < JOGADORES; ++i) 
	{
		for (int j = 0; j < CARTAS_JOGADOR; ++j) 
		{
			mao[i][j] = todas[index++];
		}
	}

	cout << "===== MÃOS DOS JOGADORES =====" << endl;
	for (int i = 0; i < JOGADORES; ++i) 
	{
		cout << "Jogador " << i + 1 << ": ";
		for (int j = 0; j < CARTAS_JOGADOR; ++j) 
		{
			cout << mao[i][j] << " | ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "");
	srand(time(0));

	string **baralho = new string*[BARALHO];
	string **mao = new string*[JOGADORES];

	for (int i = 0; i < BARALHO; ++i) 
	{
		baralho[i] = new string[CARTAS];
	}
	for (int i = 0; i < JOGADORES; ++i) 
	{
		mao[i] = new string[CARTAS_JOGADOR];
	}

	string todas[TOTAL_CARTAS];
	int cont = 0;
	for (int i = 0; i < BARALHO; ++i) 
	{
		for (int j = 1; j <= NAIPE; ++j) 
		{
			for (int k = 1; k <= NUMERO_CARTA; ++k) 
			{
				string carta = "";
				stringstream numero;

				carta += char(j + '0');

				if (k < 10) {
					numero << "0";
				}
				numero << k;

				carta += numero.str();
				carta += char((i + 1) + '0');

				baralho[i][cont % CARTAS] = carta;
				todas[cont++] = carta;
			}
		}
	}

	distribuir(todas, mao);

	for (int i = 0; i < BARALHO; ++i)
	{
		delete[] baralho[i];
	}
	delete[] baralho;

	for (int i = 0; i < JOGADORES; ++i) 
	{
		delete[] mao[i];
	}
	delete[] mao;

	return 0;
}
