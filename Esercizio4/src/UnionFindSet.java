import java.util.HashMap;

public class UnionFindSet<T> {
    private HashMap<T,Node<T>> map;

    public UnionFindSet() {
        map = new HashMap<T,Node<T>>();
    }

    /**  Crea un nuovo set con un singolo elemento
     * @param element: l'elemento del nuovo insieme
     * @throws UnionFindSetException se l'elemento e' null
     */
    public void makeSet(T elem ) throws UnionFindSetException {
        if(elem == null) {
            throw new UnionFindSetException("Element cannot be null in method makeSet");
        }
        map.put(elem,new Node<T>(elem));
    }

    /**
     * Ritorna il rappresentate di un insieme
     * @param element: Elemento che si identifica il set da ritornare
     * @return
     */
    public T findSet(T element){
        Node<T> r = map.get(element);
    
        if (r == null) 
            return null;

        return findSet(r).getElement();
    }

    /**
     * Metodo ausiliario. Ritorna il nodo contenente
     * il rappresentante dell'insieme
     * @param node: Nodo dell'insieme da ritornare 
     * @return
     */

    private Node<T> findSet(Node<T> node) {
       Node<T> r = node;

    if (r != r.getParent()){
      r.setParent(findSet(r.getParent()));
    }

    return r.getParent();
    } 

    /**
     * Unisce due insiemi collegando il rappresentante di uno a quello dell'altro
     * 
     * @param x: elemento del primo set
     * @param y: elemento del secondo set
     * @throws UnionFindSetException se uno dei due elementi non appartiene ad alcun insieme
     */

    public void union(T x, T y) throws UnionFindSetException {
        Node<T> nodeX;
        Node<T> nodeY;

        nodeX = map.get(x);
        nodeY = map.get(y);

        if(nodeX == null)
            throw new UnionFindSetException("set not contains element: " + x);
        if(nodeY == null) 
            throw new UnionFindSetException("set not contains element: " + y);

        if(nodeX.getRank() > nodeY.getRank()) {
            nodeY.setParent(nodeX);
        } else {
            nodeX.setParent(nodeY);
            if(nodeX.getRank() == nodeY.getRank()) {
                nodeY.setRank(nodeY.getRank() + 1);
            }
        }
    }
}