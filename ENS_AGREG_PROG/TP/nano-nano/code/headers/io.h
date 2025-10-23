// io.h
#ifndef IO_H
#define IO_H

#include <stdlib.h> 
#include <string.h>
#include "struct.h"

/**
 * @brief Loads a text file into the buffer line by line.
 *
 * Handles stripping newline characters at the end of each line.
 *
 * @param B Pointer to the buffer to populate.
 * @param path Path to the file to open.
 * @return 0 on success, -1 on failure (e.g., file not found).
 */
int file_load(Buffer *B, const char *path);

/**
 * @brief Saves the buffer contents back to the specified file.
 *
 * Writes each line with '\n' separators between them.
 *
 * @param B Pointer to the buffer to write.
 * @param path Output file path.
 * @return 0 on success, -1 on write error.
 */
int file_save(const Buffer *B, const char *path);

#endif // IO_H