
/** @file Die_test.c
* @date 17/3/2017
* @author Jose Maria Castro
* @brief Testeo del Die. 
* Se incluyen las ficheros de cabecera stdio.h, stdlib.h, string.h, Die_test.h y die.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/die.h"
#include "../include/test.h"
#include "../include/die_test.h"

#define MAX_TESTS 12


int main(int argc, char **argv){
    int test = 0;
    int todas = 1;

    if (argc < 2) {
        printf("Running all tests for module Set:\n");
    } 
    else {
        test = atoi(argv[1]);
        todas = 0;
        printf("Running test %d:\t", test);
	    if (test < 1 && test > MAX_TESTS) {
	        printf("Error: unknown test %d\t", test);
	        exit(EXIT_SUCCESS);
        }
    }


    if (todas || test == 1) test1_die_create();
    
    if (todas || test == 2) test2_die_create();
    if (todas || test == 3) test1_die_destroy();
    if (todas || test == 4) test2_die_destroy();
    if (todas || test == 5) test1_die_get_num();
    if (todas || test == 6) test2_die_get_num();
    if (todas || test == 7) test1_die_roll();
    if (todas || test == 8) test2_die_roll();
    if (todas || test == 9) test1_die_get_id();
    if (todas || test == 10) test2_die_get_id();
    if (todas || test == 11) test1_die_print();
    if (todas || test == 12) test2_die_print();
    
   
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_die_create(){
    int result=die_create(2)!=NULL;
    PRINT_TEST_RESULT(result);
}

void test2_die_create(){
    Die *d;
    d=die_create(3);
    
    PRINT_TEST_RESULT(die_get_id(d)==3);
}



void test1_die_destroy(){
    Die *d;
    
    d=die_create(5);
    
    PRINT_TEST_RESULT(die_destroy(d)==OK);
}

void test2_die_destroy(){
    Die *d=NULL;
    
     PRINT_TEST_RESULT(die_destroy(d)==ERROR);
}

void test1_die_roll(){
    Die *d;
    
    d=die_create(4);
    
    PRINT_TEST_RESULT(die_roll(d)==OK);
}

void test2_die_roll(){
    Die *d;
    d=NULL;
    
    PRINT_TEST_RESULT(die_roll(d)==ERROR);
}

void test1_die_get_num(){
    Die *d;
    
    d=NULL;
    
    
    PRINT_TEST_RESULT(die_get_num(d)==-1);

}


void test2_die_get_num(){
    Die *d;
    
    d=die_create(2);
    
    die_roll(d);
    
    PRINT_TEST_RESULT(die_get_num(d)!=-1);
}


void test1_die_print(){
    Die *d;
    
    d=NULL
    
    
    
    PRINT_TEST_RESULT(die_print(d)==ERROR);
}

void test2_die_print(){
    Die *d;
    
    d=die_create(3);
    
    die_roll(d);
    
    PRINT_TEST_RESULT(die_print(d)==OK);
}


void test1_die_get_id(){
    Die *d;
    
    d=die_create(2);
    
    
    
    PRINT_TEST_RESULT(die_get_id(d)==2);
}

void test2_die_get_id(){
    Die *d;
    
    d=NULL;
    
    
    
    PRINT_TEST_RESULT(die_get_id(d)==-1);
}
    









