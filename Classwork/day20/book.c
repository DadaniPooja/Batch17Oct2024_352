/*Q1.

The first line contains an integer N, denoting the total number of books.
Next, N lines contain a string that denotes "title", "author", and "genre" separated by a comma.
Note: In code stub, you get 2D array books: where the 0th column denotes the title,
      the 1st column denotes the author, and the 2nd column denotes the genre

Input:

4
The Great Gatsby,F. Scott Fitzgerald,fiction
The Diary of a Young Girl,Anne Frank,non-fiction
Harry Potter and the Philosophers Stone,J.K. Rowling,children
The Catcher in the Rye,J.D. Salinger,fiction

Output:
Harry Potter and the Philosophers Stone
The Great Gatsby
The Catcher in the Rye
The Diary of a Young Girl

Explanation

The sorted genre is: [children, fiction, fiction, non-fiction].
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(((char **)a)[2], ((char **)b)[2]);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char ***books = (char ***)malloc(N * sizeof(char **));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        books[i] = (char **)malloc(3 * sizeof(char *));
        if (books[i] == NULL) {
            printf("Memory allocation failed for book %d!\n", i + 1);
            return 1;
        }

        for (int j = 0; j < 3; j++) {
            books[i][j] = (char *)malloc(100 * sizeof(char));
            if (books[i][j] == NULL) {
                printf("Memory allocation failed for field %d of book %d!\n", j + 1, i + 1);
                return 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        char line[300];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",");
        int j = 0;
        while (token != NULL) {
            if (j < 3) {
                strcpy(books[i][j], token);
            }
            token = strtok(NULL, ",");
            j++;
        }
    }

    qsort(books, N, sizeof(books[0]), compare);

    for (int i = 0; i < N; i++) {
        printf("%s\n", books[i][0]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            free(books[i][j]);
        }
        free(books[i]);
    }
    free(books);

    return 0;
}

