//============================================================================
// Ohjelmointiharjoitus 1 : Jarjestely järjestelyalgoritmi; Selection Sort
// Tekija      : Jonathan Soinio
//============================================================================
#include <stdio.h>

//============================================================================
// Paa funktio
int main() {

    //listan alustus
    int a[] =  {7,2,10,63,1,109,34};
    int length = 6;

    //for loop joka etsii jarjestamattoman listan pienimman numeron paikan arvon listassa
    for (int i=0; i < length -1; i++) {

        int min = i;
        for ( int j = i +1; j < length; j++)
            if (a[j] <a[min]) min = j;


        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }

    }

    //tulostaa jarjestellyn listan
    for (int i = 0; i< length; i++)
        printf("[%d] = %d ", i, a[i]);

    return 0;
}
//============================================================================