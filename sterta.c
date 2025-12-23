#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "sterta.h"
#include "wersjowanie.h"

void main()
{

//######### DOPASOWAC FUNKCJE Z WERSJI ZEBY DZIALALY	
	printf("WERSJA = %d\n",WERSJA);
	float function = 0.0;

	//setlocale(LC_ALL, "");//takie wyglupy tylko an wind*wsiku
	while(true)
	{
		puts("================ Tablice & Funkcje ================");
		puts("wprowadz numer przykladu: ");
		scanf("%f",&function);
		switch((int)(function*10))
		{
			case 10:
			case 11:
			{
				#if WERSJA == STOSTAB
					float tablica[TABLICA_10];
					wypelnij_recznie_tablice(tablica);
					zsumuj_tablice(tablica);
					sumuj_wszystkie_dodatnie(tablica);
					sumuj_wszystkie_ujemne(tablica);
					sumuj_wieksze_od_k(tablica);
					sumuj_indeksy_parzyste(tablica);
					sumuj_indeksy_nieparzyste(tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			if((int)(function*10)!=10){break;}
			}
			case 12:
			{
				#if WERSJA == STOSTAB
					int m, n, k1, k2 = 0; 
					wprowadz_zmienne(&m, &n, &k1, &k2, function);
					printf("m = %d n = %d k1 = %d k2 = %d <-k1 i k2 odpowiednio pomniejszone bo kompe liczy od 0", m, n, k1, k2);
					float tablica2d[m][n];
					float temp_tablica[m][n];//mozna by bylo kopiowac pojedyncze kolumny
					wypelnij_losowo_tablice(k1, k2, m, n, tablica2d, function);
					zamiana_miejscami(k1, k2, m, n, tablica2d, temp_tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			break;
			}
			case 20:
			case 21:
			{
				#if WERSJA == STOSTAB
					float tablica[TABLICA_10];
					wypelnij_recznie_tablice(tablica);
					ziloczynuj_tablice(tablica);
					ziloczynuj_parzyste(tablica);
					ziloczynuj_nieparzyste(tablica);
					ziloczynuj_dodatnie(tablica);
					ziloczynuj_ujemne(tablica);
					ziloczynuj_wieksze_od_k(tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			if((int)(function*10)!=20){break;}
			}
			case 22:
			{
				#if WERSJA == STOSTAB
					int n = wprowadz_zmienna_n();
					float tablica2d[n][n];
					float temp_tablica[n][n];//mozna by bylo kopiowac pojedyncze kolumny
					wypelnij_losowo_tablice(0, 0, n, n, tablica2d, function);
					zamien_miejscami_przekatne(n, n, tablica2d,temp_tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			break;
			}			
			case 30:
			case 31:
			{
				#if WERSJA == STOSTAB
					float tablica[TABLICA_10];
					wypelnij_recznie_tablice(tablica);
					srednia_parzystych(tablica);
					srednia_nieparzystych(tablica);
					srednia_dodatnich(tablica);
					srednia_wiekszych_od_k(tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			if((int)(function*10)!=30){break;}
			}
			case 32:
			{
				#if WERSJA == STOSTAB
					int m, n, k1, k2 = 0; 
					wprowadz_zmienne(&m, &n, &k1, &k2, function);
					float tablica2d[n][n];
					float temp_tablica[n][n];//mozna by bylo kopiowac pojedyncze kolumny
					wypelnij_losowo_tablice(0, 0, n, n, tablica2d, function);
					kolumna_z_maksymalna_srednia(n, n, k1, k2, tablica2d, temp_tablica);
				#elif WERSJA == STOSWSK
				#elif WERSJA == STERTARETURN
				#endif
			break;
			}
		}
	}
}
void kolumna_z_maksymalna_srednia(int m, int n, int k1, int k2, float tablica2d[n][n], float temp_tablica[n][n])
{
	float srednie[n];
	float najwieksza_srednia=0.0;
	int kolumna_z_najwieksza_srednia=-1;
	float wyliczona_srednia=0.0;
	//printf("n = %d\n",n);
	for(int i=0;i<n;i++)
	{
		wyliczona_srednia=0.0;
		for(int j=0;j<n;j++)
		{
		wyliczona_srednia+=tablica2d[i][j];
		if(j==n-1)
		{
			wyliczona_srednia=wyliczona_srednia/n;
			srednie[i]=wyliczona_srednia;
			if(wyliczona_srednia>najwieksza_srednia)
			{
				najwieksza_srednia=wyliczona_srednia;
				kolumna_z_najwieksza_srednia=i;
			}
		}
		}
	}
	//printf("kolumna z najwieksza srednia = %d\n",kolumna_z_najwieksza_srednia);
	k1=0;
	k2=kolumna_z_najwieksza_srednia;
	printf("\n");
	for(int i=0;i < n;i++)
	{
		if(i==kolumna_z_najwieksza_srednia)
		{
			printf("\x1b[32m%.1f\x1b[0m ",srednie[i]);
		}
		else
		{
			printf("\x1b[34m%.1f\x1b[0m ",srednie[i]);
		}
	}
	printf("\n");
	zamiana_miejscami(k1, k2, m, n, tablica2d, temp_tablica);
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			printf("\x1b[32m%.1f\x1b[0m ",srednie[kolumna_z_najwieksza_srednia]);
		}
		else if(i==kolumna_z_najwieksza_srednia)
		{
			printf("\x1b[34m%.1f\x1b[0m ",srednie[0]);
		}
		else
		{
			printf("\x1b[34m%.1f\x1b[0m ",srednie[i]);
		}
	}
	printf("\n\n");
}

void srednia_wiekszych_od_k(float tablica[TABLICA_10])
{
	float temp=0.0;
	float liczba_wiekszych_od_k=0.0;
	float k=0.0;
	puts("wprowadz k: ");
	scanf("%f",&k);
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] > k)
		{
			temp=tablica[i];
			liczba_wiekszych_od_k+=1.0;
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]>k)
				{
					temp+=tablica[j];
					liczba_wiekszych_od_k+=1.0;
				}
			}
			break;
		}
	}
	temp=temp/liczba_wiekszych_od_k;
	printf("srednia wiekszych od k komurek: %.1f\n",temp);
}

void srednia_dodatnich(float tablica[TABLICA_10])
{
	float temp=0.0;
	float liczba_dodatnich=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] > 0)
		{
			temp=tablica[i];
			liczba_dodatnich+=1.0;
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]>0)
				{
					temp+=tablica[j];
					liczba_dodatnich+=1.0;
				}
			}
			break;
		}
	}
	temp=temp/liczba_dodatnich;
	printf("srednia dodatnich komurek: %.1f\n",temp);
}

void srednia_nieparzystych(float tablica[TABLICA_10])
{
	float temp=0.0;
	float liczba_nieparzystych=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] % 2 != 0)
		{
			temp=tablica[i];
			liczba_nieparzystych+=1.0;
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]%2!=0)
				{
					temp+=tablica[j];
					liczba_nieparzystych+=1.0;
				}
			}
			break;
		}
	}
	temp=temp/liczba_nieparzystych;
	printf("srednia nieparzystych komurek: %.1f\n",temp);
}

void srednia_parzystych(float tablica[TABLICA_10])
{
	float temp=0.0;
	float liczba_parzystych=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] % 2 == 0)
		{
			temp=tablica[i];
			liczba_parzystych+=1.0;
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]%2==0)
				{
					temp+=tablica[j];
					liczba_parzystych+=1.0;
				}
			}
			break;
		}
	}
	temp=temp/liczba_parzystych;
	printf("srednia parzystych komurek: %.1f\n",temp);
}

void zamien_miejscami_przekatne(int m, int n, float tablica2d[n][n],float temp_tablica[n][n])
{
	printf("\nzamienione przekatne:\n");
	//kopioowanie tablicy
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			temp_tablica[i][j]=tablica2d[i][j]; 
		}
	}
	//zamiana przekatnych
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j){tablica2d[i][j]=temp_tablica[i][(n-1)-j];}//temp_tablica[(n-1)-i][(n-1)-j];}
			if(j==(n-1)-i){tablica2d[i][j]=temp_tablica[i][i];}
		}
	}
	//rysowanie zamienionej tablicy
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j && n % 2 !=0&& i==n/2){printf("\x1b[34m");}
			else if(i==j){printf("\x1b[31m");}
			else if(j==(n-1)-i){printf("\x1b[32m");}
			else {printf("\x1b[0m");}
			printf("%.1f ", tablica2d[i][j]);
			if(tablica2d[i][j]<10.0){printf(" ");}
			if(j==n-1){printf("\n");}
		}
	}
	printf("\x1b[0m\n");
}

void ziloczynuj_wieksze_od_k(float tablica[TABLICA_10])
{
	float k=0.0;
	float temp=0.0;
	puts("wprowadz k: ");
	scanf("%f",&k);
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] >k)
		{
			temp=tablica[i];
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]>k)
				{
					temp*=tablica[j];
				}
			}
			break;
		}
	}
	printf("iloczyn wiekszych od k komorek tablicy: %.1f\n",temp);
}

void ziloczynuj_ujemne(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] < 0)
		{
			temp=tablica[i];
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]<0)
				{
					temp*=tablica[j];
				}
			}
			break;
		}
	}
	printf("iloczyn ujemnych komorek: %.1f\n",temp);
}

void ziloczynuj_dodatnie(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] > 0)
		{
			temp=tablica[i];
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]>0)
				{
					temp*=tablica[j];
				}
			}
			break;
		}
	}
	printf("iloczyn dodatnich komorek: %.1f\n",temp);
}

void ziloczynuj_nieparzyste(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] % 2 != 0)
		{
			temp=tablica[i];
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]%2!=0)
				{
					temp*=tablica[j];
				}
			}
			break;
		}
	}
	printf("iloczyn nieparzystych komorek: %.1f\n",temp);
}

void ziloczynuj_parzyste(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if((int)tablica[i] % 2 == 0)
		{
			temp=tablica[i];
			for(int j=i+1;j<TABLICA_10;j++)
			{
				if((int)tablica[j]%2==0)
				{
					temp*=tablica[j];
				}
			}
			break;
		}
	}
	printf("iloczyn parzystych komurek: %.1f\n",temp);
}

void ziloczynuj_tablice(float tablica[TABLICA_10])
{
	float temp=tablica[0];
	for(int i=1; i<TABLICA_10;i++)
	{
		temp*=tablica[i];
	}
	printf("iloczyn komorek tablicy: %.1f\n",temp);
}	

void wypelnij_recznie_tablice(float tablica[TABLICA_10])
{
	puts("wprowadz 10 liczb do tablicy!");
	scanf("%f %f %f %f %f %f %f %f %f %f",&tablica[0],&tablica[1],&tablica[2],&tablica[3],&tablica[4],&tablica[5],&tablica[6],&tablica[7],&tablica[8],&tablica[9]);
	printf("liczby wpisane do tablicy:\n%.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f\n", tablica[0],tablica[1],tablica[2],tablica[3],tablica[4],tablica[5],tablica[6],tablica[7],tablica[8],tablica[9]);
	//porzadnie by bylo to zrobic na petli for i czytaniu inputu ale na szybko na cwiczeniach robie a nie ladnie :P
}
void zsumuj_tablice(float tablica[10])
{
	printf("suma komorek wprowadzonej tablicy wynosi: %.1f\n", tablica[0] + tablica[1] + tablica[2] + tablica[3] + tablica[4] + tablica[5] + tablica[6] + tablica[7] + tablica[8] + tablica[9]);
}

void wprowadz_zmienne(int *m, int *n, int *k1, int *k2, float function)
{
	if(function < 2.0)
	{
		puts("wprowadz m: ");
		scanf("%i",m);
	}
	puts("wprowadz n: ");
	scanf("%i",n);
	if(function < 3.0)
	{
		puts("wprowadz k1: ");
		scanf("%i",k1);
		puts("wprowadz k2: ");
		scanf("%i",k2);
	}	
	//bo miedzy tablicami a na oko jest offset 1
	(*k1)-=1;
	(*k2)-=1;
	//return m, n, k1, k2;//nie wolno zrobic kilku returnow xD
}

int wprowadz_zmienna_n()
{
	int n = 0;
	puts("wprowadz n: ");
	scanf("%i",&n);
	return n;
}

void wypelnij_losowo_tablice(int k1, int k2, int m, int n, float tablica2d[m][n], float function)
{
	printf("\nwylosowana tablica:\n");

	srand(time(NULL));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			//float losowa_liczba = rand() % 100;//zbyt dokladne losowanie
			float losowa_liczba = (float)rand()/((float)RAND_MAX/MOJ_RAND_MAX);//lepsze losowanie
			tablica2d[i][j]=losowa_liczba;
			if(function >= 2 && function < 3)
			{
				if(i==j && n % 2 !=0&& i==n/2){printf("\x1b[34m");}
				else if(j==(n-1)-i){printf("\x1b[31m");}
				else if(i==j){printf("\x1b[32m");}
				else {printf("\x1b[0m");}
			}
			if(function < 2)
			{
				if(j==k1){printf("\x1b[34m");}
				if(j==k2){printf("\x1b[32m");}
			}
			if(function >= 3)
			{
				if(j==0){printf("\x1b[34m");}
			}
			printf("%.1f \x1b[0m", tablica2d[i][j]);
			if(tablica2d[i][j]<10.0){printf(" ");}
			if(j==n-1){printf("\n");}
		}
	}
}

void zamiana_miejscami(int k1, int k2, int m, int n, float tablica2d[m][n], float temp_tablica[m][n])
{
	printf("\nzamienione kolumny %d z %d:\n",k1,k2);
	//kopioowanie tablicy
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			temp_tablica[i][j]=tablica2d[i][j]; 
		}
	}
	//zamiana kolumn
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j==k1){tablica2d[i][j]=temp_tablica[i][k2];} 
			if(j==k2){tablica2d[i][j]=temp_tablica[i][k1];}
		}
	}
	//rysowanie zamienionej tablicy
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j==k1){printf("\x1b[32m");}
			if(j==k2){printf("\x1b[34m");}
			printf("%.1f \x1b[0m", tablica2d[i][j]);
			if(tablica2d[i][j]<10.0){printf(" ");}
			if(j==n-1){printf("\n");}
		}
	}
	printf("\n");
}

void sumuj_wszystkie_dodatnie(float tablica[TABLICA_10])
{
	float temp=0;
	for(int i=0; i<TABLICA_10; i++)
	{
		if(tablica[i]>0){temp+=tablica[i];}
	}
	printf("suma dodatnich komorek tablicy: %.1f\n",temp);
}

void sumuj_wszystkie_ujemne(float tablica[TABLICA_10])
{
	float temp=0;
	for(int i=0; i<TABLICA_10; i++)
	{
		if(tablica[i]<0){temp+=tablica[i];}
	}
	printf("suma ujemnych komorek tablicy: %.1f\n",temp);
}

void sumuj_wieksze_od_k(float tablica[TABLICA_10])
{
	float k=0.0;
	float temp=0.0;
	puts("wprowadz k: ");
	scanf("%f",&k);
	for(int i=0; i<TABLICA_10; i++)
	{
		if(tablica[i]>k){temp+=tablica[i];}
	}
	printf("suma wiekszych od k komorek tablicy: %.1f\n",temp);
}

void sumuj_indeksy_parzyste(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if(i % 2 == 0){temp+=tablica[i];}
	}
	printf("suma komorek o indeksach parzystych tablicy: %.1f\n",temp);
}

void sumuj_indeksy_nieparzyste(float tablica[TABLICA_10])
{
	float temp=0.0;
	for(int i=0;i<TABLICA_10;i++)
	{
		if(i % 2 != 0){temp+=tablica[i];}
	}
	printf("suma komorek o indeksach nieparzystych tablicy: %.1f\n",temp);
}

void stworz_tablice_2d(float **tablica2d, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
	for (int j = 0; j < m; j++)
	{
		tablica2d[i][j] = 0;
	}
    }
}

float* create_1d_array_re(int cols)
{
	float* wsk = NULL;
	wsk = (float*)malloc(cols*sizeof(float));
	return wsk;
}
int* free_1d_array_re(float* arr, int* cols) // funkcja zeruje cols
{
	free(arr);
	return cols;
}
void create_1d_array(float** arr, int cols)
{
	float* wskTemp = (float*)malloc(cols * sizeof(float));
	*arr = wskTemp;
}
void free_1d_array(float** arr, int* cols) // funkcja zeruje cols
{
	free(*arr);
	*arr = NULL;
}
float** create_2d_array_re(int rows, int cols)
{
	float** wsk = NULL;
	wsk = (float**)malloc(rows * sizeof(float*));
	for(int i=0;i<rows;i++) {
		wsk[i] = (float*)malloc(cols * sizeof(float));
	}
	return wsk;
}
int free_2d_array_re(float** arr, int* rows, int* cols) // funkcja zeruje rows i cols
{
	for (int i = 0;i < *rows;i++)
	{
		free(arr[i]);
	}
	free(arr);

	return *rows * *cols;
}
void create_2d_array(float*** myarr, int rows, int cols)
{
	float** wsk2 = NULL;
	wsk2 = (float**)malloc(rows * sizeof(float*));
	for(int i=0;i<rows;i++) {
		wsk2[i] = (float*)malloc(cols * sizeof(float));
	}
	*myarr = wsk2; 
}
void free_2d_array(float*** arr, int* rows, int* cols) // funkcja zeruje rows i cols
{
	for (int i = 0;i < *rows;i++)
	{
		free((*arr)[i]);//tutaj kluczowy jest ten nawias wokol *wsk
	}

	free(*arr);
	*arr = NULL;
}