/** @file object_test.c
* @date 20/3/2017
* @author Jose Maria Castro
* @brief Testeo del módulo object. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, object_test.h e object.h 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/test.h"
#include "../include/types.h"
#include "../include/object_test.h"
#include "../include/object.h"

#define MAX_TESTS 19


int main(int argc, char **argv){
    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all tests for module object:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_object_create();
    if (todas || test == 2) test1_object_destroy();
    if (todas || test == 3) test2_object_destroy();
    if (todas || test == 4) test1_object_set_name();
    if (todas || test == 5) test2_object_set_name();
    if (todas || test == 6) test1_object_get_name();
    if (todas || test == 7) test2_object_get_name();
    if (todas || test == 8) test1_object_get_id();
    if (todas || test == 9) test2_object_get_id();
    if (todas || test == 10) test1_object_set_description();
    if (todas || test == 11) test2_object_set_description();
    if (todas || test == 12) test1_object_get_description();
    if (todas || test == 13) test2_object_get_description();
    if (todas || test == 14) test1_object_set_opens();
    if (todas || test == 15) test2_object_set_opens();
    if (todas || test == 16) test1_object_get_opens();
    if (todas || test == 17) test2_object_get_opens();
    if (todas || test == 18) test1_object_print();
    if (todas || test == 19) test2_object_print();
    
    PRINT_PASSED_PERCENTAGE;
    
    
    return 1;
}

void test1_object_create(){
    int result=object_create(4)!=NULL;
    PRINT_TEST_RESULT(result);
}

void test1_object_destroy(){
    Object *o;
    
    o = object_create(4);
    PRINT_TEST_RESULT(object_destroy(o)==OK);
}

void test2_object_destroy(){
  Object *o = NULL;
  
  PRINT_TEST_RESULT(object_destroy(o)==ERROR);
}

void test1_object_set_name(){
    Object *o;
    
    o = object_create(4);
    PRINT_TEST_RESULT(object_set_name(o, "algo")==OK);
}

void test2_object_set_name(){
    Object *o = NULL;
    
     PRINT_TEST_RESULT(object_set_name(o, "algo")==ERROR);
}

void test1_object_get_name(){
     Object *o;
    
    o = object_create(4);
    object_set_name(o, "algo");
    PRINT_TEST_RESULT(strcmp(object_get_name(o),"algo")== 0);
}

void test2_object_get_name(){
    Object *o = NULL;
    
    PRINT_TEST_RESULT(object_get_name(o)== NULL);
}

void test1_object_get_id(){
    Object *o;
    
    o = object_create(4);
    PRINT_TEST_RESULT(object_get_id(o)==4);
}

void test2_object_get_id(){
    Object *o = NULL;
   
    PRINT_TEST_RESULT(object_get_id(o)==-1);
}

void test1_object_set_description(){
    Object *o;
    
    o = object_create(4);
    PRINT_TEST_RESULT(object_set_description(o, "algo")==OK);
}

void test2_object_set_description(){
    Object *o = NULL;
    
     PRINT_TEST_RESULT(object_set_description(o, "algo")==ERROR);
}

void test1_object_get_description(){
     Object *o;
    
    o = object_create(4);
    object_set_description(o, "algo");
    PRINT_TEST_RESULT(strcmp(object_get_description(o),"algo")== 0);
}

void test2_object_get_description(){
    Object *o = NULL;
    
    PRINT_TEST_RESULT(object_get_description(o)== NULL);
}

void test1_object_set_opens(){
    Object *o;
    
    o = object_create(4);
    PRINT_TEST_RESULT(object_set_opens(o,4)==OK);
}

void test2_object_set_opens(){
    Object *o = NULL;
   
    PRINT_TEST_RESULT(object_set_opens(o,4)==ERROR);
}


void test1_object_get_opens(){
    Object *o;
    
    o = object_create(4);
    object_set_opens(o,4);
    PRINT_TEST_RESULT(object_get_opens(o)==4);
}

void test2_object_get_opens(){
    Object *o = NULL;
   
    PRINT_TEST_RESULT(object_get_opens(o)==-1);
}

void test1_object_print() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_print(o) == ERROR);
}

void test2_object_print() {
    Object *o;
    o = object_create(3);
    
    PRINT_TEST_RESULT(object_print(o) == OK);
}