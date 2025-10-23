// render.h
#ifndef RENDER_H
#define RENDER_H

#include <string.h>
#include "struct.h"

/**
 * @brief Adjusts scrolling offsets so the cursor remains visible on screen.
 */
void ensure_cursor_visible(Editor *E);

/**
 * @brief Draws the visible text region (main editor area) on screen.
 */
void draw_text(const Editor *E);

/**
 * @brief Draws the bottom status bar with file info and messages.
 */
void draw_status(const Editor *E);

/**
 * @brief Redraws the entire screen (text area + status bar).
 */
void redraw(Editor *E);


#endif // RENDER_H