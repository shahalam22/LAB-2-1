import java.util.Random;
import java.util.random.RandomGenerator;

public class PrintTask implements Runnable{
    private final int sleepTime;
    private final String taskName;
    private final static Random generator = new Random();

    public PrintTask(String name){
        this.taskName = name;
        sleepTime = generator.nextInt(5000);
    }

    public void run(){
        try{
            System.out.printf("%s going to sleep for %d milliseconds.\n", taskName, sleepTime);
            Thread.sleep(sleepTime);
            System.out.printf("%s woke up.\n", taskName);
        }catch (InterruptedException exception){
            System.out.printf("%s done sleeping.\n", taskName);
        }
    }
}
