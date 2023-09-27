#include <iostream>
#include <fstream>
#include <string>
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

void modification()
{
    
}

int main()
{
    int reponse;
    while (true)
    {
        cout << "Que souhaitez vous faire?" << endl;
        cout << "1 = Creer un profil, 2 = modifier un profil, 3 = supprimer un profil, autre = fin" << endl;
        cin >> reponse;
        switch(reponse)
        {
            case 1 :
                creation();
                break;
            case 2 :
                //modification();
                break;
            case 3 :
                //suppresion();
                break;
            default :
                return 0;
                break;
        }
    }
}