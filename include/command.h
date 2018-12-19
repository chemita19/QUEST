/** 
 * @brief It implements the command interpreter
 * 
 * @file command.h
 * @version 1.0 
 * @date 19-12-2014 
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "../include/types.h"

typedef enum enum_Command {
  NO_CMD = -1, 
  UNKNOWN, 
  QUIT, 
  NEXT, 
  BACK,
  TAKE,
  DROP,
  ROLL,
  LEFT,
  RIGHT,
  INSPECT,
  GO,
  UP,
  DOWN,
  TURNON,
  TURNOFF,
  OPEN
} T_Command;

T_Command get_user_input();

char* command_to_string(T_Command cmd);

#endif
