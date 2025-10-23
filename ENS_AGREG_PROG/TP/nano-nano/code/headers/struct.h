// struct.h
#ifndef STRUCT_H
#define STRUCT_H

#define _XOPEN_SOURCE 700
#include <ncurses.h>
#include <stddef.h>

#define MAX_FILENAME 4096
#define STATUS_MSG_MAX 256

/// Shortcut macro to interpret Ctrl-key combinations.
#define CTRL_KEY(k) ((k) & 0x1f)
#define CUSTOM_KEY_SAVE    CTRL_KEY('s')  ///< Ctrl+S for saving.
#define CUSTOM_KEY_QUIT    CTRL_KEY('q')  ///< Ctrl+Q for quitting.


/**
 * @struct Line
 * @brief Represents a single editable line of text.
 *
 * Each line is dynamically allocated and can grow or shrink as the user edits.
 * The newline character ('\\n') is never stored inside `data`.
 */
typedef struct {
    char  *data;   ///< UTF-8 text content (null-terminated, without newline)
    size_t len;    ///< Logical length in bytes (excluding null terminator)
    size_t cap;    ///< Allocated capacity
} Line;

/**
 * @struct Buffer
 * @brief Represents the full text buffer as a dynamic array of lines.
 *
 * The buffer maintains all lines of the opened file in memory, allowing
 * random access and modification.
 */
typedef struct {
    Line  *lines;  ///< Array of editable lines
    size_t count;  ///< Number of lines currently in the buffer
    size_t cap;    ///< Allocated capacity for lines
} Buffer;

/**
 * @struct Cursor
 * @brief Represents the logical and visual position of the cursor.
 *
 * Keeps track of the text position (row/column) and scrolling offsets
 * for rendering within the ncurses window.
 */
typedef struct {
    size_t row;         ///< Logical row index in the buffer
    size_t col;         ///< Logical column index within the line
    size_t row_offset;  ///< First visible line index (for vertical scrolling)
    size_t col_offset;  ///< First visible column index (for horizontal scrolling)
} Cursor;

/**
 * @struct Editor
 * @brief Holds the global state of the editor.
 *
 * The editor contains the loaded buffer, the cursor state, filename,
 * modification status, screen dimensions, and temporary status messages.
 */
typedef struct {
    Buffer buf;                         ///< The text buffer
    Cursor cur;                         ///< The cursor state
    char   filename[MAX_FILENAME];      ///< Currently opened file path
    int    dirty;                       ///< 1 if the buffer has unsaved changes
    char   status[STATUS_MSG_MAX];      ///< Status bar message
    int    screen_rows, screen_cols;    ///< Terminal dimensions
} Editor;

#endif // STRUCT_H