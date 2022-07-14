/**
* This program is free software : you can redistribute itand /or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
* GNU General Public License for more details.
*/

//@brief Program kontroluje hesla podla poziadaviek.

#include <iostream>
#include <string>
#include <iomanip>

#define MAX_SIZE 126

/**
* *Kontroluje 'chary' v 'stringu' nazvu hesla,
*	heslo musi obsahovat aspon jedno velke a male pismeno.
*
* @param[in, out] 'std::string nazov, int dlzka'.
* 
* @return 'kontrola', 'true' pokial splnuje poziadavky,
*	'false' pokial nesplnil poziadavky.
*/
bool pismena(std::string nazov, int dlzka);

/**
*@tparam *Kontroluje poziadavky podla zadania 'PARAM'.
*	(PARAM 1) prva poziadavka, aspon jedno male pismeno.
*	(PARAM 2) druha poziadavka, aspon jedno velke pismeno.
*	(PARAM 3) tretia poziadavka, aspon jedeno cislo, (0-9).
*	(PARAM 4) stvrta poziadavka, aspon jeden specialny znak, ASCII (32-126).
*
* @param[in, out] 'int PARAM, std::string nazov, int dlzka'.
* 
* @return 'kontrola', 'true' pokial splnuje poziadavky,
*	'false' pokial nesplnil poziadavky.
*/
bool ASCI_porovnavanie(int PARAM, std::string nazov, int dlzka);

/**
* *Kontroluje sekvenciu 'PARAM' istych znakov v 'stringu'.
*
* @param[in, out] 'int PARAM, std::string nazov, int dlzka'.
*
* @return 'kontrola', 'true' pokial splnuje poziadavku,
*	'false' pokial nesplnil poziadavku.
*/
bool opakovanie_pismen(int PARAM, std::string nazov, int dlzka);

/**
* *Kontroluje opakovanie istych podretazcov pismen
*	s dlzkov 'PARAM'.
*
* @param[in, out] 'int PARAM, std::string nazov, int dlzka'.
*
* @return 'kontrola', 'true' pokial splnuje poziadavku,
*	'false' pokial nesplnil poziadavku.
*/
bool opakovanie_podretazcov(int PARAM, std::string nazov, int dlzka);

/**
* *Kontroluje opakovanie istych podretazcov pismen
*	s dlzkov 'PARAM'.
*
* @param[in, out] 'int PARAM, std::string nazov, int dlzka'.
*/
void stats(int moznosti, int min_dlzka, int sucet_dlziek, int pocet);

//@tparam Pre organizaciu kodu.
struct Heslo {
	std::string nazov;
};

int main(int argc, char* argv[]) {
	Heslo heslo;
	bool overenie = false;
	int LEVEL = std::stoi(argv[1]);
	int PARAM = std::stoi(argv[2]);
	int pocet = 0;
	int dlzka = 0;
	int moznosti = 0;
	int sucet_dlziek = 0;
	int min_dlzka = MAX_SIZE;
	int statistiky_b = false;
	char ABCD[MAX_SIZE];

	if (LEVEL > 4) return EXIT_FAILURE; //@warning Pokial je LEVEL vasci ako styri, ukonci program.
	if (LEVEL < 1) return EXIT_FAILURE; //@warning Pokial je LEVEL mensi ako jeden, ukonci program.
	if (PARAM < 1 || (PARAM > MAX_SIZE)) return EXIT_FAILURE; //@warning Pokial je PARAM mensi ako jeden, alebo vasci ako (MAX_SIZE), ukonci program.
	if (argc > 4) return EXIT_FAILURE; //@warning Pokial do vstupu dame viac ako 3 argumenty, program sa ukonci.
	/**
	*@warning Pokial pocet argumentov je 3, 
	*	kontroluje treti argument ci sa zhoduje so slovom '--stats'.
	*	Ked sa zhoduje spusti funkciu 'stats()', cez premenu 'statistiky_b'.
	*/
	if (argc == 4) { 
		std::string tem_string = "--stats"; //@note Zadefinovanie vzoru porovnia '--stats'.
		if (argv[3] == tem_string) statistiky_b = true;
		else return EXIT_FAILURE;
	}

	while (std::getline(std::cin, heslo.nazov)) {
		if (MAX_SIZE <= heslo.nazov.length()) overenie = false; //@warning Moc dlhe heslo je neplatne.
		else overenie = true;
		dlzka = heslo.nazov.length();

		for (int i = 1; i <= LEVEL; i++) {
			switch (i) {
			case (1): {
				if (overenie)
					overenie = pismena(heslo.nazov, dlzka);
				break;
			}
			case (2): {
				if (overenie)
					overenie = ASCI_porovnavanie(PARAM, heslo.nazov, dlzka);
				break;
			}
			case (3): {
				if (overenie)
					overenie = opakovanie_pismen(PARAM, heslo.nazov, dlzka);
				break;
			}
			case (4): {
				if (overenie)
					overenie = opakovanie_podretazcov(PARAM, heslo.nazov, dlzka);
				break;
			}
			}
		}
		std::cout.flush();
		if (overenie) { //@note Vypise heslo pokial uspesne presiel vsetky poziadavky.
			std::cout << heslo.nazov << std::endl;
		}

		if (min_dlzka > dlzka) min_dlzka = dlzka; //@note Kontrola najmensej dlzky.
		sucet_dlziek += dlzka; //@note Sucet dlziek

		for (int i = 0; i < dlzka; i++) { //@note Kontroluje pocet roznych pismen.
			bool kontrola = false;
			for (int j = 0; j < moznosti; j++) {
				if (ABCD[j] == heslo.nazov.at(i))
					kontrola = true;
			}
			if (!kontrola) {
				ABCD[moznosti] = heslo.nazov.at(i);
				moznosti++;
			}
		}
		pocet++; //@tparam Prida pocet hesiel.
	}

	if (statistiky_b) {
		stats(moznosti, min_dlzka, sucet_dlziek, pocet);
	}
	return EXIT_SUCCESS;
}

bool pismena(std::string nazov, int dlzka) {
	bool kontrola = false;

	for (int i = 0; i < dlzka; i++) {
		char temp_char = nazov[i];

		if (temp_char >= 65 && temp_char <= 90) {
			kontrola = true;
		}
	}

	if (kontrola) {
		kontrola = false;

		for (int i = 0; i < dlzka; i++) {
			char temp_char = nazov[i];

			if (temp_char >= 97 && temp_char <= 122) {
				kontrola = true;
			}
		}
	}
	return kontrola;
}

bool ASCI_porovnavanie(int PARAM, std::string nazov, int dlzka) {
	bool konrola_1 = false;
	bool konrola_2 = false;
	bool konrola_3 = false;
	bool konrola_4 = false;

	if (PARAM > 4) PARAM = 4;

	for (int i = 0; i < dlzka; i++) {
		for (int j = 0; j <= PARAM; j++) {
			switch (j) {
			case (1): {
				if (!konrola_1)
					if (nazov[i] >= 65 && nazov[i] <= 90)
						konrola_1 = true;
				break;
			}
			case (2): {
				if (!konrola_2)
					if (nazov[i] >= 97 && nazov[i] <= 122)
						konrola_2 = true;
				break;
			}
			case (3): {
				if (!konrola_3)
					if (nazov[i] >= 48 && nazov[i] <= 57)
						konrola_3 = true;
				break;
			}
			case (4): {
				if (!konrola_4)
					if ((nazov[i] >= 32 && nazov[i] <= 47) || (nazov[i] >= 58 && nazov[i] <= 64) || (nazov[i] >= 91 && nazov[i] <= 96) || (nazov[i] >= 123 && nazov[i] <= 126))
						konrola_4 = true;
				break;
			}
			}
		}
	}

	/** 
	*@tparam Pokial PARAM mensi ako cislo,
	*	podmienka sa da do true hodnoty,
	*	preto ze meno neprechadza cez podmienku.
	*/
	if (4 > PARAM) {
		konrola_4 = true;
		if (3 > PARAM) {
			konrola_3 = true;
			if (2 > PARAM) {
				konrola_2 = true;
				if (1 > PARAM) {
					konrola_1 = true;
				}
			}
		}
	}
	if (konrola_1 && konrola_2 && konrola_3 && konrola_4) return true;
	else return false;
}

bool opakovanie_pismen(int PARAM, std::string nazov, int dlzka) {
	int kontrola = 0;

	if (PARAM == 1) return false;
	for (int i = 0; i < dlzka; i++) {
		if (nazov[i] == nazov[i + 1]) {
			kontrola++;
			if (kontrola >= PARAM - 1) return false;
		}
		else kontrola = 0;
	}
	return true;
}

bool opakovanie_podretazcov(int PARAM, std::string nazov, int dlzka) {
	int tem_int = 0;
	bool kontrola = true;
	int pocet = 0;
	std::string string_array[MAX_SIZE * 2]; //@note Dvojnasobok hodnoty MAX_SIZE (126), kvoli pripadnemu preteceniu pamete.
	int int_array[MAX_SIZE * 2]; 
	/**
	*@note Ukonci fukciu, preto ze sa podretazec nebzde opakovat,
	*	bude iba jeden podretazec (cele slovo).
	*/
	if (dlzka < PARAM) return true;
	while (kontrola) {
		int increasing_int = 0; //@note Meniaca sa pozicia zacinajuceho sa podretazca.

		while (kontrola) {
			string_array[pocet] = nazov.substr(increasing_int + tem_int, PARAM);
			int_array[pocet] = increasing_int + tem_int;

			increasing_int += PARAM;

			if (dlzka == (increasing_int + tem_int) - PARAM) break; //@warning Koniec slova.
			if (dlzka < increasing_int + tem_int + PARAM) break; //@warning Koniec slova, nezmesti sa podretazec dlzky PARAM.

			pocet++;
		}

		for (int i = 0; i < pocet; i++) {
			for (int j = i + 1; j < pocet; j++) {
				if (int_array[i] != int_array[j]) {
					if (string_array[j] == string_array[i]) { //@note Kontrolovanie isteho podretazca.
						return false;
					}
				}
			}
		}

		tem_int++;
		if (dlzka <= PARAM + tem_int) kontrola = false; //@warning Ukoncenie, nezmesti sa podretazec dlzky (PARAM +  tem_int) do dlzky hesla.
		else pocet++;
	}
	return true;
}

void stats(int moznosti, int min_dlzka, int sucet_dlziek, int pocet) {
	float priem_dlzka = 0.0;
	if (sucet_dlziek != 0) priem_dlzka = static_cast<float>(sucet_dlziek) / pocet;
	else min_dlzka = 0; //@tparam Ked nie je ziadny vstup, 'min_dlzka' ma hodnotu MAX_SIZE.

	std::cout << "Statistika: " << std::endl;
	std::cout << "Pocet roznich znakov: " << moznosti << std::endl;
	std::cout << "Minimalna dlzka: " << min_dlzka << std::endl;
	std::cout << "Priemerna dlzka: ";
	//cout.width(5);
	std::cout << std::fixed << std::setprecision(1) << priem_dlzka << std::endl;
}