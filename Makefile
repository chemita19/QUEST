all: QUEST Die_test Set_test Inventory_test Player_test Space_test Object_test Link_test

QUEST: obj/game.o obj/screen.o obj/space.o obj/graphic_engine.o obj/game_loop.o obj/game_management.o obj/command.o obj/object.o obj/player.o obj/set.o obj/die.o obj/link.o obj/inventory.o
	gcc obj/game.o obj/screen.o obj/space.o obj/graphic_engine.o obj/game_loop.o obj/game_management.o obj/command.o obj/object.o obj/player.o obj/set.o obj/die.o obj/link.o obj/inventory.o -o QUEST
	
Die_test: obj/die_test.o obj/die.o 
	gcc obj/die_test.o obj/die.o -o Die_test

Set_test: obj/set_test.o obj/set.o 
	gcc obj/set_test.o obj/set.o -o Set_test
	
Link_test: obj/link_test.o obj/link.o 
	gcc obj/link_test.o obj/link.o -o Link_test
	
Object_test: obj/object_test.o obj/object.o 
	gcc obj/object_test.o obj/object.o -o Object_test
	
Player_test: obj/player_test.o obj/player.o obj/inventory.o obj/set.o
	gcc obj/player_test.o obj/player.o obj/inventory.o obj/set.o -o Player_test

Inventory_test: obj/inventory.o obj/inventory_test.o obj/set.o
	gcc obj/inventory.o obj/inventory_test.o obj/set.o -o Inventory_test
	
Space_test: obj/space_test.o obj/space.o obj/set.o
	gcc obj/space_test.o obj/space.o obj/set.o -o Space_test

obj/game.o: src/game.c include/game.h include/screen.h include/space.h include/graphic_engine.h include/game_management.h include/command.h include/player.h include/object.h include/set.h include/die.h
	gcc -c -Wall -g -pedantic src/game.c -o obj/game.o
    
obj/screen.o: src/screen.c include/screen.h 
	gcc -c -Wall -g -pedantic src/screen.c -o obj/screen.o
	
obj/space.o: src/space.c include/space.h 
	gcc -c -Wall -g -pedantic src/space.c -o obj/space.o
	
obj/graphic_engine.o: src/graphic_engine.c include/graphic_engine.h include/command.h 
	gcc -c -Wall -g -pedantic src/graphic_engine.c -o obj/graphic_engine.o
	
obj/game_loop.o: src/game_loop.c include/game.h include/types.h
	gcc -Wall -g -c -pedantic src/game_loop.c -o obj/game_loop.o
	
obj/game_management.o: src/game_management.c include/game_management.h include/game.h
	gcc -c -Wall -g -pedantic src/game_management.c -o obj/game_management.o
	
obj/command.o: src/command.c include/command.h 
	gcc -Wall -c -g -pedantic src/command.c -o obj/command.o
	
obj/object.o: src/object.c include/object.h
	gcc -c -Wall -g -pedantic src/object.c -o obj/object.o
	
obj/player.o: src/player.c include/player.h include/inventory.h 
	gcc -c -Wall -g -pedantic src/player.c -o obj/player.o
	
obj/set.o: src/set.c include/set.h
	gcc -c -Wall -g -pedantic src/set.c -o obj/set.o
	
obj/die.o: src/die.c include/die.h 
	gcc -c -Wall -g -pedantic src/die.c -o obj/die.o
	
obj/link.o: src/link.c include/link.h
	gcc -c -Wall -g -pedantic src/link.c -o obj/link.o
	
obj/inventory.o: src/inventory.c include/inventory.h
	gcc -c -Wall -g -pedantic src/inventory.c -o obj/inventory.o

obj/player_test.o: src/player_test.c include/test.h include/inventory.h include/player.h
	gcc -Wall -c -g -pedantic src/player_test.c -o obj/player_test.o
	
obj/space_test.o: src/space_test.c include/test.h include/set.h include/space.h
	gcc -Wall -c -g -pedantic src/space_test.c -o obj/space_test.o
	
obj/inventory_test.o: src/inventory_test.c include/test.h include/inventory.h
	gcc -Wall -c -g -pedantic src/inventory_test.c -o obj/inventory_test.o
	
obj/die_test.o: src/die_test.c include/die_test.h include/test.h src/die.c include/die.h
	gcc -c -Wall -g -pedantic src/die_test.c -o obj/die_test.o
	
obj/set_test.o: src/set_test.c include/set_test.h include/test.h src/set.c include/set.h
	gcc -c -Wall -g -pedantic src/set_test.c -o obj/set_test.o
	
obj/link_test.o: src/link_test.c include/link_test.h include/link.h src/link.c include/link.h
	gcc -c -Wall -g -pedantic src/link_test.c -o obj/link_test.o
	
obj/object_test.o: src/object_test.c include/object_test.h include/test.h src/object.c include/object.h
	gcc -c -Wall -g -pedantic src/object_test.c -o obj/object_test.o
	
clean: 
	rm obj/*.o *QUEST *_test
	
dist:
	tar -cvzf Iteracion3_2121_Pareja1.tgz *c *h *dat *Makefile 
	
doc:
	doxygen doxyfile
	
doxyfile: 
	doxygen -g doxyfile