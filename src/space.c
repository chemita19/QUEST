/** @file space.c
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para manejar los espacios
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/space.h"
#include "../include/set.h"


/** Definicion de la estructura de datos. */ 

struct _Space {
    Id id; /**!< Id espacio*/
    char name[WORD_SIZE + 1]; /**!< Nombre espacio*/
    char description[DESC]; /**!< La descripción del espacio*/
    char description2[DESC]; /**!< La descripción al hacer inspect*/
    Id id_link_north;                       /**!< id del link por el norte*/
    Id id_link_south;                       /**!< id del link por el sur*/
    Id id_link_east;                        /**!< id del link por el este*/
    Id id_link_west;                        /**!< id del link por el oeste*/
    Id id_link_up;                          /**!< id del link por arriba*/
    Id id_link_down;                        /**!< id del link por abajo*/
    Set* objects;                           /**!< Id objeto*/
    BOOL is_lit;                           /**!< El espacio está iluminado o no*/
};

Space* space_create(Id id) {

    Space *newSpace = NULL;

    if (id == NO_ID)
        return NULL;

    newSpace = (Space*)malloc(sizeof(Space));

    if (newSpace == NULL) {
        return NULL;
    }
    newSpace->id = id;

    newSpace->name[0] = '\0';
    newSpace->description[0] = '\0';
    newSpace->description2[0] = '\0';
    newSpace->id_link_north = NO_ID;
    newSpace->id_link_south = NO_ID;
    newSpace->id_link_east = NO_ID;
    newSpace->id_link_west = NO_ID;
    newSpace->id_link_up = NO_ID;
    newSpace->id_link_down = NO_ID;
    newSpace->objects = set_create();
    newSpace->is_lit = TRUE;

    return newSpace;
}

STATUS space_destroy(Space* space) {
    if (!space) {
        return ERROR;
    }
    set_destroy(space->objects);
    space->objects = NULL;
    free(space);
    space = NULL;

    return OK;
}

STATUS space_set_name(Space* space, char* name) {
    if (!space || !name) {
        return ERROR;
    }

    if (!strcpy(space->name, name)) {
        return ERROR;
    }

    return OK;
}

STATUS space_set_description (Space* space, char* description) {
    if (!space || !description) {
        return ERROR;
    }

    if (!strcpy(space->description, description)) {
        return ERROR;
    }

    return OK;
}

STATUS space_set_description2 (Space* space, char* description) {
    if (!space || !description) {
        return ERROR;
    }

    if (!strcpy(space->description2, description)) {
        return ERROR;
    }

    return OK;
}

const char * space_get_description(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->description;
}

const char * space_get_description2(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->description2;
}

Id space_get_north_link(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id_link_north;
}


STATUS space_set_north_link(Space* space, Id id_link) {
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_north = id_link;
    return OK;
}


Id space_get_south_link(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id_link_south;
}


STATUS space_set_south_link(Space* space, Id id_link) {
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_south = id_link;
    return OK;
}


Id space_get_east_link(Space* space) {
    if (!space) {    
        return NO_ID;
	}    
    return space->id_link_east;
}



STATUS space_set_east_link(Space* space, Id id_link) {
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_east = id_link;
    return OK;
}


Id space_get_west_link(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id_link_west;
}

STATUS space_set_west_link(Space* space, Id id_link) {
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_west = id_link;
    return OK;
}

Id space_get_up_link(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id_link_up;
}

STATUS space_set_up_link(Space* space, Id id_link){
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_up = id_link;
    return OK;
}

Id space_get_down_link(Space* space){
    if (!space) {
        return NO_ID;
    }
    return space->id_link_down;
}

STATUS space_set_down_link(Space* space, Id id_link){
    if (!space || id_link ==NO_ID) {
        return ERROR;
    }
    space->id_link_down = id_link;
    return OK;
}

BOOL space_find_objects(Space* space, Id id){
	if (!space || id == NO_ID){
		return FALSE;
	}
	return set_find_id(space->objects, id);
}

Id* space_get_objects(Space* space){
	if(space == NULL){
		return NULL;
	}

	return set_get_element(space->objects);
}

Id space_add_object(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
	if (set_add(space->objects, id)==ERROR){
	    
	    return NO_ID;
	};
    return id;
}

Id space_del_object(Space* space, Id id){ 
	if (!space || id == NO_ID){
		return ERROR;
	}

	if (set_del(space->objects, id)==ERROR){
	    
	    return NO_ID;
	}

	return id;
}




const char * space_get_name(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->name;
}

Id space_get_id(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id;
}

BOOL space_get_is_lit(Space* space){
    if (!space){
        return FALSE;
    }
    return space->is_lit;
}

STATUS space_set_is_lit(Space* space, BOOL lit){
    if(!space){
        return ERROR;
    }
    space->is_lit = lit;
    return OK;
}

STATUS space_print(Space* space) {
    Id idaux = NO_ID;
  
    if (!space) {
        return ERROR;
    }

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
    
    idaux = space_get_north_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> North link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No north link.\n");
    }
    
    idaux = space_get_south_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> South link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No south link.\n");
    }
    
    idaux = space_get_east_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> East link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No east link.\n");
    }
    
    idaux = space_get_west_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> West link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No west link.\n");
    }
    
     idaux = space_get_up_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> Up link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No up link.\n");
    }
    
     idaux = space_get_down_link(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> Down link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No down link.\n");
    }
    
   if (space_get_objects(space)) {
        fprintf(stdout, "---> Object in the space.\n");
    } else {
        fprintf(stdout, "---> No object in the space.\n");
    }

    return OK;
}

 /*space_add_object(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
	if (set_add(space->objects, id)==ERROR){
	    
	    return NO_ID;
	};
    return id;
}

Id space_del_object(Space* space, Id id){ 
	if (!space || id == NO_ID){
		return ERROR;
	}

	if (set_del(space->objects, id)==ERROR){
	    
	    return NO_ID;
	}

	return id;
}*/