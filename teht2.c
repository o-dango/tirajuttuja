/*Procedure lajittelu(var A: kokonaislukutaulukko,
                     var n: taulukon koko);
Var i,j
Begin
  For i := 1 to n-1 do
    For j := n downto i+1 do
      If A[j-1] > A[j] then
        swap(A[j-1],A[j]);
      End;
    End;
  End;
End;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    int size;
    int i = 0;
    int j;
    int temp;

    printf("Kokonaislukutaulukon lajittelu\n");

    printf("Syötä taulukon koko: ");
    scanf("%d", &size);

    int table[size];

    for(i; i < size; i++) {

        printf("Syötä kokonaislukualkio: ");
        scanf("%d", &table[i]);

    }

    printf("Järjestämätön taulukko: ");
    for(i = 0; i < size; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    i = 0;
    j = size - 1;

    for(i; i < size; i++) {
        j = size - 1;
        for(j; j > i; j--) {

            if(table[j-1] > table[j]) {

                temp = table[j-1];
                table[j-1] = table[j];
                table[j] = temp;

            }

        }

    }

    printf("Järjestetty taulukko: ");
    for(i = 0; i < size; i++) {

        printf("%d\t", table[i]);

    }
    printf("\n");

    return 0;
}
