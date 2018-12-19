/** @file set_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo de los Sets. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, Set_test.h y Set.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/set.h"
#include "../include/test.h"
#include "../include/set_test.h"

#define MAX_TESTS 17


int main(int argc, char **argv){
    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all tests for module Set:\n");
    } else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_set_create();
    
    if (todas || test == 2) test1_set_destroy();
    if (todas || test == 3) test2_set_destroy();
    if (todas || test == 4) test1_set_add();
    if (todas || test == 5) test2_set_add();
    if (todas || test == 6) test1_set_del();
    if (todas || test == 7) test2_set_del();
    if (todas || test == 8) test3_set_del();
    if (todas || test == 9) test4_set_del();
    if (todas || test == 10) test1_set_get_n_elements();
    if (todas || test == 11) test2_set_get_n_elements();
    if (todas || test == 12) test1_set_get_element();
    if (todas || test == 13) test2_set_get_element();
    if (todas || test == 14) test1_set_find_id();
    if (todas || test == 15) test2_set_find_id();
    if (todas || test == 16) test1_set_print();
    if (todas || test == 17) test2_set_print();
   
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_set_create(){
    int result=set_create()!=NULL;
    PRINT_TEST_RESULT(result);
}


void test1_set_destroy(){
    Set *s;
    
    s=set_create(5);
    
    PRINT_TEST_RESULT(set_destroy(s)==OK);
}

void test2_set_destroy(){
    Set *s=NULL;
    
     PRINT_TEST_RESULT(set_destroy(s)==ERROR);
}

void test1_set_add(){
    Set *s;
    
    s=set_create();
    
    PRINT_TEST_RESULT(set_add(s, 3)==OK);
}

void test2_set_add(){
    Set *s;
    
    s=set_create();
    
    PRINT_TEST_RESULT(set_add(s, NO_ID)==ERROR);
}

void test1_set_del(){
    Set *s;
    
    s=NULL;
    
    set_add(s, 3);
    
    PRINT_TEST_RESULT(set_del(s, 3)==ERROR);

}


void test2_set_del(){
     Set *s;
    
    s=set_create();
    
    set_add(s, 4);
    
    PRINT_TEST_RESULT(set_del(s, 4)==OK);
}

void test3_set_del(){
    Set *s;
    
    s=set_create();
    
    set_add(s, 1);
    
    PRINT_TEST_RESULT(set_del(s, NO_ID)==ERROR);
}

void test4_set_del(){
    Set *s;
    
    s=set_create();
    
    set_add(s, 3)
    
    PRINT_TEST_RESULT(set_del(s, 4)==ERROR);
}

void test1_set_get_n_elements(){
    Set *s;
    
    s=set_create();
    
    set_add(s, 3);
    
    PRINT_TEST_RESULT(set_get_n_elements(s)==1);
}

void test2_set_get_n_elements(){
    Set *s;
    
    s=NULL;
    
    PRINT_TEST_RESULT(set_get_n_elements(s)==-1);
}

void test1_set_get_element(){  
    Set *s;
    
    s=set_create();
    
    set_add(s, 6);
    
    PRINT_TEST_RESULT(set_get_element(s)!=NULL);
}

void test2_set_get_element(){
    
    Set *s;
    s=NULL;
   
    PRINT_TEST_RESULT(set_get_element(s)== NULL);

}

void test1_set_find_id() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_find_id(s, 6) == FALSE);
}

void test2_set_find_id() {
    Set *s;
    s = set_create();
    set_add(s, 4);
    PRINT_TEST_RESULT(set_find_id(s, 4) == TRUE);
}

void test1_set_print() {
    Set *l = NULL;
    PRINT_TEST_RESULT(set_print(l) == ERROR);
}

void test2_set_print() {
    Set *s;
    s = set_create();
    set_add(s, 4);
    PRINT_TEST_RESULT(set_print(s) == OK);
}


    
    
    
    
    









