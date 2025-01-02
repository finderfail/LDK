#include "../../engine/include/Screen.h"
#include "../../engine/include/Map.h"
#include "../../engine/include/Player.h"
#include "../../engine/include/Raycaster.h"
#include "../../engine/include/Config.h"

#include <termios.h>
#include <unistd.h>
int main() {
  Config config;
  if (!config.load("./LDKGame/config/game.conf")) {
    return 1;
  }
 struct termios oldSettings, newSettings;
 tcgetattr(STDIN_FILENO, &oldSettings);
 newSettings = oldSettings;
 newSettings.c_lflag &= ~(ICANON | ECHO);
 tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
  int screenWidth = config.getInt("screenWidth");
  int screenHeight = config.getInt("screenHeight");
  Screen screen(screenWidth, screenHeight);
  Map map;
  if (!map.load("./LDKGame/maps/map.txt")) {
    return 1;
  }
 float playerStartX = config.getInt("playerStartX");
  float playerStartY = config.getInt("playerStartY");
  float playerStartDir = config.getInt("playerStartDir") * M_PI / 180.0f;
  Player player(playerStartX, playerStartY, playerStartDir);
  Raycaster raycaster(map, screen);
  bool isRunning = true;
  while(isRunning)
  {
      screen.clear();
      raycaster.castRays(player);
      screen.draw();
      char move = std::getchar();
      if (move == 'w') player.move(0.1);
      if (move == 's') player.move(-0.1);
      if (move == 'a') player.rotate(-0.1);
      if (move == 'd') player.rotate(0.1);
      if (move == 'q') isRunning = false;
   }
 tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
  return 0;
}
