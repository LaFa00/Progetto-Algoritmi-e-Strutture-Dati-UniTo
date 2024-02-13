

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class GraphTests {
    Graph <Integer,Double > graph;
    private Integer v1, v2, v3, v4, v5, v6, v7,v8,v9;
    private Double num1, num2, num3, num4, num5;

    @Before
    public void createGraph() throws GraphException {

        graph = new Graph <Integer,Double>(false);

        v1 = 1;
        v2 = 2;
        v3 = 3;
        v4 = 4;
        v5 = 5;
        v6 = 6;
        v7 = 7;
        v8 = 8;
        v9 = 9;


        num1 = 10.0;
        num2 = 5.0;
        num3 = 9.0;
        num4 = 2.0;
        num5 = 4.0;

        graph.addVertex(v1);
        graph.addVertex(v2);
        graph.addVertex(v3);
        graph.addVertex(v4);
        graph.addVertex(v5);
        graph.addVertex(v6);
        graph.addVertex(v7);

        graph.addEdge(v1, v2, num1);
        graph.addEdge(v2, v3, num2);
        graph.addEdge(v1, v3, num3);
        graph.addEdge(v4, v6, num4);
        graph.addEdge(v7, v2, num5);
    }

    @Test
    public void numberVertex() throws Exception {
        assertEquals(graph.vertexCount(), 7);
    }

    @Test
    public void numberEdge() throws Exception {
        assertEquals(graph.edgeCount(), 5);
    }

    @Test
    public void GraphUnDirected() throws Exception {
        Graph <Integer,Double> graph2;
        graph2 = new Graph <Integer,Double> (true);
        assertTrue(graph2.isOriented());
    }

    @Test
    public void GraphDirected() throws Exception {
        assertFalse(graph.isOriented());
    }

    @Test
    public void WeigthEdge() throws Exception {
        assertTrue(graph.getWeight(v7, v2) == 4.0);
    }

    @Test
    public void testDeleteVertex() throws Exception {
        graph.deleteVertex(v2);
        assertEquals(graph.vertexCount(),6);
        graph.deleteVertex(v3);
        graph.deleteVertex(v4);
        assertEquals(graph.vertexCount(),4);
    }

    @Test
    public void testDeleteEdge() throws Exception {
        graph.deleteEdge(v1,v2);
        assertEquals(graph.edgeCount(),4);
        graph.deleteEdge(v2,v3);
        graph.deleteEdge(v1,v3);
        assertEquals(graph.edgeCount(),2);
    }

    @Test
    public void testHasEdge() throws Exception {
        assertTrue(graph.hasEdge(v1,v2));
        assertTrue(graph.hasEdge(v2,v3));
        assertTrue(graph.hasEdge(v1,v3));
        assertTrue(graph.hasEdge(v4,v6));
        assertTrue(graph.hasEdge(v7,v2));
        assertFalse(graph.hasEdge(v1,v4));
        assertFalse(graph.hasEdge(v3,v7));
        assertFalse(graph.hasEdge(v4,v5));
    }

    @Test
    public void testHasVertex() throws Exception {
        assertTrue(graph.hasVertex(v1));
        assertTrue(graph.hasVertex(v2));
        assertTrue(graph.hasVertex(v3));
        assertTrue(graph.hasVertex(v4));
        assertFalse(graph.hasVertex(v8));
        assertFalse(graph.hasVertex(v9));
    }


}
