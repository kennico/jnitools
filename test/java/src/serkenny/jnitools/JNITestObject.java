package serkenny.jnitools;

import serkenny.test.TestObject;

public abstract class JNITestObject extends TestObject {

    public NativeMethods getNative() {
        return methods;
    }

    private NativeMethods methods;
    @Override
    protected void initialize() {
        System.loadLibrary("cpp");
        methods = new NativeMethods();
    }

}
