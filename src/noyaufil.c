/* NOYAUFILE.C */
/*--------------------------------------------------------------------------*
 *  gestion de la file d'attente des taches pretes et actives               *
 *  la file est rangee dans un tableau. ce fichier decrit toutes            *
 *  les primitives de base                                                  *
 *--------------------------------------------------------------------------*/
#include <stdint.h>
#include "serialio.h"
#include "noyau.h"

/* variables communes a toutes les procedures *
 *--------------------------------------------*/

static uint16_t  _file[MAX_TACHES];   /* indice=numero de tache */
				   /* valeur=tache suivante  */
static uint16_t  _queue;              /* valeur de la derniere tache */
				   /* pointe la prochaine tache a activer */

/*     initialisation de la file      *
 *------------------------------------*
entre  : sans
sortie : sans
description : la queue est initialisee vide, queue prend la valeur de tache
	      impossible
*/

void	file_init( void )
{
	int i;
	for (i=0; i<MAX_TACHES; i++) {
		_file[i] = F_VIDE;
	}
	_queue = F_VIDE;
}

/*        ajouter une tache dans la pile      *
 *--------------------------------------------*
entree : n numero de la tache a entrer
sortie : sans
description : ajoute la tache n en fin de pile
*/

void	ajoute ( uint16_t n )
{
	if (_queue == F_VIDE) {
		// si la file est vide
		_file[n] = n;
	} else {
		// sinon, ajoute n dans la file
		uint16_t prochaine_tache = _file[_queue];
		_file[_queue] = n;
		_file[n] = prochaine_tache;
	}
	// modifie la prochaine tache pour  que
	// la nouvelle tache s'execute en dernier
	_queue = n;
}

/*           retire une tache de la file        *
 *----------------------------------------------*
entree : t numero de la tache a sortir
sortie : sans
description: sort la tache t de la file. L'ordre de la file n'est pas
	     modifie
*/

void	retire( uint16_t t )
{
 	int i;
	for (i=0; i<MAX_TACHES; i++) {
		if (_file[i] == t){
			break;
		}
	}
	if (i == MAX_TACHES)
		return;
	
	// si la prochaine tache est à supprimer
	// on la remplace par la suivant
	if (_queue == t) {
		_queue = _file[t];
	}
	// supprime la tache de la file
	_file[i] = _file[t];
	_file[t] = F_VIDE;
}


/*        recherche du suivant a executer       *
 *----------------------------------------------*
entree : sans
sortie : t numero de la tache a activer
description : la tache a activer est sortie de la file. queue pointe la
	      suivante
*/
uint16_t	suivant( void )
{
	if (_queue == F_VIDE)
		return _queue;
	else
		return _queue = _file[_queue];
}

/*     affichage du dernier element     *
 *--------------------------------------*
entree : sans
sortie : sans
description : affiche la valeur de queue
*/

void affic_queue( void )
{
	printf("_queue = %d\n", _queue);
}

/*     affichage de la file     *
 *------------------------------*
entree : sans
sortie : sans
description : affiche les valeurs de la file
*/

void affic_file( void )
{
	int i;
	for (i=0; i<MAX_TACHES; i++) {
		printf("_file[%d] = %d\n", i, _file[i]);
	}
}
