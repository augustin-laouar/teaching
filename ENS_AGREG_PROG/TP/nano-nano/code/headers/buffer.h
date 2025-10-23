// buffer.h
#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * @brief Initializes a new empty line.
 */
void line_init(Line *L);

/**
 * @brief Frees the memory allocated for a line.
 */
void line_free(Line *L);

/**
 * @brief Ensures that the line has at least `need` bytes of capacity.
 */
void line_reserve(Line *L, size_t need);

/**
 * @brief Inserts a character at the given column index in the line.
 *
 * Shifts existing characters to the right.
 */
void line_insert_char(Line *L, size_t col, char ch);

/**
 * @brief Deletes a character to the left of the given column index.
 *
 * Typically used for backspace operations.
 */
void line_delete_char(Line *L, size_t col);

/**
 * @brief Initializes an empty buffer.
 */
void buffer_init(Buffer *B);

/**
 * @brief Frees all lines contained in the buffer.
 */
void buffer_free(Buffer *B);

/**
 * @brief Ensures the buffer has space for at least `need` lines.
 */
void buffer_reserve(Buffer *B, size_t need);

/**
 * @brief Inserts a new line at position `idx`.
 *
 * If `s` is provided, the line is initialized with that content.
 */
void buffer_insert_line(Buffer *B, size_t idx, const char *s);

/**
 * @brief Deletes the line at index `idx` from the buffer.
 */
void buffer_delete_line(Buffer *B, size_t idx);

/**
 * @brief Splits a line into two at the given column index.
 *
 * The current line is truncated and the remaining text is inserted
 * as a new line immediately below.
 */
void buffer_split_line(Buffer *B, size_t row, size_t col);

/**
 * @brief Joins the specified line with the one above it.
 *
 * Typically used when pressing backspace at the beginning of a line.
 */
void buffer_join_with_previous(Buffer *B, size_t row);

#endif // BUFFER_H