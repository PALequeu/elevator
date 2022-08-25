#include<ncurses.h>

#define HEIGHT 50
#define WIDTH 70

int main() {
    initscr();
    cbreak();
    noecho();
    WINDOW *win=stdscr;
    keypad(win, TRUE);
    nodelay(win, TRUE);
    
    box(win,0,0);

    int loop=1;

    while(loop){
        int ch = getch();
        int cursor_x = getcurx(win);
        int cursor_y = getcury(win);

        if (ch == KEY_RIGHT){
            wmove(win,cursor_y,cursor_x+1);
            wrefresh(win);
            }
        if (ch == KEY_LEFT){
            wmove(win,cursor_y,cursor_x-1);
            wrefresh(win);
            }
        if (ch == KEY_UP){
            wmove(win,cursor_y-1,cursor_x);
            wrefresh(win);
            }
        if (ch == KEY_DOWN){
            wmove(win,cursor_y+1,cursor_x);
            wrefresh(win);
            }
         if (ch == KEY_DC){
            loop=0;
            }
    }
    
    endwin();
    
    return 0;
    
}