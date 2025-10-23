#include "render.h"

void ensure_cursor_visible(Editor *E) {
    int text_rows = 0; // TODO
    if (E->cur.row < E->cur.row_offset) E->cur.row_offset = E->cur.row;
    if (E->cur.row >= E->cur.row_offset + (size_t)text_rows) {
        E->cur.row_offset = E->cur.row - (size_t)text_rows + 1;
    }
    if (E->cur.col < E->cur.col_offset) E->cur.col_offset = E->cur.col;
    if (E->cur.col >= E->cur.col_offset + (size_t)E->screen_cols) {
        E->cur.col_offset = E->cur.col - (size_t)E->screen_cols + 1;
    }
}

void draw_text(const Editor *E) 
{
    int text_rows = 0; // TODO
    for (int y = 0; y < text_rows; ++y) {
        int buf_row = (int)E->cur.row_offset + y;
        move(y, 0);
        clrtoeol();
        if (buf_row >= 0 && (size_t)buf_row < E->buf.count) {
            const Line *L = &E->buf.lines[buf_row];
            size_t start = E->cur.col_offset;
            if (start < L->len) {
                int max_cols = E->screen_cols;
                int to_print = (int)((L->len - start) < (size_t)max_cols
                                     ? (L->len - start) : (size_t)max_cols);
                if (to_print > 0) addnstr(L->data + start, to_print);
            }
        }
    }
    // Cursor position
    int vx = 0; // TODO
    int vy = 0; // TODO
    if (vy >= 0 && vy < text_rows && vx >= 0 && vx < E->screen_cols) {
        move(vy, vx);
    } else {
        move(text_rows - 1, E->screen_cols - 1);
    }
}

void draw_status(const Editor *E) {
    int save_y, save_x;
    getyx(stdscr, save_y, save_x);

    attron(A_REVERSE);
    char left[128];
    snprintf(left, sizeof(left), " %s %s  | lines:%zu ",
             E->filename[0] ? E->filename : "[NoName]",
             E->dirty ? "(modified)" : "          ",
             E->buf.count);
    mvhline(E->screen_rows - 1, 0, ' ', E->screen_cols);
    mvaddnstr(E->screen_rows - 1, 0, left, E->screen_cols);

    int used = (int)strlen(left);
    if (used < E->screen_cols && E->status[0]) {
        int start = E->screen_cols - (int)strlen(E->status) - 1;
        if (start < used) start = used;
        mvaddnstr(E->screen_rows - 1, start, E->status, E->screen_cols - start);
    }
    attroff(A_REVERSE);

    move(save_y, save_x);
}


void redraw(Editor *E)
{
    getmaxyx(stdscr, E->screen_rows, E->screen_cols);
    ensure_cursor_visible(E);
    clear();
    draw_text(E);
    draw_status(E);
    refresh();
}