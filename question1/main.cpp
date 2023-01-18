#include <cmath>
#include <iostream>

using namespace std;

bool valider(double, double, double);

void q1()
{
    int valeur = 0;

    do {
        cout << "Entrer un nombre entier : ";
        cin >> valeur;
    } while (!valider(valeur, 0, INFINITY));

    if (valeur == 2) {
        cout << "Ce nombre est premier.\n";
    }
    else if (valeur % 2 == 0) {
        cout << "Ce nombre n'est pas premier car il est divisible par 2.\n";
    }
    else {
        for (int i = 3; i <= sqrt(valeur); i += 2) {
            if (valeur % i == 0) {
                cout << "Ce nombre n'est pas premier car il est divisible par "
                     << i << ".\n";
                return;
            }
        }
        cout << "Ce nombre est premier.\n";
    }
}

void q2()
{
    double sommeArgentEmprunte     = -1;
    double montantRembourseParMois = -1;
    double tauxAnnuel              = -1;

    while (!valider(sommeArgentEmprunte, 0.0, INFINITY)) {
        cout << "Entrer la somme d'argent empruntée : ";
        cin >> sommeArgentEmprunte;
    }
    while (!valider(montantRembourseParMois, 0.0, INFINITY)) {
        cout << "Entrer le montant remboursé chaque mois : ";
        cin >> montantRembourseParMois;
    }
    while (!valider(tauxAnnuel, 0.0, 100.0)) {
        cout << "Entrer le taux d'intérêt annuel : ";
        cin >> tauxAnnuel;
    }

    double tauxMensuel = tauxAnnuel / 12;

    double sommeInteret = 0;
    int    nMois       = 0;
    while (sommeArgentEmprunte >= 0.01) {
        double interet = sommeArgentEmprunte * tauxMensuel / 100;

        sommeInteret += interet;
        sommeArgentEmprunte += interet - montantRembourseParMois;

        nMois++;
    }
    cout << "la somme d'intérêts payés au total : " << sommeInteret << '\n'
         << "vous allez payer le montant total avec interet en " << nMois
         << " mois \n";
}

void q3()
{
    double hauteurInitiale   = 0;
    int    nbreDeRebonds     = 0;
    double coefficientRebond = 0;

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

int main()
{
    q1();

    q2();

    q3();

    return 0;
}

bool valider(double valeur, double min, double max)
{
    if (valeur >= min && valeur <= max) {
        return true;
    }
    else {
        return false;
    }
}
