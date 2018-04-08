package serkenny.jnitools;

public class AccessCharArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                getNative().testAccessCharArray("misaka10032".toCharArray());
            }
        };
    }
}
