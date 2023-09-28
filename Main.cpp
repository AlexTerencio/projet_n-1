//Auteur : Alex Terencio
//Date de création : 25/09/2023
//Modifier : 28/09/2023
//Description : Code principale fesant appeler a toute les fonctions et etant le menu de navigation utilisateur

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <C:\Users\alext\projects\projet_n-1\Fonctions\fonctions.h>

using namespace std;

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
                modification();
                break;
            case 3 :
                suppresion();
                break;
            default :
                return 0;
                break;
        }
    }
}