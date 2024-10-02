#include <stdio.h>
#include <string.h>

#include "functions.h"

#define MAX_LENGTH 1024

/**
 * @brief Main function for testing the Replace and Insert functions.
 *
 * This function demonstrates the use of the `Replace` and `Insert` functions by
 * performing the following operations:
 * 1. Replaces all occurrences of the character 'q' with 'g' in the string `s`,
 * storing the result in `c`.
 * 2. Inserts the substring "gato" at each occurrence of the character 'e' in
 * the string `s`, storing the result in `e`.
 * 3. Prints the original string `s`, the result of the `Replace` function
 * (`c`), and the result of the `Insert` function (`e`).
 *
 * @return An integer indicating the exit status of the program. Returns 0 on
 * successful execution.
 */
int main() {
  char s[] = "que tu quieres porque?"; /**< Original string to be processed. */
  char *g = "gato"; /**< Substring to be inserted in place of character 'e'. */
  char c[MAX_LENGTH]; /**< Buffer to store the result of character replacement.
                       */
  char e[MAX_LENGTH]; /**< Buffer to store the result of substring insertion. */

  Replace(s, c, 'q', 'g'); /**< Replace occurrences of 'q' with 'g' in string
                              `s` and store result in `c`. */
  Insert(s, e, 'e', g); /**< Insert substring `g` at each occurrence of 'e' in
                           string `s` and store result in `e`. */

  printf("%s \n", s); /**< Print the original string `s`. */
  printf("%s \n",
         c); /**< Print the result of the `Replace` function stored in `c`. */
  printf("%s \n",
         e); /**< Print the result of the `Insert` function stored in `e`. */

  return 0; /**< Return 0 to indicate successful execution. */
}
