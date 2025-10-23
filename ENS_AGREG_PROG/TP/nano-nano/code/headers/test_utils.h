#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include "struct.h"
#include <stdio.h>

/**
 * @brief Prints the content of a single line, including its text, length, and capacity.
 *
 * @param L Pointer to the line to print.
 * @param index Index of the line (useful for debugging).
 */
void print_line(const Line *L, size_t index);

/**
 * @brief Prints the current state of the buffer: number of lines, capacity,
 *        and the content of each line.
 *
 * @param B Pointer to the buffer to display.
 */
void print_buffer(const Buffer *B);

#endif // TEST_UTILS_H