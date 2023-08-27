import java.util.Arrays;

public class usingArrays {
    private int intArray[] = {2,12,11,45,4,8,9,10};
    private double doubleArray[] = {8.2,5.6,4.5,1.2,2.9,3.5};
    private int filledIntArray[], intArrayCopy[];

    public usingArrays(){
        filledIntArray = new int[10];
        intArrayCopy = new int[intArray.length];

        Arrays.fill(filledIntArray, 7);
        Arrays.sort(doubleArray);
        System.arraycopy(intArray, 0, intArrayCopy, 0, intArray.length);
    }

    public void printArrays(){
        System.out.println("DoubleArray: ");
        for(double doubleValue:doubleArray){
            System.out.printf("%f ", doubleValue);
        }
        System.out.println("\nintArray: ");
        for(int intValue: intArray){
            System.out.printf("%d ", intValue);
        }
        System.out.println("\nfilledIntArray: ");
        for(int intValue:filledIntArray){
            System.out.printf("%d ", intValue);
        }
        System.out.println("\nintArrayCopy: ");
        for(int intValue:intArrayCopy){
            System.out.printf("%d ", intValue);
        }

        System.out.println("\n");
    }

    public int searchForInt(int value){
        return Arrays.binarySearch(intArray, value);
    }

    public void printEquality(){
        boolean b = Arrays.equals(intArray, intArrayCopy);
        System.out.printf("intArray %s intArrayCopy\n", (b?"==":"!="));

        b = Arrays.equals(intArray, filledIntArray);
        System.out.printf("intArray %s filledIntArray\n", (b?"==":"!="));
    }

    public static void main(String[] args) {
        usingArrays usingArrays = new usingArrays();
        usingArrays.printArrays();
        usingArrays.printEquality();

        int location = usingArrays.searchForInt(5);
        if(location>=0){
            System.out.printf("Found 5 at element %d in intArrays\n", location);
        }else{
            System.out.println("5 not found in intArray\n");
        }
        location = usingArrays.searchForInt(8763);
        if(location>=0){
            System.out.printf("Found 8763 at element %d in intArrays\n", location);
        }else{
            System.out.println("8763 not found in intArray\n");
        }
    }
}
