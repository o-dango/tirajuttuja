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


void printInorder(pTree pNode) {

    if(pNode) {

        printInorder(pNode->pLeft);
        printf("%d\t", pNode->node);
        printInorder(pNode->pRight);

    }

}


int searchKey(pTree pNode, int key) {

	if(pNode == NULL) {

		return 0;

	}

	else if(pNode->node == key) {

		return pNode->node;

	}

	else if(pNode->node > key) {

		searchKey(pNode->pLeft, key);

	}

	else {

		searchKey(pNode->pRight, key);

	}

}


void firstList(void) {

    int i;
	int key;
    int table[] = {8, 9, 10, 2, 1, 5, 3, 6, 4};
    pTree pStart = NULL;

	printf("Lisättävät alkiot:\n");

    for(i = 0; i < 7; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    printf("Lisätään alkiot listaan.\n");
    for(i = 0; i < 7; i++) {

        pStart = addNumber(pStart, table[i]);

    }

    printTree(pStart, 0);

	printf("Hae arvoa: ");
	scanf("%d", &key);

	int result = searchKey(pStart, key);

	if(result != 0) {

		printf("Löydettiin avain %d!\n", result);

	}

	else {

		printf("Avainta ei löytynyt!\n");

	}

	printf("Tulostetaan järjestyksessä: \n");
	printInorder(pStart);
	printf("\n");

    emptyTree(pStart);
    printf("\nMuisti vapautettu!\n");
	printf("＼\\ ٩( ᐛ )و /／\n");

}



int main(void) {

    firstList();

    return 0;

}
