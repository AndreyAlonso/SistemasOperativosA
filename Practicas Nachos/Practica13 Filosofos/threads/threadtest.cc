/***************************************************************************************
 * Proyecto:    Practica 13 - Filosofos
 * Fecha:       22 mayo 2018
 * Integrantes: Garcia Rivera Braulio, Hernandez Alonso Andrey 
 * 
 * Clases modificadas:
 *  * thread.h
 *  * thread.cc
 *  * scheduler.cc
 * 
 * Funcionalidad:
 * 
 *
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



#include "synch.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------
int *Buffer;
int prioridad;
Semaphore *sem = new Semaphore("semaphore", 1);
Semaphore *palillo[6];

int *palillos;
int i = 1;
int c = 0;

void SimpleThread(int which)
{
    int num;

    for (num = 0; num < 5; num++)
    {
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

void sincroniza(int which)
{
    while(true)
    {
        printf("Hilo %d antes de seccion critica\n", which);
        palillo[which]->P();
        printf("Hilo %d tomo el palillo %d\n", which, which);
        c++;
        palillo[(which + 1)%5]->P();
        printf("Hilo %d tomo el palillo %d\n", which, (which+1)%5);
        c++;
        
        if (c == 2)
        {
            printf("\nHilo %d comiendo arroz\n\n", which);
                
           // currentThread->Yield();
            
            palillo[which]->V();
            printf("Hilo %d solto el palillo %d\n", which, which);
            c--;
      /*      if (which >= 5)
            {
                palillo[which]->V();
                printf("Hilo %d solto el palillo %d\n", which, 1);
            }
            else
            {*/
                palillo[(which + 1)%5]->V();
                printf("Hilo %d solto el palillo %d\n", which,(which+1)%5);
        //    }
            c--;
            
            
        }
        //  i++;
       // if(which != 5)
       currentThread->Yield();
            
      
    }
   
}

// Ordena el arreglo de manera descendiente
// y lo muestra en pantalla
void ordena(int which)
{
    printf("-----------------------------------------------\n");
    printf("ENTRADA HILO 1\n");
    printf("\n\nORDENACION DEL ARREGLO... \n");
    int i, j;    //contadores del arreglo
    int aux = 0; //variable auxiliar
    //Algorito de ordenacion de forma descendiente
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Buffer[j] < Buffer[j + 1])
            {
                aux = Buffer[j];
                Buffer[j] = Buffer[j + 1];
                Buffer[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("[ %d ]\n", Buffer[i]);
    }
    currentThread->Yield();
}
// funcion recursiva que obtiene el factorial de un numero
int calculaFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * calculaFactorial(n - 1));
    }
}
// Funcion encargada de encontrar el numero mayor
// lo envia a la funcion calculaFactorial
// e imprime el resultado
void factorial(int which)
{
    printf("-----------------------------------------------\n");
    printf("ENTRADA HILO 2\n");
    int i;
    int mayor;
    int f;
    mayor = Buffer[0];
    for (i = 0; i < 5; i++)
    {
        if (mayor < Buffer[i])
        {
            mayor = Buffer[i];
        }
    }
    printf("\nMayor: %d\n", mayor);
    f = calculaFactorial(mayor);
    printf("\n\nFactorial: %d\n\n", f);
    currentThread->Yield();
}
void calculaPromedio(int which)
{
    printf("-----------------------------------------------\n");
    printf("ENTRADA HILO 3\n");
    int i;
    int promedio;
    promedio = 0;
    for (i = 0; i < 5; i++)
    {
        promedio = promedio + Buffer[i];
    }
    promedio = promedio / 5;
    printf("\n\nPromedio: %d\n\n", promedio);
    currentThread->Yield();
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void ThreadTest()
{

    int val;
    int i;
    int opcion;
    Thread *t, *t1, *t2, *t3;
    Thread *f1, *f2, *f3, *f4, *f5;
    Buffer = new int[5];
    palillos = new int[5];
    palillo[0] = new Semaphore("semaphore", 1);
    palillo[1] = new Semaphore("semaphore", 1);
    palillo[2] = new Semaphore("semaphore", 1);
    palillo[3] = new Semaphore("semaphore", 1);
    palillo[4] = new Semaphore("semaphore", 1);
    palillo[5] = new Semaphore("semaphore", 1);

    printf("\n--------------------------------------------------\n");
    printf("\n\tGarcia Rivera Braulio\n");
    printf("\n\tHernandez Alonso Andrey\n");
    printf("\n--------------------------------------------------\n");

    printf("\nMENU\n");
    printf("-----------------------------\n");
    printf("1. SimpleThread\n");
    printf("2. Ejemplo de hilos(FCFS)\n");
    printf("3. Ejemplo de hilos(Prioridades no apropiativo)\n");
    printf("4. Semaforos\n");
    printf("5. Filosofos\n");
    printf("6. Salir\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        DEBUG('t', "Entering SimpleTest");
        t = new Thread("forked thread");
        t->Fork(SimpleThread, 1);
        SimpleThread(0);
        break;
    case 2:

        printf("\n\nEstoy en 2\n\n");
        for (i = 0; i < 5; i++)
        {
            printf("[%d] = ", i);
            scanf("%d", &Buffer[i]);
        }
        printf("Declarando hilos");
        // Declaracion de los 3 hilos
        t1 = new Thread("hilo 1");
        t2 = new Thread("hilo 2");
        t3 = new Thread("hilo 3");
        t1->Fork(ordena, 1);
        t2->Fork(factorial, 1);
        t3->Fork(calculaPromedio, 1);
        //SimpleThread(0);

        break;
    case 3:
        // Llenado del Buffer
        for (i = 0; i < 5; i++)
        {
            printf("[%d] = ", i);
            scanf("%d", &Buffer[i]);
        }
        // Seleccion de prioridad
        printf("-- PRIORIDAD --\n");
        printf("Hilo 1: \n");
        do
        {
            scanf("%d", &prioridad);
            if (0 > prioridad || prioridad > 5)
            {
                printf("Prioridad no valida inserte otra: ");
            }
        } while (0 > prioridad || prioridad > 5);
        t1 = new Thread("hilo 1", prioridad);
        printf("Hilo 2: \n");
        do
        {
            scanf("%d", &prioridad);
            if (0 > prioridad || prioridad > 5)
            {
                printf("Prioridad no valida inserte otra: ");
            }
        } while (0 > prioridad || prioridad > 5);
        t2 = new Thread("hilo 2", prioridad);
        printf("Hilo 3: \n");
        do
        {
            scanf("%d", &prioridad);
            if (0 > prioridad || prioridad > 5)
            {
                printf("Prioridad no valida inserte otra: ");
            }
        } while (0 > prioridad || prioridad > 5);
        t3 = new Thread("hilo 3", prioridad);
        // LLamadas al metodo Fork
        t1->Fork(ordena, 1);
        t2->Fork(factorial, 1);
        t3->Fork(calculaPromedio, 1);
        break;
    case 4:
        t1 = new Thread("hilo 1");
        t2 = new Thread("hilo 2");
        t3 = new Thread("hilo 3");
        t1->Fork(sincroniza, 1);
        t2->Fork(sincroniza, 2);
        t3->Fork(sincroniza, 3);

        break;
    case 5: // Case Filosofos
        f1 = new Thread("filosofo 1");
        f2 = new Thread("filosofo 2");
        f3 = new Thread("filosofo 3");
        f4 = new Thread("filosofo 4");
        f5 = new Thread("filosofo 5");

        f1->Fork(sincroniza, 1);
        f2->Fork(sincroniza, 2);
        f3->Fork(sincroniza, 3);
        f4->Fork(sincroniza, 4);
        f5->Fork(sincroniza, 5);

        break;
    case 6:
        printf("Saliendo...\n");
        break;
    }
}
