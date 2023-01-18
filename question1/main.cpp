#include <iostream>
#include <cmath>

using namespace std;

void q1() {
	int valeur;
	cout << "entrez la valeur : ";
	cin >> valeur;
	if (valeur == 2) {
		cout << "ce nombre est premier \n";
	}
	else if (valeur %2==0) {
		cout << "ce nombre n est pas premier car il est divisible par " << "2" << "\n";
	} else {
		for (int i = 3; i <= sqrt(valeur); i += 2) {
			if (valeur % i == 0) {//
				cout << "ce nombre n est pas premier car il est divisible par " << i <<"\n";
				return;
			} 
		}
		cout << "ce nombre est premier \n";
	}


	
}

bool valider(double valeur,double min,double max) {
	if (valeur >= min && valeur <= max) {
		return true;
	}
	else {
		return false;
	}
}


void q2() {
	double sommeArgentEmprunte=-1;
	double montantRembourseParMois=-1;
	double tauxAnnuel=-1;

	while (!valider(sommeArgentEmprunte, 0, INFINITY)) {
		cout << "La somme d argent emprunte = ";
		cin >> sommeArgentEmprunte;

	}
	while (!valider(montantRembourseParMois, 0, INFINITY)) {
		cout << "montant rembourse chaque mois ";
		cin >> montantRembourseParMois;

	}
	while (!valider(tauxAnnuel, 0, 100)) {
		cout << "taux annuel ";//sachantque le taux mensuel --> tauxAnuel/12
		cin >> tauxAnnuel;

	}



	double tauxMensuel = tauxAnnuel / 12;
	
	double sommeInteret=0;
	int nbMois=0;
	while (sommeArgentEmprunte>=0.01) {
		double interet = sommeArgentEmprunte * tauxMensuel/100;
		sommeInteret += interet;
		sommeArgentEmprunte += interet - montantRembourseParMois;
		nbMois++; 
	}
	cout << "la somme d interet paye au total = " << sommeInteret << endl;
	cout << "vs allez paye le montant total avec interet en : " << nbMois << " mois \n";

}


void q3() {
	double hauteurInitiale = 0;
	int nbreDeRebonds = 0;
	double coefficientRebond=0;
	
	while (!valider(hauteurInitiale, 0, INFINITY)) {
		cout << " hauteur initiale : ";
		cin >> hauteurInitiale;

	}
	while (!valider(nbreDeRebonds, 0, INFINITY)) {
		cout << " nmbre de rebonds : ";
		cin >> nbreDeRebonds;

	}
	while (!valider(coefficientRebond, 0, 1)) {
		cout << "coefficient rebond : ";
		cin >> coefficientRebond;
	}


}






int main() {

	
	//q1();

	//q2();

	q3();


	return 0;
}