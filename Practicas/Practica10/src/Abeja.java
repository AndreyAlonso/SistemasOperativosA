public class Abeja extends Thread {

    private Tarro tarro;
    private int miel;         // esta es la miel, es un valor que entra para el tarro
    private char nombre;


    public Abeja(char nombre,Tarro t){
        this.nombre = nombre;
        this.tarro = t;
        this.miel = 1;

    }
    public void run()
    {
        for(;;){
            try {

                Thread.sleep(2500); //2000
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            tarro.introduceMiel(miel,nombre);          //Siempre va a estae entrando 1 para que vaya incrementando
            //el tarro en 1
        }
    }
}
