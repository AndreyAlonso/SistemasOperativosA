/*****************************************************************************************************************
 *  Proyecto:       Practica 7
 *  Equipo:         Granja Chavez Ricardo, Hernández Alonso Héctor Andrey
 *  Clases:         Principal, Buffer, Consumidor, Productor
 *  Implementación: Uso de una pila manejando hilos (productor-consumidor)
 *****************************************************************************************************************/
public class Principal {
    public static void main(String [] args){
        System.out.println("Nombres:  Granja Chavez Ricardo, Hernández Alonso Héctor Andrey" );
        System.out.println("Fecha: 13 Abril 2018");
        Buffer bf = new Buffer();
        Productor p = new Productor(bf);
        Consumidor c = new Consumidor(bf);
        c.start();
        p.start();


    }
}
