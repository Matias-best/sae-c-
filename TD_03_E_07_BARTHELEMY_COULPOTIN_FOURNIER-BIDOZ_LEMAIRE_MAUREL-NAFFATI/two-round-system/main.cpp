#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;

const unsigned NB_CANDIDATS = 5; // Déclare et initialise la constante NB_CANDIDATS
const unsigned NB_ELECTEURS = 5; // Déclare et initialise la constante NB_ELECTEURS

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

template<typename T> // Pour rendre la fonction générique, sans type pour les utiliser avec les unsigned et les strings
T supprimerElem(vector<T> & tab, const size_t & pos){
    T tmp = tab[pos];
    for (size_t i = pos; i < tab.size() - 1; ++i) {
        tab[i] = tab[i + 1];
    }
    tab.resize(tab.size() - 1);
    return tmp;
}

template<typename T>// Pour rendre la fonction générique, sans type pour les utiliser avec les unsigned et les strings
void insererElem(vector<T> & tab, const size_t & pos, const T & val){
    tab.push_back(T());
    for (size_t i = tab.size() - 1; i > pos; --i) {
        tab[i] = tab[i - 1];
    }
    tab[pos] = val;
}

template<typename T>// Pour rendre la fonction générique, sans type pour les utiliser avec les unsigned et les strings
void deplacerElem (vector<T> & tab, const size_t & posInit, const size_t & posFin){

    insererElem(tab, posFin, supprimerElem(tab, posInit));
}


void scrutin (){
    vector<string> Candidat(NB_CANDIDATS);
    for(unsigned i (0); i < NB_CANDIDATS; ++i) Candidat[i] = litUneString(); // Déclare et initialise un tableau de string représentant les candidats
    vector<unsigned> Compte(Candidat.size(),0); // Déclare et initialise un tableau d'entier naturel
    vector<unsigned> Compte_Pourcent(Candidat.size(),0); // Déclare et initialise un tableau d'entier naturel
    unsigned vote = 0; // Déclare et initialise la variable vote
    unsigned Compteur = 0; // Déclare et initialise la variable Compteur
    unsigned Compteur_tour = 0;// Déclare et initialise la variable Compteur_tour
    unsigned Pourcentage = 0;// Déclare et initialise la variable Pourcentage
    unsigned Max1 = 0; // Déclare et initialise la variable Max1
    unsigned Max2 = 0;// Déclare et initialise la variable Max2
    unsigned Gagnant = 0; // Déclare et initialise la variable Gagnant
    bool Gagnant_majoritaire = false; // Déclare et met a faux le booléen Gagnant_majoritaire

    while (Gagnant_majoritaire != true) // Vérifie que le booléen Gagnant_majoriataire n'est pas vrais
    {
        Compteur = NB_ELECTEURS; // (Re)Définis le compteur a NB_ELECTEURS
        if (Compteur_tour != 0){
            deplacerElem (Candidat,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Candidat,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte_Pourcent,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte_Pourcent,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            supprimerElem (Candidat,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            supprimerElem (Compte,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            supprimerElem (Compte_Pourcent,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            Compte[0] = 0;
            Compte[1] = 1;
        }
        do{
            vote = litUnEntier(); // Attend la saisi de la variable vote

            if (vote > Candidat.size() || vote <= 0){ // Boucle si avec condition que vote soit plus grand que la taille du tableau Candidat
                Compteur ++; // incrémente de 1 la variable Compteur
            }

            if (vote == 1){ // Si vote est égale à 1 alors
                Compte[0] = Compte[0]+1; // Ajouté 1 dans la case 0 du tableau Compte
            }else if (vote == 2){ // Si vote est égale à 2 alors
                Compte[1] = Compte[1]+1; // Ajouté 1 dans la case 1 du tableau Compte
            }else if (vote == 3){ // Si vote est égale à  3 alors
                Compte[2] = Compte[2]+1; // Ajouté 1 dans la case 2 du tableau Compte
            }else if (vote == 4){ // Si vote est égale à 4 alors
                Compte[3] = Compte[3]+1; // Ajouté 1 dans la case 3 du tableau Compte
            }else if (vote == 5){ // Si vote est égale à  5 alors
                Compte[4] = Compte[4]+1; // Ajouté 1 dans la case 4 du tableau Compte
            }
            Compteur--; // Désincrémente de 1 la variable Compteur
            Compteur_tour++;
        }while(Compteur != 0);// Condition de sortie la boucle tant_que ( il faut que Compteur soit a 0 ce qui assure que tout le monde a voté )

        bool gagnant_trouve = false; // Déclare et initialise a faux un booléen qui détermine si on a un gagnant ou non

        for ( unsigned i = 0; i < Candidat.size(); ++i){ // Boucle pour qui parcours les différents tableaux
            for (unsigned i=0; i < Compte_Pourcent.size(); i++){ // Boucle pour qui parcour le tableau des pourcentages
                Pourcentage = Compte[i] * 100 / NB_ELECTEURS; // Définis la variable provisoire pourcentage
                Compte_Pourcent[i]= Pourcentage; // Met pourcentage dans la ieme case du tableau pourcent
            }
        }
        for ( unsigned i = 0; i < Compte_Pourcent.size(); ++i){ // Boucle pour qui parcour le tableau des pourcentages

            if (Compte_Pourcent[i] > 50 ){ // On recherche si un pourcentage et strictement plus élevé que 50%
                Gagnant = i; //Sauvgarde la valeur i dans la variable de Gagnant
                gagnant_trouve = true; // Si il existe le booléen est vrais sinon il est faux
            }
        }
        if (gagnant_trouve != true){ // Si le gagnant_trouve et vrais alors on a un gagnant

            for (unsigned i = 0; i < Compte_Pourcent.size(); ++i) { // Boucle pour qui parcour le tableau des pourcentage
                if (Compte_Pourcent[i] > Compte_Pourcent[Max1]) {  // On vérifie que le porcentage courant et bien le pourcentage le plus grand
                    Max1 = i; // Sauvegarde du plus grand pourcentage
                }
            }

            for (unsigned j = 0; j < Compte_Pourcent.size(); ++j) { // Boucle pour qui parcour le tableau des pourcentage
                if (j != Max1 && Compte_Pourcent[j] > Compte_Pourcent[Max2]) { // On vérifie que le porcentage courant et bien le pourcentage le plus grand et qu'il est différent de Max1
                    Max2 = j; // Sauvegarde du 2eme plus grand pourcentage
                }
            }

        }else{
            cout << Candidat[Gagnant] << endl; //Affiche le gagant avec son nombre de vote et le pourcentage correspondant
            Gagnant_majoritaire = true; // Mets le bouléen Gagnant_majoriatiare a vrais
        }
    }
}

int main() // main
{
    scrutin(); // exécute la fonction scrutin
    return 0; // retourne 0
}
