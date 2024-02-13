import java.util.HashMap;
import java.util.LinkedList;
import java.io.*;


public class Graph < G, R extends Number & Comparable < R >> {
    private HashMap<G, LinkedList<Edge<G,R>>> map;

    boolean isOriented;

    public Graph() {  /*Senza parametri il grafo e' diretto */
        map = new HashMap <>();
        isOriented = true;
    }

    public Graph(boolean isOriented) {  /* Utente decide se il grafo e' diretto o meno */
        map = new HashMap <>();
        this.isOriented = isOriented;
    }

    /**
     * Creazione dell'arco (v1,v2)
     * Se il grafo e' indiretto creo anche l'arco (v2, v1)
     * Se i vertici v1 or v2 non esistono, li creo.
     * @param v1: vertice v1
     * @param v2: vertice v2
     * @param weight: peso dell'arco
     * @throws GraphEsxception se uno dei due vertici non esiste oppure il peso dell'arco e' nullo
     */

    public void addEdge(G v1, G v2, R weight) throws GraphException {
        if (v1 == null)
            throw new GraphException("method AddEdge: error v1 parameter cannot be null");
        if (v2 == null)
            throw new GraphException("method AddEdge: error v2 parameter cannot be null");
        if (weight == null)
            throw new GraphException("method AddEdge: error weight parameter cannot be null");

        if (map.get(v1) == null)
            map.put(v1, new LinkedList <>());


        if (map.get(v2) == null)
            map.put(v2, new LinkedList <>());

        map.get(v1).add(new Edge <G,R> (v1, v2, weight));

        if (!isOriented)
            map.get(v2).add(new Edge <G,R> (v2, v1, weight));

    }

    /**
     * Creazione del vertice
     * 
     * @param vertex: vertice da creare
     * @throws GraphException se il vertice e' nullo
     */
    public void addVertex(G vertex) throws GraphException {
        if (vertex == null)
            throw new GraphException("method AddVertex: error v parameter cannot be null");

        if (map.get(vertex) == null)
            map.put(vertex, new LinkedList <> ());

    }

    /**
     * Controlla se il vertice e' presente nel grafo
     * 
     * @param vertex: vertice da cercare
     * @return
     * @throws GraphException se il vertice e' nullo
     */
    public boolean hasVertex(G vertex) throws GraphException {
        if (vertex == null)
            throw new GraphException("method hasVertex: error vertex parameter cannot be null");
        if (map.containsKey(vertex))
            return true;
        else
            return false;

    }

    /**
     * Controlla se esiste l'arco (v1,v2) tra i due vertici
     * Se non e' orientato controlla anche che esista arco (v2,v1
     * ) 
     * @param v1: vertice v1
     * @param v2: vertice v2
     * @return
     * @throws GraphException se uno dei due vertici e' nullo
     */

    public boolean hasEdge(G v1, G v2) throws GraphException  {
        if (v1 == null)
            throw new GraphException("method AddEdge: error v1 parameter cannot be null");
        if (v2 == null)
            throw new GraphException("method AddEdge: error v2 parameter cannot be null");

        LinkedList<Edge<G,R>> listOfEdges = map.get(v1);
        boolean contains = false;

        for(int i = 0; i < listOfEdges.size(); i++) {
            if(listOfEdges.get(i).getSource().equals(v1) && listOfEdges.get(i).getDestination().equals(v2)) {
                contains = true;
                break;
            }
            contains = false;
        }
        if(!isOriented) {
            listOfEdges = map.get(v2);
            for(int i = 0; i < listOfEdges.size(); i++) {
                if(listOfEdges.get(i).getSource().equals(v2) && listOfEdges.get(i).getDestination().equals(v1)) {
                    contains = true;
                    break;
                }
                contains = false;
            }
        }
        return contains;
    }

    /** 
     * Ritorna i vertici 
     * @return
     */
    public HashMap<G,LinkedList<Edge<G,R>>> vertexCollection() {
        return map;
    }


    /**
     * Ritorna il numero dei vertici
     * @return
     */
    public int vertexCount() {
        return map.size();
    }

    /**
     * Ritorna il numero degli archi
     * 
     * @return
     */

    public int edgeCount() {
        int counter = 0;
        LinkedList<Edge<G,R>> listOfEdges = new LinkedList<>();

        for(G set: map.keySet()) {
            listOfEdges = map.get(set);
            counter = counter + listOfEdges.size();
        }
        if(!isOriented) {
            return counter / 2;
        } else {
            return counter;
        }
    }

    /**
     * Ritorna true se il grafo e' orientato
     * 
     * @return
     */
    public boolean isOriented() {
        return isOriented;
    }

    /**
     * Stampa la lista degli archi contenenti nella chiave v1
     * 
     * @param v1
     * @throws GraphException
     */
    public void adjacentVertex(G v1) throws GraphException {
        if(v1 == null)
            throw new GraphException("method adjacentVertex: error v1 parameter cannot be null");
        if(map.get(v1) == null)
            throw new GraphException("method adjacentVertex: error no exist vertex called" + v1);

        LinkedList<Edge<G,R>> adjList = new LinkedList<>();
        adjList = map.get(v1);
        for(int i = 0; i < adjList.size(); i++) {
            System.out.println("ajiacent vertex of vertex " + v1 + " are  " + adjList.get(i).getSource() + "    " + adjList.get(i).getDestination());
        }
    }


    /**
     * Eliminazione dell'arco (v1,v2)
     * Parto dalla chiave  v1 verificando se esiste effettivamente la coppia con v2, per rimuoverlo
     * Se il grafo e' indiretto, cerco anche l'arco(v2,v1) e lo rimuovo
     * 
     * @param v1: vertice v1
     * @param v2: vertice v2
     * @throws GraphException se uno dei due vertici e' nullo oppure non sono presenti nel grafo
     */
    public void deleteEdge(G v1, G v2) throws GraphException {
        if (v1 == null)
            throw new GraphException("method deleteEdge: error v1 parameter cannot be null");
        if (v2 == null)
            throw new GraphException("method deleteEdge: error v2 parameter cannot be null");
        if (map.get(v1) == null)
            throw new GraphException("method deleteEdge: error no exist vertex called" + v1);
        if (map.get(v2) == null)
            throw new GraphException("method deleteEdge: error no exist vertex called" + v2);

        LinkedList<Edge<G,R>> listOfEdges = new LinkedList<>();
        listOfEdges = map.get(v1);
        for(int i = 0; i < listOfEdges.size(); i++) {
            if(listOfEdges.get(i).getSource().equals(v1) && listOfEdges.get(i).getDestination().equals(v2))
                listOfEdges.remove(i);
        }

        if(!isOriented) {
            listOfEdges = map.get(v2);
            for(int i = 0; i < listOfEdges.size(); i++) {
                if(listOfEdges.get(i).getSource().equals(v2) && listOfEdges.get(i).getDestination().equals(v1))
                    listOfEdges.remove(i);
            }
        }
    }

    /**
     * Cancella il vertice v1
     * Bisogna scorrere tutte le altri chiavi
     * per poter identificare la coppia in cui il vertice
     * e' quello da cancellare
     * 
     * @param v1
     * @throws GraphException
     */

    public void deleteVertex(G v1) throws GraphException {
        if(v1 == null)
            throw new GraphException("Error method deleteVertex: v1 parameter cannot be null");

        map.remove(v1);
        LinkedList<Edge<G,R>> adjList = new LinkedList<>();

        for(G set: map.keySet()) {
            adjList = map.get(set);
            for(int i = 0; i < adjList.size(); i++) {
                if(adjList.get(i).getSource().equals(v1) || adjList.get(i).getDestination().equals(v1))
                    adjList.remove(i);
            }
        }
    }

    /**
     * Inserisce tutte le chiavi in un'arraylist per essere usato
     * nell' Algoritmo di Kruskall
     * 
     * @return
     */

    public LinkedList<Edge<G,R>> edgeCollection() {
        LinkedList<Edge<G,R>> listOfEdge = new LinkedList<>();
        LinkedList<Edge<G,R>> tmp = new LinkedList<>();

        for(G set: map.keySet()) {
            tmp = map.get(set);
            for(int i = 0; i < tmp.size(); i++) {
                listOfEdge.add(tmp.get(i));
            }
        }
        return listOfEdge;
    }

    /**
     * Ritorna il peso dell'arci (v1,v2)
     * 
     * @param v1: vertice v1
     * @param v2: vertice v2
     * @return
     * @throws GraphException se almeno uno dei due vertici e' nullo
     */
    public R getWeight(G v1, G v2) throws GraphException {
        if(v1 == null)
            throw new GraphException("Error method getWeight: v1 parameter cannot be null");
        if(v2 == null)
            throw new GraphException("Error method getWeight: v2 parameter cannot be null");

        LinkedList<Edge<G,R>> listOfEdges = new LinkedList<>();
        for(G set: map.keySet()) {
            listOfEdges = map.get(set);
            for(int i = 0; i < listOfEdges.size(); i++) {
                if(listOfEdges.get(i).getSource().equals(v1) && listOfEdges.get(i).getDestination().equals(v2)) {
                    return listOfEdges.get(i).getWeight();
                }
            }
        }
        return null;
    }
}
