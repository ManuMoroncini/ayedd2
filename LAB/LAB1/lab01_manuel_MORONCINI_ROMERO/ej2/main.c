/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000


unsigned int array_from_console(
  int array[],
  unsigned int max_size)
{
  // Abro el archivo
  FILE *f;
  f = stdin;
  // Consigo su tamanio
  unsigned int length;
  printf("Ingresar el largo del array: ");
  fscanf(f, "%u", &length);

  // Corto la length en el max size si este es menor
  if(max_size < length){
    length = max_size;
  }

  // Voy leyendo y agregando los numeros
  for(unsigned int i=0;i<length;i++){
    fscanf(f, "%d", &array[i]);
  }
  fclose(f);
  return length;

}

void array_dump(int a[], unsigned int length) {
  printf("[");
  for(unsigned int i=0; i<length; i++) 
  {
    if(i != length-1 ){
      printf(" %d,", a[i]);
    }
    else {
      printf(" %d", a[i]);
    }
  }
  printf("]\n");
}


int main(void) {

    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_console(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}