import java.lang.*;

public class OversizeException extends RuntimeException {

    public OversizeException() {

    }

    public OversizeException(String message) {
        super(message);
    }

    public OversizeException(Throwable cause) {
        super(cause);
    }

    public OversizeException(String message, Throwable cause) {
        super (message, cause);
    }

}
