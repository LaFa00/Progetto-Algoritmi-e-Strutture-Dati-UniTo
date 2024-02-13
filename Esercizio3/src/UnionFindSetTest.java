import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;

public class UnionFindSetTest {
    private UnionFindSet<Integer> unionFind;
    private int a,b,c,d;

    @Before
    public void init() {
        unionFind = new UnionFindSet<Integer>();
        a = 1;
        b = 2;
        c = 3;
        d = 4;
    }

    @After
    public void afterTest() {}

    @Test
    public void test_find_zero_element(){
		assertNull(unionFind.findSet(a));
	}

    @Test 
  public void test_find_same_representative() throws UnionFindSetException{
    unionFind.makeSet(a);
    unionFind.makeSet(b);

    unionFind.union(a,b);

    assertEquals(unionFind.findSet(a).intValue(),unionFind.findSet(b).intValue());
  }



}