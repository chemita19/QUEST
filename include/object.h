/** @file object.h
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Declaraciones de las funciones públicas de object.c
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJECTS 100

/* Definicion de la estructura de Object*/

typedef struct _Object Object;

/* Declaración de constantes.*/

#define MAX_SPACES 100
#define FIRST_SPACE 1

/* Declaración de funciones publicas.*/

/** @function  object_create
* @date     13/02/2017
* @author  Sergio Domínguez
* @brief   Se encarga de crear/inicializar el objeto. 
* @param   La ID del objeto.
* @return  newObject (puntero de la estructura Objects, con sus campos inicializados)
*/ 
Object* object_create(Id id);

/** @function  object_destroy
* @date     13/02/2017
* @author  Sergio Domínguez
* @brief   Se encarga de liberar el objeto. 
* @param   Puntero a object.
* @return  OK si todo ha salido bien y ERROR si ha habido fallo. 
*/ 
STATUS object_destroy(Object* object);

/** @function  object_get_id
* @date     13/02/2017
* @author  Sergio Domínguez
* @brief   Obtiene la Id del object.
* @param   Puntero a Object.
* @return  Id del objeto.
*/ 
Id object_get_id(Object* object);

/** @function  object_set_name
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Copia el nombre en el puntero object.
* @param El puntero Object y nombre. 
* @return Un ERROR si no se copia bien, y OK si lo copia bien. 
*/
STATUS object_set_name(Object* object, char* name);

/** @function object_get_name
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Obtiene el nombre del object.
* @param El puntero object donde recoger el nombre. 
* @return Puntero al nombre de la estructura object. 
*/
const char* object_get_name(Object* object);

/** @function  object_print
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Imprime el objeto. 
* @param El puntero Object.
* @return ERROR si hay algún fallo, sino OK.
*/
STATUS object_print(Object* object);

/** @function  object_set_description
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Copia la descripción en el puntero object.
* @param El puntero Object y descripción. 
* @return Un ERROR si no se copia bien, y OK si lo copia bien. 
*/

STATUS object_set_description(Object* object, char* desc);

/** @function object_get_description
* @date 120/03/2017
* @author Jose Maria Castro
* @brief Obtiene la descrpción del object.
* @param El puntero object donde recoger la descripción. 
* @return Puntero a la descripción de la estructura object. 
*/
const char * object_get_description(Object* object);

/** @function  object_set_description2
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Copia la descripción2 en el puntero object.
* @param El puntero Object y descripción. 
* @return Un ERROR si no se copia bien, y OK si lo copia bien. 
*/

STATUS object_set_description2(Object* object, char* desc);

/** @function object_get_description2
* @date 120/03/2017
* @author Jose Maria Castro
* @brief Obtiene la descrpción2 del object.
* @param El puntero object donde recoger la descripción2. 
* @return Descripcion2 de la estructura object. 
*/
const char * object_get_description2(Object* object);

/** @function object_get_opens
* @date 120/03/2017
* @author Jose Maria Castro
* @brief Obtiene la id del link que abre el objeto.
* @param El puntero object . 
* @return Id del link. 
*/
Id object_get_opens(Object *object);

/** @function object_set_opens
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia la id del link que abre el objeto.
* @param El puntero object y la id . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_opens(Object *object, Id opens);

/** @function object_set_movable
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia si el objeto es movible o no.
* @param El puntero object y el BOOL . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_movable(Object *object, BOOL movable);

/** @function object_get_movable
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Consigue si el objeto es movible o no.
* @param El puntero object. 
* @return TRUE si el objeto es movible, FALSE si no. 
*/
BOOL object_get_movable(Object *object);

/** @function object_set_moved
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia si el objeto se ha movido o no.
* @param El puntero object y el BOOL . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_moved(Object *object, BOOL moved);

/** @function object_get_moved
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Consigue si el objeto se ha movido o no.
* @param El puntero object. 
* @return TRUE si el objeto se ha movido, FALSE si no. 
*/
BOOL object_get_moved(Object* o);

/** @function object_set_hidden
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia si el objeto está oculto o no.
* @param El puntero object y el BOOL . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_hidden(Object* o, BOOL hidden);

/** @function object_get_hidden
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Consigue si el objeto está oculto o no.
* @param El puntero object. 
* @return TRUE si el objeto esta oculto, FALSE si no. 
*/
BOOL object_get_hidden(Object *object);

/** @function object_set_lights
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia si el objeto está iluminado o no.
* @param El puntero object y el BOOL . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_lights(Object *object, BOOL lights);

/** @function object_get_lights
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Consigue si el objeto está iluminado o no.
* @param El puntero object. 
* @return TRUE si el objeto esta iluminado, FALSE si no. 
*/
BOOL object_get_lights(Object *object);

/** @function object_set_lit
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Cambia si el objeto ha sido iluminado o no.
* @param El puntero object y el BOOL . 
* @return ERROR si hay algún fallo, sino OK. 
*/
STATUS object_set_lit(Object *object, BOOL lit);

/** @function object_get_lit
* @date 20/03/2017
* @author Jose Maria Castro
* @brief Consigue si el objeto ha sido iluminado o no.
* @param El puntero object. 
* @return TRUE si el objeto ha sido iluminado, FALSE si no. 
*/
BOOL object_get_lit(Object *object);

#endif