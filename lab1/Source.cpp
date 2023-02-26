//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int tr = 2; tr <= n / 2; tr++)
		if ((n % tr) == 0)
			return false;
	return true;
}

struct prop
{
	int length;
	char *cuv;
};

int afis_bubbleSort(int counter, prop sentence[200])
{
	int ultim = counter, lng;
	while (ultim > 0)
	{
		lng = ultim - 1;
		ultim = 0;
		for (int index = 0; index < lng; ++index) {
			if (sentence[index].length < sentence[index + 1].length)
			{
				swap(sentence[index], sentence[index + 1]);
				ultim = index + 1;
			}
			if (sentence[index].length == sentence[index + 1].length)
			{

				if (strcmp(sentence[index].cuv, sentence[index + 1].cuv) == 1)
				{
					swap(sentence[index], sentence[index + 1]);
					ultim = index + 1;
				}

			}
		}
	}
	for (int index = 0; index < counter; ++index)
	{
		printf("%s\n", sentence[index].cuv);
	}
}

int main()
{
	printf("-----------------[PROBLEMA 1]------------------------\n");
	FILE* fp;
	int index, nr, suma = 0;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char myString[200];

		while (fgets(myString, 200, fp))//citeste un rand din fisier si il pune in charul myString
		{
			myString[strlen(myString) - 1] = '\0';
			printf("Am citit din fisier: %s\n", myString);

			nr = 0, index = 0;
			while (index < strlen(myString))
			{
				nr = nr * 10 + (myString[index] - '0');
				index++;
			}

			suma += nr;
		}
	}
	printf("Suma numerelor din fisier este %d\n", suma);
	printf("-----------------------------------------------------");
	printf("\n\n");

	printf("-----------------[PROBLEMA 2]------------------------\n");

	printf("Introduceti numarul de cuvinte din propozitie: ");
	int numarCuvinte;
	scanf_s("%d", &numarCuvinte, 4);
	printf("Introduceti o propozitie: ");
	char cuvant[20];
	int counter = 0;
	prop sentence[200];
	while (scanf_s("%19s", cuvant, 19))
	{
		sentence[counter].cuv = _strdup(cuvant);//aloca dinamic
		sentence[counter++].length = strlen(cuvant);
		printf("Cuvantul citit este: %s\n", cuvant);
		if (counter >= numarCuvinte) break;
	}
	
	cout << afis_bubbleSort(counter, sentence);

	printf("-----------------------------------------------------");
	printf("\n\n");

	printf("-----------------[PROBLEMA 3]------------------------\n");
	int n;
	cout << "Enter a number:";
	cin >> n;

	if (isPrime(n))
		cout << n << " is prime !";
	else
		cout << n << " is NOT prime !";

	system("pause");
	return 0;
}