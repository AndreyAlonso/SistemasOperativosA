import java.util.concurrent.TimeUnit;

public class Consumidor extends Thread {
    private Buffer buffercomp;
    // Constructor de la clase Consumidor
    public Consumidor(Buffer buffer){
        buffercomp = buffer;
    }
    // Metodo run, siempre esta activo
    public void run(){
        for( ; ; ){
            try {
                Thread.sleep(700);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            try {
                buffercomp.sacaDato();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
