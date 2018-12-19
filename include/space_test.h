/** @file space_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo de los espacios. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, space_test.h y space.h
*/
#ifndef SPACE_TEST_H
#define SPACE_TEST_H


/**
* @author Jose Maria Castro
* @brief comprobación al crear el espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_create();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al destruir el espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al destruir el espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener la id del espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener la id del espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiarle el nombre al espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiarle el nombre al espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el nombre
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el nombre
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar la primera descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_description1();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar la primera descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_description1();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir la primera descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_description1();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir la primera descripcion
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_description1();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar la segunda descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_description2();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar la segunda descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_description2();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir la segunda descripción
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_description2();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir la segunda descripcion
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_description2();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia el norte
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_north_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia el norte
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_north_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia el norte
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_north_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia el norte
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_north_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia el sur
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/

void test1_space_set_south_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia el sur
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_south_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia el sur
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_south_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia el sur
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_south_link();


/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia la derecha
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_east_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia la derecha
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_east_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia la derecha
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_east_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia la derecha
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_east_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia la izquierda
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_west_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia la izquierda
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_west_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia la izquierda
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_west_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia la izquierda
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_west_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia arriba
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_up_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia arriba
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_up_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia arriba
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_up_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia arriba
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_up_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link hacia abajo
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_down_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link hacia abajo
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_down_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link hacia abajo
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_down_link();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link hacia abajo
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_down_link();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar la iluminación
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_set_is_lit();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar la iluminación
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_set_is_lit();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir la iluminación
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_get_is_lit();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir la iluminación
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_get_is_lit();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al imprimir por pantalla un espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test1_space_print();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al imprimir por pantalla un espacio
* @date 20/3/2017
* @file space_test.h
* @version 1.0
*/
void test2_space_print();

#endif
