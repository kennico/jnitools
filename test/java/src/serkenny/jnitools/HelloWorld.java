package serkenny.jnitools;


public class HelloWorld {
    public static void main(String[] args) {

        new JNITestObject() {
            @Override
            protected void runTest() {
                getNative().testHelloWorld();
            }

        };
    }
}
