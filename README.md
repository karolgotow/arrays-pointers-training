# kompilacja na GNU + Linux  
gcc sterta.c -o stertac -DCLIWERSJA=2 		 ->tym kompilujemy 1-3 to wersje  
# podglad zmian objetosci alokowanej pamieci
watch -n 1 'top -b -n 1 -p $(pgrep -n stertac)'	 ->tym obserwujemy zmiany pamieci przy czyszczeniu  
no tak powyzej 100 x 100 tablic widac zmiany zazwyczaj przy czym rysownanie najlepiej wyglada w tablicach typu <10
# uzycie programu
wprowadz numer przykladu: (0=zakonczenie programu, 1-3=wersja zadania, [1-3].[1-2]=podzadania)
np. 3.2 -> wywoluje podprogram 3.2
# przykladowy output
![image](https://raw.githubusercontent.com/karolgotow/arrays-pointers-training/refs/heads/main/img/output.png)
