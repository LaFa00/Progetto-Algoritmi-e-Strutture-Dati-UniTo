

public class Edge<E,R extends Number & Comparable<R>> implements Comparable<Edge<E,R>>{
    private R weight;
    private E source;
    private E destination;

    public Edge(E source, E destination,R weight){
        this.weight = weight;
        this.source =  source;
        this.destination = destination;
    }

    public R getWeight(){
        return this.weight;
    }

    public E getSource() {
        return this.source;
    }

    public E getDestination(){
        return this.destination;
    }

    @Override
    public int compareTo(Edge<E,R> edge) {
        return (this.getWeight()).compareTo(edge.getWeight());
    }

    @Override
    public String toString() {
        return "Edge ("+getSource()+", "+getDestination()+") weight="+getWeight();
    }

}
