#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Nicolas de Barros 
//TIA : 32070837

using namespace std;

#pragma warning (disable : 6386)

void redefine_tamanho(int **ptr, int tamanho_atual, int tamanho_novo)
{
	int* ptr_new;
	ptr_new = new int[tamanho_novo];

	for (int j = 0; j < tamanho_atual; j++)
	{
		ptr_new[j] = (*ptr)[j];
		//ptr_new[j]= *(*ptr + j*sizeof(int));
	}

	delete(*ptr);

	*ptr = ptr_new;
}

bool verifica_positivo(int elem)
{
	if (elem == 0)
	{
		return true;
	}

	else if (elem > 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void main()
{
	int tamanho, i, temp; 
	int tamanho_novo = 0;
	int k = 0;
	char opcao;

	cout << "\nDigite o tamanho do array : ";
	cin >> tamanho;

	int *ptr_i;
	
	ptr_i = new int[tamanho];

	for (i = 0; i < tamanho; i++)
	{
		cout << "\nDigite um número positivo para o elemento " << i << "\n";
		cin >> temp;

		//verificar se é negativo e coloca o elem 
		if (verifica_positivo(temp) == true)
		{
			ptr_i[i] = temp;
		}

		//se for negativo = > colocar todos os outros elem para -1
		else
		{
			for (k = i; k < tamanho; k++)
			{
				ptr_i [k]= -1;
			}

			if (i == 0)
			{
				++i;
			}
			break;
			
		}
	}
	 
	if (i == tamanho || k == tamanho)
	{
		cout << "\nO array está cheio, deseja aumentar o seu tamanho ? S/N \n";
		cin >> opcao;

		if (opcao == 'S')
		{
			cout << "\nInforme o novo tamanho : ";
			cin >> tamanho_novo;

			if (tamanho_novo > tamanho)
			{
				redefine_tamanho(&ptr_i, tamanho, tamanho_novo);

				//FOR p colocar os elem novo 
				for (i = tamanho; i < tamanho_novo; i++)
				{
					cout << "\nDigite o novo elemento\n";
					cin >> temp;
					ptr_i[i] = temp;
				}
			}

			else
			{
				cout << "\nO tamanho novo deve ser maior que o tamanho atual ! ";
			}
		}

		if (tamanho_novo > tamanho)
			tamanho = tamanho_novo;

		for (int n = 0; n < tamanho; n++)
		{
			cout << "\nElemento " << n << "\n";
			cout << ptr_i[n];
		}

		cout << "\nSaindo do programa... ";
		
	}

	delete[] ptr_i;
}