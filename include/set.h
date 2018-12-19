/** @file set.h
* @date 28/02/2017
* @author Sergio Domínguez
* @brief Declaraciones de las funciones públicas de set.c
*/

#ifndef SET_H
#define SET_H

/* Incluye cabeceras utilizadas posteriormente.*/
#include "../include/types.h"

/* Definicion de valores constantes.*/
#define MAX_ELEMENTS 100

/* Definicion de la estructura de datos.*/
typedef struct _Set Set;

/* Declaración de funciones publicas.*/

/** @function  set_create
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de crear/inicializar el set. 
* @param   Nada.
* @return  Puntero de la estructura Set, con sus campos inicializados
*/ 
Set* set_create();

/** @function  set_destroy
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de liberar el set. 
* @param   Puntero a set.
* @return  OK si todo ha salido bien y ERROR si ha habido fallo. 
*/ 
STATUS set_destroy(Set* set);

/** @function  set_add
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de añadir un objeto al set. 
* @param   Puntero a set y la id del objeto a añadir.
* @return  OK si todo ha salido bien y ERROR si ha habido fallo. 
*/ 
STATUS set_add(Set* set, Id id);

/** @function  set_del
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de quitar un objeto al set. 
* @param   Puntero a set y la id del objeto a quitar.
* @return  OK si todo ha salido bien y ERROR si ha habido fallo. 
*/
STATUS set_del(Set* set, Id id);

/** @function  set_get_n_elements
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de conseguir el numero de objetos del set. 
* @param   Puntero a set .
* @return  El número de objetos del set. 
*/
int set_get_n_elements(Set* set);

/** @function  set_get_element
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de conseguir los objetos del set. 
* @param   Puntero a set .
* @return  Los objetos del set. 
*/
Id* set_get_element(Set* set);

/** @function  set_find_id
* @date     13/02/2017
* @author Jose Maria Castro
* @brief   Se encarga de buscar un objetos en el set. 
* @param   Puntero a set y la id del objeto a buscar.
* @return  TRUE si ha encontrado el objeto FALSE si no. 
*/
BOOL set_find_id(Set* set, Id id);

/** @function  set_print
* @date 13/02/2017
* @author Sergio Domínguez
* @brief Imprime el set. 
* @param El puntero Set.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS set_print(Set* set);

#endif