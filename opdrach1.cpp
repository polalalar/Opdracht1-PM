#include <iostream>
#include <ctime>
using namespace std;

// Programma naam: 			Opdracht 1 - Programmeermethoden
// Gemaakt door: 			Jens van der Linden & Thijmen Roosenbrand
// Leerling nummers: 		s5205212 & s5225752
// Compiled met: 			g++ 13.3.0
// Versie: 					1.0
// Laatste wijziging op:	17-9-2026

int main()
{
	cout << "Dit programma is gemaakt door: Jens van der Linden & Thijmen Roosenbrand" << endl;
	cout << "Dit programma is voor Opdracht 1 van programeermethoden" << endl;
	cout << "Met dit programma kan je kijken of je geschikt bent voor een universitaire opleiding" << endl;

	// Datum variabelen
	int huidigeDag, huidigeMaand, huidigJaar = 0;

	// 2 hulpvariabelen voor de tijd
	tm s;
	time_t t;

	//huidige datum krijgen met behulp can ctime
	time (&t);
	s = * localtime (&t);
	huidigeDag = s.tm_mday;
	huidigeMaand = s.tm_mon + 1; // telt vanaf 0
	huidigJaar = s.tm_year + 1900; // telt vanaf 1900

	int geboorteJaar = 0;

	cout << "Wat is je geboortejaar? (xxxx)" << endl << "> ";
	cin >> geboorteJaar;

	int jaarLeeftijd = huidigJaar - geboorteJaar; //Kan dit blijven of 1 minder | iemand uit 2000 is 26 of 25 jaar oud nooit 27 of 24
	cout << jaarLeeftijd << endl;
	int maandLeeftijd = 0;
	int dagLeeftijd = 0;

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10){
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	}

	// Leeftijdcheck - ouder
	if (jaarLeeftijd > 101){
		cout << "Je bent te oud!" << endl;
		return 1;
	}

	int geboorteMaand = 0;

	cout << "Wat is je geboortemaand? (1-12)" << endl << "> ";
	cin >> geboorteMaand;

	//Check of de geboorte maand mogelijk is.
	if (geboorteMaand <= 0 or geboorteMaand >= 13) {
		cout << "Dit is geen valide maand!" << endl;
		return 1;
	}

	maandLeeftijd = huidigeMaand - geboorteMaand;
	//Stel het is nu 18-9-2026 en iemand is geboren op 18-10-2000
	// 9 - 10 = -1   < 0 dus:
	//Die is dan 26 -1 = 25 jaar oud en -1 +12 = 11 maanden
	if (maandLeeftijd < 0){
		jaarLeeftijd--;
		maandLeeftijd += 12;
	}

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10) {
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	}

	// Leeftijdcheck - ouder
	if (jaarLeeftijd > 101 || (jaarLeeftijd > 100 && geboorteMaand < huidigeMaand)) {
		cout << "Je bent te oud!" << endl;
		return 1;
	}
	

	// Maak een range voor de geboortedag (e.g. 1-31 of 30 of 28/29 in feb)
	int maxGeboorteDag = 31;

	if (
		geboorteMaand == 4 or // apr
		geboorteMaand == 6 or // jun
		geboorteMaand == 9 or // sept
		geboorteMaand == 11   // nov
		) {
			maxGeboorteDag = 30;
	} // if
	else if (geboorteMaand == 2) { // februari
		if (geboorteJaar % 4 == 0) { // schrikkeljaar, dus 29 dagen
			maxGeboorteDag = 29;
		}
		else {
			maxGeboorteDag = 28;
		}
	} // else if

	// De andere maanden zijn al 31 en hoeven niet aangepast te worden


	// Input variabele
	int geboorteDag = 0;

	// Geboortedag input
	cout << "Wat is je geboortedag? (1-" << maxGeboorteDag << ")" << endl << "> ";
	cin >> geboorteDag;

	if (geboorteDag <= 0 or geboorteDag > maxGeboorteDag){
		cout << "Dit is niet een dag die in die maand zit!" << endl;
		return 1;
	}

	dagLeeftijd = huidigeDag - geboorteDag;
	if (dagLeeftijd < 0){
		maandLeeftijd--;
		//Er hoeft geen check gemaakt te worden om te kijken hoeveel dagen er dan overblijven. 
		//Omdat daar toch niks mee wordt gedaan :D.

		//Er is alleen wel een check nodig voor als de maand leeftijd kleiner dan 0 wordt.
		if (maandLeeftijd < 0){
			jaarLeeftijd--;
			maandLeeftijd += 12;
		}
	}

	// Leeftijdcheck - jonger
	if (jaarLeeftijd < 10) {
		cout << "Je bent niet oud genoeg!" << endl;
		return 1;
	}

	// Leeftijdcheck - ouder
	if (jaarLeeftijd > 100) {
		cout << "Je bent te oud!" << endl;
		return 1;
	}

	// Display leeftijd in jaren en maanden
	cout << "Je bent " << jaarLeeftijd << " jaar en " << maandLeeftijd << " maanden; "
	<< (maandLeeftijd+(jaarLeeftijd*12)) << " maanden oud." << endl;

	// Maandig (& jarig) check
	if (geboorteDag == huidigeDag) {

		// Jarig check
		if (geboorteMaand == huidigeMaand) {
			cout << "Gefeliciteerd, je bent jarig!" << endl;
		} // if

		else {
			cout << "Gefeliciteerd, je bent maandig!" << endl;
		} // else
	} // if



	////////
	// Check dag van de week bij geboorte
	////

	// Variabelen voor geboortedag index
	int geboorteDagIndex = 0;

	// Bereken dag van de week bij geboorte (0-6)

	// 1 januari 1901 is Dinsdag
	int jaarVerschil = 0;
	int dagVerschil = 0;
	int schrikkelJaren = 0;

	jaarVerschil = geboorteJaar - 1901;
	schrikkelJaren = (jaarVerschil / 4);

	dagVerschil = schrikkelJaren * 366 + 
				  (jaarVerschil - schrikkelJaren) * 365 +
				  geboorteDag;
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

	if (geboorteJaar % 4 == 0 and geboorteMaand > 2) { // 29 feb meetellen
		dagVerschil++;
	}

	geboorteDagIndex = (dagVerschil) % 7; 
	// +1, want de telling (01/01/1901) start op dinsdag

	cout << geboorteDagIndex << endl;



	//Input variabele
	char geboorteDagLetter = 'a';
	// Geboortedag letter input
	cout << "Op welke dag van de week ben je geboren?" << 
			" (alleen de eerste letter)" << endl << "> ";
	cin >> geboorteDagLetter;

	// Note: split up days for readability
	//  - both for m/w/v as for di/do/za/zo

	// dag = m/w/v & dag klopt met berekende dag
	if	(geboorteDagLetter == 'm' && geboorteDagIndex == 0) {
		cout << "abc" << endl;
	}
	else if (geboorteDagLetter == 'w' && geboorteDagIndex == 2) {
		cout << "abcd" << endl;
	}
	else if (geboorteDagLetter == 'v' && geboorteDagIndex == 4) {
		cout << "abcdef" << endl;
	}

	// dag = di/do/za/zo
	else if (geboorteDagLetter == 'd' && 
			(geboorteDagIndex == 1 or geboorteDagIndex == 3)) {

		char geboorteDagLetter2;
		cout << "Wat is de tweede letter van deze dag?" << endl
		<< "> " << endl;
		cin >> geboorteDagLetter2;
		
		if (geboorteDagLetter2 == 'i' && geboorteDagIndex == 1) {
			cout << "test1" << endl;
		}
		else if (geboorteDagLetter2 == 'o' && geboorteDagIndex == 3) {
			cout << "test2" << endl;
		}
	}

	else if (geboorteDagLetter == 'z' &&
			(geboorteDagIndex == 5 or geboorteDagIndex == 6)) {

		char geboorteDagLetter2;
		cout << "Wat is de tweede letter van deze dag?" << endl
		<< "> " << endl;
		cin >> geboorteDagLetter2;
		

		if (geboorteDagLetter2 == 'a' && geboorteDagIndex == 5) {
			cout << "test3" << endl;
		}
		else  if (geboorteDagLetter2 == 'o' && geboorteDagIndex == 6) {
			cout << "test4" << endl;
		}
		else {
			return 1;
		}
	}
	
	// Invalide/incorrecte dag van de week
	else {
		cout << "Dit is niet de dag waarop je geboren bent!"
			 << "(of geen valide dag)"
		 	 << endl;
		return 1;
	}
	

	srand(dagVerschil);
	int num1 = (rand() % 90) + 10; // rand % 90 is 0 to 89, +10 --> 10 to 99
	int num2 = (rand() % 90) + 10;
	if (num2 % 10 == 0){//Door ze om te wisslen wordt de kans lager dat het bovenste getal 0 wordt.
		int temp = 0;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int correct_result = num1 * num2;
	int epsilon = correct_result * 0.1;
	int upper_bound = correct_result + epsilon;
	int lower_bound = correct_result - epsilon;

	int user_guess;
	//Begin stuk van de som
	cout << "  " << num1 << endl;
	cout << "  " << num2 << " X" << endl;
	cout << "  --" << endl;
	
	//reken de tweede + waarde uit. Die is % 10 == 0
	int addnum2 = num1 * (num2 / 10);
	addnum2 *= 10;
	int addnum1 = correct_result - addnum2;
	//addnum1 kan 0,21,521 ect zijn dus daarvoor moet hij kunnen inspringen
	if (addnum1 < 1000){ cout << " "; }
	if (addnum1 < 100){ cout << " "; }
	if (addnum1 < 10){ cout << " "; }
	cout << addnum1 << endl;
	//addnum2 kan niet kleiner zijn dan 100, want 10 * 10 = 100 en num2 wordt dan 100 en num1 0
	if (addnum2 < 1000){ cout << " "; }
	cout << addnum2 << " +" << endl;

	if (correct_result < 1000){//for how ---- are needed
		cout << " ---" << endl;
		cout << " "; //space so the user can fill in the 3 digit cleanly
	}
	else{
		cout << "----" << endl;
	}
	cin >> user_guess;


	bool user_oud = false;//Wordt gebruikt voor u / jij
	if (jaarLeeftijd >= 30){
		user_oud = true;
	}

	if(user_guess >= lower_bound && user_guess <= upper_bound){//Goed geraden
		cout << "Je bent op een exacte studie toegelaten!" << endl;
		return 0;
	}
	else{//Niet goed geraden
		cout << "Een kunst / literatuur opleiding past beter bij ";
		if (user_oud){
			cout << "u" << endl;

			cout << "Wie van de Beatles deelt een naam met meneer Boole?" << endl;
			cout << "A: George Harrison" << endl;
			cout << "B: John Lennon " << endl;
			cout << "C: Ringo Starr" << endl;
			cout << "D: Paul McCartney" << endl;
			cout << "> ";
		}
		else{
			cout << "jou" << endl;

			cout << "Welke letter is geen programeer taal?" << endl;
			cout << "A: A" << endl;
			cout << "B: B" << endl;
			cout << "C: C" << endl;
			cout << "D: D" << endl;
			cout << "> ";
		}
	}
	char answer = 'a';
	cin >> answer;

	if (user_oud){//Het antwoord begint zonder persoonlijk voornaamwoord
		cout << "U ";
	}else{
		cout << "Jij ";
	}
	if (answer == 'a' or answer == 'A'){//A is het goede antwoord + edge case van a
		cout << "bent geschikt voor een kunst / literatuur studie op de universiteit!" << endl;
		return 0;
	}
	else{
		cout << "bent niet geschikt voor een universitaire studie :(" << endl;
		return 1;
	}
	return 0;
} //main
