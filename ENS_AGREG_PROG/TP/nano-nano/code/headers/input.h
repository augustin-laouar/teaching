// input.h
#ifndef INPUT_H
#define INPUT_H

#include "struct.h"

/**
 * @brief Moves the cursor one character left, wrapping to the previous line if needed.
 */
void move_left(Editor *E);

/**
 * @brief Moves the cursor one character right, wrapping to the next line if needed.
 */
void move_right(Editor *E);

/**
 * @brief Moves the cursor one line up.
 */
void move_up(Editor *E);

/**
 * @brief Moves the cursor one line down.
 */
void move_down(Editor *E);

/**
 * @brief Inserts a printable character at the current cursor position.
 */
void insert_char_at_cursor(Editor *E, char ch);

/**
 * @brief Inserts a newline at the current cursor position (splits the line).
 */
void insert_newline_at_cursor(Editor *E);

/**
 * @brief Handles backspace: deletes the previous character or joins lines.
 */
void backspace_at_cursor(Editor *E);

/**
 * @brief Centralized key handler for user input.
 *
 * Interprets keystrokes for navigation, editing, saving, and quitting.
 */
void handle_key(Editor *E, int key);

#endif // INPUT_H