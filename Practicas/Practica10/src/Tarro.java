public class Tarro{
    // Declaración de variables
    private int tam;
    private int tope;
    private boolean band1, band2;

    /************************************************************************************
     *  Constructor de la clase
     *  recibe como parametros una variable entera que le asigna el tamaño del tarro
     *************************************************************************************/
    public Tarro(int M){
        this.tam = M;
        tope = 0;
        band1 = false;
        band2 = false;

        System.out.println("Tamaño del tarro: " + tam);
        System.out.println("");
    }

    /************************************************************************************
     * Metodo que ocupa la clase Abeja, envia un entero de valor aleatorio hasta llenar
     * el tarro
     ************************************************************************************/
    public void introduceMiel(int miel,char abeja){
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }




        if(tope < tam){

            tope = tope + miel;
            System.out.println("La abeja " + abeja + " dio una porción de miel");
            System.out.println("Valor del tarro: " + tope);
            System.out.println(" ");

        }
        if(tope == tam){
            System.out.println("La abeja " + abeja + " lleno el tarro");
            System.out.println("La abeja " + abeja + " despertara al oso");
            band2 = true;
            System.out.println(" ");
        }


        
    }

    public void comeMiel(){


        if(band2 == true){

            System.out.println("Oso se desperto ");
            System.out.println("" );
            System.out.println("Oso comiendo");
            System.out.println("\nSe vacio el tarro de miel\n");

            band2 = false;
            tope = 0;
            //System.out.println("Bandera 1: " + band1);
            //System.out.println("Bandera 2: " + band2);
            System.out.println("Tamaño del tarro: " + tam);
            System.out.println("");
        }
        else{
            System.out.println("Oso durmiendo...");


        }

    }
}
