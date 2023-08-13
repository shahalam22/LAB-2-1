import java.util.InputMismatchException;
import java.util.Scanner;

public class DividedByZeroWithExceptionHandling {
    public static int quotient(int numerator, int denominator) throws ArithmeticException {
        return numerator/denominator;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean continueLoop = true;

        do{
            try{
                System.out.println("Please enter an integer numerator: ");
                int numerator = scanner.nextInt();
                System.out.println("Please enter an integer denominator: ");
                int denominator = scanner.nextInt();

                int result = quotient(numerator, denominator);
                System.out.printf("\nResult: %d / %d = %d\n", numerator, denominator, result);

                continueLoop = false;
            }
            catch (InputMismatchException inputMismatchException){
                System.err.printf("\nException: %s\n", inputMismatchException);
                scanner.nextLine();
                System.out.println("You must enter integers. Please try again.");
            }
            catch (ArithmeticException arithmeticException){
                System.err.printf("\nException: %s\n", arithmeticException);
                System.out.println("Zero is an invalid denominator. Please try again.");
            }
            catch (Exception e){
                System.out.println(e);
            }
            finally {
                System.out.println("\nThis statement is inside of finally block. This must be executed.\n");
            }
        } while (continueLoop);
    }
}
