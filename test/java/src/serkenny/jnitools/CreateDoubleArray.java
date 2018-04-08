package serkenny.jnitools;

public class CreateDoubleArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                double[] ret = getNative().testCreateDoubleArray();
                for(double i : ret)
                    System.out.println(i);
            }
        };
    }
}
