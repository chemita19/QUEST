/** @file inventory.h
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Declaraciones de las funciones públicas de inventory.c
*/
#ifndef INVENTORY_H
#define INVENTORY_H

/* Incluye cabeceras utilizadas posteriormente.*/
#include "types.h"
#include "set.h"

/* Definicion de la estructura de datos.*/
typedef struct _Inventory Inventory;

/* Declaración de funciones publicas.*/

/** @function inventory_create
 *@date: 20/03/2017
 * @author Jose Maria Castro
 *@brief Se encarga de crear el inventario y lo inicializa.
 *@param La id que le damos al inventario. 
 *@return newInventory(puntero a la estructura Inventory, con sus campos inicializados).
 */
Inventory* inventory_create(int max_objects);

/** @function inventory_destroy
 *@date: 20/03/2017
 * @author Jose Maria Castro
 *@brief Se encarga de destruir el inventario.
 *@param El inventario que vamos a destruir. 
 *@return OK si el inventario ha sido destruido.
 */
STATUS inventory_destroy(Inventory* inventory);

/** @function  inventory_add_object
 *@date: 20/03/2017
 * @author Jose Maria Castro
 *@brief Añade un objeto al inventario.
 *@param Puntero a inventory e id del objeto a añadir.
 *@return OK si todo ha ido bien. ERROR si ha habido algún porblema.
 */ 
STATUS inventory_add_object(Inventory* inventory, Id id);

/** @function inventory_del_object
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Elimina un objeto de un inventario.
* @param Puntero a inventory e id del objeto a eliminar.
* @return OK si todo ha ido bien. ERROR si ha habido algún porblema.
*/ 
STATUS inventory_del_object(Inventory* inventory, Id id);

/** @function inventory_get_n_objects
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Devuelve el número de objetos que hay en un inventario.
* @param Puntero a inventory.
* @return int con el número de objetos que hay en el inventario.
*/ 
int inventory_get_n_objects(Inventory* inventory);

/** @function inventory_get_capacity
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Devuelve la capacidad de un inventario.
* @param Puntero a inventory.
* @return tipo de dato entero con el valor de la capacidad del inventario.
*/ 
int inventory_get_capacity(Inventory* inventory);

/** @function inventory_set_capacity
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Establece la capacidad de un inventario.
* @param Puntero a inventory y entero indicando la capacidad que se le asignará al inventario.
* @return OK si todo ha ido bien. ERROR si ha habido algún porblema.
*/ 
STATUS inventory_set_capacity(Inventory* inventory, int new_capacity);

/** @function inventory_full
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Comprueba si un inventario está lleno.
* @param Puntero a inventory.
* @return TRUE si está lleno. FALSE si no lo está.
*/ 
BOOL inventory_full(Inventory* inventory);

/** @function inventory_find_object
 *@date: 20/03/2017
 * @author Jose Maria Castro
* @brief Comprueba si un objeto está en el inventario.
* @param Puntero a inventory, id del objeto.
* @return TRUE si el objeto está. FALSE si no lo está.
*/ 
BOOL inventory_find_object(Inventory* inventory,Id id);


/** @function inventory_print
 *@date: 20/03/2017
 * @author Jose Maria Castro
 *@brief Se encarga de imprimir el inventario.
 *@param El inventario del que vamos a imprimir los valores. 
 *@return OK si el inventario ha sido impreso, si no, NULL.
 */
STATUS inventory_print(Inventory* inventory);

#endif
