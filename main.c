/* Program that prints a tree too specified height, with random ornaments
 * as well as having a trunk 1/4 the size of a tree
 * Stefan Conovali 539716 28/09/2022*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Return user inputed int
int getUserInput() {
    int input = 0;
    printf("Input height of tree: ");
    scanf("%d", &input);
    return input;
}

void printTree(int height) {
    // Init variables
    int spaces = height - 1;
    int stars = 1;

    // Loop for tree height
    for(int itHeight = 0; itHeight < height; itHeight++) {

        // Loop to insert spaces, calculated by height - 1
        for (int itSpaces = 0; itSpaces < spaces; itSpaces++) {
            printf(" ");
        }
        // Remove a space for next layer of drawing
        spaces--;

        // Insert stars in drawing
        for (int itStars = 0; itStars < stars; itStars++) {
            // Make the top a "!"
            if(stars == 1) printf("!");
            else {
                // Randomize lights and balls on tree
                int temp = rand() % 4;
                switch (temp) {
                    case 1:
                        printf("*");
                        break;
                    case 2:
                        printf("o");
                        break;
                    case 3:
                        printf("+");
                        break;
                    default:
                        printf("*");
                        break;
                }
            }
        }
        // Add 2 stars, because the tree is extending by one on either side
        stars+=2;

        // Start a new line
        printf("\n");
    }

    // Calculate the size of the trunk. Height / 4 rouned up
    int trunk = (int)(ceil((double)height / 4));
    spaces = height - 1;

    // Print the trunk, centering it using the spaces
    for(int itTrunk = 0; itTrunk < trunk; itTrunk++){
        for(int itSpaces = 0; itSpaces < spaces; itSpaces++){
            printf(" ");
        }
        printf("*\n");
    }
}

int main() {
    // Set a random seed using time
    srand(time(0));

    // Init variables
    int height = 0;

    // Get user height
    height = getUserInput();

    //Output tree
    printTree(height);

    return 0;
}
