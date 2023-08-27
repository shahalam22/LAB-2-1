import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class iterator {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<>();
        colors.add("Black");
        colors.add("White");
        colors.add("Red");
        colors.add("Blue");
        colors.add("Violate");
        colors.add("Orange");

        System.out.println(colors);

        Iterator<String> it = colors.iterator();

        while(it.hasNext()){
            colors.remove("Red");
            System.out.println(it.next());
        }
    }
}
