import java.sql.Time;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class Productor extends Thread {
    private Buffer buffercomp;
    private Random random;
    private int val;

    // Constructor de la clase Productor
    public Productor(Buffer buffer){
        buffercomp = buffer;
    }
    public void run(){
        for( ; ; ){
            try {
                Thread.sleep(700);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            val = (int)(Math.random()*15);
            try {
                buffercomp.introduceDato(val);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

}
