/** @file player.h
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Declaraciones de las funciones públicas de player.c
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "set.h"
#include "inventory.h"

typedef struct _Player Player;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define MAX_CAPACITY 50

/* Declaración de funciones publicas.*/


/** @function  player_create
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Se encarga de crear/inicializar el player. 
* @param   La ID del player.
* @return  newPlayer (puntero de la estructura Player, con sus campos inicializados)
*/ 
Player* player_create(Id id);

/** @function  player_destroy
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Se encarga de liberar el player. 
* @param   Puntero a player.
* @return  OK si todo ha salido bien y ERROR si ha salido fallo. 
*/ 
STATUS player_destroy(Player* player);

/** @function  player_get_id
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Obtiene la id del player. 
* @param   Puntero a player.
* @return  Id del player. 
*/ 
Id player_get_id(Player* player);

/** @function  player_get_location
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Obtiene la Localizacion del player. 
* @param   Puntero a player.
* @return  Puntero a la localizacion de player. 
*/ 
Id player_get_location(Player* player);

/** @function  player_set_name
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Copia el nombre en el puntero player. 
* @param   Puntero a player y a name.
* @return  OK si todo ha salido bien y ERROR si ha salido fallo. 
*/ 
STATUS player_set_name(Player* player, char* name);

/** @function  player_get_name
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Obtiene el nombre del player. 
* @param   Puntero a player.
* @return  OK si todo ha salido bien y ERROR si ha salido fallo. 
*/ 
const char* player_get_name(Player* player);

/** @function  player_print
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Imprime el jugador. 
* @param El puntero Player.
* @return ERROR si hay algún fallo, sino OK. 
*/

STATUS player_print(Player* player);

/** @function  player_get_object
* @date     13/02/2017
* @author Jose Maria Castro 
* @brief   Obtiene el objeto. 
* @param   Puntero a player.
* @return  Puntero al objeto. 
*/ 
Inventory* player_get_inventory(Player* player);

/** @function  player_set_location
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Copia la localización en el puntero player.
* @param El puntero Player e Id. 
* @return Un ERROR si no se copia bien, y OK si lo copia bien. 
*/
STATUS player_set_location(Player* player, Id id);

/** @function  player_set_objects
* @date     13/02/2017
* @author Jose Maria Castro  
* @brief   Cambia el inventario del jugador. 
* @param   Puntero a player y el nuevo inventario.
* @return  OK si se ha modificado, si no ERROR. 
*/ 
STATUS player_set_inventory(Player* player, Inventory* inventory);

/** @function  player_add_object
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Añade un objeto al inventario. 
* @param   Puntero a player y la id del objeto.
* @return  OK si se ha añadido, si no ERROR. 
*/
STATUS player_take_object(Player* player, Id id);


/** @function  player_drop_object
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Quita un objeto del inventario. 
* @param   Puntero a player y la id del objeto.
* @return  OK si se ha quitado, si no ERROR. 
*/
STATUS player_drop_object(Player* player, Id id);

#endif