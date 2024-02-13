package Kruskal;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class KruskalTestsRunner {


    public static void main (String[] Args) {
        Result result = JUnitCore.runClasses(KruskalTests.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }

        System.out.println(result.wasSuccessful());
    }
}
