# kompilacja na GNU + Linux  
gcc sterta.c -o stertac -DCLIWERSJA=2 &emsp; -> &emsp; tym kompilujemy 1-3 to wersje podmieniajac cyfre w -DCLIWERSJA=2
# podglad zmian objetosci alokowanej pamieci
watch -n 1 'top -b -n 1 -p $(pgrep -n stertac)' &emsp; -> &emsp; tym obserwujemy zmiany pamieci przy czyszczeniu  
tak powyzej 100 x 100 tablic widac zmiany zazwyczaj przy czym rysownanie najlepiej wyglada w tablicach typu <10
# uzycie programu
wprowadz numer przykladu: (0=zakonczenie programu, 1-3=wersja zadania, [1-3].[1-2]=podzadania)
np.   
1 &emsp; -> &emsp;  wywoluje caly program 1 z kolejnymi podpunktami 1.1 i 1.2  
3.2 &emsp; -> &emsp; wywoluje tylko podprogram 3.2
# przykladowy output
![image](https://raw.githubusercontent.com/karolgotow/arrays-pointers-training/refs/heads/main/img/output.png)
