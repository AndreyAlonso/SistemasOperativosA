/***************************************************************************************
 * Proyecto:    Practica 10
 * Fecha:       11 mayo 2018
 * Integrantes: Hernandez Alonso 
 ***************************************************************************************/


// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------
int *Buffer;

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}
/***********************************************************************************************
 * Funciones Agregadas:
 * Ordena
 * calculaFactorial
 * factorial
 * calculaPromedio
 * *********************************************************************************************/


// Ordena el arreglo de manera descendiente 
// y lo muestra en pantalla
void ordena(int which)
{
    printf("\n\nORDENACION DEL ARREGLO... \n");
    int i,j; //contadores del arreglo
    int aux = 0; //variable auxiliar
    //Algorito de ordenacion de forma descendiente
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(Buffer[j] < Buffer[j+1]){
                aux = Buffer[j];
                Buffer[j] = Buffer[j+1];
                Buffer[j+1] = aux;
            }
        }
    }

    for(i = 0; i < 5; i++){
        printf("[ %d ]\n",Buffer[i]);
    
    }
    currentThread->Yield();
     
   
}
// funcion recursiva que obtiene el factorial de un numero
int calculaFactorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else{
        return (n * calculaFactorial(n-1));
    }
}
// Funcion encargada de encontrar el numero mayor
// lo envia a la funcion calculaFactorial
// e imprime el resultado
void factorial(int which)
{
    
    int i;
    int mayor;
    int f;
    mayor = Buffer[0];
    for(i =0; i < 5; i++)
    {
        if(mayor < Buffer[i])
        {
            mayor = Buffer[i];
        }
    }
    printf("\nMayor: %d\n",mayor);
    f = calculaFactorial(mayor);
    printf("\n\nFactorial: %d\n\n",f);
    currentThread->Yield();
    
}
void calculaPromedio(int which)
{
    int i;
    int promedio;
    promedio = 0;
    for(i = 0; i < 5; i++)
    {
        promedio = promedio + Buffer[i];
    }
    promedio = promedio/5;
    printf("\n\nPromedio: %d\n\n", promedio);
    currentThread->Yield();

}




//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
   
   int val;
   int i;
   int opcion;
   Thread *t, *t1, *t2, *t3;
   Buffer = new int[5];

    printf("\n--------------------------------------------------\n");
    printf("\n\tHernandez Alonso Andrey\n");
    printf("\n--------------------------------------------------\n");

    printf("\nMENU\n");
    printf("-----------------------------\n");
    printf("1. SimpleThread\n");
    printf("2. Ejemplo de hilos(FCFS)\n");
    printf("3. Salir\n"); 
    scanf("%d",&opcion);

    
    
    switch(opcion)
    {
        case 1:
            DEBUG('t', "Entering SimpleTest");
            t = new Thread("forked thread");
            t->Fork(SimpleThread, 1);
            SimpleThread(0);
        break;
        case 2:

            printf("\n\nEstoy en 2\n\n");
            for(i = 0; i < 5; i++){
                printf("[%d] = ", i);
                scanf("%d",&Buffer[i]);
            }
            printf("Declarando hilos");
            // Declaracion de los 3 hilos
            t1 = new Thread("hilo 1");
            t2 = new Thread("hilo 2");
            t3 = new Thread("hilo 3");
            t1->Fork(ordena,1);
            t2->Fork(factorial,1);
            t3->Fork(calculaPromedio,1);
            //SimpleThread(0);
            

        break;
        case 3:
            printf("Saliendo...\n" );
        break;
    }

}

    




