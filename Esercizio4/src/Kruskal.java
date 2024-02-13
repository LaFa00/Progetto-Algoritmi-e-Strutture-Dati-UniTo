
import java.util.Collections;
import java.util.LinkedList;
import java.util.HashMap;
import java.io.*;

public class Kruskal<E,R extends Number & Comparable<R>> {
    private LinkedList<Edge<E, Double>> graphEdges = null;
    private HashMap<E,LinkedList<Edge<E,Double>>> map = null;
    private Graph < E, Double > kruskalGraph = null;
    private UnionFindSet<E> nodeSet = null;
    private Double weight = 0.0;


    public Kruskal(Graph<E, Double> graph) throws Exception{
        if(graph == null)
            throw new Exception("Kruskal Constructor: error graph cannot be null");
        this.graphEdges = graph.edgeCollection();
        this.map = graph.vertexCollection();
        this.weight = 0.0;
        this.doMakeSet();
    }

    public void doMakeSet() {
        this.kruskalGraph = new Graph<>(false);
        this.nodeSet = new UnionFindSet<E>();

        for(E set: map.keySet()) {
            try {
                nodeSet.makeSet(set);
                kruskalGraph.addVertex(set);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public Double getTotalWeight() {
        return this.weight;
    }

    public Graph<E,Double> kruskalMST() {
        Collections.sort(graphEdges);

        for(int i = 0; i < graphEdges.size(); i++) {
            Edge<E,Double> edge = graphEdges.get(i);
            E root1 = nodeSet.findSet(edge.getSource());
            E root2 = nodeSet.findSet(edge.getDestination());

            if(root1 != root2) {
                try {
                    if(edge.getWeight() instanceof Double) {
                        this.weight += (Double) edge.getWeight();
                    }
                    kruskalGraph.addEdge(edge.getSource(), edge.getDestination(),this.weight );
                    nodeSet.union(root1,root2);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
        return kruskalGraph;
    }


}
