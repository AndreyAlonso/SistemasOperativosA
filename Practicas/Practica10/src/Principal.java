/*********************************************************************************************************************
 *  Proyecto: Practica 10. Oso y Abejas
 *  Fecha:    25 de Abril del 2018
 *  Autores:  Granja Chavez Ricardo, Hernández Alonso Andrey
 *  Clases:   Principal, Abeja, Oso, Tarro
 ********************************************************************************************************************/

public class Principal {
    public static void main(String [] args) throws InterruptedException {

        int M = (int)(Math.random() * 20) + 1;        //Este random es para la capasidad del el tarro
        int N = (int)(Math.random() * 15) + 1;        //Este random es la capasidad de las abejas
        System.out.println("Numero de abejas: " + N);
        char nombre = 'A';

        Tarro t = new Tarro(M);
        Oso oso = new Oso(t);
        Abeja[] abejas = new Abeja[N];


        oso.start();
        for (int i = 0; i < N ; i++) {

            abejas[i] = new Abeja(nombre, t);
            nombre++;
        }
        for (int i = 0; i < N ; i++) {
            abejas[i].start();
            Thread.sleep(1000);
        }
        for (int i = 0; i < N ; i++) {
            abejas[i].join();
        }


    }
}
