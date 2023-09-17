import java.util.Scanner;

public class FileDemonstrationTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        FileDemonstration application = new FileDemonstration();

        System.out.print("Enter file or directory name here: ");
        application.analyzePath(input.nextLine());
    }
}


//file name : /home/shahalamabir/Desktop/LAB-2-1/OOP2 - 306