/** @file link.c
* @date 21/03/2017
* @author Jose Maria Castro
* @brief Gestión de los links. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h y link.h También se define 
* la estructura del link.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"

struct _Link{
    Id link_id;  /*!< id del link*/
    Id id1;      /*!< id de la casilla anterior*/
    Id id2;      /*!< id de la siguiente casilla*/
    char name[WORD_SIZE+1];  /*!< nombre del link*/
    BOOL state;   /*!< estado del link -> 1 abierto 0 cerrado*/
};

Link *link_create(Id id){
    Link *link;
    
    link=(Link*)malloc(sizeof(Link));
    
    if(link==NULL){
        return NULL;
    }
    
    link->link_id=id;
    link->id1=NO_ID;
    link->id2=NO_ID;
    
    return link;
}

STATUS link_destroy(Link *link){
    if (link==NULL){
        return ERROR;
    }
    
    free(link);
    
    return OK;
}

STATUS link_set_name(Link *link, char *name){
    if(!link || !name){
        return ERROR;
    }
    
    
    if(!strcpy(link->name, name)){
        return ERROR;
    }
    
    
    return OK;
}

const char *link_get_name(Link *link){
    if(!link){
        return NULL;
    }
    
    return link->name;
}

Id link_get_id(Link *link){
    if(!link){
        return NO_ID;
    }
    
    return link->link_id;
}

Id link_get_id1(Link *link){
    if(!link){
        return NO_ID;
    }
    
    return link->id1;
}

Id link_get_id2 (Link *link){
    if(!link){
        return NO_ID;
    }
    
    return link->id2;
}

STATUS link_set_id1(Link *link, Id id1){
    if(!link || id1 == NO_ID){
        return ERROR;
    }
    
    link->id1=id1;
    
    return OK;
}

STATUS link_set_id2(Link *link, Id id2){
    if(!link || id2 == NO_ID){
        return ERROR;
    }
    
    link->id2=id2;
    
    return OK;
}

STATUS link_set_id(Link *link, Id id){
    if(!link || id == NO_ID){
        return ERROR;
    }
    
    link->link_id=id;
    
    return OK;
}

STATUS link_set_state(Link *link, BOOL state){
    if(!link){
        return ERROR;
    }
    
    link->state=state;
    
    return OK;
}

BOOL link_get_state(Link *link){
    if(!link){
        return FALSE;
    }
    
    return link->state;
}