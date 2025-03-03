/* Ropes.h
 @author Josh Brandon
 -> This is my custom ropes header file that I've written to help me deal with unknown lengths of strings
*/

#ifndef ROPES_H
#define ROPES_H

struct Rope {
    char content[100]; // this is an arbitrary limit
    struct Rope* nextLink; // linked list moment
};

typedef struct Rope Rope; // I hate writing struct

#endif // ROPES_H

// allocates memory for a rope and returns the address
Rope* createRope() {
    return (Rope*)malloc(sizeof(Rope));
}

// frees the memory of a rope memory passed in
void destroyRope(Rope* target) {
    free(target);
}

// turns a file's worth of data into a link of ropes
Rope* fileToRope(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return createRope();
    }

    Rope* root = createRope();
    Rope* currentRope = root;

    char curChar = fgetc(file);
    int index = 0;
    while (curChar != EOF) {
        if (index >= 100) {
            currentRope->nextLink = createRope();
            currentRope = currentRope->nextLink;
            currentRope->nextLink = NULL;
            index = 0;
        }
        currentRope->content[index] = curChar;
        // printf("%c", currentRope->content[index]);
        index++;
        curChar = fgetc(file);
    }

    if (curChar == EOF) {
        currentRope->nextLink = createRope();
        currentRope = currentRope->nextLink;
        currentRope->content[0] = '\0';
    }

    fclose(file);

    return root;
}

// turns a link of ropes into a file
void ropeToFile(char* filename, Rope* root) {
    Rope* currentRope = root;
    FILE* file = fopen(filename, "w");
    while (currentRope != NULL) {
        fprintf(file, "%s", currentRope->content);
        currentRope = currentRope->nextLink;
    }
    fclose(file);
}
