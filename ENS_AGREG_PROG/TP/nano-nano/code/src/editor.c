#include "editor.h"

void editor_init(Editor *E, const char *filename) 
{
    // TODO: Clear editor memory (with memset)

    // TODO: Init editor's buffer, filename and dirty

    // TODO: Cursor position

    // Init ncurses
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(1);
    refresh();
    getmaxyx(stdscr, E->screen_rows, E->screen_cols);


    // TODO: Open file with file_load

}

void editor_free(Editor *E) 
{
    endwin();
    // TODO
}
void editor_set_status(Editor *E, const char *fmt, ...) 
{
    va_list ap;
    va_start(ap, fmt);

    int n = vsnprintf(E->status, sizeof(E->status), fmt, ap);

    va_end(ap);

    if (n < 0 || (size_t)n >= sizeof(E->status)) 
    {
        n = (int)sizeof(E->status) - 1;
    }

    const char *help = "   |   Ctrl+S: Save  |  Ctrl+Q: Quit";
    size_t remaining = sizeof(E->status) - (size_t)n - 1;
    if (remaining > 0) {
        strncat(E->status, help, remaining);
    }
}