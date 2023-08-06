import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Vector;

public class collectionAlgo {

    public collectionAlgo(){
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(45);
        numbers.add(12);
        numbers.add(22);
        numbers.add(87);
        numbers.add(37);
        numbers.add(59);
        numbers.add(77);
        numbers.add(92);
        numbers.add(64);
        numbers.add(18);

        ArrayList<Integer> numbers2 = new ArrayList<>();
        for(int value:numbers){
            numbers2.add(value);
        }


        printNumber(numbers);

        Collections.sort(numbers);

        printNumber(numbers);

        int index = Collections.binarySearch(numbers, 10);

        if(index != -1){
            System.out.println("Passed Value Found in [index number]: "+index);
        }else{
            System.out.println("Sorry! Passed value not found.");
        }

        Collections.reverse(numbers);
        System.out.println("\nShowing numbers in reversed way - ");
        printNumber(numbers);

        Collections.shuffle(numbers);
        System.out.println("\nPrinting Shuffled Numbers...");
        printNumber(numbers);

        int value = 22;

        System.out.println("\nList Before fill(): ");
        printNumber(numbers);
        Collections.fill(numbers, value);
        System.out.println("\nList After fill(): ");
        printNumber(numbers);

        Collections.copy(numbers, numbers2);
        System.out.println("List after coping value : ");
        printNumber(numbers);

        System.out.println("\nMinimum Value of numbers is : "+Collections.min(numbers));
        System.out.println("\nMinimum Value of numbers is : "+Collections.max(numbers));

        ArrayList<Integer> numbers3 = new ArrayList<>();
        numbers3.addAll(numbers);
        System.out.println("\nnumbers3 after adding all values from numbers : ");
        printNumber(numbers3);

        System.out.println("Frequency of 45 in numbers is : "+Collections.frequency(numbers, 45));

        System.out.println("\nWhether numbers3 have no common elements with numbers or not : " + Collections.disjoint(numbers3, numbers));
    }

    private void printNumber(ArrayList<Integer> numbers){
        if(numbers.isEmpty()){
            System.out.println("This list is Empty.");
        }else {
            //System.out.println("The list Contains: ");
            for(int element:numbers){
                System.out.printf("%d ", element);
            }
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        new collectionAlgo();
    }
}
