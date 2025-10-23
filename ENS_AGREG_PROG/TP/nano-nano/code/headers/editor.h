// editor.h
#ifndef EDITOR_H
#define EDITOR_H

#include <string.h>
#include "struct.h"
#include "buffer.h"
#include "io.h"

/**
 * @brief Initializes the editor, loads the given file, and starts ncurses mode.
 *
 * @param E Pointer to the Editor instance to initialize.
 * @param filename Path to the file to open (may be NULL or non-existent).
 */
void editor_init(Editor *E, const char *filename);

/**
 * @brief Frees all editor resources and closes ncurses.
 *
 * @param E Pointer to the Editor instance to clean up.
 */
void editor_free(Editor *E);

/**
 * @brief Updates the status bar message.
 *
 * Accepts printf-like arguments to format a short message displayed
 * in the status bar.
 *
 * @param E Pointer to the Editor.
 * @param fmt printf-style format string.
 * @param ... Additional arguments.
 */
void editor_set_status(Editor *E, const char *fmt, ...);

#endif // EDITOR_H