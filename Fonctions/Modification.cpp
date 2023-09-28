//Auteur : Alex Terencio
//Date de création : 25/09/2023
//Modifier : 28/09/2023
//Description : Fonction de Modification de profil

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


void modification() {
    string NomFichier, NouveauNom;
    using recursive_directory_iterator = filesystem::recursive_directory_iterator;

    // Liste les fichiers dans le répertoire
    for (const auto& dirEntry : recursive_directory_iterator("C:/Users/alext/projects/projet_n-1/Profils"))
        cout << dirEntry << endl;

    cout << "Quel profil voulez-vous modifier?" << endl;
    cin.ignore(1, '\n');
    getline(cin, NomFichier);

    string CheminFichier = "C:/Users/alext/projects/projet_n-1/Profils/" + NomFichier + ".txt";

    ifstream FluxLecture(CheminFichier);
    string AncienContenu;

    if (FluxLecture.is_open()) {
        // Lire l'ancien contenu du fichier
        string ligne;
        while (getline(FluxLecture, ligne)) {
            AncienContenu += ligne + "\n";
        }
        FluxLecture.close();

        // L'utilisateur renseigne son nouveau nom et prénom
        string Nom_Prenom;
        cout << "Entrez votre nouveau nom et prenom:" << endl;
        getline(cin, Nom_Prenom);

        // Construire le nouveau nom de fichier avec Nom_Prenom
        NouveauNom = "C:/Users/alext/projects/projet_n-1/Profils/" + Nom_Prenom + ".txt";

        // Écriture des nouvelles données dans le fichier texte
        ofstream monFlux(NouveauNom);
        if (monFlux) {
            monFlux << "Nom et Prenom: " << Nom_Prenom << endl;

            // L'utilisateur renseigne sa date de naissance
            int birthday, birthmonth, birthyear, Age;
            cout << "Entrez votre nouvelle Date de naissance dans cet ordre jour/mois/annee" << endl;
            cout << "Entrez le Jour:" << endl;
            cin >> birthday;
            cout << "Entrez le Mois:" << endl;
            cin >> birthmonth;
            cout << "Entrez l'Annee:" << endl;
            cin >> birthyear;

            // Calcul de l'âge
            Age = 2023 - birthyear;

            monFlux << "Né le: " << birthday << "/" << birthmonth << "/" << birthyear << endl;
            monFlux << "Age: " << Age << endl;

            cout << "Profil modifié avec succès." << endl;
        } else {
            cerr << "Erreur lors de l'ouverture du fichier pour écriture." << endl;
        }
    } else {
        cerr << "Erreur : Fichier introuvable." << endl;
    }

    // Supprimer l'ancien fichier
    if (remove(CheminFichier.c_str()) != 0) {
        cerr << "Erreur lors de la suppression de l'ancien fichier." << endl;
    }
}