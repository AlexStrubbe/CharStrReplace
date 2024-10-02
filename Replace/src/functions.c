#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

/**
 * @brief Replaces all occurrences of a character in a string with another
 * character.
 *
 * This function iterates through the source string `src`, replacing every
 * occurrence of the character `find` with the character `replacement`. The
 * result is stored in the destination string `dst`, which is dynamically
 * allocated.
 *
 * @param src The source string where characters will be replaced.
 * @param dst Pointer to the destination string where the result will be stored.
 * @param find The character to find and replace.
 * @param replacement The character to replace `find` with.
 *
 * @note The function will exit with an error if the source string is too long.
 */
void Replace(char* src, char* dst, char find, char replacement) {
  int i;
  size_t length = strlen(src);

  if (length >= MAX_LENGTH) {
    fprintf(stderr,
            "Error: Source string is too long for the destination buffer\n");
    exit(EXIT_FAILURE);
  }

  *dst = (char*)malloc((length + 1) * sizeof(char));
  if (*dst == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  for (i = 0; src[i] != '\0'; i++) {
    if (src[i] == find) {
      dst[i] = replacement;
    } else {
      dst[i] = src[i];
    }
  }
  dst[length] = '\0';
}

/**
 * @brief Inserts a substring at each occurrence of a character in a string.
 *
 * This function creates a new string `dst` by inserting the substring `ins` at
 * each occurrence of the character `find` in the source string `src`. The
 * resulting string is dynamically allocated.
 *
 * @param src The source string where characters will be replaced.
 * @param dst Pointer to the destination string where the result will be stored.
 * @param find The character to find and replace.
 * @param ins The substring to insert in place of `find`.
 *
 * @note The function will exit with an error if memory allocation fails.
 */
void Insert(char* src, char* dst, char find, char* ins) {
  int i;
  size_t src_len = strlen(src);
  size_t ins_len = strlen(ins);
  size_t result_len = 0;
  const char* p = src;

  while (*p != '\0') {
    if (*p == find) {
      result_len += ins_len;
    } else {
      result_len++;
    }
    p++;
  }

  *dst = (char*)malloc(result_len + 1);
  if (*dst == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  while (*src != '\0') {
    if (*src == find) {
      for (i = 0; ins[i] != '\0'; i++) {
        *dst = ins[i];
        *dst++;
      }
    } else {
      *dst = *src;
      *dst++;
    }
    *src++;
  }
  *dst = '\0';
}
