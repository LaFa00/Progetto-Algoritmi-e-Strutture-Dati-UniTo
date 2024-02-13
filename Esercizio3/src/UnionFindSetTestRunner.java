import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class UnionFindSetTestRunner {
	public static void main(String[] args) {
		Result test_result = JUnitCore.runClasses(TestUnionFindSet.class);

		for(Failure failed :test_result.getFailures()) {
			System.out.println(failed.toString());
		}
	
		System.out.println(test_result.wasSuccessful());
	}
}
