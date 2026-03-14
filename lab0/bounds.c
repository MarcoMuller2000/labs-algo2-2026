#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length){  //arr = {0, -1, 9, 4}, value = 9
    struct bound_data result;
    unsigned int i;

    result.is_upperbound = true;
    result.is_lowerbound = true;
    result.exists = false;
    result.where = 0;
    i = 0;
    
    while (i < length) {
        result.is_upperbound = result.is_upperbound && (value >= arr[i]);
        result.is_lowerbound = result.is_lowerbound && (value <= arr[i]);
        if (arr[i] == value && !result.exists){
            result.where = i;
        }
        result.exists = result.exists || (value == arr[i]);
        i++;
    }

    return result;
}

    
int main () {
    unsigned int length;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%u",&length);
    int arr[length];

    unsigned int i;
    i = 0;
    int value;

    while (i < length){
    printf("Ingrese un elemento %u: ",i);
    scanf("%d", &arr[i]);
    i++;
    }

    printf("Ingrese un valor: ");
    scanf("%d",&value);
    
    struct bound_data result;
    result = check_bound(value, arr, length);

    if (result.is_upperbound) {
        printf ("Es cota superior\n");
    } else {
        printf("No es cota superior\n");
    }

    if (result.is_lowerbound) {
    printf("Es cota inferior\n");
} else {
    printf("No es cota inferior\n");
}

if (result.exists) {
    printf("El valor existe en la posicion %u\n", result.where);
} else {
    printf("El valor no existe en el arreglo\n");
}
    return 0;
}
