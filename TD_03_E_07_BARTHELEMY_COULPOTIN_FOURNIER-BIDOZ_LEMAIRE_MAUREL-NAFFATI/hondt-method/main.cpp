#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned int CANDIDATENUMBER = 6; // Nombre de listes candidates à l'élection
const unsigned int PARTICIPANTNUMBER = 60; // Nombre de participants aux votes
const unsigned int SEATS = 5; // Nombre de sièges à pourvoir

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

struct candidate {
    string listName; // Nom de la liste candidate
    float votes; // Le nombre de voix obtenu
    int coef = 1;
};

vector<candidate> candidateInitialization(){
    vector<candidate> listOfLists(CANDIDATENUMBER); // Création du tableau contenant les listes candidates
    for(unsigned int i = 0; i <= CANDIDATENUMBER-1; ++i) // Initialistation du tableau contenant les listes candidates
        listOfLists[i].listName = litUneString();

    vector<int> ballot(PARTICIPANTNUMBER); // Création du tableau contenant le scrutin
    for(unsigned int i = 0; i <= PARTICIPANTNUMBER-1; ++i) // Initialistation du tableau contenant le scrutin
        ballot[i] = litUnEntier();

    for(unsigned int i = 0; i <= PARTICIPANTNUMBER-1; ++i) // Décompte des bulletins de vote
        listOfLists[ballot[i] - 1].votes += 1;

    return listOfLists;
}

int main(){
    vector<candidate> resultsList = candidateInitialization(); // Tableau des candidats ainsi que leur score
    vector<string> elected(SEATS); // Tableau des listes élus
    unsigned int largest; // Buffer
    for(unsigned int i = 0; i <= SEATS - 1; ++i){
        largest = 0;
        for(unsigned int j = 1; j <= CANDIDATENUMBER - 1; ++j)
            if(resultsList[largest].votes < resultsList[j].votes || (resultsList[largest].votes == resultsList[j].votes && (resultsList[largest].votes * resultsList[largest].coef < resultsList[j].votes * resultsList[j].coef)))
                largest = j;
        elected[i] = resultsList[largest].listName;
        resultsList[largest].votes = (resultsList[largest].votes * resultsList[largest].coef) / (resultsList[largest].coef + 1);
        resultsList[largest].coef = resultsList[largest].coef + 1;
        cout << elected[i] << endl;
    }
    return 0;
}
