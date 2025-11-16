declarer  nbcandidats -> entier_naturel;
afficher ("Nombre de candidats : ", nbcandidats);
declarer nbelecteurs -> entier_naturel;
afficher ("Nombre d'électeurs : ", nbelecteurs);

declarer candidats -> tableau_de entier_naturel de taille nbcandidats;   
pour (i variant_de 1 à nbcandidats) // tout les nom des candidats
    faire
        afficher ("nom du candidat ",i,":" candidats[i]);
    ffaire
declarer vote -> tableau_de entier_naturel;
pour (i variant_de 1 à nbelecteurs)
    faire 
        afficher ("electeur",i,"taper votre classement :");
        declarer classement -> tableau_de tableau_de entier_naturel de taille nbelecteurs;
        pour (j variant_de 1 à nbcandidats)
            faire 
                afficher ("candidat en position ",j,":"classement[i]);
            ffaire
        ajouter (classement,vote);
    ffaire

pour (i variant_de 1 à taille(vote))
    faire 
        classement <- vote[i];
         pour (j variant_de 1 a nbCandidats)
            faire
         declarer points : entier_naturel;
         points <- nbCandidats - 1 - j;
            ffaire
    ffaire
