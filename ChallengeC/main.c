#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define MAXCANTAZAR 1000

void intervaloPrimos(int,int);
void sumaArray(int []);
void ordenamientoBurbujeo(int [],int);
void mostrarArray(int [],int);
void arrayRepetidos(int [],int);
void piedraPapelTijera();
void salario();
void numerosAleatorios();

int main()
{
    int array[MAX] = {1,3,5,2,1};
    intervaloPrimos(1,20);
    intervaloPrimos(20,1);
    sumaArray(array);
    mostrarArray(array,5);
    printf("\n");
    ordenamientoBurbujeo(array,5);
    printf("\n");
    mostrarArray(array,5);
    arrayRepetidos(array,5);
    piedraPapelTijera();
    salario();
    numerosAleatorios();
    return 0;
}

void numerosAleatorios(){
  int i,a,b,c,cont,bandera;
  cont = 0;
  do{
    a = rand() % MAXCANTAZAR;  //genera aleatoriamente un numero entero entre 0 y MAXCANT
    b = rand() % MAXCANTAZAR;
    c = rand() % MAXCANTAZAR;
    printf("%d %d %d\n",a,b,c);
    cont++;
    bandera = a%2==0 && b%2==0 && c%2!=0; //variable para verificar si se cumple la condicion
    if(bandera){ //se cumple
      printf("se encontro par, par, impar!!\n");
      printf("numero de intentos: %d",cont);
    }else{       //no se cumple
      printf("no se consiguio par, par, impar\n");
      printf("presione una tecla cualquiera\n");
      getch();
    }
  }while(!bandera);
}

void salario(){
  char nombre[MAX];
  int edad;
  float salario;
  printf("ingrese nombre\n");
  scanf("%s",nombre);
  do{
    printf("ingrese edad\n");
    scanf("%d",&edad);
  }while(edad<0);     //verifico que sea mayor a 0
  do{
    printf("ingrese salario\n");
    scanf("%f",&salario);
  }while(salario<0);  //verifico que sea mayor a 0
  if(edad<16)
    printf("%s no tiene edad para trabajar",nombre);
  else{
    if(edad>=19 && edad<=50)
      salario += salario*0.05;
    else if(edad>=51 && edad<=60)
      salario += salario*0.1;
    else
      salario += salario*0.15;
    printf("el salario de %s es: %f",nombre,salario);
  }
}

void piedraPapelTijera(){
  char opcion1,opcion2;
  printf("ingrese P para piedra / A para papel / T para tijera\n");
  do{
    printf("\ningrese opcion de jugador 1\n");
    opcion1 = toupper(getche());
  }while(opcion1!='P' && opcion1!='A' && opcion1!='T');
  do{
    printf("\ningrese opcion de jugador 2\n");
    opcion2 = toupper(getche());
  }while(opcion2!='P' && opcion2!='A' && opcion2!='T');
  printf("\n");
  if(opcion1=='P'){
    switch(opcion2){
      case 'P': printf("empate");
      break;
      case 'A': printf("gana jugador2");
      break;
      case 'T': printf("gana jugador1");
      break;
    }
  }else if(opcion1=='A'){
      switch(opcion2){
      case 'P': printf("gana jugador1");
      break;
      case 'A': printf("empate");
      break;
      case 'T': printf("gana jugador2");
      break;
    }
  }else{
      switch(opcion2){
      case 'P': printf("gana jugador 2");
      break;
      case 'A': printf("gana jugador 1");
      break;
      case 'T': printf("empate");
      break;
    }
  }
}

void arrayRepetidos(int array[],int k){
  int i,j;
  printf("\nnumeros repetidos en el array: \n");
  for(i=0;i<k;i++){  //pivote
    j = i+1;
    while(j<k && array[i]!=array[j])  //busca si no esta repetido en todo el array
      j++;
    if(j<k && array[i]==array[j])     //esta repetido
      printf("%d ",array[i]);
  }
}

void mostrarArray(int array[],int k){ //funcion para testear
  int i;
  for(i=0;i<k;i++)
    printf("%d ",array[i]);
}

void ordenamientoBurbujeo(int array[],int k){ //k es el tamaño del array
  int i,j,aux;
  for(i=1;i<k;i++)
    for(j=0;j<k-1;j++)
      if(array[j] > array[j+1]){//compara
        aux = array[j];         //intercambia
        array[j] = array[j+1];
        array[j+1] = aux;
      }
}

void sumaArray(int array[]){
  int i,num,suma,largoArray;
  largoArray = 5;
  suma = 0;
  for(i=0;i<largoArray;i++){
    printf("ingrese un numero\n");
    scanf("%d",&num); //lee
    array[i] = num;   //guardo en el array
    suma += num;      //sumo
  }
  printf("la suma es: %d\n",suma);
  printf("numeros en orden inverso: \n");
  for(i=largoArray-1;i>=0;i--)  //recorre desde el indice 4 hasta 0
    printf("%d ",array[i]);
}


void intervaloPrimos(int a,int b){
  int i,k,aux;
  if(a>b){  //por ejemplo 10 y 5
    aux = a;
    a = b;
    b = aux;
  }
  for(i=a;i<=b;i++){ //muestra intervalo
    printf("numero: %d",i);
    k = 2;
    while(k<i && i%k!=0) //busco divisores entre 2 hasta el k-1
      k++;
    if(k==i)
      printf(" es primo\n");
    else
      printf(" no es primo\n");
  }
}
