/* Archivo : die.c
 Fecha: 01/03/2017
 Autor: Jose María Castro.
 Descripción: Implementación del dado. 
 Se incluyen las librerias stdio.h, stdlib.h, string.h, time.h y die.h. También se define 
 una constante DIE_ROLL que es la encargada de la función del dado. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/die.h"
#define DIE_ROLL 1+rand()%6 

/* La estructura de Die tiene una Id y un entero que será el valor del dado.*/
struct _Die {
    Id id;
    int value;
};


Die* die_create(Id id) {

    Die *newDie = NULL;

    if (id == NO_ID)
        return NULL;

    newDie = (Die *) malloc(sizeof (Die));

    if (newDie == NULL) {
        return NULL;
    }
    newDie->id = id;

    newDie->value = 0;

    return newDie;
}

STATUS die_destroy(Die* die) {
    if (!die) {
        return ERROR;
    }

    free(die);
    die = NULL;

    return OK;
}


STATUS die_roll(Die* die) {
    int i = 0;
    int number;
    if(!die){
        return ERROR;
    }
    if ( i < 0){
      srand((unsigned)time(NULL));       
        
    }
    number = DIE_ROLL;
    die->value = number;
    return OK;
    
}

 
int die_get_num(Die* die){
    if (die == NULL) {
        return -1;
    }
    return die->value;
}


Id die_get_id(Die* die){
	  if (die == NULL) {
        return NO_ID;
    }
    return die->id;
}


STATUS die_print(Die* die){


	if (die == NULL){
		return ERROR;
	}

	if (die->value >= 1 || die->value <= 6){
		printf("Die Id: %ld, valor: %d", die->id, die->value);
	}else{
		printf("still you have not released the die");
	}
	
	return OK;
}