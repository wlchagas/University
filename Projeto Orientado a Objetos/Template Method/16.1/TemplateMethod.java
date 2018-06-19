import java.util.Arrays;

public class TemplateMethod {
    public static void main(String[] args) {
        String str[] = new String[2];
        str[0] = "abc";
        str[1] = "aba";

        System.out.println(Arrays.sort(str,new Template()));

    }
}
