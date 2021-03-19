#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 2.4
#define SQUELET
/**************************************************************************/
/* Compléter votre Nom et votre Prénom ici                                */
/*   Nom :  Sénéchal				       Prénom :  Pierre               */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	if (rep->nb_elts < MAX_ENREG)  // On ajoute un contact dans le répertoire
	{
		modif = true; // Il y a modification donc on met true
		rep->tab[rep->nb_elts] = enr;  // On vérifie la condition initiale
		compact(rep->tab[rep->nb_elts].tel); //On supprime les caractères non numériques
		rep->nb_elts++; // On augmente de 1
		trier(rep); // On trie
		return(OK); // si tout est bon
	}
	else {
		return(ERROR); // Si ca ne fonctionne pas 
	}
	

	
#else
#ifdef IMPL_LIST
	// compléter code ici pour Liste
	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
		

	}


#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1)		// s'il y a au moins un élément dans le tableau 
	{							// et que l'indice pointe vers l'intérieur 
		modif = true; // Il y a eu une modif donc on change modif
		for (int i = indice; i < rep->nb_elts; i++)
		{
			rep->tab[i] = rep->tab[i + 1]; // On supprime le contact
		}
		rep->nb_elts -= 1;		// dans tous les cas, il y a un élément en moins 
	}

	return;
} // fin supprimer 

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* Supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex : Rick, Pascal           0320346537                             */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code à compléter ici
	printf("%s,%s\t\t %s\n\n", enr.nom, enr.prenom, enr.tel);

} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /*                                                                    */
  /* ex |Rick               |Pascal                 |0320346537         */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// On affiche nom prénom et tel avec un affichage plus soigné
	printf("|-Nom : %s\n|-Prénom : %s\n|-Tél : %s\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n", enr.nom, enr.prenom, enr.tel);
	// comme fonction affichage_enreg, mais avec présentation alignée des infos


} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabétique, un enregistrement est après     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code à compléter ici
	int ordrealph = strcmp(enr1.nom, enr2.nom); // On teste l'ordre alphabétique
	if (ordrealph >=0) // Si c'est dans l'ordre ou non : 
		return(false); // si ce n'est pas dans l'ordre
	else
		return(true); // si c'est dans l'ordre

}
 
/*********************************************************************/
/*   Tri Alphabétique du tableau d'enregistrement                    */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	int position = 0;
	while ((rep->est_trie == false) && (position < rep->nb_elts - 1)) //Tant que les conditions ne sont pas vérifiées
	{
		if (est_sup(rep->tab[position + 1], rep->tab[position])) // On vérifie que c'est supérieur
		{
			Enregistrement tmp; // déclaration variable temporaire
			tmp = rep->tab[position]; 
			rep->tab[position]= rep->tab[position +1]; // On prend la valeur d'après pour vérifier
			rep->tab[position + 1] = tmp; // On affecte la variable temporaire à la position suivante
			position = 0; // on place la position à 0
		}
		position++; // On augment la position de 1
	}


	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true; 

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchée et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		// Si ce n'est pas trouvé


#ifdef IMPL_TAB
							// ajouter code ici pour tableau
	strcpy_s(tmp_nom, MAX_NOM, nom); // On copie les chaines dans les 2 chaines temporaires on les convertit en majuscules
	for (int a = 0; a < MAX_NOM - 1;a++) 
	{
		tmp_nom[a] = toupper(tmp_nom[a]); // La chaine en majuscule
	}
	
	for (int i = 0; i < rep->nb_elts; i++)
	{

		strcpy_s(tmp_nom2, MAX_NOM, rep->tab[i].nom); // copie de la chaine
		for (int b = 0; b < MAX_NOM - 1;b++)
		{
			tmp_nom2[b] = toupper(tmp_nom2[b]); // la chaine en majuscule
		}
		if (strcmp(tmp_nom, tmp_nom2) == 0)
		{
			return i; // Si chaines identiques on retourne i
		}
	}
#else
#ifdef IMPL_LIST
							// ajouter code ici pour Liste
	
#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caractères non numériques de la chaine         */
  /*********************************************************************/
void compact(char *s)
{
	// compléter code ici
	for (int a = 0; a < strlen(s); a++)
	{
		if (!isdigit(s[a])) // Si ce n'est pas un nombre
		{
			for (int b = a; b < strlen(s); b++)
				s[b] = s[b + 1];
			a--;
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	trier(rep); // Appel de la fonction de tri
	char* tmp = malloc(sizeof(char)*sizeof(Enregistrement)); // On définit une variable pour pouvoir copier dans le fichier .txt
	int Opentxt = fopen_s(&fic_rep, nom_fichier, "w"); // On ouvre le fichier
	if (!Opentxt)
	{	// Si le fichier est bien ouvert
		for (int i = 0; i < rep->nb_elts; i++) // On répète autant de fois qu'il y a d'élements 
		{
			sprintf_s(tmp, MAX_NOM + MAX_NOM + MAX_TEL, "%s%c%s%c%s%c\n", rep->tab[i].nom, SEPARATEUR, rep->tab[i].prenom, SEPARATEUR, rep->tab[i].tel, SEPARATEUR); // On écrit
			fputs(tmp, fic_rep); // On écrit dans le fichier
		}
	}
	fclose(fic_rep); // On ferme le fichier

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */