#include <iostream>
#include <ctime>
using namespace std;

// Opdracht 1 - Programmeermethoden - Vermenigvuldiging
// Makers: Jens van der Linden & Thijmen Rosenbrand
// Studentnummers: s5205212 & s5225752
// Compiled met: g++ 13.3.0
// Versie: 1.0
// Laatste wijziging op: 21-9-2026

int main()
{
	// Infoblokje
	cout << "Makers        | Jens van der Linden | Thijmen Rosenbrand"
		 << endl 
		 << "--------------------------------------------------------"
		 << endl
		 << "Studentnummer |      s5205212       |     s5225752      "
		 << endl
		 << "--------------------------------------------------------"
		 << endl
	 	 << "Aankomstjaar  |        2026         |       2026        "
	     << endl
	     << "--------------------------------------------------------"
	     << endl;
	cout << "Laatste wijziging : 21-09-2026." << endl;
	cout << "Opgave 1 - Programeermethoden - Vermenigvuldiging." 
		 << endl;
	cout << "--------------------------------------------------------"
		 << endl;
	cout << "Dit programma kijkt of je geschikt bent voor een " << 
			"universitaire opleiding, met behulp van de volgende stappen:"
		 << endl
		 << "1. Leeftijdcheck, checkt of je jong/oud genoeg bent."
		 << endl
		 << "2. Geboortedag check, checkt voor de dag van de week " <<
		 	"op je geboortedag."
		 << endl
		 << "3a. Rekenvraag, een vermenigvuldigingsvraag om te " <<
		 	"checken of je geschikt bent voor een beta studie."
		 << endl
		 << "3b. Kunst/literatuurvraag, een vraag over kunst/" << 
		 	"literatuur, als je de rekenvraag fout hebt." << endl;

	cout << endl << endl;



	// Datum variabelen
	int huidigeDag, huidigeMaand, huidigJaar = 0;

	// 2 hulpvariabelen voor de tijd
	tm s;
	time_t t;

	// Huidige datum krijgen met behulp can ctime
	time (&t);
	s = * localtime (&t);
	huidigeDag = s.tm_mday;
	huidigeMaand = s.tm_mon + 1; // Telt vanaf 0
	huidigJaar = s.tm_year + 1900; // Telt vanaf 1900

	int geboorteJaar = 0;

	cout << "Wat is je geboortejaar? (xxxx)" << endl << "> ";
	cin >> geboorteJaar;

	int jaarLeeftijd = huidigJaar - geboorteJaar;

	// Leeftijdcheck - toekomst
	if (jaarLeeftijd < 0){
		cout << "Je bent nog niet geboren" << endl;
		return 1;
	}

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10){
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (jaarLeeftijd > 101){
		cout << "Je bent te oud!" << endl;
		return 1;
	} // if

	int geboorteMaand = 0;

	cout << "Wat is je geboortemaand? (1-12)" << endl << "> ";
	cin >> geboorteMaand;

	// Check of de geboorte maand mogelijk is.
	if (geboorteMaand <= 0 || geboorteMaand >= 13) {
		cout << "Dit is geen valide maand!" << endl;
		return 1;
	} // if

	int maandLeeftijd = huidigeMaand - geboorteMaand;

	if (maandLeeftijd < 0) {
		jaarLeeftijd--;
		maandLeeftijd += 12;
	} // if

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10) {
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (
		jaarLeeftijd > 101 || 
		(jaarLeeftijd > 100 && geboorteMaand < huidigeMaand)
	   ) {
		cout << "Je bent te oud!" << endl;
		return 1;
	} // if

	// Maak een range voor de geboortedag (e.g. 1-31(/30/29/28))
	int maxGeboorteDag = 31;

	if (geboorteMaand == 4 || // apr
		geboorteMaand == 6 || // jun
		geboorteMaand == 9 || // sept
		geboorteMaand == 11)  // nov
		{
			maxGeboorteDag = 30;
		} // if
	else if (geboorteMaand == 2) { // februari
		if (geboorteJaar % 4 == 0) { // schrikkeljaar, dus 29 dagen
			maxGeboorteDag = 29;
		} // if
		else {
			maxGeboorteDag = 28;
		} // else
	} // else if

	// De andere maanden zijn al 31 en hoeven niet aangepast te worden

	int geboorteDag = 0;

	cout << "Wat is je geboortedag? (1-";
	cout << maxGeboorteDag << ")" << endl << "> ";
	cin >> geboorteDag;

	if (geboorteDag <= 0 || geboorteDag > maxGeboorteDag){
		cout << "Dit is niet een dag die in die maand zit!" << endl;
		return 1;
	} // if

	int dagLeeftijd = huidigeDag - geboorteDag;

	if (dagLeeftijd < 0) {
		maandLeeftijd--;
		// Dagen hoeven niet uitgerekend te worden
		if (maandLeeftijd < 0){
			jaarLeeftijd--;
			maandLeeftijd += 12;
		} // if
	} // if

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10) {
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (jaarLeeftijd > 100) {
		cout << "Je bent te oud!" << endl;
		return 1;
	} // if

	// Leeftijd in jaren en maanden
	cout << "Je bent " << jaarLeeftijd << " jaar en " << maandLeeftijd
		 << " maanden; " << (maandLeeftijd+(jaarLeeftijd*12)) 
		 << " maanden oud." << endl;

	// Maandig / jarig check
	if (geboorteDag == huidigeDag) {
		if (geboorteMaand == huidigeMaand) {// Jarig
			cout << "Gefeliciteerd, je bent jarig!" << endl;
		} // if
		else {// Maandig
			cout << "Gefeliciteerd, je bent maandig!" << endl;
		} // if
	} // if

	bool gebruiker_oud = false; // Wordt gebruikt voor u / jij
		if (jaarLeeftijd >= 30) {
			gebruiker_oud = true;
		} // if


	int geboorteDagIndex = 0; // Dag van de week bij geboorte (0-6)

	// 1 januari 1901 is dinsdag
	int jaarVerschil = 0;
	int dagVerschil = 0;
	int schrikkelJaren = 0;

	jaarVerschil = geboorteJaar - 1901;
	schrikkelJaren = (jaarVerschil / 4);

	dagVerschil = schrikkelJaren * 366 + 
				  (jaarVerschil - schrikkelJaren) * 365 +
				  geboorteDag;

	// Toevoegen aantal dagen per volledige maand
	if (geboorteMaand > 1) dagVerschil += 31;
	if (geboorteMaand > 2) dagVerschil += 28;
	if (geboorteMaand > 3) dagVerschil += 31;
	if (geboorteMaand > 4) dagVerschil += 30;
	if (geboorteMaand > 5) dagVerschil += 31;
	if (geboorteMaand > 6) dagVerschil += 30;
	if (geboorteMaand > 7) dagVerschil += 31;
	if (geboorteMaand > 8) dagVerschil += 31;
	if (geboorteMaand > 9) dagVerschil += 30;
	if (geboorteMaand > 10) dagVerschil += 31;
	if (geboorteMaand > 11) dagVerschil += 30;

	if (geboorteJaar % 4 == 0 and geboorteMaand > 2) { // 29 feb
		dagVerschil++;
	} // if

	// Index 0 was op dinsdag, om maandag 0 te maken moet index dus +1
	// Deze +1 is al meegeteld bij het tellen van 1 januari
	// 03/01/1901 telt 1 januari mee, terwijl dit niet zou moeten
	geboorteDagIndex = (dagVerschil) % 7;

	// Input variabele
	char geboorteDagLetter = 'a';

	// Geboortedag letter input
	cout << "Wat is de eerste letter van ";

	// Aanspreekvorm
	if (gebruiker_oud) {
		cout << "uw";
	} // if
	else {
		cout << "jouw";
	} // else

	cout << " geboortedag? (bijv. m(aandag))";
	cout << endl << "> ";
	cin >> geboorteDagLetter;

	// 3 Mogelijkheden:

	// 1. Op een Maandag / Woensdag / Vrijdag
	if (
		(geboorteDagLetter == 'm' && geboorteDagIndex == 0) ||
		(geboorteDagLetter == 'w' && geboorteDagIndex == 2) ||
		(geboorteDagLetter == 'v' && geboorteDagIndex == 4)
		) {
		cout << "Dat is correct!" << endl;
	} // if


	// 2. Op een DInsdag / DOnderdag / ZAterdag / ZOndag
	else if (
			 (geboorteDagLetter == 'd' && 
			 (geboorteDagIndex == 1 || geboorteDagIndex == 3)) ||
			 (geboorteDagLetter == 'z' && 
			 (geboorteDagIndex == 5 || geboorteDagIndex == 6))
			) {

		char geboorteDagLetter2 = 'a';
		cout << "Wat is de tweede letter van deze dag?" << endl << 
				"> ";
		cin >> geboorteDagLetter2;

		if (geboorteDagLetter == 'd') { // DInsdag / DOnderdag
			if (
				(geboorteDagLetter2 == 'i' && geboorteDagIndex == 1) ||
				(geboorteDagLetter2 == 'o' && geboorteDagIndex == 3)
			   ) {
				cout << "Dat is correct!" << endl;
			} // if
			else {
				cout << "Dat is niet correct!" << endl;
				return 1;
			} // else
		} // if

		else { // ZAterdag / ZOndag
			if (
			    (geboorteDagLetter2 == 'a' && geboorteDagIndex == 5) ||
				(geboorteDagLetter2 == 'o' && geboorteDagIndex == 6)
			   ) {
				cout << "Dat is correct!" << endl;
			} // if
			else {
				cout << "Dat is niet correct!" << endl;
				return 1;
			} // else
		} // else
	} // else if

	// 3. Fout antwoord
	else { // Als het niet een van de letters van de week is,
		   // of de eerste letter niet klopt
		cout << "Dat is niet correct!" << endl;
		return 1;
	} // else



	////////
	// Rekensom
	////


	cout << endl << "Wat is het resultaat van deze som?" << endl;

	srand(dagVerschil);
	int num1 = (rand() % 90) + 10; // rand % 90 => 0-89, +10 => 10-99
	int num2 = (rand() % 90) + 10;

	if (num2 % 10 == 0) { // Kans lager dat addnum1 0 wordt
		int temp = 0;
		temp = num1;
		num1 = num2;
		num2 = temp;
	} // if

	int goede_resultaat = num1 * num2;
	int epsilon = goede_resultaat * 0.1;
	int boven_limiet = goede_resultaat + epsilon;
	int onder_limiet = goede_resultaat - epsilon;

	// Input variabele
	int gebruiker_gok = 0;

	// Begin van de som
	cout << "  " << num1 << endl;
	cout << "  " << num2 << " x" << endl;
	cout << "  --" << endl;
	
	// Reken de tweede som waarde uit. Die is % 10 == 0
	int addnum2 = num1 * (num2 / 10) * 10;
	int addnum1 = goede_resultaat - addnum2;

	// Inspringing grootste nummer
	if (addnum1 < 1000) cout << " ";
	if (addnum1 < 100)  cout << " ";
	if (addnum1 < 10)   cout << " ";
	cout << addnum1 << endl;

	// addnum2 kan niet kleiner zijn dan 100, 
	// Want 10 * 10 = 100 en num2 wordt dan 100 en num1 0
	if (addnum2 < 1000) { 
		cout << " ";
	} // if
	cout << addnum2 << " +" << endl;

	if (goede_resultaat < 1000) { // Check voor hoeveel "-" nodig zijn
		cout << " ---" << endl;
		cout << " "; // Spatie zodat het resultaat er mooi onder past
	} // if
	else {
		cout << "----" << endl;
	} // else
	cin >> gebruiker_gok;


	// Toegelaten tot beta studie
	if (gebruiker_gok >= onder_limiet && 
		gebruiker_gok <= boven_limiet) { // Goed antwoord
		
		// Aanspreekvorm
		if (gebruiker_oud) {
			cout << "U";
		} // if
		else {
			cout << "Je";
		} // else

		cout << " bent op een beta studie toegelaten!" << endl;
		return 0;
	} // if




	// Quiz
	else { // Fout antwoord
		// Onderscheid maken tussen vermenigvuldiging en quiz.
		cout << endl;
		cout << "Een kunst / literatuur opleiding past beter bij ";
		if (gebruiker_oud) { // Quiz oud
			cout << "u." << endl; // Aanspreekvorm

			cout << "Hoeveel pagina's heeft het gouden ei?";
			cout << "A: 69" << endl;
			cout << "B: 104" << endl;
			cout << "C: 117" << endl;
			cout << "D: 129" << endl;
			cout << "> ";
		} // if

		else { // Quiz jong
			cout << "jou." << endl; // Aanspreekvorm

			cout << "Wie is geen ninja turtle?" << endl;
			cout << "A: Donatello" << endl;
			cout << "B: Lorenzo" << endl;
			cout << "C: Raphael" << endl;
			cout << "D: Leonardo" << endl;
			cout << "> ";
		} // else
	} // else
	char gebruiker_antwoord = 'e';
	cin >> gebruiker_antwoord;

	// Antwoord check (a/A is goed)


	// Aanspreekvorm
	if (gebruiker_oud) { // Het antwoord begint zonder jij / u
		cout << "U ";
	} // if
	else {
		cout << "Jij ";
	} // else


	// Goed antwoord
	if (gebruiker_antwoord == 'b' || gebruiker_antwoord == 'B') {
		cout << "bent geschikt voor een kunst/" << 
				"literatuur studie op de universiteit!" << endl;
		return 0;
	} // if

	// Fout antwoord
	else {
		cout << "bent niet geschikt voor" <<
				"een universitaire opleiding :(" << endl;
		return 1;
	} // else
} // main