public class Oso extends Thread {
    private Tarro tarro;

    public Oso(Tarro t){
        this.tarro = t;
    }

    public void run(){

        for(;;)
        {

            try {
                Thread.sleep( 625); // 500
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            tarro.comeMiel();

        }
    }
}
