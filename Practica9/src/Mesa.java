import java.util.Stack;
import java.util.concurrent.TimeUnit;

public class Mesa {

    private int val, val2;
    private String  ingrediente1, ingrediente2;
    private String ingrediente3;
    private boolean tam;

    // Constructor de la clase Mesa
    public Mesa()
    {
        tam = false;
    }

    /****************************************************************************************************************
     *
     *  coloca los 2 ingrendientes en la mesa, si son repetidos no cuenta
     *
     *****************************************************************************************************************/
    public void introduceIngrediente(int i1, int i2){
        this.val = i1;
        this.val2 = i2;

        switch (val)
        {
            case 1:
                ingrediente1 = "TABACO";

            break;
            case 2:
                ingrediente1 = "CERILLOS";

            break;
            case 3:
                ingrediente1 = "PAPEL";


                break;
        }
        switch (val2){
            case 1:
                ingrediente2 = "TABACO";

                break;
            case 2:
                ingrediente2 = "CERILLOS";

                break;
            case 3:
                ingrediente2 = "PAPEL";
                break;
        }

        if(tam == true){
            System.out.println("Mesa llena");
        }
        else if(tam == false){


            System.out.println("Agente introduce: " + ingrediente1);
            System.out.println("Agente introduce: " + ingrediente2);
            System.out.println("La mesa tiene: " + ingrediente1 + ", " + ingrediente2);

        }
        tam = true;



    }

    public void retiraIngrediente(String nomb, String ing3) {
        tam = false;
       System.out.println(nomb + " tiene: " +ing3);
       //System.out.println("");
       if( (ingrediente1 != ing3) && (ingrediente2 != ing3)) {
           System.out.println(nomb + " Esta Fumando...");
           try {
               Thread.sleep(100);
           } catch (InterruptedException e) {
               e.printStackTrace();
           }
           System.out.println("Se dejo de fumar ");


       }
        else{
           System.out.println(nomb + " Intentando Fumar");

       }

    }
}
