/** @file object_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo de los objetos. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, object_test.h y object.h
*/
#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H


/**
* @author Jose Maria Castro
* @brief comprobación al crear el objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_create();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al destruir el objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al destruir el objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_destroy();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al obtener la id del objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al obtener la id del objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_get_id();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiarle el nombre al objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiarle el nombre al objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_set_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el nombre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el nombre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_get_name();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar la primera descripción
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_set_description();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar la primera descripción
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_set_description();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir la primera descripción
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_get_description();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir la primera descripcion
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_get_description();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al cambiar el link que abre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/

void test1_object_set_opens();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al cambiar el link que abre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_set_opens();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al conseguir el link que abre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_get_opens();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al conseguir el link que abre
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test2_object_get_opens();

/**
* @author Jose Maria Castro
* @brief comprobación del primer caso posible al imprimir por pantalla un objeto
* @date 20/3/2017
* @file object_test.h
* @version 1.0
*/
void test1_object_print();

/**
* @author Jose Maria Castro
* @brief comprobación del segundo caso posible al imprimir por pantalla un objeto
* @date 20/3/2017
* @file objeto_test.h
* @version 1.0
*/
void test2_object_print();

#endif