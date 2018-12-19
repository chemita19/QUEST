/** @file player.c
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para manipular los jugadores 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/player.h"
#include "../include/object.h"
#include "../include/set.h"
#include "../include/inventory.h"

#define max_objects 100

/** Definicion de la estructura de datos. */ 

struct _Player {
    Id id; /**!< Id player*/
    char name[WORD_SIZE + 1]; /**!< Nombre jugador*/
    Id location; /**!< Id localización del player*/
    Inventory *inventory; /**!< Inventario del jugador*/
};

Player* player_create(Id id){
    Player *newPlayer = NULL;

    if (id == NO_ID){
        return NULL;
    }
    newPlayer = (Player*)malloc(sizeof(Player));
    if (newPlayer == NULL){
        return NULL;
    }
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    newPlayer->inventory = inventory_create(max_objects);

    return newPlayer;
}

STATUS player_destroy(Player* player){
    
    if (!player) {
        return ERROR;
    }
    
    inventory_destroy(player->inventory);
    player->inventory = NULL;
    free(player);
    player = NULL;
    
    return OK;
}

Id player_get_id(Player* player){
    if(!player){
        return -1;
    }
    
    return player->id;
}

STATUS player_set_name(Player* player, char* name) {
    if (!player || !name) {
        return ERROR;
    }

    if (!strcpy(player->name, name)) {
        return ERROR;
    }

    return OK;
}

const char * player_get_name(Player* player) {
    if (!player) {
        return NULL;
    }
    return player->name;
}

Id player_get_location(Player* player) {
    if (!player) {
        return NO_ID;
    }
    return player->location;
}

STATUS player_set_location(Player* player, Id id) {
    if (!player || id == NO_ID) {
        return ERROR;
    }
    player->location = id;
    return OK;
}

STATUS player_print(Player* player) {
    Id idaux = NO_ID;
  
    if (!player) {
        return ERROR;
    }

    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
    
    idaux = player_get_location(player);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> Player location %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No player location.\n");
    }

    return OK;
}

Inventory* player_get_inventory(Player* player) {
    if (!player) {
        return NULL;
    }
    return player->inventory;
}

STATUS player_set_inventory(Player* player, Inventory* inventory) {
    if (!player || max_objects < 1) {
        return ERROR;
    }
    player->inventory = inventory_create(max_objects);
    return OK;
}

STATUS player_take_object(Player* player, Id id){
    if(!player || !id){
        return ERROR;
    }
    inventory_add_object((player->inventory),id);
    return OK;
}

STATUS player_drop_object(Player* player, Id id){
    if(!player || !id){
        return ERROR;
    }
    inventory_del_object((player->inventory),id);
    return OK;
}