public class Node<T> {
    private T element;
    private int rank;
    private Node<T> parent;

    public Node(T element) {
        this.element = element;
        this.rank = 0;
        this.parent = this;
    }

    /**
     * Ritorna l'elemento del nodo
     * @return
     */
    public T getElement() {
        return this.element;
    }

    /**
     * Ritorna il rank dell'elemento del nodo
     * @return
     */
    public int getRank() {
        return this.rank;
    }

    /**
     * Ritorna il parent del Nodo
     * @return
     */
    public Node<T> getParent() {
        return this.parent;
    }

    /**
     * Modifica elemento del nodo
     * @param element: nuovo elemento
     */

    public void setElement(T element) {
        this.element = element;
    }

    /**
     * Modifica il rango dell'elemento del nodo
     * @param rank
     */
    public void setRank(int rank)  {
        this.rank = rank;
    }

    /**
     * Modifica il parent del nodo
     * @param parent: Nuovo parent
     */
    public void setParent(Node<T> parent) {
        this.parent = parent;
    }
}