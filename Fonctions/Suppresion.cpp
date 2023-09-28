//Auteur : Alex Terencio
//Date de création : 25/09/2023
//Modifier : 28/09/2023
//Description : Fonction de suppresion de profil

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


void suppresion()
{
    string NomFichier;
    bool reponse;
    using recursive_directory_iterator = filesystem::recursive_directory_iterator;

    // Liste les fichiers dans le répertoire
    for (const auto& dirEntry : recursive_directory_iterator("C:/Users/alext/projects/projet_n-1/Profils"))
        cout << dirEntry << endl;

    cout << "Quel profil voulez-vous supprimer?" << endl;
    cin.ignore(1, '\n');
    getline(cin, NomFichier);

    string CheminFichier = "C:/Users/alext/projects/projet_n-1/Profils/" + NomFichier + ".txt";
    cout << "Le profil selectionné est celui de " << NomFichier << "." << endl;
    cout << "Etes vous sure de vouloir le supprimer?" << endl;
    cout << "Ce changement sera irreversible." << endl;
    cout << "1 = Supprimer, 0 = annule" << endl;
    cin >> reponse;
    if (reponse)
    {
        if (std::remove(CheminFichier.c_str()) == 1) // Suppression du fichier
        {
            std::cout << "Profil supprime." << std::endl;
        }
        else
        {
            std::cerr << "Erreur lors de la suppression du profil." << std::endl;
        }
    }
    else
    {
        std::cout << "Suppression annulee ou echouee." << std::endl;
    }
}