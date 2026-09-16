#include <iostream>
#include <ctime>
using namespace std;


// Note: add information for other programmers/graders
//  - e.g. used compiler
//  - at start of run, display creators
//   - creators: year of start study, study, student number, name
//   - code: assignment #, general info about program, date of creation
//   - may be a little fancy but nothing extreme (only ASCII)



// Opdracht 1 - Programmeermethoden
// Jens van der Linden & Thymen Roosenbrand
// s5205212 & s5225752
// Compiled with: g++ 13.3.0



int main()
{
	////////
	// Infoblok ofzo
	////



	////////
	// Huidige datum
	////

	// Note: split lines
	// Datum variabelen aanmaken
	int huidigeDag, huidigeMaand, huidigJaar = 0;

	// 2 hulpvariabelen maken
	tm s;
	time_t t;

	// Datum variabelen updaten met huidige datum
	time (&t);
	s = * localtime (&t);
	huidigeDag = s.tm_mday;
	huidigeMaand = s.tm_mon + 1; // telt vanaf 0
	huidigJaar = s.tm_year + 1900; // telt vanaf 1900

	

	////////
	// Leeftijd check
	////


	// Note: add checks for invalid input (e.g. year 4242 or month -8)
	//  - years: future, 0 < month < 13
	//  - check before age checks to ensure right error message




	// Input variabele
	int geboorteJaar = 0;

	// Jaar input
	cout << "Wat is je geboortejaar? (xxxx)" << endl << "> ";
	cin >> geboorteJaar;

	if (geboorteJaar > huidigJaar){
		cout << "\033[31mJe bent nog niet geboren!\033[0m" << endl;
		return 1;
	}
	// Leeftijdcheck - jonger
	if (huidigJaar - geboorteJaar < 10) {
		cout << "\033[31mJe bent niet oud genoeg!\033[0m" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (huidigJaar - geboorteJaar > 100) {
		cout << "\033[31mJe bent te oud!\033[0m" << endl;
		return 2;
	} // if


	// Input variabele
	int geboorteMaand = 0;

	// Geboortemaand input
	cout << "Wat is je geboortemaand? (1-12)" << endl << "> ";
	cin >> geboorteMaand;

	// Leeftijdcheck - jonger
	if (huidigJaar - geboorteJaar == 10 and 
	    geboorteMaand > huidigeMaand) {
		cout << "\033[31mJe bent niet oud genoeg!\033[0m" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (huidigJaar - geboorteJaar == 100 and 
	    geboorteMaand < huidigeMaand) {
		cout << "\033[31mJe bent te oud!\033[0m" << endl;
		return 2;
	} // if
	

	// Input variabele
	int geboorteDag = 0;

	int maxGeboorteDag = 31;
	if (geboorteMaand == 2){//feb
		maxGeboorteDag = 28;
		if (geboorteJaar % 4 == 0){//schrikkeljaar
			maxGeboorteDag++;
		}
	}
	else{
		//Maanden met 31 dagen: jan(1),maart(3),mei(5),juli(7),augustus(8) okotober (10) december(12)
		//Maanden groter dan 7.5 zijn even
		int maandGetal = geboorteMaand;
		if (maandGetal > 7){//Maakt augustus 8->9
			maandGetal++;
		}
		if (maandGetal % 2 == 0) {//even = 30 dagen
			maxGeboorteDag = 30;
		}
	}

	// Geboortedag input
	cout << "Wat is je geboortedag? (1-" << maxGeboorteDag << ")" << endl << "> ";
	cin >> geboorteDag;

	

	// Leeftijdcheck - jonger
	if (huidigJaar - geboorteJaar == 10 and 
	    geboorteMaand == huidigeMaand and
	    geboorteDag > huidigeDag) {
		cout << "\033[31mJe bent niet oud genoeg!\033[0m" << endl;
		return 1;
	} // if

	// Leeftijdcheck - ouder
	if (huidigJaar - geboorteJaar == 100 and 
	    geboorteMaand == huidigeMaand and
	    geboorteDag <= huidigeDag) {
		cout << "\033[31mJe bent te oud!\033[0m" << endl;
		return 2;
	} // if
	//Check of datum valid is
	if (geboorteDag < 0){
		cout << "\033[31mNiet een dag in 1-"<< maxGeboorteDag << "\033[0m" << endl;
		return 3;
	}
	
	if (geboorteDag > maxGeboorteDag){
		cout << "\033[31mNiet een dag in 1-" << maxGeboorteDag << "\033[0m" << endl;
		return 3;
	}

	////////
	// Leeftijd in jaren/maanden
	////



	// Bereken leeftijd in jaren en maanden
	int maandLeeftijd = (huidigJaar - geboorteJaar) * 12
		+ (huidigeMaand - geboorteMaand)
		+ (huidigeDag <= geboorteDag) - 1;
		// Check of een volledige maand in dagen al voorbij is
		// Een boolean wordt hier gezien als een integer door de code
	int jaarLeeftijd = maandLeeftijd / 12;

	// Display leeftijd in jaren en maanden
	cout << "Je bent " << 
			jaarLeeftijd << " jaar en " <<
			(maandLeeftijd-jaarLeeftijd*12) << " maanden; " <<
			maandLeeftijd << " maanden oud." << endl;



	////////
	// Jarig/maandig?
	////



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
	schrikkelJaren = jaarVerschil / 4;

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

	if (geboorteJaar % 4 == 0 and geboorteMaand >= 3) {//Zodat 29 feb ook meetelt als een dag
		dagVerschil++;
	}

	geboorteDagIndex = (dagVerschil + 1) % 7; // + 1 om start op dinsdag te hebben, want 1901 1jan is op een dinsdag

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
			return 3;
		}
	}
	
	// Invalide/incorrecte dag van de week
	else {
		cout << "\033[31mDit is niet de dag waarop je geboren bent!"
			 << "(of geen valide dag)\033[0m"
		 	 << endl;
		return 3;
	}


*/
	//////
	// De "echte test"
	//  - Want wie weet zn geboortedag vd week nou niet???
	//


	// Note: mogen variabelen wel als string??
	//  - Letters moeten worden ingelezen als char (en niet str)
	/*
	if (jaarLeeftijd >= 30) {
		persoonlijkVNW = "u"
		bezittelijkVNW = "uw"
	}
	else {
		persoonlijkVNW = "jij"
		bezittelijkVNW = "jouw"
	}
	
	srand(0);
	int num1 = (rand() % 90) + 10; // rand % 90 is 0 to 89, +10 --> 10 to 99
	int num2 = (rand() % 90) + 10;
	num1 = 42;
	num2 = 17;

	int correct_result = num1 * num2;
	int epsilon = correct_result * 0.1;
	int upper_bound = correct_result + epsilon;
	int lower_bound = correct_result - epsilon;

	int user_guess;
	cout << "What is " << num1 << " x " << num2 << "?" << endl << ">";
	cin >> user_guess;

	if (user_guess == correct_result){
		cout << "Perfect!" << endl;
	}
	else if(user_guess >= lower_bound && user_guess <= upper_bound){
		cout << "Correct!" << endl;
	}
	else{
		cout << "FALSE" << endl;
	}
	return 0;
} //main
