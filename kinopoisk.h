#include <stdio.h>
typedef struct {
	char name[100];
	int year;
	float rating;
} Film;
void loadFilms(Film **films, int *count);
void saveFilms(Film *films, int count);
void addFilm(Film **films, int *count);
void editFilm(Film *films, int count);
void deleteFilm(Film *films, int *count);
void searchFilms(Film *films, int count);
void displayFilms(Film *films, int count);
