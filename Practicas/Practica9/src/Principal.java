/*********************************************************************************************************************
 *  Proyecto:       Practica 9. Fumadores
 *  Integrantes:    Granja Chavez, Hernández Alonso
 *  Clases:         Principal, Fumador, Mesa, Agente
 *  Fecha:          19 Abril 2018
 *
 *********************************************************************************************************************/
public class Principal {
    public static void main(String [] args){
        Mesa m = new Mesa();
         Agente agente = new Agente(m);

         Fumador f1 = new Fumador(m,"CERILLOS","A");
         Fumador f2 = new Fumador(m,"PAPEL","B");
         Fumador f3 = new Fumador(m,"TABACO","C");

         agente.start();
         f1.start();
         f2.start();
         f3.start();
         /**** El agente coloca dos de los tres ingredientes en una mesa de manera  ******/





    }
}
