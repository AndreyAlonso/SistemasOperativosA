/*  Imprimir cuando se crean los hilos de los fumadores indicando el nombre del ingrediente asignado.
    Imprimir cuando el fumador intenta fumar indicando el ingrediente que tiene.
    Imprimir cuando el fumador fuma.
    Imprimir cuando el fumador termina de fumar.
    Imprimir si el fumador no puede fumar y por qué.
*/


import org.omg.PortableServer.THREAD_POLICY_ID;

import java.util.Random;

public class Fumador extends Thread {
    private Mesa mesa;
    private String ingrediente1;  //Este es el ingrediente que es de por vida
    private int ingrediente2, ingrediente3;
    private String nombre;

    public Fumador(Mesa m, String i, String nom) {
        //enrolla un cigarrillo y luego lo fuma
        mesa = m;
        ingrediente1 = i;
        nombre = nom;
    }

    public void run() {

        for(;;) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            mesa.retiraIngrediente(nombre,ingrediente1);

        }
    }

}
