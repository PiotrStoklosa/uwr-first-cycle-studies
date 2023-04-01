package structures;

public interface OrderedSequence<T extends Comparable<T>> {
        boolean search(T el);
        void insert(T el) throws Exception;
        void remove(T el) throws Exception;
        T max() throws Exception;
        T min() throws Exception;
        T at(int pos) throws Exception;
        int index(T el);
}