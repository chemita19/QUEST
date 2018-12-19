/* Archivo : die.h
 Fecha: 06/03/201
 Descripción: Declaraciones de las funciones públicas de die.c.
 Se incluye la librería types.h. */

#ifndef DIE_H
#define DIE_H

/* Incluye cabeceras utilizadas posteriormente. */
#include "types.h"

/* Definicion de la estructura de datos. */
typedef struct _Die Die;

/* Declaración de funciones publicas.*/

/** @function die_create
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Inicia el dado.
 * @param Puntero a Die.
 * @return OK
 */ 
Die* die_create(Id id);

/** @function die_destroy
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Libera toda la memoria creada en el dado.
 * @param Puntero a Die.
 * @return OK  
 */
STATUS die_destroy(Die* die);

/** @function die_roll
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Lanza el dado.
 * @param Puntero a Die.
 * @return OK/ERROR  
 */
STATUS die_roll(Die* die);

/** @function die_get_num
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Devuelve el valor del dado.
 * @param Puntero a Die.
 * @return El valor del dado  
 */
int die_get_num(Die* die);

/** @function die_get_id
 * @date 19/02/2017
 * @author Jose Maria Castro
 * @brief Consigue la id del dado.
 * @param Puntero a Die.
 * @return La id del dado  
 */
Id die_get_id(Die* die);

/** @function  die_print
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Imprime el dado. 
* @param El puntero Die.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS die_print(Die* die);

#endif