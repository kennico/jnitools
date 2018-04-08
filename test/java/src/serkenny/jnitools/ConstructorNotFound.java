package serkenny.jnitools;

public class ConstructorNotFound {
    public static void main(String[] args) {
        new JNITestObject() {

            @Override
            protected void runTest() {
                getNative().testConstructorNotFound();
            }
        };
    }
}
