#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
  int k;
  int i;
  int q;
  int contador;
  int a=0;
  int numLineas = 0;
  int numPal = 0;
  static int hashpalabras[10000];
  static int comparador[10000];
  static int contar[5000];
  int j=0;
  FILE *fp; 
  fp = fopen("entrada.txt", "r");

  char linea[5000]; 

  while ( fgets (linea, 1000, fp) != NULL ) { // Lee el archivo linea por linea
    linea[strcspn(linea, "\r\n")] = 0; // elimina el salto de linea de la palabra
    printf("\n\n linea: %i", numLineas);
    char delim[] = " "; // define como delimitador el espacio para separar cada palabra
    char *palabra = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
    while(palabra != NULL){   // recorre palabra a palabra
    
      if(numLineas==0){
        k = atoi(palabra);
        printf("\n K = %i",k);
      }
      else if(numLineas==1){

        printf("\n\nP %i: ", numPal);
        printf("'%s'\n", palabra); // ELIMINAR. Imprime la    palabra.
        int hash = 0;
        for(i=0;i<strlen(palabra);i++){
          
          int ascci = palabra[i];
          printf("\n '%c' a ascci: %i", palabra[i],ascci);
          hash += hash + (ascci * pow(k,i));
          
          if(hash >= 1000000){
            hash = hash % 1000000;
          }
          else if(hash<0){
            hash = hash * -1;
            if(hash >= 1000000){
              hash = hash % 1000000;
            }
          }
        }
        comparador[j]=hash;
        j++;
        printf("\nHASH = %i",hash);
      }
      else if(numLineas==2){
        q = atoi(palabra);
        printf("\n Q = %i",q);
      }

      else{
        int hash = 0;
        for(i=0;i<strlen(palabra);i++){
          
          int ascci = palabra[i];
          hash += hash + (ascci * pow(k,i));
          
          if(hash >= 1000000){
            hash = hash % 1000000;
          }
          else if(hash<0){
            hash = hash * -1;
            if(hash >= 1000000){
              hash = hash % 1000000;
            }
          }
        }
        hashpalabras[a]=hash;
        a++;
        printf("\nHASH = %i",hash);
      }
      palabra = strtok(NULL, delim); // vuelve a separar palabra a palabra. Si usted elimina esta linea el programa no se detiene
      numPal++;
    }
    numLineas++;
  }
  for(i=0;i<10000;i++)
  {
    if(comparador[i]!=0){
      printf("\n comparador = %d",comparador[i]); //la condicion está puesta para que solo muestre los espacios del arreglo que han sido ocupados
    }
  }
  for(a=0;a<10000;a++){
    contador = 0;
    if(hashpalabras[a]!=0){
      printf("\n\n hashpalabras = %d",hashpalabras[a]);
      for(i=0;i<10000;i++){
        if(hashpalabras[a]==comparador[i]){
          contador++;
        }
      }
      contar[a] = contador;
      printf(" %i", contador);
    }
    
  }
  FILE * salida = fopen("salida.txt", "w");
  for(i=0;i<q;i++){
    fprintf(salida, "%i %i\n", hashpalabras[i], contar[i]);
    
  }
  fclose(salida);
  fclose(fp); // cierra el archivo de entrada 

  return 0;
}
/*
Todos los print puestos en el código están ahí porque fueron una ayuda durante la creación, debido a que me permitian ver todo lo que necesitaba ver que realizaba la maquina*/