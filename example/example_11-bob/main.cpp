
#include <SFML/Config.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Event.hpp>

#include <sxbCommon/utils.h>
#include "bob.h"

#if defined(SXB_SYSTEM_IOS)
    #include <SFML/Main.hpp>
#endif

int main(int argc, char *argv[])
 {
     // Create the main window
     sf::WindowBase window(sf::VideoMode(WNDW_WIDTH, WNDW_HEIGHT), "SFML window");
	 Bob bob;
	 bob.init(window.getWindowHandle());

	 uint64_t count = 0;

     // Start the game loop
     while (window.isOpen())
     {
         // Process events
		 sf::Event event;
         while (window.pollEvent(event))
         {
             // Close window: exit
             if (event.type == sf::Event::Closed)
                 window.close();
             else if (event.type == sf::Event::TouchBegan && event.touch.finger == 0)
                 bob.touchBegin(event.touch.x, event.touch.y);
             else if (event.type == sf::Event::TouchMoved && event.touch.finger == 0)
                 bob.touchMove(event.touch.x, event.touch.y);
             else if (event.type == sf::Event::TouchEnded && event.touch.finger == 0)
                 bob.touchEnd();
         }

		 bob.update(count);
		 count++;
     }

     return EXIT_SUCCESS;
 }
