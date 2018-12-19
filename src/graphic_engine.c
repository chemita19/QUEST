/** @file graphic_engine.c
* @date 13/02/2017
* @author Jose Maria Castro
* @brief Implementación de las funciones para el motor gráfico
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/screen.h"
#include "../include/graphic_engine.h"
#include "../include/game.h"
#include "../include/player.h"

/** Definicion de la estructura de datos. */ 

struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;
  
  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));
  
  ge->map      = screen_area_init( 1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner   = screen_area_init(28,15, 23,  1);
  ge->help     = screen_area_init( 1,16, 78,  2);
  ge->feedback = screen_area_init( 1,19, 78,  3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;
  
  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);
  
  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID;
  Space* space_act = NULL;
  int i = 0;
  char obj='\0';
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];
  STATUS command_info;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = link_get_id2(game_get_link(game,space_get_north_link(space_act)));
    id_next = link_get_id2(game_get_link(game,space_get_south_link(space_act)));
      
    if (game_get_object_location(game) == id_back) 
      obj='*';
    else 
      obj=' ';
    
    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |",obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
    
    if (game_get_object_location(game) == id_act)
      obj='*';
    else
      obj=' ';
    
    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | 8D      %2d|",(int) id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |           |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |           |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |           |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |           |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
    
    if (game_get_object_location(game) == id_next)
      obj='*';
    else
      obj=' ';
    
    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|",(int) id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |",obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint the in the description area */
  screen_area_clear(ge->descript);
  
  
  sprintf(str, " Space objects:");
  screen_area_puts(ge->descript, str);
  if(space_get_is_lit(game_get_space(game,id_act))==TRUE){
     for (  i = 0; i < MAX_OBJECTS + 1 ; i++){
      id_act = game_get_player_location(game);
      if (space_find_objects(game_get_space(game,id_act + 1),i) == TRUE){
          sprintf(str, "     %s ", object_get_name(game_get_object(game,i)));
          screen_area_puts(ge->descript, str); 
         }
      }
    }
  
    sprintf(str," ");
    screen_area_puts(ge->descript, str);
    sprintf(str, " Description:%s", game_get_last_description(game));
    screen_area_puts(ge->descript, str);
    sprintf(str," ");
    screen_area_puts(ge->descript, str);
    sprintf(str, " Inventory:");
    screen_area_puts(ge->descript, str);
     for (  i = 0; i < MAX_OBJECTS + 1 ; i++){
      id_act = game_get_player_location(game);
      if (inventory_find_object(player_get_inventory(game_get_player(game)), i) == TRUE){
        sprintf(str, "     %s ", object_get_name(game_get_object(game,i)));
        screen_area_puts(ge->descript, str);
      }
    }
  
    sprintf(str," ");
    screen_area_puts(ge->descript, str);


  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " QUEST");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, " go, take or t, drop or d, or quit or q,ton or turnon, tof or turnoff");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  command_info = game_get_command_info(game);
  if(command_info == OK){
    sprintf(str, " %s: OK", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);
  }
  else{
    sprintf(str, " %s: ERROR", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);
  }
  
  
  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
