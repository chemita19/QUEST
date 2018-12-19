/** @file link.h
 @date 30/03/2017
 @author Sergio Domínguez
 @brief Declaraciones de las funciones públicas de link.c
 Se incluyen la libreria types.h. También se define la estructura Link.
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link;

/** @function link_create 
* @date 06/03/2016
* @author Jose Maria Castro
* @brief Crea un link.
* @param El id del link.
* @return El link creado.
*/


Link *link_create(Id id);

/** @function link_destroy.
* @date 06/03/2016
* @author Jose Maria Castro
* @brief Destruye un link.
* @param Un link.
* @return OK si no ha habido errores, ERROR si ha habido algun problema.
*/

STATUS link_destroy(Link *link);

/** @function link_set_name
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Establece el nombre del link.
* @param Un link y una cadena de caracteres.
* @return OK si no ha habido errores, ERROR si ha habido algun problema.
*/

STATUS link_set_name(Link *link, char *name);

/** @function link_get_name
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Obtiene el nombre del link.
* @param Un link.
* @return Cadena de caracteres con el nombre del link.
*/

const char *link_get_name(Link *link);

/** @function link_get_id
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Obtiene el id de un link.
* @param Un link.
* @return Id del link.
*/

Id link_get_id(Link *link);

/** @function link_get_id1
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Obtener el id1 del link.
* @param Un link.
* @return Id1 del link.
*/

Id link_get_id1(Link *link);

/** @function link_get_id2
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Obtener el id2 del link.
* @param Un link.
* @return Id2 del link.
*/


Id link_get_id2 (Link *link);

/** @function link_set_id1
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Establece el id1 del link.
* @param Un link y un id.
* @return OK si no ha habido errores, ERROR si ha habido algun problema.
*/

STATUS link_set_id1(Link *link, Id id1);

/** @function link_set_id2
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Establece el id2 del link.
* @param Un link y un id.
* @return OK si no ha habido errores, ERROR si ha habido algun problema.
*/ 

STATUS link_set_id2(Link *link, Id id2);


/** @function: link_set_state
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Establece el estado del link.
* @param Un link y un id.
* @return OK si no ha habido errores, ERROR si ha habido algun problema.
*/ 

STATUS link_set_state(Link *link, BOOL state);

/** @function link_get_state
* @date 23/03/2017
* @author Jose Maria Castro
* @brief Establece el estado del link.
* @param Un link.
* @return dato tipo int con el estado del link.
*/ 


BOOL link_get_state(Link *link);

#endif
