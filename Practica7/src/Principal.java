public class Principal {
    public static void main(String [] args){
       Buffer bf = new Buffer();
       Productor p = new Productor(bf);
       Consumidor c = new Consumidor(bf);
        c.start();
        p.start();


    }
}
