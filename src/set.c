/* Archivo : set.c
 Fecha: 20/02/2017
 Autor: Jose Maria Castro.
 Descripción: Implementacion de las funciones de set.c que se encargan de regular los conjuntos.
 Se incluyen las librerias stdio.h, stdlib.h, string.h types.h y set.h. Además de una constante MAX. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/set.h"
#define MAX 100

/* La estructura de set tiene la informacion de un id y un entero para el número de elementos del conjunto. */
struct _Set {
    Id id[MAX]; 
    int n_elements;
};


Set* set_create() {

    Set *newSet = NULL;
    int i = 0;
    newSet = (Set*)malloc(sizeof(Set));

    if (newSet == NULL){
        return NULL;
    }
    for (i = 0; i < MAX; i++){
		newSet->id[i] = NO_ID;
	}

	newSet-> n_elements = 0;
    return newSet;
}


STATUS set_destroy(Set* set){
    int i = 0;
	if (set == NULL){
		return ERROR;
	}
    for(i=0;i<set->n_elements;i++){
        set->id[i] = NO_ID;
    }
	free(set);
	set = NULL;

	return OK;
}


STATUS set_add(Set* set, Id id){
	int i = 0;

	if (set == NULL || id == NO_ID){
		return ERROR;
	}

	for (i=0; i< MAX; i++){
		if(set->id[i] == NO_ID){
        	set->id[i] = id;
			(set->n_elements)++; 
			return OK;
        }
    }
    
    return ERROR;
}

STATUS set_del(Set* set, Id id){ 
	int i = 0;

	if (set == NULL || id == NO_ID){
		return ERROR;
	}

	for (i= 0; i < MAX; i++){

		if(set->id[i] == id){
        
        	set->id[i] = NO_ID;
			(set->n_elements)--;

			return OK;
        
        }
    }
   
    return ERROR;
	}
	

int set_get_n_elements(Set* set){
	if(set == NULL){
		return -1;
	}

	return set->n_elements;
}


Id* set_get_element(Set* set){
	if(set == NULL || set->n_elements== 0){
		return NULL;
	}

	return set->id;
}


BOOL set_find_id(Set* set, Id id){
	int i;

	if(set == NULL){
		return FALSE;
	}

	for(i = 0; i<MAX_ELEMENTS; i++){
		if(set->id[i] != NO_ID){
			if (set->id[i] == id){
				return TRUE;
			}
		}
		
	}

	return FALSE;
	
}	


STATUS set_print(Set* set){
	int i = 0;

	if (set == NULL){
		return ERROR;
	}

	if (set-> n_elements == 0){
		fprintf(stdout,"You dont have objects in the set");
	}else {
		for(i = 0; i < set->n_elements; i++){
		
			fprintf(stdout,"Object %d, id: %ld", i+1, set->id[i]);
		
		}
	}
	
	return OK;
}
