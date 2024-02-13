import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
         Graph<String, Double> graph = new Graph<>(false);
        Kruskal<String,Double> kruskal;
        Graph<String,Double> minimalGraph = new Graph<>(false);
        String v1;
        String v2;
        Double weight;

        try(BufferedReader in = new BufferedReader(new FileReader("italian_dist_graph.csv"))) {
            String line = in.readLine();
            while(line  != null) {
                String[] pair = line.split(",");
                v1 = pair[0];
                v2 = pair[1];
                weight = Double.parseDouble(pair[2]);

                graph.addVertex(v1);
                graph.addVertex(v2);
                graph.addEdge(v1,v2,weight);
                
                line = in.readLine();
            }
        } catch (FileNotFoundException ex) {
            System.out.println("No file found");
            System.exit(-1);

        } catch (IOException e) {
            System.out.println("IOException error");
            System.exit(-1);
        }
        System.out.println("file read successfull");

        kruskal = new Kruskal<String,Double>(graph);
        minimalGraph = kruskal.kruskalMST();
        System.out.println("Peso = "+ Math.round(kruskal.getTotalWeight()) / 1000.0 + " Km ");
        System.out.println("Numero di archi = "+ minimalGraph.edgeCount());
        System.out.println("Numero vertici = " + minimalGraph.vertexCount());


    }

}
