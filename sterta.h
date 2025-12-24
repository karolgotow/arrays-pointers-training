#define TABLICA_1 1
#define TABLICA_10 10
#define MOJ_RAND_MAX 99

//float function = 0.0;
//float tablica[TABLICA_10];
//int m=0;
//int n=0;
//int k1=0;
//int k2=0;

void wypelnij_recznie_tablice();
float wypelnij_tablice();
void zsumuj_tablice();
void wypelnij_losowo_tablice(int k1, int k2, int m, int n, float tablica2d[m][n], float function);
void zamiana_miejscami(int k1, int k2, int m, int n, float tablica2d[m][n], float temp_tablica[m][n]);
void sumuj_wszystkie_dodatnie();
void sumuj_wszystkie_ujemne();
void sumuj_wieksze_od_k();
void sumuj_indeksy_parzyste();
void sumuj_indeksy_nieparzyste();
void stworz_tablice_2d();
void wprowadz_zmienne(int *m, int *n, int *k1, int *k2, float function);

void zamien_miejscami_przekatne();
int wprowadz_zmienna_n();
void ziloczynuj_tablice();
void ziloczynuj_parzyste();
void ziloczynuj_nieparzyste();
void ziloczynuj_dodatnie();
void ziloczynuj_ujemne();
void ziloczynuj_wieksze_od_k();

void kolumna_z_maksymalna_srednia();
void srednia_parzystych();
void srednia_nieparzystych();
void srednia_dodatnich();
void srednia_wiekszych_od_k();

float* create_1d_array_re(int cols);
int* free_1d_array_re(float* arr, int* cols); // funkcja zeruje cols

void create_1d_array(float** arr, int cols);
void free_1d_array(float** arr, int* cols); // funkcja zeruje cols

float** create_2d_array_re(int rows, int cols);
int free_2d_array_re(float** arr, int* rows, int* cols); // funkcja zeruje rows i cols

void create_2d_array(float*** myarr, int rows, int cols);
void free_2d_array(float*** arr, int* rows, int* cols); // funkcja zeruje rows i cols