/** @file inventory.c
* @date 20/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para manejar el inventario del jugador
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/inventory.h"


struct _Inventory{
    
    Set *objects;    /*!< Puntero a set*/
    int max_objects;  /*!< Número máximo de objetos del inventory*/
};

Inventory* inventory_create(int max_objects){
    
    Inventory *newInventory = NULL;
    
    newInventory = (Inventory*)malloc(sizeof(Inventory));
    if ( newInventory == NULL){
        return NULL;
    }
    
    newInventory->objects = set_create();
    newInventory->max_objects = max_objects;
    
    return newInventory;
}

STATUS inventory_destroy(Inventory* inventory){
    
    if (inventory == NULL){
        return ERROR;
    }
    set_destroy(inventory->objects);
    inventory->objects = NULL;
    free (inventory);
    inventory = NULL;
    return OK; 
    
}

STATUS inventory_add_object(Inventory* inventory, Id id){
    
    if ( inventory == NULL || id == NO_ID){
        return ERROR;
    }
    if (set_add(inventory->objects, id) == ERROR){
        return ERROR;
    }
    return OK;
}

STATUS inventory_del_object(Inventory* inventory, Id id){
    
    if ( inventory == NULL || id == NO_ID){
        return ERROR;
    }
    if ( set_del(inventory->objects, id) == ERROR){
        return ERROR;
    }
    return OK;
}

int inventory_get_n_objects(Inventory* inventory){
    if ( inventory == NULL){
        return -1;
    }
    return set_get_n_elements(inventory->objects);
}

int inventory_get_capacity(Inventory* inventory){
    if ( inventory == NULL){
        return -1;
    }
    return inventory->max_objects;
    
}

STATUS inventory_set_capacity(Inventory* inventory, int new_capacity){
    int i;
    int storage_used = 0;
        if ( inventory == NULL ){
        return ERROR;
    }
    for ( i = 0; i < inventory->max_objects; i++){
        if ( set_find_id(inventory->objects,i)==TRUE){
            storage_used++;
        } 
    }
    if ( new_capacity < storage_used){
        printf ( "Error.\n");
        return ERROR;
        
    }
    inventory->max_objects = new_capacity;
    return OK;
}

BOOL inventory_full(Inventory* inventory){
    int current_n_objects = 0;
    if ( inventory == NULL){
        return FALSE;
    }
    current_n_objects = inventory_get_n_objects(inventory);
    if ( current_n_objects == inventory->max_objects){
        return TRUE;
    }
    return FALSE;
}

BOOL inventory_find_object(Inventory* inventory,Id id){
    if (set_find_id(inventory->objects,id) == TRUE) return TRUE;
    else return FALSE;

}

STATUS inventory_print (Inventory* inventory){
    
    if ( inventory == NULL){
        return ERROR;
    }
    printf ("%d/%d",inventory_get_n_objects(inventory),inventory_get_capacity(inventory));
    set_print(inventory->objects);
    return OK;
}