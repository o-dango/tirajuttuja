#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {

    int node;
    struct tree *pLeft;
    struct tree *pRight;

}; typedef struct tree *pTree;


struct tree *addNumber(pTree pNode, int number) {

    struct tree *ptrNew = NULL;
    struct tree *ptr = NULL;


    if(pNode == NULL) {

        ptrNew = (struct tree*)malloc(sizeof(struct tree));
        ptrNew->node = number;
        ptrNew->pRight = NULL;
        ptrNew->pLeft = NULL;
        pNode = ptrNew;

        return pNode;

    }

    else {

        if((pNode->node) > number) {

            pNode->pLeft = addNumber(pNode->pLeft, number);

        }

        else if((pNode->node) < number){

            pNode->pRight = addNumber(pNode->pRight, number);

        }

        else {

            return pNode;

        }

    }

    return pNode;

}



void emptyTree(pTree pNode) {

    if(pNode) {

        emptyTree(pNode->pRight);
        emptyTree(pNode->pLeft);
        free(pNode);

    }

}


void printTree(pTree pNode, int i) {

    i++;

    if(pNode) {

        printTree(pNode->pRight, i);
        for(int j = 1; j < i; j++) {
            printf("\t");
        }

        printf("%d\n", pNode->node);
        printTree(pNode->pLeft, i);

    }

}


void firstList(void) {

    int i;
    int table[] = {25, 23, 28, 16, 44, 24, 27};
    pTree pStart = NULL;

    printf("Ensimmäinen lista...\n");

    for(i = 0; i < 7; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    printf("Lisätään alkiot listaan.\n");
    for(i = 0; i < 7; i++) {

        pStart = addNumber(pStart, table[i]);

    }

    printTree(pStart, 0);

    emptyTree(pStart);
    printf("\nTyhjennetty:3\n\n");

}


void secondList(void) {

    int i;
    int table[] = {44, 28, 27, 23, 16, 24, 25};
    pTree pStart = NULL;

    printf("Toinen lista...\n");

    for(i = 0; i < 7; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    printf("Lisätään alkiot listaan.\n");
    for(i = 0; i < 7; i++) {

        pStart = addNumber(pStart, table[i]);

    }

    printTree(pStart, 0);

    emptyTree(pStart);
    printf("\nTyhjennetty:3\n");

}



int main(void) {

    firstList();
    secondList();

    return 0;

}
