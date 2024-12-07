#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kinopoisk.h"
void loadFilms(Film **films, int *count) {
	FILE *file = fopen("kinopoisk.txt", "rb");
	if (!file) {
		*count = 3;
		*films = malloc(*count * sizeof(Film));
		strcpy((*films)[0].name, "Brilliantovaya ruka");
		(*films)[0].year = 1969;
		(*films)[0].rating = 8.5;
		strcpy((*films)[1].name, "Ivan Vasilyevich menyaet professiyu");
		(*films)[1].year = 1973;
		(*films)[1].rating = 8.8;
		strcpy((*films)[2].name, "Kavkazskaya plennica");
		(*films)[2].year = 1967;
		(*films)[2].rating = 8.5;
		return;
	}
	fread(count, sizeof(int), 1, file);
	*films = malloc((*count) * sizeof(Film));
	fread(*films, sizeof(Film), *count, file);
	fclose(file);
}
void saveFilms(Film *films, int count) {
	FILE *file = fopen("kinopoisk.txt", "wb");
	fwrite(&count, sizeof(int), 1, file);
	fwrite(films, sizeof(Film), count, file);
	fclose(file);
}
void addFilm(Film **films, int *count) {
	*films = realloc(*films, (*count + 1) * sizeof(Film));
	Film *newFilm = &(*films)[*count];
	printf("Vvedite nazvanie filma: ");
	scanf("%s", newFilm->name);
	printf("Vvedite god vihoda filma: ");
	scanf("%i", &newFilm->year);
	printf("Vvedite ocenku filma: ");
	scanf("%f", &newFilm->rating);
	(*count)++;
}
void editFilm(Film *films, int count) {
	int id;
	displayFilms(films, count);
	printf("Vvedite nomer filma, kotorogo hotite izmenit: ");
	scanf("%i", &id);
	if (id < 0 || id >= count) {
		printf("Nevernoe znachenie\n");
		return;
	}

	Film *film = &films[id];
	printf("Vvedite novoe nazvanie filma(vvedite ODNU lyubyu bukvu ili cifru dlya propuska): ");
	char temp[100];
	scanf("%s", temp);
	if (strlen(temp) > 1){
		strcpy(film->name, temp);
	}
	printf("Vvedite noviy god vihoda filma(vvedite '-1' dlya propuska): ");
	int year;
	scanf("%i", &year);
	if (year != -1){
		film->year = year;
	}
	printf("Vvedite novuyu ocenku filma(vvedite '-1' dlya propuska): ");
	float rating;
	scanf("%f", &rating);
	if (rating != -1) {
		film->rating = rating;
	}
}
void deleteFilm(Film *films, int *count) {
	int id;
	displayFilms(films, *count);
	printf("Vvedite nomer filma, kotorogo hotite udalit: ");
	scanf("%i", &id);
	if (id < 0 || id >= *count) {
		printf("Nevernoe znachenie\n");
		return;
	}

	for (int i = id; i < *count - 1; i++) {
		films[i] = films[i + 1];
	}
	(*count)--;
	films = realloc(films, (*count) * sizeof(Film));
}
void searchFilms(Film *films, int count) {
	int year;
	printf("Vvedite god vipuska filma: ");
	scanf("%i", &year);
	for (int i = 0; i < count; i++) {
		if (films[i].year == year) {
			printf("Film: %s, God: %i, Ocenka: %f\n", films[i].name, films[i].year, films[i].rating);
		}
	}
}
void displayFilms(Film *films, int count) {
	for (int i = 0; i < count; i++) {
		printf("%i. Film: %s, God: %i, Ocenka: %f\n", i, films[i].name, films[i].year, films[i].rating);
	}
}
