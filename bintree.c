#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {

    int node;
    int status;
    struct tree *pLeft;
    struct tree *pRight;

}; typedef struct tree *pTree;


/*struct tree *addNumber(pTree pNode, int number) {

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

}*/

void rotate_left(pTree *pNode, int *status) {

    pTree child, grandchild;

    child = (*pNode)->pLeft;

    if(child->status == 1) {  //LL-kierto

        printf("Tehdään LL-kierto\n\n\n");
        (*pNode)->pLeft = child->pRight;
        child->pRight = *pNode;
        (*pNode)->status = 0;
        (*pNode) = child;

    }

    else { //LR-kierto

        printf("Tehdään LR-kierto\n\n\n");
        grandchild = child->pRight;
        child->pRight = grandchild->pLeft;
        grandchild->pLeft = child;
        (*pNode)->pLeft = grandchild->pRight;
        grandchild->pRight = *pNode;

        switch(grandchild->status) {

            case 1:
            (*pNode)->status = -1;
            child->status = 0;
            break;

            case 0:
            (*pNode)->status = child->status = 0;
            break;

            case -1:
            (*pNode)->status = 0;
            child->status = 1;
        }

        *pNode = grandchild;

    }

    (*pNode)->status = 0;
    *status = 0;

}

void rotate_right(pTree *pNode, int *status) {

    pTree child, grandchild;

    child = (*pNode)->pRight;

    if(child->status == -1) {  //RR-kierto

        printf("Tehdään RR-kierto\n\n\n");
        (*pNode)->pRight = child->pLeft;
        child->pLeft = *pNode;
        (*pNode)->status = 0;
        (*pNode) = child;

    }

    else { //RL-kierto

        printf("Tehdään RL-kierto\n\n\n");
        grandchild = child->pLeft;
        child->pLeft = grandchild->pRight;
        grandchild->pRight = child;
        (*pNode)->pRight = grandchild->pLeft;
        grandchild->pLeft = *pNode;

        switch(grandchild->status) {

            case 1:
            (*pNode)->status = 1;
            child->status = 0;
            break;

            case 0:
            (*pNode)->status = child->status = 0;
            break;

            case -1:
            (*pNode)->status = 0;
            child->status = -1;
        }

        *pNode = grandchild;

    }

    (*pNode)->status = 0;
    *status = 0;

}


void addNode(pTree *pNode, int number, int *stable) {

    if(!(*pNode)) {

        *stable = 1;
        if(!(*pNode = (pTree)malloc(sizeof(pTree)))) {
            perror("malloc");
            exit(1);
        }

        (*pNode)->pLeft = (*pNode)->pRight = NULL;
        (*pNode)->status = 0;
        (*pNode)->node = number;
    }

    else if(number < (*pNode)->node) {

        addNode(&(*pNode)->pLeft, number, stable);

        if(*stable) {

            switch((*pNode)->status) {

                case -1:
                (*pNode)->status = 0;
                *stable = 0;
                break;

                case 0:
                (*pNode)->status = 1;
                break;

                case 1:
                rotate_left(pNode, stable);
                break;

            }

        }

    }

    else if(number > (*pNode)->node) {

        addNode(&(*pNode)->pRight, number, stable);

        if(*stable) {

            switch((*pNode)->status) {

                case 1:
                (*pNode)->status = 0;
                *stable = 0;
                break;

                case 0:
                (*pNode)->status = -1;
                break;

                case -1:
                rotate_right(pNode, stable);
                break;

            }

        }

    }

    else {

        *stable = 0;
        printf("Luku %d on jo puussa\n", number);

    }

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

        printf("%d(%d)\n", pNode->node, pNode->status);
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

void printList(pTree pNode) {

    if(pNode) {

        printList(pNode->pRight);
        printf("%d\t", pNode->node);
        printList(pNode->pLeft);

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
    int stable = 0;
    int table[] = {8, 9, 10, 2, 1, 5, 3, 6, 4};
    pTree pStart = NULL;

	printf("Lisättävät alkiot:\n");

    for(i = 0; i < 7; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    printf("Lisätään alkiot listaan.\n");
    for(i = 0; i < 7; i++) {

        printf("Lisätään luku: %d", table[i]);
        getchar();

        printf("\n\n");
        addNode(&pStart, table[i], &stable);
        printTree(pStart, 0);
        printf("\n\n");

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

    emptyTree(pStart);
    printf("\nMuisti vapautettu!\n");
	printf("＼\\ ٩( ᐛ )و /／\n");

}



int main(void) {

    firstList();

    return 0;

}
