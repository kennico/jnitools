package serkenny.jnitools;

public class CreateCharArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                char[] ret = getNative().testCreateCharArray();
                for(char c: ret)
                    System.out.print(c);
                System.out.println("");
            }
        };
    }
}
