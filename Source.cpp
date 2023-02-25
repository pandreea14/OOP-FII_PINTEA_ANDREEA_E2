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

int main()
{
	//Exemplificare printf
	printf("-----------------[EXEMPLU CU PRINTF]------------------------\n");
	int a = 123;
	printf("Valoare lui a este: %d\n", a);
	char c = 123;
	printf("Valoarea lui c (char) este: %c\n", c);
	printf("Valoarea numerica a lui c este: %d\n", c);
	char sir[20] = "ana are mere\0";
	printf("Sirul meu are valoarea: %s\n", sir);
	printf("-----------------------------------------------------");
	printf("\n\n");


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
		/*
		if (fgets(myString, 200, fp))
		{
			printf("Am citit din fisier: %s\n", myString);
		}
		*/
		
		while (fgets(myString, 200, fp))//citeste un rand din fisier si il pune in charul myString
		{
			myString[strlen(myString)-1] = '\0';
			printf("Am citit din fisier: %s\n", myString);

			nr = 0, index = 0;
			while (index < strlen(myString))
			{
				nr = nr*10 + (myString[index] - '0');
				index++;
			}
			printf("-Nr meu este %d\n\n", nr);

			suma += nr;
		}
	}
	printf("Suma numerelor din fisier este %d\n", suma);
	printf("-----------------------------------------------------");
	printf("\n\n");

	printf("-----------------[PROBLEMA 2]------------------------\n");
	
	printf("Introduceti o propozitie: ");
	char vectCuvinte[50][200], sentence[200];
	scanf_s("%200s", sentence);
	//scanf("%19s", cuvant);
	int counter = 0, numarCuvinte = 0;
	while (scanf_s("%200s", vectCuvinte[counter]))
	{
		//if (strcmp(cuvant, "\n\n") == 0)
		//	break;

		numarCuvinte++;

		printf("Cuvantul citit este: %s\n", vectCuvinte[counter]);
		counter++;

		//if (counter >= numarCuvinte)
			//break;
	}
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
