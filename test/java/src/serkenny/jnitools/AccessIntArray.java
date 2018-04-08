package serkenny.jnitools;

public class AccessIntArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                getNative().testAccessIntArray(new int[]{9982,10031,10032,20001});
            }
        };
    }
}
