#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

static const int TAILLE = 10;

bool               valider(double, double, double);
array<int, TAILLE> trierTableau(array<int, TAILLE>);
void               afficherTableau(array<int, TAILLE>);

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
    int    nMois        = 0;
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
    int    nRebonds          = 0;
    double coefficientRebond = 0;

    static const double constanteGravité = 9.81;

    do {
        cout << "Entrer la hauteur initiale : ";
        cin >> hauteurInitiale;
    } while (!valider(hauteurInitiale, 0.0, INFINITY));
    do {
        cout << "Entrer le nombre de rebonds : ";
        cin >> nRebonds;
    } while (!valider(nRebonds, 0, INFINITY));
    do {
        cout << "Entrer le coefficient de rebond : ";
        cin >> coefficientRebond;
    } while (!valider(coefficientRebond, 0.0, 1.1));

    double hauteurActuelle = hauteurInitiale;

    for (int i = 0; i < nRebonds; i++) {
        double vitesseInitiale = sqrt(2 * constanteGravité * hauteurActuelle);
        double vitesseActuelle = coefficientRebond * vitesseInitiale;
        hauteurActuelle = pow(vitesseActuelle, 2.0) / (2 * constanteGravité);
    }

    cout << "Hauteur de la balle après " << nRebonds
         << " rebonds : " << hauteurActuelle << ".\n";
}

void q4()
{
    default_random_engine             aléatoire(random_device{}());
    uniform_real_distribution<double> distribution(-1.0, 1.0);

    int nIterations = 0;
    do {
        cout << "Entrer le nombre d'itérations: ";
        cin >> nIterations;
    } while (!valider(nIterations, 0, INFINITY));

    int nDansCercle = 0;

    for (int i = 0; i < nIterations; i++) {
        const double x = distribution(aléatoire);
        const double y = distribution(aléatoire);

        if (x * x + y * y < 1.0) {
            nDansCercle++;
        }
    }

    const double        piCalculé = 4.0 * nDansCercle / nIterations;
    static const double piRéel    = 3.141593;

    cout << "Valeur de pi calculée: " << fixed << setprecision(6) << piCalculé
         << '\n'
         << "Écart relatif avec la valeur réelle de pi: " << fixed
         << setprecision(6) << fabs(piCalculé - piRéel) << '\n';
}

void q5()
{
    array<int, TAILLE> tableau = {};

    cout << "Entrer les éléments du tableau.\n";
    for (int i = 0; i < TAILLE; i++) {
        cout << "Élément " << i + 1 << ": ";
        cin >> tableau[i];
    }

    array<int, TAILLE> tableauTrié = trierTableau(tableau);

    cout << "Tableau résultant: ";
    afficherTableau(tableauTrié);
}

void q6()
{
}

int main()
{
    // q1();

    // q2();

    // q3();

    // q4();

    q5();

    // q6();

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

array<int, TAILLE> trierTableau(array<int, TAILLE> tableau)
{
    array<int, TAILLE> tableauTrié = {};
    int                nTriés      = 0;

    for (int i = 0; i < TAILLE; i++) {
        if (tableau[i] % 2 == 0) {
            tableauTrié[nTriés++] = tableau[i];
        }
    }
    for (int i = 0; i < TAILLE; i++) {
        if (tableau[i] % 2 != 0) {
            tableauTrié[nTriés++] = tableau[i];
        }
    }

    return tableauTrié;
}

void afficherTableau(array<int, TAILLE> tableau)
{
    cout << '{';

    for (int i = 0; i < TAILLE; i++) {
        cout << tableau[i];

        if (i != TAILLE - 1) {
            cout << ", ";
        }
    }

    cout << "}\n";
}