public class UsingExceptions {
    public static void main(String[] args) {
        try{
            throwException();
        }catch(Exception e){
            System.err.println("Exception handled in main function");
        }
        doesNotThrowException();
    }

    public static void throwException() throws Exception{
        try{
            System.out.println("Method throwException");
            throw new Exception();
        }catch (RuntimeException runtimeException){
            System.err.println("Exception handled in method throwException");
            throw runtimeException;    //ei exception ke handle korche main method jeta ei method er outer scope. ei ghotona holo "STACK UNWINDING"
        }finally {
            System.err.println("Finally executed in throwException");
        }
    }

    public static void doesNotThrowException(){
        try{
            System.out.println("Method doesNotThrowException");
        }catch(Exception exception){
            System.err.println(exception);
        }finally {
            System.err.println("Finally executed in doesNotThrowException");
        }
        System.out.println("End of method doesNotThrowException");
    }
}

//we can handle "Exception" but can't handle "Error"
//we can resolve exceptions by try catch
//we can resolve errors by trace-back process