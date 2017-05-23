#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 

/**************************************************************/
/***Déclaration de la structure la base de la liste chainée ***/
struct cell{ 
	int id ;
	int valeur;
	struct cell * suivant;
};
/* Création d'un nouveau type Cellule à partir de struct cell */
typedef struct cell Cellule;

/*****************Fonctions de la liste chainée*****************/

/* Fonction estVide retourne 1 si vide,  0 sinon 
*  Pour réaliser un test dans le main(), on fait comme suit:
*	if(estVide(Liste)) printf("Liste est vide"); 
*	else printf("Liste n'est pas vide"); 
*/
int estVide(Cellule *L){
	if(L == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Fonction numElements retourne le nombre d'éléments d'une liste pointé par pointeur <Liste> 
*  Pour l'utiliser dans le main(), on fait comme suit:
*	int tailleListe = numElements(Liste)
*	printf("le nombre d'éléments de la  liste est %d \n",tailleListe);
*/
int numElements(Cellule *L){
	Cellule *laux = L;
	int n=0;
	while(laux!=NULL){
		n++;
		laux=laux->suivant;
	}
	return n;
}

;;
/*
* Fonction Retourner_i retourne l'élément (cellule) ayant l'indice i de la liste chainée
* Le premier élément de la liste a indice 0
* Dans le main, pour utiliser cette fonction, on doit tester si c'est pas NULL :
*	Cellule* iCellule = Retourner_i(L,3);
*	if (iCellule!=NULL) printf("iCellule id=% valeur=%d \n",iCellule->id,iCellule->valeur);
*/
Cellule* Retourner_i(Cellule *L, int indice){
	int i=0;
	Cellule *laux=L;
    /* On se déplace de i éléments, tant que c'est possible */
    while(laux != NULL)
    {
    	if (i==indice) return laux; //retourne l'élément ayant indice en paramètre
    	i++;
        laux = laux->suivant;
    }
 
    /* Si indice est grand que la taille de la liste chainée;
	*  Ceci dit qu'il n'existe pas un élément ayant l'indice demandé,
	*  En effet, on retourne NULL;
	*/
    return NULL;
}

/*
* Chercher le premier élément ayant id et val dans la liste chainée
*	Dans le main, pour utiliser cette fonction, on doit tester si c'est pas NULL :
*	Cellule* iCellule = Chercher(L,3,4);
*	if (iCellule!=NULL) printf("iCellule trouvé id=% valeur=%d \n",iCellule->id,iCellule->valeur);
*/
Cellule* Chercher(Cellule *L, int id, int val) {
	Cellule *laux=L;
    /* Tant que l'on n'est pas au bout de la liste */
    while(laux != NULL)
    {
        if(laux->valeur == val && laux->id == id) 
        {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return laux;
        }
        laux = laux->suivant;
    }
    return NULL;
}


/*
* Chercher le premier élément ayant id et val dans la liste chainée
*	Dans le main, pour utiliser cette fonction, on doit tester si c'est pas NULL :
*	Cellule* iCellule = Chercher(L,3,4);
*	if (iCellule!=NULL) printf("iCellule trouvé id=% valeur=%d \n",iCellule->id,iCellule->valeur);
*/
Cellule Chercher(Cellule *L, int id, int val) {
	Cellule *laux=L;
    /* Tant que l'on n'est pas au bout de la liste */
    while(laux != NULL)
    {
        if(laux->valeur == val && laux->id == id) 
        {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return *laux;
        }
        laux = laux->suivant;
    }
    return NULL;
}


/*
* Retourne le nombre d'occurences d'un élément ayant id et val dans la liste chainée
*	Dans le main, pour utiliser cette fonction, on doit tester si c'est pas NULL :
*	int nbrOccurences = Chercher(L,3,4);
*	printf("Le nombre d'occurences de (id=%d valeur=%d) \n",id,valeur,nbrOccurences);
*/
int nbrOccurences(Cellule *L, int id, int val) {
	Cellule *laux=L;
	int n=0;
    /* Tant que l'on n'est pas au bout de la liste */
    while(laux != NULL)
    {
        if(laux->valeur == val && laux->id == id) 
        {            
            n++;
        }
        laux = laux->suivant;
    }
    return n;
}


/* Fonction Afficher affiche tous les éléments d'une liste pointé par pointeur L 
*  L'affichage est réalisé ligne par ligne; On affiche dans chaque ligne, les
* informations d'un élément (son indice,adresse, id,valeur, adresse de l'element
* suivant)
*/
void afficherListe(Cellule *L){

	if (estVide(L)) printf("La liste de cellules est vide\n");
	else {	
		int num=0;
		Cellule *laux = L;
		while(laux!=NULL){
			/* Affichage des éléments de la liste ligne par ligne */
			printf("Cellule (%d) \t", num); 
			printf ("Son adresse memoire %x |", laux);
			printf("laux->id=(%d) | laux->valeur=(%d) |", laux->id,laux->valeur);
			printf ("Adresse mémoire de l'element suivant est %x \n", laux->suivant);
			num++;
			laux=laux->suivant;
		}
	}
}

/*
* Fonction ajouterEnTete permet d'ajouter un element (cellule) à l'entête de la 
* liste chainée.
*/

Cellule* ajouterEnTete(Cellule *L, Cellule *nouveau){
	/*Allocation du nouveau élément Cellule*/
	nouveau = (Cellule*)malloc(sizeof(Cellule)) ;
	/* Saisie des donnees de la nouvelle cellule  */
	printf("Entrer l'id du nouveau élément : "); scanf("%d",&(nouveau->id));
	printf("Entrer la valeur du nouveau élément "); scanf("%d",&(nouveau->valeur));
	/* Mise à jour des liens */
	nouveau->suivant=L;
	L=nouveau;
	return L;
}

/*
* Fonction ajouterALaFin permet d'ajouter un element (cellule) à la fin de la 
* liste chainée.
*/
Cellule* ajouterALaFin(Cellule *L, Cellule *nouveau){
	/*Allocation du nouveau*/
	nouveau = (Cellule*)malloc(sizeof(Cellule)) ;
	/* Saisie des donnees de la nouvelle cellule  */
	printf("Entrer l'id du nouveau élément "); scanf("%d",&nouveau->id);
	printf("Entrer la valeur du nouveau élément "); scanf("%d",&nouveau->valeur);	
	/* c'est le dernier élément Cellule alors il pointe sur NULL */
	nouveau->suivant=NULL;
	
	if(estVide(L))
    {
        /* Si la liste est vide, le nouveau element devient l'entête de la liste
        *  chainée
        */
        L=nouveau;
        return L;
    }
    else
    {
    	/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
		Cellule *laux=L;
		/*Recherche du dernier element*/
		while(laux->suivant!=NULL){
			laux=laux->suivant;
		}			
		/* Mise à jour des liens */	
		laux->suivant=nouveau;		
        return L;
	}
}

/*
* AjouterApres(Cellule *pos) ajoute un élément après l'élément identifié par pointeur pos
* Cette fonction ne modifie pas l'entête (par opposition aux autres fonctions d'ajout)
* de la liste chainée. Du coup, son type de retour est void.
*/
void ajouterApres(Cellule *pos){
	if (pos==NULL) printf("le parametre entre est NULL");
	else {	
		/*Allocation du nouveau élément*/
		Cellule *nouveau;
		nouveau = (Cellule*)malloc(sizeof(Cellule)) ;
		/* Saisie des donnees de la nouvelle cellule  */
		printf("Entrer l'id du nouveau élément "); scanf("%d",&nouveau->id);
		printf("Entrer la valeur du nouveau élément "); scanf("%d",&nouveau->valeur);	
	
		/*Mise A Jour des liens */
		nouveau->suivant = pos->suivant;
		pos->suivant = nouveau;
	}
	
}

/*
* Fonction supprimerPremier permet de supprimer le premier element -entête- de la 
*	liste chainée.
*/
Cellule* supprimerPremier(Cellule *L){
	if(estVide(L)){
		/*Si la liste est vide, on retroune NULL puisque la liste
		* est vide
		*/
		printf("La liste est vide !!!\n");
        return NULL;
	}
	else
    {
        /* Si la liste est non vide, on  supprime l'élément à l'entête et on retourne
		* le deuxième élément */
        Cellule* Temp = L;
        L=L->suivant;
        /* On supprime-libère- le premier élément */
        free(Temp);
        /* On retourne le nouveau début de la liste */
        return L;
    }
    
}

/*
* Fonction supprimerDernier permet de supprimer le dernier element -queue- de la 
*	liste chainée.
*/

Cellule* supprimerDernier(Cellule *L){
	/* Si la liste est vide, on retourne NULL */
    if(estVide(L)){
    	printf("La liste est vide !!!\n");
		return NULL;    	
	}         
    /* Si la liste contient un seul élément */
    else if(L->suivant == NULL) // ou bien if (numElements(L)==1)
    {
        /* On libère le premier élément et on 
		*  retourne NULL (la liste est maintenant vide) 
		*/
        free(L);
        return NULL;
    }
 	else
	{
 	   /* Si la liste contient au moins deux éléments */
	    Cellule* dernier = L;
	    Cellule* avantDernier = L;
	    /* Tant qu'on n'est pas au dernier élément */
	    while(dernier->suivant != NULL)
	    {
	        /* avantDernier stocke l'adresse de dernier */
	        avantDernier = dernier;
	        /* On déplace dernier (mais avantDernier garde l'ancienne valeur de dernier */
	        dernier = dernier->suivant;
	    }
	    /* A la sortie de la boucle, dernier pointe sur le dernier élément, et avantDernier sur
	    l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
	    et on libere le dernier élément */
	    avantDernier->suivant = NULL;
	    free(dernier);
	    //ici, on indique que le nouveau dernier élément c'est l'avant Dernier
	    dernier = avantDernier;
	    return L;
	}
}


/*
* supprimerApres(Cellule *pos) supprime un élément après l'élément identifié par pointeur pos
* Cette fonction ne modifie pas l'entête (par opposition aux autres fonctions de suppression)
* de la liste chainée. Du coup, son type de retour est void.
*/
void supprimerApres(Cellule *pos){
	//Quand l'élément pos est vide
	if (estVide(pos)) printf("La liste est vide!!!\n");
	//Quand pos est le dernier élément, donc son suivant est vide
	else if (pos->suivant==NULL) 
	printf("Cet élément est le dernier dans la liste, en effet, il n'existe pas un élément suivant a supprimer'!!!\n");
	
	else{
		//Cellule à supprimer
		Cellule *Asupp = pos->suivant;
		//MAJ des liens
		pos->suivant=Asupp->suivant;
		//Suppression de Asupp
		free(Asupp);
	}
	
}




/*Fonction ViderListe supprime tous les éléments de la liste L 
* Elle peut appeler la fonction supprimerPremier autant de fois qu'il
* faut pour supprimer tous les éléments de la liste chainée
*/
Cellule* ViderListe(Cellule *L){
	Cellule *laux=L;
	Cellule *tmp;
	while (laux!=NULL){
		tmp = laux;		
		laux  = laux->suivant;
		free(tmp);
	}
	return NULL;
}

Cellule* ViderListe(Cellule *L){		
	while (L!=NULL){
		L = supprimerPremier(L);		
	}
	return NULL;
}

/* fonction principale main */
int main(){
	/*On a déclarer un pointeur sur une liste chainée de cellules, il s’agit de l’entête de la liste*/
	Cellule *L=NULL;
	/*Création d'un pointeur auxiliaire de liste */	
	Cellule *li=NULL, *nouveau=NULL, *laux=NULL;
    int val, i, n, k, choix; 
  	system("cls"); // ou bien cette fonction ==> clrscr(); 	
	//k=fflush(NULL); //k=flushall(); 		 
	
  	do { 
    system("cls"); // ou bien cette fonction ==> clrscr();
    printf("\n\n\n\n") ;
    printf("\n\t\t $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n"); 
    printf("\t\t $$  Pour vider toute la liste ....... 1\n"); 
    printf("\t\t $$  Pour afficher la liste saisie  ....... 2\n"); 
    printf("\t\t $$  Pour calculer la longueur      ....... 3\n"); 
    printf("\t\t $$  Pour calculer le nombre d'occ. ....... 4\n"); 
    printf("\t\t $$  Pour inserer au debut          ....... 5\n"); 
    printf("\t\t $$  Pour inserer a la fin         ....... 6\n"); 
    printf("\t\t $$  Pour inserer apres Cellule ayant indice i... 11\n");
    printf("\t\t $$  Pour supprimer au debut        ....... 7\n"); 
    printf("\t\t $$  Pour supprimer a la fin       ....... 8\n"); 
    printf("\t\t $$  Pour supprimer apres Cellule ayant indice i... 12\n");
    printf("\t\t $$  Pour retourner la i ème cellule       ....... 9\n");
    printf("\t\t $$  Pour chercher une cellule....... 10\n");
    printf("\t\t $$  Pour quitter le programme      ....... 0\n"); 
    printf("\t\t $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n"); 
    printf("\t\t $$  Donner votre choix s.v.p.      .......: "); 
    
	scanf("%d",&choix);     
    switch(choix) { 
   	case  1 : { 
	   	system("cls"); // ou bien cette fonction ==> clrscr();     		
		li = ViderListe(li);    		
		break;  
	} 
    case 2 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		afficherListe(li); 
		getch(); 
		break; 
  	} 
  	case 3 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		k=numElements(li); 
		printf("\n\n\n\n\t\t la longueur est %d\n",k); 
		getch(); 
		break; 
  	} 
	case 4 : {      
     	system("cls"); // ou bien cette fonction ==> clrscr();
		int id,valeur;
		/* Demander à l'utilisateur de saisir id et valeur de la cellule recherchée */
		printf ("Entrez id de la cellule recherchee: ");
		scanf("%d",&id);
		printf ("Entrez valeur de la cellule recherchee: ");
		scanf("%d",&valeur);
		int nbr = nbrOccurences(li,id,valeur);
		printf("Le nombre d'occurrences est %d \n",nbr);
		getch();
		break;
 
 	}   
  	case 5 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();     		
		li = ajouterEnTete(li,nouveau);    		
		break; 
	}	 
	case 6 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();     		
		li = ajouterALaFin(li,nouveau);    		
		break; 
	}  	
  case 7 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		li = supprimerPremier(li);
		getch();
		break; 
  }
  case 8 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		li = supprimerDernier(li);
		getch();
		break; 
  } 
  case 9 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		int idx;
		/* Demander à l'utilisateur de saisir indice de la cellule recherchée */
		printf ("Entrez indice de la cellule recherchee: ");
		scanf("%d",&idx);
		
		Cellule *iCellule = Retourner_i(li,idx);
		if (iCellule!=NULL) printf("iCellule id=%d valeur=%d \n",iCellule->id,iCellule->valeur);
		
		getch();
		break;
  } 
  case 10 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();
		int id,valeur;
		/* Demander à l'utilisateur de saisir id et valeur de la cellule recherchée */
		printf ("Entrez id de la cellule recherchee: ");
		scanf("%d",&id);
		printf ("Entrez valeur de la cellule recherchee: ");
		scanf("%d",&valeur);
		Cellule *iCellule = Chercher(li,id,valeur);
		if (iCellule!=NULL) printf("iCellule id=%d valeur=%d \n",iCellule->id,iCellule->valeur);
		getch();
		break;
  }
  case 11 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();     		
		int idx;
		/* Demander à l'utilisateur de saisir indice de la cellule apres laquelle 
		*  il faut supprimer la cellule:  
		*/
		do {
		
			printf ("Entrez indice de la cellule apres laquelle il faut inserer nouvelle cellule, \n");
			/*
			*  L'intervalle des indices d'Une liste ayant n éléments est [0,n-1] car le premier indice est 0.
			*  L'utilisateur ne doit pas entrer un indice superieur à n-1, car il n'existe pas un élément
			*  Dans la liste ayant un indice supérieur à n-1. 
			*  En effet, l'intervalle valide des indices est [0,n-1], en C, [0,numElements(li)-1]
			*/
			printf ("L'indice ne doit pas dépasser cette intervalle de la liste chainee [0,%d] : \n",numElements(li)-1);
			scanf("%d",&idx);			
		}
		while((numElements(li)-1)<idx);
		
		/* Ajout apres l'élément ayant l'indice i :
		*	Retourner_i(li,idx) retourne l'élément ayant l'indice i
		*	on passe donc cet élément à la fonction ajouterApres(li,iCellule)
		*	pour qu'on puisse ajouter un élément après ce i ème élément.
		*/
		Cellule *iCellule = Retourner_i(li,idx);		
		ajouterApres(iCellule);  
		getch();
		break; 
	} 
	
	case 12 : { 
		system("cls"); // ou bien cette fonction ==> clrscr();     		
		/* Tester si la liste contient au plus un élément */
		if (numElements(li)<=1) {
			printf ("La suppression apres une position ne peut etre realisee vue la taille de la liste (%d) !!! \n",numElements(li));
			getch();
			break;		
		}
		
		int idx;
		/* Demander à l'utilisateur de saisir indice de la cellule apres laquelle 
		*  il faut inserer nouvelle cellule:  
		*/
		do {
		
			printf ("Entrez indice de la cellule apres laquelle il faut supprimer une cellule, \n");
			/* 
			*  L'intervalle des indices d'Une liste ayant n éléments est [0,n-1] car le premier indice est 0.
			*  On ne peut pas supprimer après le dernier element, donc on ne doit pas donner n-1 comme indice
			*  pour la suppression après position.
			*  En effet, l'intervalle valide des indices est [0,n-2], en C, [0,numElements(li)-2]
			*/
			printf ("L'indice ne doit pas dépasser cette intervalle de la liste chainee [0,%d] : \n",numElements(li)-2);
			scanf("%d",&idx);			
		}
		while((numElements(li)-2)<idx);
		Cellule *iCellule = Retourner_i(li,idx);		
		supprimerApres(iCellule);  
		
		/* Suppression apres l'élément ayant l'indice i:
		*	Retourner_i(li,idx) retourne l'élément ayant l'indice i
		*	On passe donc cet élément à la fonction supprimerApres(iCellule);
		*	pour qu'on puisse supprimer l'élément après ce i ème élément.
		*/
		
		getch();
		break; 
	} 
	
  case 0  :    break; 
  default   :    break; 
  } 
  }while(choix!=0); 
  /* Fin do while */      
  
  //system("pause");
  return 0;
	
}
