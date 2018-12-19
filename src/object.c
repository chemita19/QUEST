/** @file object.c
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para manipular los objetos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/object.h"

/** Definicion de la estructura de datos. */ 

struct _Object {
    Id id; /**!< Id objeto*/
    char name[WORD_SIZE + 1]; /**!< Nombre objeto*/
    char description[1000]; /**!< Descripción del objeto*/
    char description2[1000]; /**!< Descripción2 del objeto*/
    Id opens;
    BOOL movable;
    BOOL moved;
    BOOL visible;
    BOOL enciende;
    BOOL encendido;
};


Object* object_create(Id id) {

    Object *newObject = NULL;

    if (id == NO_ID){
        return NULL;
    }
    
    newObject = (Object*)malloc(sizeof(Object));

    if (newObject == NULL) {
        return NULL;
    }
    
    newObject->id = id;
    newObject->name[0] = '\0';
    newObject->description[0] = '\0';
    newObject->description2[0] = '\0';
    newObject->opens = NO_ID;
    newObject->movable = FALSE;
    newObject->moved = FALSE;
    newObject->visible = TRUE;
    newObject->enciende = FALSE;
    newObject->encendido = TRUE;
    return newObject;
}

STATUS object_destroy(Object* object) {
    if (!object) {
        return ERROR;
    }
    
    free(object);
    object = NULL;

    return OK;
}

Id object_get_id(Object* object) {
    if (!object) {
        return NO_ID;
    }
    return object->id;
}

STATUS object_set_name(Object* object, char* name) {
    if (!object || !name) {
        return ERROR;
    }

    if (!strcpy(object->name, name)) {
        return ERROR;
    }

    return OK;
}

const char * object_get_name(Object* object) {
    if (!object) {
        return NULL;
    }
    return object->name;
}

STATUS object_set_opens(Object *object, Id opens){
    if(!object){
        return ERROR;
    }
    
    object->opens=opens;
    
    return OK;
}

Id object_get_opens(Object *object){
    if(!object){
        return NO_ID;
    }
   
   return object->opens;
}


STATUS object_print(Object* object) {
  
    if (!object) {
        return ERROR;
    }

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}

STATUS object_set_description(Object* object, char* description) {
    if (!object || !description) {
        return ERROR;
    }

    if (!strcpy(object->description, description)) {
        return ERROR;
    }

    return OK;
}

const char * object_get_description(Object* object) {
    if (!object) {
        return NULL;
    }
    return object->description;
}

STATUS object_set_description2(Object* object, char* description) {
    if (!object || !description) {
        return ERROR;
    }

    if (!strcpy(object->description2, description)) {
        return ERROR;
    }

    return OK;
}

const char * object_get_description2(Object* object) {
    if (!object) {
        return NULL;
    }
    return object->description2;
}

STATUS object_set_movable(Object *object, BOOL movable){
    if(!object || !movable){
        return ERROR;
    }
    object->movable = movable;
    return OK;
}

BOOL object_get_movable(Object *object){
    if(!object){
        return FALSE;
    }
    return object->movable;
}

STATUS object_set_moved(Object *object, BOOL moved){
    if(!object || !moved){
        return ERROR;
    }
    object->moved = moved;
    return OK;
}

BOOL object_get_moved(Object* object){
    if(!object){
        return FALSE;
    }
    return object->movable;
}

STATUS object_set_hidden(Object* object, BOOL hidden){
    if(!object || !hidden){
        return ERROR;
    }
    object->visible = hidden;
    return OK;
}

BOOL object_get_hidden(Object *object){
    if(!object){
        return FALSE;
    }
    return object->visible;
}

STATUS object_set_lights(Object *object, BOOL lights){
    if(!object || !lights){
        return ERROR;
    }
    object->enciende = lights;
    return OK;
}

BOOL object_get_lights(Object *object){
    if(!object){
        return FALSE;
    }
    return object->enciende;
}

STATUS object_set_lit(Object *object, BOOL lit){
    if(!object || !lit){
        return ERROR;
    }
    object->encendido = lit;
    return OK;
}

BOOL object_get_lit(Object *object){
    if(!object){
        return FALSE;
    }
    return object->encendido;
}
