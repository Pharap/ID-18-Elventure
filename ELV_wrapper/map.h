#ifndef __MAP__
#define __MAP__

#define SCROLL_UP 0
#define SCROLL_DOWN 1
#define SCROLL_LEFT 2
#define SCROLL_RIGHT 3

#define CURRENT_ROOM -1

typedef struct {
  char x;
  char y;
  char len;
} Vector;

char checkMapRoomMove(char x, char y);
char getMapBlock(char map_x, char map_y, char room);
void drawMapRoom();
void scrollMap(char direction);
char getMapCurrentRoom();
void roomTransition(char room_start, char room_finish, char direction);
void setMapRoom(char room);
void drawMapElements(char room, Vector vector);

#endif __MAP__
