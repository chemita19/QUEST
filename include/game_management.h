/** @file game_management.h
* @date 13/02/2017
* @brief Declaraciones de las funciones públicas de game_management.c
*/

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

/* Incluye cabeceras utilizadas posteriormente.*/
#include "../include/game.h"
#include "../include/space.h"
#include "../include/link.h"


/* Declaración de funciones publicas.*/

/**@function  game_reader_load_spaces.
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Se encarga de leer los espacios. 
* @param Un puntero a Game y un char para el nombre del archivo.
* @return ERROR si ha habido algun error al leer, sino OK. 
*/
STATUS game_reader_load_spaces(Game* game, char* filename);

/* Declaración de funciones publicas.*/

/**@function  game_reader_load_spaces.
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Se encarga de leer los objetos. 
* @param Un puntero a Game y un char para el nombre del archivo.
* @return ERROR si ha habido algun error al leer, sino OK.
*/
STATUS game_reader_load_object(Game* game, char* filename);

/* Declaración de funciones publicas.*/

/**@function  game_reader_load_links.
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Se encarga de leer los links. 
* @param Un puntero a Game y un char para el nombre del archivo.
* @return ERROR si ha habido algun error al leer, sino OK.
*/
STATUS game_reader_load_links(Game *game, char* filename);

#endif 

