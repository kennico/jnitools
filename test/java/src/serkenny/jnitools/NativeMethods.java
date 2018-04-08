package serkenny.jnitools;

public class NativeMethods {
    public native void testHelloWorld();
    public native void testClassNotFound();
    public native void testConstructorNotFound();
    public native void testAccessIntArray(int[] a);
    public native void testAccessDoubleArray(double[] a);
    public native void testAccessCharArray(char[] a);
    public native int[] testCreateIntArray();
    public native double[] testCreateDoubleArray();
    public native char[] testCreateCharArray();
}
