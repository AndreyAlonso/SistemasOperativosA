import java.util.concurrent.TimeUnit;

public class Consumidor extends Thread {
    private Buffer buffercomp;
    public Consumidor(Buffer buffer){
        buffercomp = buffer;
    }
    public void run(){
        for( ; ; ){
            try {
                Thread.sleep(2000);
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
