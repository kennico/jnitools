package serkenny.jnitools;

public class AccessDoubleArray {
    public static void main(String[] args) {

        new JNITestObject() {

            @Override
            protected void runTest() {
                getNative().testAccessDoubleArray(new double[]{9.982,1.0031,1.0032,2.0001});
            }
        };
    }
}
