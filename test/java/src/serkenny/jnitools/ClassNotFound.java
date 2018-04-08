package serkenny.jnitools;

public class ClassNotFound {
    public static void main(String[] args) {
        new JNITestObject() {

            @Override
            protected void runTest() {
                getNative().testClassNotFound();
            }

        };
    }
}
