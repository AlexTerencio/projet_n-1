"""
Auteur : Alex Terencio
Date de création : 25/09/2023
Modifier :
Description : Ce code prendra les informations des utilisateurs et les ecrira dans un fichier texte

"""

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout << "Entrée votre nom est prenom" << endl;
    getline (cin,Nom_Prenom); 
    string const nomFichier("/Profils/"Nom_Prenom);
    ifstream monFlux(nomFichier.c_str());
    if(monFlux)
    {
        string user_entry
        cin >> user_entry;
        monFlux << user_entry << endl;
        string ligne;
        while(getline(monFlux,ligne))
        cout << ligne << endl; 
    }
    return 0;
}