package serkenny.jnitools;

public class CreateIntArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                int[] ret = getNative().testCreateIntArray();
                for(int i: ret)
                    System.out.println(i);
            }
        };
    }
}
