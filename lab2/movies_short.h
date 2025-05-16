#define MaxStrLen 40
#define MaxMoviesNo 50
#define ActualMoviesNo 10

struct Movie
{
    char Title[MaxStrLen];
    char Director[MaxStrLen];
    unsigned short Year;
};

struct Movie Movies[MaxMoviesNo] = {
    {"150 na godzine", "Jakubowska Wanda", 1972},
    {"Akwarele", "Rydzewski Ryszard", 1978},
    {"Bal na dworcu w Koluszkach", "Bajon Filip", 1989},
    {"Bilet powrotny", "Petelscy Ewa i Czeslaw", 1978},
    {"Byl jazz", "Falk Feliks", 1981},
    {"Cierpkie glogi", "Weychert Janusz", 1966},
    {"Deszczowy lipiec", "Buczkowski Leonard", 1958},
    {"Do widzenia, do jutra", "Morgenstern Janusz", 1960},
    {"Dyrygent", "Wajda Andrzej", 1980},
    {"Krajobraz po bitwie", "Wajda Andrzej", 1970}};