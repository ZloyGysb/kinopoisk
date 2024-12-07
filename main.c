#include <stdio.h>
#include <stdlib.h>
#include "kinopoisk.h"
int main() {
	Film *films = NULL;
	int count = 0;
	loadFilms(&films, &count);
	int choice;
	do {
		printf("Menu:\n");
		printf("1. Spisok fimov\n");
		printf("2. Dobavit film\n");
		printf("3. Redaktirovat film\n");
		printf("4. Udalit film\n");
		printf("5. Poisk filma po godu vipuska\n");
		printf("6. Sohranit i viyti\n");
		printf("Vvedite nomer: ");
		scanf("%i", &choice);
		switch (choice) {
			case 1:
				displayFilms(films, count);
				break;
			case 2:
				addFilm(&films, &count);
				break;
			case 3:
				editFilm(films, count);
				break;
			case 4:
				deleteFilm(films, &count);
				break;
			case 5:
				searchFilms(films, count);
				break;
			case 6:
				saveFilms(films, count);
				break;
			default:
				printf("Nevernoe znachenie, poprobuyte snova\n");
		}
	}
	while (choice != 6);
	free(films);
	return 0;
}
