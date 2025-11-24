#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
{
    unsigned nbcandidats = 5;
    unsigned nbelecteur = 6;
    vector <string> candidats(nbcandidats);
    vector <string> electeurs(nbelecteur);
    for(unsigned int i=0;i<=candidats.size()-1; i=i+1)
    {
        candidats[i]=litUneString();
    }
    for(unsigned int i=0;i<=electeurs.size()-1; i=i+1)
    {
        electeurs[i]=litUneString();
    }

    vector<vector<string>> choix(electeurs.size(), vector<string>(candidats.size()));
    for (unsigned int i=0;i<=choix.size()-1;i=i+1)
    {
        for (unsigned int j=0;j<=candidats.size()-1;j=j+1)
        {
            choix[i][j] = litUneString();
        }

    }
    unsigned points;
    vector<unsigned> score(nbcandidats);
    for(unsigned int i=0;i<=candidats.size();i=i+1)
    {
        score[i]=0;
    }
    for(unsigned int i=0;i<=choix.size()-1;i=i+1)
    {

        for(unsigned int j=0;j<=candidats.size()-1;j=j+1)
        {
            for(unsigned int v=0;v<=candidats.size()-1;v=v+1)
            {
                if(choix[i][j]==candidats[v])
                {
                    points = nbcandidats -1 - j;
                    score[v] = score[v] + points;
                }
            }

        }
    }
    unsigned int maxscore;
    maxscore= 0;
    string gagnant;
    for (unsigned int i=0;i<=candidats.size()-1;i=i+1)
    {
        if(score[i]>maxscore)
        {
            maxscore = score[i];
            gagnant = candidats[i];
        }
    }
    cout << gagnant << endl;
    return 0;
}
