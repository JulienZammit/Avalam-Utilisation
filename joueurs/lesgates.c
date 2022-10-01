/********* Moteur de tournoi : joueur ***************/

#include <stdio.h>
#include <stdlib.h>
#include "avalam.h"
#include "moteur.h"

void choisirCoup(T_Position currentPosition, T_ListeCoups listeCoups) {
	// Cette fonction peut appeler la fonction ecrireIndexCoup(coupChoisi);
	// Pour sélectionner l'index d'un coup à jouer dans la liste l 

	int priorite = 1;
	T_Voisins voisinscheck;
	octet voisincase;
	int i,j;
	int good=0;
	int alea;
	int nbvoisins;
	int compteurVoisins;  //nombre de voisins remplissant la condition afin de savoir si il faut effectuer le deplacement
	int compteurVoisins2;
	octet o, d, o2, d2, v; 
	octet myColor = currentPosition.trait; 

	// afficherListeCoups(listeCoups);


	printf("Ma couleur : %s\n", COLNAME(currentPosition.trait));
	printf("Nombre de coup %d\n", listeCoups.nb);

	for(i=0;i<listeCoups.nb; i++) 
	{
		priorite = 1;	//variable du switch, definit dans quelle categorie de priorité de coup on se trouve
		int coupJoue = 0;  //si un coup a été joué, 'coupJoue' prend la valeur 1
		o = listeCoups.coups[i].origine; 
		d = listeCoups.coups[i].destination;  
		printf("Coup %d : ", i); 
		printf("%d (%d - %s) ->", o, currentPosition.cols[o].nb, COLNAME(currentPosition.cols[o].couleur));
		printf("%d (%d - %s) \n", d, currentPosition.cols[d].nb, COLNAME(currentPosition.cols[d].couleur)); 

	
	//***********LES DIFFERENTS CAS D'OUVERTURE****************//
		switch(currentPosition.trait)
			{
				case 1 :
					if(listeCoups.nb>=291){// on fait en sorte de jouer le coup uniquement en début de partie pour démarer notre stratégie d'ouverture
						for (j = 0; j < listeCoups.nb; ++j)
						{
							o2 = listeCoups.coups[j].origine; 
							d2 = listeCoups.coups[j].destination;  
							if((int)o2==20 && (int)d2==29){
								ecrireIndexCoup(j);
							return;
							}
						}
					}
					// ouverture deuxième option pour jaune
					if((int)o==21 && (int)d==28){
						//start compteur voisin
						voisinscheck=getVoisins(d);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==1 && currentPosition.cols[28].couleur==2){
							// le joueur adverse a joué 29 sur 28 (car le nombre de voisin de 28 est de 1) donc on va jouer 21 sur 28
							ecrireIndexCoup(i);
							return;
						}
					}
					if((int)o==21 && (int)d==12){
						//start compteur voisin
						voisinscheck=getVoisins(o);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==5 && currentPosition.cols[21].couleur==2 && currentPosition.cols[28].couleur==1){
							// cas ou le joueur adverse a joué 29 sur 30
							ecrireIndexCoup(i);
							return;
						}
					}
					if((int)o==21 && (int)d==12){
						//start compteur voisin
						voisinscheck=getVoisins(o);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==5 && currentPosition.cols[21].couleur==1 && currentPosition.cols[28].couleur==1 && currentPosition.cols[30].nb==3){
							// cas ou le joueur adverse a joué 29 sur 30
							ecrireIndexCoup(i);
							return;
						}
					}
					// ouverture 1ère option pour jaune
					/*
					if((int)o==8 && (int)d==4){
						//start compteur voisin
						voisinscheck=getVoisins(d);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==7 && currentPosition.cols[4].couleur==2){
							//ouverture du jeu sur la gauche pour assurer une tour
							ecrireIndexCoup(i);
							return;
						}
					}
					if((int)o==9 && (int)d==16){
						//start compteur voisin
						voisinscheck=getVoisins(o);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==6 && currentPosition.cols[4].nb==2 && currentPosition.cols[4].couleur==1){
							//ouverture du jeu sur la gauche pour assurer une tour
							ecrireIndexCoup(i);
							return;
						}
					}
					*/
					break;
				case 2 :
					if(listeCoups.nb>=276){// on fait en sorte de jouer le coup uniquement en début de partie pour démarer notre stratégie d'ouverture
						for (j = 0; j < listeCoups.nb; ++j)
						{
							o2 = listeCoups.coups[j].origine; 
							d2 = listeCoups.coups[j].destination;  
							if((int)o2==18 && (int)d2==19){
								ecrireIndexCoup(j);
							return;
							}
						}
					}
					// ouverture 1 ère option pour jaune
					if((int)o==27 && (int)d==19){
						//start compteur voisin
						voisinscheck=getVoisins(d);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==1 && currentPosition.cols[19].couleur==1 && currentPosition.cols[19].nb==3){
							// le joueur adverse a joué 29 sur 28 (car le nombre de voisin de 28 est de 1) donc on va jouer 21 sur 28
							ecrireIndexCoup(i);
							return;
						}
					}
					if((int)o==19 && (int)d==27){
						//start compteur voisin
						voisinscheck=getVoisins(d);
						nbvoisins=0;
						for (j = 0; j < voisinscheck.nb; ++j)
						{
							voisincase = voisinscheck.cases[j];
							if ((currentPosition.cols[voisincase].couleur == 1)||(currentPosition.cols[voisincase].couleur == 2))
							{
								nbvoisins=nbvoisins+1;
							}
						}
						printf("Nombre voisin : %d\n", nbvoisins);
						//end compteur voisin
						if(nbvoisins==1 && currentPosition.cols[19].couleur==2 && currentPosition.cols[19].nb==2 && currentPosition.cols[27].nb==2 && currentPosition.cols[27].couleur==1){
							// le joueur adverse a joué 29 sur 28 (car le nombre de voisin de 28 est de 1) donc on va jouer 21 sur 28
							ecrireIndexCoup(i);
							return;
						}
					}
					break;
			}
	//***********FIN DES DIFFERENTS CAS D'OUVERTURE****************//
	}


//***********LES DIFFERENTES STRATEGIES****************//


	//***********STRATEGIE 1****************//

	//strat. 1 livr. 2, si on peut former une tour de 5 on prend

		printf("\tLancement strat 1 (pile de 5)\n");
		for(i=0;i<listeCoups.nb; i++) 
		{
			o = listeCoups.coups[i].origine; 
			d = listeCoups.coups[i].destination;  

				if (((currentPosition.cols[o].nb) + (currentPosition.cols[d].nb)) == 5)  //si l'association de l'origine et de l'arrivé fait une tour de 5
				{
					if ((currentPosition.cols[o].couleur == myColor) && (currentPosition.cols[d].couleur != myColor))  //si on prend une tour adverse
					{
						printf("Coup choisi : stratégie 1\n"); 
						ecrireIndexCoup(i);
						return;     // on quitte la fonction 
					}
				}
				
					
		
		}

	//***********FIN STRATEGIE 1****************//



	//***********STRATEGIE 2****************// 

	//strat. 10 livr. 2, on isole une tour

		printf("\tLancement strat 2 (isolation attaque)\n");
		for(i=0;i<listeCoups.nb; i++) 
		{
			o = listeCoups.coups[i].origine; 
			d = listeCoups.coups[i].destination;  
			compteurVoisins = 0;
			
			if ((currentPosition.cols[o].couleur == myColor) && (currentPosition.cols[d].couleur != myColor))   //on joue notre couleur sur couleur adverse
			{
				//start compteur voisin
				voisinscheck=getVoisins(d);
				nbvoisins=0;
				for (j = 0; j < voisinscheck.nb; ++j)
				{
					voisincase = voisinscheck.cases[j];
					if ((currentPosition.cols[voisincase].couleur != 0)) //si la case est vide
					{
						nbvoisins=nbvoisins+1;
					}
				}
				printf("Nombre voisin : %d\n", nbvoisins);
				//end compteur voisin
				if(nbvoisins == 1)  //si pas de voisins
				{
					printf("Coup choisi : stratégie 2\n"); 
					ecrireIndexCoup(i);
					return; // on quitte la fonction
				}
			}
		}

	//***********FIN STRATEGIE 2****************//


//***********STRATEGIE 3****************// 

//strat. 2 livr. 2, on isole une tour des pions adverses, elle sera entourée de cases vides ou de cases amicales 

	printf("\tLancement strat 3 (semi-isolation)\n");
	for(i=0;i<listeCoups.nb; i++) 
	{
		o = listeCoups.coups[i].origine; 
		d = listeCoups.coups[i].destination;  
		compteurVoisins = 0;
		
		if ((currentPosition.cols[o].couleur == myColor) && (currentPosition.cols[d].couleur != myColor))   //on joue notre couleur sur couleur adverse
		{
			voisins = getVoisins(d);  //liste des voisins de la destination
			
			for (j = 0; j < voisins.nb; j++) //pour chaque voisins
				{
					v = voisins.cases[j];

					if(currentPosition.cols[v].couleur != myColor) //checkeur de voisins de la couleur adverse
					{
						compteurVoisins = 1;
					}

				}	
		
			if(compteurVoisins == 0)  //si il y n'y a pas de voisins de la couleur adverse
			{
				printf("Coup choisi : stratégie 3\n"); 
				ecrireIndexCoup(i);
				return; // on quitte la fonction
			}
		}
	}

//***********FIN STRATEGIE 3****************//



//***********STRATEGIE 4****************// 

// on prend si autour de la destination et de la reception on compte des tours trop hautes ou des cases vides

	printf("\tLancement strat 4 (prise car personne autour)\n");
	for(i=0;i<listeCoups.nb; i++) 
	{
		o = listeCoups.coups[i].origine; 
		d = listeCoups.coups[i].destination;  
		compteurVoisins = 0;
		
		
		if ((currentPosition.cols[o].couleur == myColor) && (currentPosition.cols[d].couleur != myColor))   //si on joue 2 pions de l'adversaire
		{
			voisins = getVoisins(o);  //liste des voisins de l'origine
				
			for (j = 0; j < voisins.nb; j++) //pour chaque voisins de l'origine
			{
				v = voisins.cases[j];

				if((currentPosition.cols[v].nb + (currentPosition.cols[o].nb) + (currentPosition.cols[d].nb)) < 6 && (currentPosition.cols[v].couleur != 0)) //si une tour peut reprendre deriiere (il reste de la place)
				{
					compteurVoisins = 1;
				}

			}	
				
			voisins = getVoisins(d);  //liste des voisins de la destination
				
			for (j = 0; j < voisins.nb; j++) //pour chaque voisins de la destination
			{
				v = voisins.cases[j];

				if((currentPosition.cols[v].nb + (currentPosition.cols[o].nb) + (currentPosition.cols[d].nb)) < 6 && (currentPosition.cols[v].couleur != 0)) //si une tour peut reprendre deriiere (il reste de la place)
				{
					compteurVoisins = 1;
				}

			}	

		if(compteurVoisins = 0) //si la condition n'a pas été validé
				{
					printf("Coup choisi : stratégie 4\n"); 
					ecrireIndexCoup(i);
					return;
				}
		}

	}

//***********FIN STRATEGIE 4****************//






//***********STRATEGIE 5****************// 

	//strat. 7 livr. 2, on fait des piles de 3 entouré de nos pions

		printf("\tLancement strat 4 (formation vague)\n");
		for(i=0;i<listeCoups.nb; i++) 
		{
			
			o = listeCoups.coups[i].origine; 
			d = listeCoups.coups[i].destination;  
			compteurVoisins = 0;
			compteurVoisins2 = 0;
			
			if ((currentPosition.cols[o].couleur == myColor) && (currentPosition.cols[d].couleur != myColor))   //on joue notre couleur sur couleur adverse
			{
				if (((currentPosition.cols[o].nb) + (currentPosition.cols[d].nb)) == 3) //si le resultat donne une pile de 3
				{
					voisinscheck = getVoisins(d);  //liste des voisins de la destination
					
					for (j = 0; j < voisinscheck.nb; j++)
					{
						voisincase = voisinscheck.cases[j];

						if(currentPosition.cols[voisincase].couleur == myColor) //compteur de voisins de notre couleur
						{
							compteurVoisins++;
						}
						else if(currentPosition.cols[voisincase].couleur != myColor) //compteur de voiins de la couleur adverse
						{
							compteurVoisins2++;
						}

					}	
					
					if(compteurVoisins == 3 && (compteurVoisins2 == 2 || compteurVoisins2 == 3)) //si 3 pions amis et 2 ou 1 pions ennemis a la destination
					{
						printf("Coup choisi : stratégie 4\n"); 
						ecrireIndexCoup(i);
						return;
					}
				}
			}

		}

//***********FIN STRATEGIE 5****************//


//***********STRATEGIE 6****************// 

//strat. 7 livr. 2, on fait des tours de 2 avec les pions de l'adversaire

	printf("\tLancement strat 6 (empilement)\n");
	for(i=0;i<listeCoups.nb; i++) 
	{
		o = listeCoups.coups[i].origine; 
		d = listeCoups.coups[i].destination;  
		compteurVoisins = 0;
		
		
		if ((currentPosition.cols[o].couleur != myColor) && (currentPosition.cols[d].couleur != myColor))   //si on joue 2 pions de l'adversaire
		{
			if (((currentPosition.cols[o].nb) + (currentPosition.cols[d].nb)) == 2) //si le resultat donne une pile de 2
			{
				voisins = getVoisins(d);  //liste des voisins de la destination
				
				for (j = 0; j < voisins.nb; j++) //pour chaque voisins
				{
					v = voisins.cases[j];

					if(currentPosition.cols[v].nb > 1) //si on compte une tour de plus de 1 pion
					{
						compteurVoisins = 1;
					}

				}	
				
				if(compteurVoisins = 0) //si tout les voisins de la destination sont des pions de 1
				{
					printf("Coup choisi : stratégie 6\n"); 
					ecrireIndexCoup(i);
					return;
				}
			}
		}
	
	}

//***********FIN STRATEGIE 6****************//






	














	// CAS OU AUCUNE STRATEGIE NE FONCTIONNE //
	// aléatoire avec quelques modifications pour pas offrir des points //

	while (1)
	{
		alea = rand()%listeCoups.nb;
		o = listeCoups.coups[alea].origine; 
		d = listeCoups.coups[alea].destination;  
 
		if ( (currentPosition.cols[o].couleur != myColor) && ((currentPosition.cols[o].nb+currentPosition.cols[d].nb) != 5) ) 
		{
			ecrireIndexCoup(alea);
			return;
		}
	}

 


}

