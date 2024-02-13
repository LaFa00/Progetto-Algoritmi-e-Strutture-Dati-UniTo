package Kruskal;

import Grafo.*;
import java.io.IOException;
import java.util.*;

import UnionFindSet.UnionFindSetException;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class KruskalTests {
   Graph<Integer,Double> graph = new Graph<>(false);
    Integer v1,v2,v3,v4,v5,v6,v7,v8,v9;
   @Before
    public void initialize() throws GraphException{
       v1 = 1;
       v2 = 2;
       v3 = 3;
       v4 = 4;
       v5 = 5;
       v6 = 6;
       v7 = 7;
       v8 = 8;
       v9 = 9;

       graph.addVertex(v1);
       graph.addVertex(v2);
       graph.addVertex(v3);
       graph.addVertex(v4);
       graph.addVertex(v5);
       graph.addVertex(v6);
       graph.addVertex(v7);
       graph.addVertex(v8);
       graph.addVertex(v9);

       graph.addEdge(v1,v2,4.0);
       graph.addEdge(v2,v3,8.0);
       graph.addEdge(v3,v4,7.0);
       graph.addEdge(v4,v5,9.0);
       graph.addEdge(v5,v6,10.0);
       graph.addEdge(v6,v7,2.0);
       graph.addEdge(v7,v8,1.0);
       graph.addEdge(v8,v9,7.0);
       graph.addEdge(v1,v7,8.0);
       graph.addEdge(v2,v7,11.0);
       graph.addEdge(v3,v6,4.0);
       graph.addEdge(v3,v9,2.0);
       graph.addEdge(v4,v6,14.0);
       graph.addEdge(v7,v9,6.0);


   }

   @Test
    public void kruskalMST() throws GraphException, UnionFindSetException,Exception {
       Kruskal<Integer,Double> mst = new Kruskal<Integer, Double>(graph);
       mst.kruskalMST();
       assertEquals(mst.getTotalWeight(),37.0,0.0);

   }

}
