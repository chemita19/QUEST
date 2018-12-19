/** 
 * @brief It defines a space
 * 
 * @file space.h
 * @author Jose Maria Castro
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "link.h"

typedef struct _Space Space;

/* Definicion de valores constantes.*/
#define MAX_SPACES 100
#define FIRST_SPACE 1
#define GRAPHICS_DIM 3
#define GRAPHICS_COL 7
#define DESC 1000

/* Declaración de funciones publicas.*/

/** @function space_create
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Se encarga de crear/inicializar el espacio.
* @param La ID del space.
* @return newSpace (puntero de la estructura Spaces, con sus campos inicializados)
*/
Space* space_create(Id id);

/** @function space_destroy
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Libera el espacio reservado para el puntero space.
* @param El puntero Space.
* @return Un ERROR si hay algún fallo, sino OK.
*/
STATUS space_destroy(Space* space);

/** @function space_get_id
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Obtiene la ID del space.
* @param El puntero space donde poder recoger la ID.
* @return puntero al ID de la estructura de Space.
*/
Id space_get_id(Space* space);

/** @function space_set_name
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Copia el nombre en el puntero space.
* @param El puntero Space y nombre. 
* @return Un ERROR si no se copia bien, y OK si lo copia bien. 
*/
STATUS space_set_name(Space* space, char* name);

/** @function space_get_name
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Obtiene el nombre del space.
* @param El puntero space donde recoger el nombre. 
* @return Puntero al nombre de la estructura Space. 
*/
const char* space_get_name(Space* space);

char* space_get_graphics(Space* space, int row);

STATUS space_set_graphics(Space* space, char* graphics, int row);

/* Funciones encargadas de leer los espacios y sus coordenadas N, E, W, S, Arriba y Abajo*/

STATUS space_set_north_link(Space* space, Id id);
Id space_get_north_link(Space* space);

STATUS space_set_south_link(Space* space, Id id);
Id space_get_south_link(Space* space);

STATUS space_set_east_link(Space* space, Id id);
Id space_get_east_link(Space* space);

STATUS space_set_west_link(Space* space, Id id);
Id space_get_west_link(Space* space);

STATUS space_set_up_link(Space* space, Id id_link);
Id space_get_up_link(Space* space);

STATUS space_set_down_link(Space* space, Id id_link);
Id space_get_down_link(Space* space);
/*-------------------------------------------------------------------------*/

/** @function space_del_object
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Quita un objeto del espacio.
* @param El puntero Space donde está el objeto y la id de dicho objeto. 
* @return Id del objeto que hemos quitado. 
*/
Id space_del_object(Space* space, Id id);

/** @function space_add_object
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Añade un objeto del espacio..
* @param El puntero Space donde poder añadir el objeto y la id del objeto. 
* @return Id del objeto que añadimos. 
*/
Id space_add_object(Space* space, Id id);

/** @function space_find_objects
* @date 19/02/2017
* @author Jose Maria Castro
* @brief Busca el objeto con una id  en el espacio.
* @param El puntero Space donde buscar el objeto y la id del objeto. 
* @return TRUE si está el objeto y FALSE si no
*/
BOOL space_find_objects(Space* space, Id id);

/** @function space_get_objects
* @date 19/02/2017
* @author José María Castro y Pablo Contreras
* @brief Obtiene el objeto del espacio.
* @param El puntero Space donde poder recoger el objeto. 
* @return Id del espacio donde está el objeto. 
*/
Id* space_get_objects(Space* space);


/** @function space_get_is_lit
* @date 10/04/2017
* @author Jose Maria Castro
* @brief Obtiene la iluminación del espacio.
* @param El puntero Space que podemos iluminar. 
* @return Boolean, TRUE si el espacio etá iluminao, si no FALSE. 
*/
BOOL space_get_is_lit(Space* space);


/** @function space_set_is_lit
* @date 10/04/2017
* @author Jose Maria Castro
* @brief Cambia la iluminación del espacio.
* @param El puntero Space que podemos iluminar. 
* @return El espacio al que le hemos cambiado la iluminación. 
*/
STATUS space_set_is_lit(Space* space, BOOL lit);

/** @function  space_print
* @date 13/02/2017
* @author José María Castro y Pablo Contreras
* @brief Imprime el espacio. 
* @param El puntero Space.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS space_print(Space* space);

/** @function  space_set_description
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia la descripción del espacio. 
* @param El puntero Space y la nueva descripción.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS space_set_description(Space* space, char* description);

/** @function  space_get_description
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Devuelve la descripción del espacio. 
* @param El puntero Space.
* @return NULL si hay algún fallo, sino devuelve la descripción.
*/
const char * space_get_description(Space* space);

/** @function  space_set_description2
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia la segunda descripción del espacio. 
* @param El puntero Space y la nueva segunda descripción.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS space_set_description2(Space* space, char* description);

/** @function  space_get_description2
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Devuelve la segunda descripción del espacio. 
* @param El puntero Space.
* @return NULL si hay algún fallo, sino devuelve la segunda descripción.
*/
const char * space_get_description2(Space* space);

#endif