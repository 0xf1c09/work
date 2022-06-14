
public class JNI {
    public native int invokeMethod(int argc, String[] argv);
    public static void main(String[] args) {
	    JNI initiator = new JNI();
	    initiator.invokeMethod(args.length, args);
    }

    static {
        System.load("/tmp/libffmpeg.so");
    }
}
