/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 19-12-2014 
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <string.h>
#include "../include/command.h"

#define CMD_LENGHT 30
#define N_CMD 18

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Quit", "Next", "Back","Take","Drop", "Roll", "Left", "Right", "Inspect", "Go", "Up", "Down","Turnon","Turnoff", "Open"};

T_Command get_user_input(){

    T_Command cmd = NO_CMD;
    char input[CMD_LENGHT] = "";  

    if (scanf("%s", input) > 0){
        if (!strcmp(input, "q") || !strcmp(input, "quit")){
            cmd = QUIT;
    }
    else if (!strcmp(input, "n") || !strcmp(input, "next")){
        cmd = NEXT;
    }
    else if (!strcmp(input, "t") || !strcmp(input, "take")){
        cmd = TAKE;
    }
    else if (!strcmp(input, "d") || !strcmp(input, "drop")){
        cmd = DROP;
    }
    else if (!strcmp(input, "b") || !strcmp(input, "back")){
        cmd = BACK;
    }
    else if (!strcmp(input, "r") || !strcmp(input, "roll")){
        cmd = ROLL;    
    }
    else if (!strcmp(input, "l") || !strcmp(input, "left")){
        cmd = LEFT;    
        
    }else if (!strcmp(input, "ri") || !strcmp(input, "right")){
        cmd = RIGHT;    
    }
    else if (!strcmp(input, "i") || !strcmp(input, "inspect")){
        cmd = INSPECT;
    }
    else if (!strcmp(input, "g") || !strcmp(input, "go")){
        cmd = GO;
    }
    else if (!strcmp(input, "u") || !strcmp(input, "up")){
        cmd = UP;
    }
    else if (!strcmp(input, "d") || !strcmp(input, "down")){
        cmd = DOWN;
        
    }else if (!strcmp(input, "ton") || !strcmp(input, "turnon")){
        cmd = TURNON;
        
    }else if (!strcmp(input, "tof") || !strcmp(input, "turnoff")){
        cmd = TURNOFF;
    
    }else if (!strcmp(input, "o") || !strcmp(input, "open")){
        cmd = OPEN;
    
    }
    else{cmd = UNKNOWN;}
        
    }
    return cmd;
}

char* command_to_string(T_Command cmd){
    if(!cmd){
        return NULL;
    }
    
    return cmd_to_str[cmd - NO_CMD];
}
