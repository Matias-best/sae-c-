#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;

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
    vector<string> Candidat = {"Candidat_A", "Candidat_B", "Candidat_C"}; // Déclare et initialise un tableau de string représentant les candidats
    vector<unsigned> Compte(Candidat.size(),0); // Déclare et initialise un tableau d'entier naturel
    vector<unsigned> Compte_Pourcent(Candidat.size(),0); // Déclare et initialise un tableau d'entier naturel
    unsigned vote = 0; // Déclare et initialise la variable vote
    unsigned NB_Electeur = 0; // Déclare et initialise la variable NB_Electeur
    unsigned Compteur = 0; // Déclare et initialise la variable Compteur
    unsigned Compteur_tour = 0;// Déclare et initialise la variable Compteur_tour
    unsigned Pourcentage = 0;// Déclare et initialise la variable Pourcentage
    unsigned Max1 = 0; // Déclare et initialise la variable Max1
    unsigned Max2 = 0;// Déclare et initialise la variable Max2
    unsigned Gagnant = 0; // Déclare et initialise la variable Gagnant
    bool Gagnant_majoritaire = false; // Déclare et met a faux le booléen Gagnant_majoritaire

    while (Gagnant_majoritaire != true) // Vérifie que le booléen Gagnant_majoriataire n'est pas vrais
    {
        if (Compteur_tour == 0){
            cout << "Bonjour, nous cherchons a élire un président! voici la liste de candidat disponible Candidat A, Candidat B, Candidat C. Le système ne propose pas de gestion en cas d'égalité." << endl; // Affiche un message
            cout << "Avant de commencé veuillez rentré le nombre d'électeur" << endl; // Affiche un message
            cin >> NB_Electeur ; // Attend la saisis de la variable NB_Electeur
            Compteur = NB_Electeur; // Définis Compteur a la valeur NB_Electeur
        }else{
            cout << "Nous sommes a présent au " << Compteur_tour << "eme tours" << endl; // Affiche un message
            cout << "Pour rappelle nous avons " << NB_Electeur << " d'électeur" << endl; // Affiche un message
            cout << "Les candidat encore encore en piste sont " << Candidat[Max1] << " avec " << Compte[Max1] << " de votes soit,  " << Compte_Pourcent[Max1] << "%"<< endl; // Affiche le 1er candidat qualifié
            cout << "Le second est" << Candidat[Max2] << " avec " << Compte[Max2] << " de votes soit,  " << Compte_Pourcent[Max2] << "%"<< endl; // Affiche le 2eme candidat qualifié        
            Compteur = NB_Electeur; // Remet le compteur a NB_Electeur
            deplacerElem (Candidat,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Candidat,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte_Pourcent,Max1,0); // Utilise la fonction deplacerElem pour déplacer des éléments
            deplacerElem (Compte_Pourcent,Max2,1); // Utilise la fonction deplacerElem pour déplacer des éléments
            supprimerElem (Candidat,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            supprimerElem (Compte,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            supprimerElem (Compte_Pourcent,2); // Utilise la fonction supprimerElem pour supprimer des éléments
            Compte[0]=0;
            Compte[1] = 1;
        }
        do{
            cout << "Saisir le numéro de candidat pour qui vous souhaitez voté :" <<endl; // Affiche un message
            cin >> vote ; // Attend la saisi de la variable vote

            if (vote > Candidat.size() || vote <= 0){ // Boucle si avec condition que vote soit plus grand que la taille du tableau Candidat
                cout << "Numéro incorrect" << endl; // Affiche le message d'érreur si vrais
                cout << "Veuillez saisir un numéro de candidat valide" << endl; // Affiche un message
                Compteur ++; // incrémente de 1 la variable Compteur
            }

            if (vote == 1) // Si vote est égale à 1 alors
            {
                Compte[0] = Compte[0]+1; // Ajouté 1 dans la case 0 du tableau Compte
            }else if (vote == 2){ // Si vote est égale à 2 alors
                Compte[1] = Compte[1]+1; // Ajouté 1 dans la case 1 du tableau Compte
            }else if (vote == 3){ // Si vote est égale à  3 alors
                Compte[2] = Compte[2]+1; // Ajouté 1 dans la case 2 du tableau Compte
            }
            Compteur--; // Désincrémente de 1 la variable Compteur
            Compteur_tour++;
        }while(Compteur != 0);// Condition de sortie la boucle tant_que ( il faut que Compteur soit a 0 ce qui assure que tout le monde a voté )

        cout << "Tout le monde a voté ? " << endl; // Affiche un message
        cout << "L'heure du décompte a sonné, voici les résultat" << endl; // Affiche un message

        bool gagnant_trouve = false; // Déclare et initialise a faux un booléen qui détermine si on a un gagnant ou non

        for ( unsigned i = 0; i < Candidat.size(); ++i){ // Boucle pour qui parcours les différents tableaux
            for (unsigned i=0; i < Compte_Pourcent.size(); i++){ // Boucle pour qui parcour le tableau des pourcentages
                Pourcentage = Compte[i] * 100 / NB_Electeur; // Définis la variable provisoire pourcentage
                Compte_Pourcent[i]= Pourcentage; // Met pourcentage dans la ieme case du tableau pourcent
            }


            cout << Candidat[i] << ":" << Compte[i] << " votes, soit " << Compte_Pourcent[i] << "%" << endl; // Affichage des résultat en nombre de vote et en pourcentage par condidat
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

                if ( Max2 == Max1){ //Concerne le cas d'égalité mais il est traité comme si aucun des deux candidat a eu la majorité c'est juste pour un affichage d'un message spécifique
                    cout << "Les candidat sont a égalité " << Candidat[Max1] << ", " << Candidat[Max2] << "sont tout les deux arriver avec " << Compte_Pourcent[Max1] << "% des voies" << endl; // affiche un message
                }else {
                    cout << "Les candidat ayant obtenue le plus de voie sont " << Candidat[Max1] << ": " << Compte_Pourcent[Max1]<< "%" << endl; // Affiche les candidats ayant obtenue le plus de votes
                    cout<<Candidat[Max2] << ": " << Compte_Pourcent[Max2] << "%" <<endl;
                    Gagnant_majoritaire = false; // Mets le bouléen Gagnant_majoritaire a faux
                }
            }else{
                cout << " Il y a un gagnant " << endl; // affiche un message
                cout << "C'est " << Candidat[Gagnant] <<" avec " << Compte[Gagnant] << "votes, soit " << Compte_Pourcent[Gagnant] << "% qui l'emporte." <<endl; //Affiche le gagant avec son nombre de vote et le pourcentage correspondant
                cout << "Fin du scrutin, "<< "Nombre de votant " << NB_Electeur <<endl; // Affiche le nombre d'électeurs
                Gagnant_majoritaire = true; // Mets le bouléen Gagnant_majoriatiare a vrais
            }
        //}
        // for (unsigned i = 0; i < Candidat.size(); ++i) { // Boucle Pour qui parcours le tableau Candidat et Compte
        //     cout << Candidat[i] << ": " << Compte[i] << " votes" << endl; // Affiche la Case ieme du tableau Candidat et du tableau Compte et d'un message sur la même ligne
        // }
        // cout << "Nombre d'électeur :" << NB_Electeur << endl; // Affiche la variable NB_Electeur
        // cout << "Fin" << endl; // Message de fin
    }
}

int main() // main
{
    //cout << "Hello World!" << endl;
    scrutin(); // exécute la fonction scrutin
    return 0; // retourne 0
}
