#include <stdio.h>
#include <ncurses.h>

struct Dete {
   WINDOW *childwin;
   int width;
   int height;
   int x;
   int y;
};

int main() {
   WINDOW *mainwin;
   struct Dete dete, dete2;
   int ch;

   dete.width = 15;
   dete.height = 7;
   int rows = 30, cols = 30;

   dete.x = (cols - dete.width) / 2;
   dete.y = (rows - dete.height) / 2;

   if ( (mainwin = initscr()) == NULL ) {
      fprintf(stderr, "Error with main window");
   }

   noecho();
   keypad(mainwin, TRUE);

   dete.childwin = subwin(mainwin, dete.height, dete.width, dete.y, dete.x);
   box(dete.childwin, 0, 0);
   mvwaddstr(dete.childwin, 1, 4, "Move the window");
   mvwaddstr(dete.childwin, 2, 2, "with the arrow keys");     
   mvwaddstr(dete.childwin, 3, 6, "or HOME/END");     
   mvwaddstr(dete.childwin, 5, 3, "Press 'q' to quit");

   refresh();

   while ( (ch = getch()) != 'q') {
      switch(ch) {
         case KEY_UP:
            if (dete.y > 0)
               --dete.y;
            break;
         case KEY_DOWN:
            if (dete.y < (rows-dete.height)) ++dete.y;
            break;
         case KEY_LEFT:
            if (dete.x > 0) dete.x--;
            break;
         case KEY_RIGHT:
            if (dete.x < (cols - dete.width)) ++dete.x;
            break;
         case KEY_HOME:
            dete.x = 0;
            dete.y = 0;
            break;
      }
      mvwin(dete.childwin, dete.y, dete.x);
      wrefresh(dete.childwin);
   }

   delwin(dete.childwin);
   delwin(mainwin);
   endwin();
   refresh();
   return 1;
}
