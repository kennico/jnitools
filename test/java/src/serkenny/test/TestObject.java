package serkenny.test;

public abstract class TestObject {
    /**
     * usage
     *
     * public static void main(String[]) {
     *     new TestObject() {
     *         @Override
     *         protected void initialize() {
     *             // STUB
     *         }
     *
     *         protected void runTest() {
     *             // STUB
     *         }
     *     };
     * }
     *
     */
    public TestObject() {
        initialize();
        runTest();
    }

    protected abstract void initialize();
    protected abstract void runTest();
}
