public class Agente extends  Thread {
    private int val1, val2;
    private Mesa mesa;
    public Agente(Mesa m){
        this.mesa = m;
    }
    public void run()
    {
        for(;;){
            try {
                Thread.sleep(800);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            val1 = (int)(Math.random() * 3) + 1;
            val2 = (int)(Math.random() * 3) + 1;
            if(val2 != val1)
                mesa.introduceIngrediente(val1,val2);
        }

    }

}
