#include <iostream>
#include <ctime>
using namespace std;

// Programma naam: Opdracht 1 - Programmeermethoden
// Gemaakt door: Jens van der Linden & Thijmen Rosenbrand
// Leerling nummers: s5205212 & s5225752
// Compiled met: g++ 13.3.0
// Versie: 1.0
// Laatste wijziging op: 18-9-2026

int main()
{
	cout << "Gemaakt door: Jens van der Linden & Thijmen Rosenbrand" << endl;
	cout << "Gemaakt voor opdracht 1 van programeermethoden" << endl;
	cout << "Met dit programma kan je kijken of je geschikt ";
	cout << "bent voor een universitaire opleiding" << endl;

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

	int jaarLeeftijd = huidigJaar - geboorteJaar; //Kan dit blijven of 1 minder
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
	if (geboorteMaand <= 0 || geboorteMaand >= 13) {
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
	if (jaarLeeftijd > 101 || (jaarLeeftijd > 100 && 
		geboorteMaand < huidigeMaand)) {
		cout << "Je bent te oud!" << endl;
		return 1;
	}

	// Maak een range voor de geboortedag (e.g. 1-31 of 30 of 28/29 in feb)
	int maxGeboorteDag = 31;

	if (geboorteMaand == 4 || // apr
		geboorteMaand == 6 || // jun
		geboorteMaand == 9 || // sept
		geboorteMaand == 11)  // nov
		{
			maxGeboorteDag = 30;
		}
	else if (geboorteMaand == 2) { // februari
		if (geboorteJaar % 4 == 0) { // schrikkeljaar, dus 29 dagen
			maxGeboorteDag = 29;
		}
		else {
			maxGeboorteDag = 28;
		}
	}
	// De andere maanden zijn al 31 en hoeven niet aangepast te worden

	int geboorteDag = 0;

	cout << "Wat is je geboortedag? (1-";
	cout << maxGeboorteDag << ")" << endl << "> ";
	cin >> geboorteDag;

	if (geboorteDag <= 0 || geboorteDag > maxGeboorteDag){
		cout << "Dit is niet een dag die in die maand zit!" << endl;
		return 1;
	}

	dagLeeftijd = huidigeDag - geboorteDag;
	if (dagLeeftijd < 0){
		maandLeeftijd--;
		//Dagen hoeven niet uitgerekend te worden!
		//Omdat daar toch niks mee wordt gedaan :D.
		//Alleen een check voor de maand.
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

	//leeftijd in jaren en maanden
	cout << "Je bent " << jaarLeeftijd << " jaar en ";
	cout << maandLeeftijd << " maanden; ";
	cout << (maandLeeftijd+(jaarLeeftijd*12)) << " maanden oud." << endl;

	// Maandig / jarig check
	if (geboorteDag == huidigeDag) {
		if (geboorteMaand == huidigeMaand) {//Jarig
			cout << "Gefeliciteerd, je bent jarig!" << endl;
		}
		else {//Maandig
			cout << "Gefeliciteerd, je bent maandig!" << endl;
		}
	}

	int geboorteDagIndex = 0;// Bereken dag van de week bij geboorte (0-6)

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

	//Input variabele
	char geboorteDagLetter = 'a';
	// Geboortedag letter input
	cout << "Op welke dag van de week ben je geboren?"; 
	cout << " (alleen de eerste letter (kleine letter))";
	cout << endl << "> ";
	cin >> geboorteDagLetter;

	//2 mogelijkheden:

	//1. op een Maandag / Woensdag / Vrijdag
	if ((geboorteDagLetter == 'm' && geboorteDagIndex == 0) ||
		(geboorteDagLetter == 'w' && geboorteDagIndex == 2) ||
		(geboorteDagLetter == 'v' && geboorteDagIndex == 4)
		){
		cout << "Dat is correct!" << endl;
	}
	//2. op een DInsdag / DOnderdag / ZAterdag / ZOndag
	else if((geboorteDagLetter == 'd' && 
		(geboorteDagIndex == 1 || geboorteDagIndex == 3)) ||
		(geboorteDagLetter == 'z' && 
		(geboorteDagIndex == 5 || geboorteDagIndex == 6))
		){
		char geboorteDagLetter2 = 'a';
		cout << "Wat is de tweede letter van deze dag?" << endl << "> ";
		cin >> geboorteDagLetter2;

		if (geboorteDagLetter == 'd'){//DInsdag / DOnderdag
			if ((geboorteDagLetter2 == 'i' && geboorteDagIndex == 1) ||
				(geboorteDagLetter2 == 'o' && geboorteDagIndex == 3)
				){
				cout << "Dat is correct!" << endl;
			}
			else{
				cout << "Dat is niet correct!" << endl;
				return 1;
			}
		}
		else{//ZAterdag / ZOndag
			if ((geboorteDagLetter2 == 'a' && geboorteDagIndex == 5) ||
				(geboorteDagLetter2 == 'o' && geboorteDagIndex == 6)
				){
				cout << "Dat is correct!" << endl;
			}
			else{
				cout << "Dat is niet correct!" << endl;
				return 1;
			}
		}
	}
	else{//Als het niet een van de letters van de week is
		cout << "Dat is niet correct!" << endl;
		return 1;
	}

	srand(dagVerschil);
	int num1 = (rand() % 90) + 10; // rand % 90 is 0 to 89, +10 --> 10 to 99
	int num2 = (rand() % 90) + 10;
	if (num2 % 10 == 0){//Kans lager dat addnum1 0 wordt
		int temp = 0;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int goede_resultaat = num1 * num2;
	int epsilon = goede_resultaat * 0.1;
	int boven_limiet = goede_resultaat + epsilon;
	int onder_limiet = goede_resultaat - epsilon;

	int gebruiker_gok;
	//Begin stuk van de som
	cout << "  " << num1 << endl;
	cout << "  " << num2 << " X" << endl;
	cout << "  --" << endl;
	
	//reken de tweede + waarde uit. Die is % 10 == 0
	int addnum2 = num1 * (num2 / 10);
	addnum2 *= 10;
	int addnum1 = goede_resultaat - addnum2;
	//addnum1 kan 0,21,521 ect zijn dus daarvoor moet hij kunnen inspringen
	if (addnum1 < 1000){ cout << " "; }
	if (addnum1 < 100){ cout << " "; }
	if (addnum1 < 10){ cout << " "; }
	cout << addnum1 << endl;
	//addnum2 kan niet kleiner zijn dan 100, 
	//Want 10 * 10 = 100 en num2 wordt dan 100 en num1 0
	if (addnum2 < 1000){ cout << " "; }
	cout << addnum2 << " +" << endl;

	if (goede_resultaat < 1000){//Check voor hoeveel - nodig zijn
		cout << " ---" << endl;
		cout << " "; //spatie zodat het resultaat er netjes onder past
	}
	else{
		cout << "----" << endl;
	}
	cin >> gebruiker_gok;

	bool gebruiker_oud = false;//Wordt gebruikt voor u / jij
	if (jaarLeeftijd >= 30){
		gebruiker_oud = true;
	}

	if(gebruiker_gok >= onder_limiet && 
		gebruiker_gok <= boven_limiet){//Goed geraden
		cout << "Je bent op een exacte studie toegelaten!" << endl;
		return 0;
	}
	else{//Niet goed geraden
		cout << "Een kunst / literatuur opleiding past beter bij ";
		if (gebruiker_oud){//Quiz oud
			cout << "u" << endl;

			cout << "Wie van de Beatles deelt";
			cout << "een naam met meneer Boole?" << endl;
			cout << "A: George Harrison" << endl;
			cout << "B: John Lennon " << endl;
			cout << "C: Ringo Starr" << endl;
			cout << "D: Paul McCartney" << endl;
			cout << "> ";
		}
		else{//Quiz jong
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

	if (gebruiker_oud){//Het antwoord begint zonder jij / u
		cout << "U ";
	}else{
		cout << "Jij ";
	}
	if (answer == 'a' || answer == 'A'){// a/A is goed
		cout << "bent geschikt voor een kunst /";
		cout << "literatuur studie op de universiteit!" << endl;
		return 0;
	}
	else{
		cout << "bent niet geschikt voor";
		cout << "een universitaire studie :(" << endl;
		return 1;
	}
}