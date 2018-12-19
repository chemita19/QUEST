/** 
 * @brief It defines the game interface
 * for each command
 * 
 * @file game.h
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "../include/command.h"
#include "../include/space.h"
#include "../include/player.h"
#include "../include/object.h"
#include "../include/link.h"
#include "../include/die.h"


/** Definicion de la estructura de datos. */ 

typedef struct _Game Game;

/* Declaración de funciones publicas.*/

/** @function game_create
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Inicia el juego.
 * @param Puntero a Game.
 * @return OK
 */ 
Game* game_create();

/** @function game_create_from_file
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Inicia el juego desde un archivo.
 * @param Puntero a Game, y ficheros 
 * @return OK  
 */
Game* game_create_from_file(char* filename, char* filename2, char* filename3);

/** @function game_update
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Se encarga de actualizar el juego.
 * @param Puntero a Game, los Callback para el comandos.
 * @return OK/ERROR.  
 */
STATUS game_update(Game* game, T_Command cmd);

/** @function game_destroy
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Libera toda la memoria creada en el juego.
 * @param Puntero a Game.
 * @return OK  
 */
STATUS game_destroy(Game* game);

/** @function game_is_over
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Se encarga del fin de juego.
 * @param Puntero a Game.
 * @return FALSE 
 */
BOOL   game_is_over(Game* game);

/** @function game_get_player
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el jugador.
 * @param Puntero a Game.
 * @return El puntero a player 
 */
Player* game_get_player(Game* game);

/** @function game_get_last_description
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve la descripción del juego.
 * @param Puntero a Game.
 * @return El puntero a char de la descripción 
 */
char* game_get_last_description(Game* game);

/** @function game_get_command_info
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el estado del comando.
 * @param Puntero a Game.
 * @return El estado del último comando 
 */
STATUS game_get_command_info(Game* game);


/** @function game_set_command_info
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Cambia el estado del comando.
 * @param Puntero a Game.
 * @return ERROR si hay algún fallo, sino OK. 
 */
STATUS game_set_command_info(Game* game, STATUS info);

Id game_get_space_id_at(Game* game, int position);

/** @function game_add_space
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Es la función encargada de añadir espacios.
 * @param Un puntero a Game y Space. 
 * @return ERROR si ha habido algun error al leer, sino OK. 
 */
STATUS game_add_space(Game* game, Space* space);

/** @function game_print_screen
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Se encarga de imprimir la pantalla.
 * @param Puntero a Game.
 * @return - (void) 
 */
void   game_print_screen(Game* game);

/** @function game_print_data
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Se encarga de imprimir los datos del juego.
 * @param Puntero a Game.
 * @return - (void) 
 */
void   game_print_data(Game* game);

/** @function game_get_space_id_at
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el estado de un espacio.
 * @param Puntero a Game e Id.
 * @return Espacios.  
 */
Space* game_get_space(Game* game, Id id);

/** @function game_get_player_location
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve la localizacion del jugador.
 * @param Puntero a Game.
 * @return La localización del jugador.  
 */

Id game_get_player_location(Game* game);

/** @function game_get_die
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el dado.
 * @param Puntero a Game.
 * @return El dado del juego.  
 */
Die* game_get_die(Game* game);

/** @function game_get_object_location
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve la localizacion del objeto.
 * @param Puntero a Game.
 * @return La localización del objeto.  
 */
Id game_get_object_location(Game* game);


/** @function game_get_object
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el objeto dada una id.
 * @param Puntero a Game y una id.
 * @return El objeto del juego que tiene la id dada.  
 */
Object* game_get_object(Game* game, Id id);

/** @function game_get_last_command
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el ultimo comando.
 * @param Puntero a Game.
 * @return El ultimo comando del juego.  
 */
T_Command game_get_last_command(Game* game);


/** @function game_set_object_location
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Modifica la localizacion del objeto
 * @param Puntero a Game e Id.
 * @return ERROR/OK  
 */
STATUS game_set_object_location(Game* game, Id space, Id object);

/** @function game_set_player_location
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Modifica la localizacion del jugador
 * @param Puntero a Game e Id.
 * @return ERROR/OK  
 */
STATUS game_set_player_location(Game* game, Id id);


/** @function game_add_object
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Añade un objeto al juego
 * @param Puntero a Game y el objeto.
 * @return ERROR/OK  
 */
STATUS game_add_object(Game* game, Object* object);


/** @function game_add_object
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Añade un objeto al juego
 * @param Puntero a Game y el objeto.
 * @return ERROR/OK  
 */
STATUS game_add_link(Game *g, Link *l);

/** @function game_get_link
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve un link con una id dada
 * @param Puntero a Game y una id.
 * @return Puntero al Link con la id dada 
 */
Link* game_get_link(Game *g, Id id);

#endif
