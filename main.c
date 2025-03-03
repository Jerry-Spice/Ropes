#include <stdio.h>
#include <stdlib.h>
#include "Ropes.h"

#define LOOP_LIMIT 10000


int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Err. Please enter more arguments:\n");
        printf("%s <file_2_parse.txt> <file_2_ouput>\n", argv[0]);
    }

    Rope* root = createRope();
    root = fileToRope(argv[1]);
    ropeToFile(argv[2], root);
    destroyRope(root);



    printf("\n");
    return 0;
}
