#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int tabwynik[10];

int szukanie_liniowe_1(int TAB[], int n, int x)
{
	for ( int i = 0; i < n; i++)
	{
		if ( TAB[i] == x )
		{
			return(i);
		}
	}
	return(-1);
}

int* szukanie_liniowe_2(int TAB[], int n, int x, int* ilosc)
{
	for (int i = 0; i < n; i++)
	{
		if (TAB[i] == x)
		{
			tabwynik[*ilosc] = i;
			(*ilosc)++;
		}
	}
	return(tabwynik);
}

void sort(int TAB[],int w)
{
	int x;
	int i;
	for (int j = w; j >= 0; j--)
	{
		x = TAB[j];
		i = j + 1;
		while ((i < w) && (x > TAB[i]))
		{
			TAB[i - 1] = TAB[i];
			i++;
		}
		TAB[i - 1] = x;
	}
}

int szukanie_binarne(int TAB[], int n, int x)
{
	int mid=0;
	int l = TAB[0];
	int r = TAB[n - 1];
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (TAB[mid] == x) return mid;
		if (TAB[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
}

main()
{
	int sz = 0;
	int w = 10;
	printf("podaj szukana liczbe: ");
	scanf("%d",&sz);
	printf("podaj wielkosc tablicy: ");
	scanf("%d", &w);
	int* tablica;
	tablica = malloc(sizeof (*tablica) * w );
	int wynik_1;
	int* wynik_2;
	int ilosc = 0 ;
	for (int i = 0; i < w; i++)
	{
		int x = 0;
		printf("podaj wartosc do tablicy ");
		scanf("%d", &x);
		*(tablica+i) = x;
	}


	wynik_1 = szukanie_liniowe_1(tablica, w, sz);
	printf("indeks szukanego elemantu: %d\n", wynik_1);

	if (wynik_1 !=(-1))
	{
		wynik_2 = szukanie_liniowe_2(tablica, w, sz, &ilosc);
		printf("ilosc znalezionych wartosci: %d\n", ilosc);
		printf("tablica z wynikami ma adres: %p\n", wynik_2);
		for (int i = 0; i < ilosc; i++) printf("watrosc znaleziona w indeksie: %d\n", *(wynik_2 + i));
	}
	
	sort(tablica, w);
	printf("indeks szukanego elementu(szukanie binarne) to: %d\n",szukanie_binarne(tablica, w, sz));

	free(tablica);
	return 0;
}
