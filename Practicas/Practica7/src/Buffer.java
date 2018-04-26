import java.util.Stack;
import java.util.concurrent.TimeUnit;

public class Buffer {
    private int[] pila;
    private int index;

    public Buffer() {
        // Creación del arreglo (memoria compartida)
        pila = new int[6];
        index = 0;
    }
    public void introduceDato(int dato) throws InterruptedException {
        // Si el buffer está lleno, esperar a que exista
        // por lo menos un lugar en el buffer.
        // Imprimir que el buffer está lleno.
        // Insertar dato en el buffer.
        // Imprimir mensaje de inserción, la posición
        // donde se insertó y el dato.
        if (pila.length-1 == index) {
            System.out.println("El buffer esta lleno");
        }
        else {
            Thread.sleep(700);
            index++;
            pila[index] = dato;

            System.out.println(dato + " se insetó a la pila en el lugar " + index);
        }
    }
    public void sacaDato() throws InterruptedException {
        // Si el buffer está vacío, esperar a que
        // exista por lo menos un dato en el buffer.
        // Imprimir que el buffer está vacío.
        // Sacar dato del buffer.
        // Imprimir dato consumido y la posición de
        // donde se sacó.
        int datoEliminado;
        if (index == 0) {
            System.out.println("El buffer esta vacio");
        }
        else {
            Thread.sleep(800);
            datoEliminado = pila[index];
            pila[index] = -1;
            System.out.println("Se saco del buffer el numero " + datoEliminado +" de la posición "+ index);
            index--;
        }
    }
}
