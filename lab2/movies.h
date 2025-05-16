#define MaxStrLen 40
#define MaxMoviesNo 50
#define ActualMoviesNo 34

struct Movie
{
    char Title[MaxStrLen];
    char Director[MaxStrLen];
    unsigned short Year;
};

struct Movie Movies[MaxMoviesNo] = {
    {"150 na godzine", "Jakubowska Wanda", 1972},
    {"300 mil do nieba", "Dejczer Maciej", 1989},
    {"Agent nr 1", "Kuzminski Zbigniew", 1972},
    {"Akcja pod Arsenalem", "Lomnicki Jan", 1978},
    {"Akwarele", "Rydzewski Ryszard", 1978},
    {"Anatomia milosci", "Zaluski Roman", 1972},
    {"Bal na dworcu w Koluszkach", "Bajon Filip", 1989},
    {"Bez konca", "Kieslowski Krzysztof", 1984},
    {"Bilet powrotny", "Petelscy Ewa i Czeslaw", 1978},
    {"Bitwa o Kozi Dwor", "Berestowski Wadim", 1962},
    {"Blekitny krzyz", "Munk Andrzej", 1955},
    {"Boleslaw Smialy", "Lesiewicz Witold", 1972},
    {"Boris Godunov", "Zulawski Andrzej", 1989},
    {"Brzezina", "Wajda Andrzej", 1970},
    {"Byl jazz", "Falk Feliks", 1981},
    {"Chudy i inni", "Kluba Henryk", 1967},
    {"Cierpkie glogi", "Weychert Janusz", 1966},
    {"Co mi zrobisz jak mnie zlapiesz", "Bareja Stanislaw", 1978},
    {"Czarny wawoz", "Majewski Janusz", 1989},
    {"Czerwone berety", "Komorowski Pawel", 1963},
    {"Czlowiek na torze", "Munk Andrzej", 1957},
    {"Czlowiek z marmuru", "Wajda Andrzej", 1977},
    {"Czlowiek z zelaza", "Wajda Andrzej", 1981},
    {"Danton", "Wajda Andrzej", 1982},
    {"Deszczowy lipiec", "Buczkowski Leonard", 1958},
    {"Diably, diably", "Kedzierzawska Dorota", 1991},
    {"Do widzenia, do jutra", "Morgenstern Janusz", 1960},
    {"Dotkniecie nocy", "Bareja Stanislaw", 1962},
    {"Droga", "Ber Ryszard", 1981},
    {"Drugi czlowiek", "Nalecki Konrad", 1961},
    {"Dyrygent", "Wajda Andrzej", 1980},
    {"Dzien kolibra", "Rydzewski Ryszard", 1983},
    {"Dziewczeta z Nowolipek", "Sass Barbara", 1985},
    {"Krajobraz po bitwie", "Wajda Andrzej", 1970}};