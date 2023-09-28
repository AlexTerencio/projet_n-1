//Auteur : Alex Terencio
//Date de création : 25/09/2023
//Modifier : 28/09/2023
//Description : Fonction de création de profil

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


void creation()
{
// L'utilisateur renseigne sont nom et prenom
    string Nom_Prenom;
    cout << "Entree votre nom et prenom:" << endl;
    cin.ignore(1, '\n');
    getline(cin,Nom_Prenom); 
    string NomFichier("C:/Users/alext/projects/projet_n-1/Profils/"); 
    NomFichier = NomFichier + Nom_Prenom + ".txt";
    ofstream monFlux(NomFichier.c_str());
    if(monFlux)
    {
        monFlux << "Nom et Prenom: " << Nom_Prenom << endl;
    }

// L'utilisateur renseigne sa date de naissance
    int birthday, birthmonth, birthyear, Age;
    cout << "Entree votre Date de naissance dans cette ordre jours/mois/annees" << endl;
    cout << "Entre le Jour:" << endl;
    cin >> birthday;
    cout << "Entre le Mois:" << endl;
    cin >> birthmonth;
    cout << "Entre l'Annee:" << endl;
    cin >> birthyear;

// Calcul Age
    Age = 2023 - birthyear;

// Ecriture de tout dans le fichier texte
    if(monFlux)
    {
        monFlux << "né le: " << birthday << "/" << birthmonth << "/" << birthyear << endl;
        monFlux << "Age: " << Age << endl;
    }
    cout << "Profil creer avec succes." << endl;
    monFlux.close();
}

