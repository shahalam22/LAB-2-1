public class ThreadCreator {
    public static void main(String[] args) {
        System.out.println("Creating Threads");

        Thread thread1 = new Thread(new PrintTask("Task1"));
        Thread thread2 = new Thread(new PrintTask("Task2"));
        Thread thread3 = new Thread(new PrintTask("Task3"));

        System.out.println("Threads created, starting tasks.\n");

        thread1.start();
        thread2.start();
        thread3.start();

        System.out.println("Tasks started, main ends here.\n");
    }
}
