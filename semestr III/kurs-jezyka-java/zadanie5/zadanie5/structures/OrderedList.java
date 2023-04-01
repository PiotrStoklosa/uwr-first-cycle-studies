package structures;

import java.util.Iterator;

public class OrderedList <T extends Comparable<T>> implements OrderedSequence<T>,Iterable<T>{

    @Override
    public Iterator<T> iterator() {
        return new ListIterator();
    }


    private class ListIterator implements Iterator<T> {

        private Node<T> temp = start;

        public boolean hasNext() {
            return temp != null;
        }

        @Override
        public T next() {
            T data= temp.data;
            temp = temp.next;

            return data;
        }

        @Override
        public void remove() {
            start.remove(index(temp.data));
        }

    }

        private class Node <T extends Comparable<T>>{
            private Node<T> next;
            private T data;

            private Node(T data){
                this.data=data;
            }
            private Node(Node<T> node){
                this.data=node.data;
                if (node.next!=null)
                    this.next=new Node<>(node.next);
            }
            private void insert(T el) throws Exception {


                if (search(el))
                    throw new Exception("Ten element juz istnieje w liscie");

                if (this.data.compareTo(el)>0){
                    this.next= new Node<>(this);
                    this.data=el;
                    return;
                }

                Node<T> newNode= new Node<>(el);
                Node<T> temp=this;

                    while (true) {
                        if (temp.next==null){
                            temp.next=newNode;
                            return;
                        }
                        if (temp.next.data.compareTo(newNode.data)>0){
                            newNode.next=temp.next;

                            temp.next=newNode;
                            return;
                        }

                        temp = temp.next;
                }
            }

            public boolean search(T el) {

                return index(el) > -1;

            }

            @Override
            public String toString() {
                return "Node{" +
                        "next=" + (next==null ? null : this.next.toString()) +
                        ", data=" + data +
                        '}';
            }


            public void remove(int index) {

                Node<T> temp=this;
                for(int i=0; i<index-1;i++)
                    temp=temp.next;
                temp.next=temp.next.next;
            }

            public int index(T el) {
                int i=0;
                Node<T> temp=this;
                while(temp!=null){
                    if (temp.data.compareTo(el)==0)
                        return i;
                    i++;
                    temp=temp.next;
                }
                return -1;
            }

            public T max() {
                Node<T> temp = this;
                while(temp.next!=null)
                    temp=temp.next;
                return temp.data;
            }

            public T at(int pos) throws Exception {
                Node<T> temp = this;
                for (int i=0; i<pos; i++) {
                    if (temp == null)
                        break;
                    temp=temp.next;
                }
                if (temp==null)
                    throw new Exception("Lista nie posiada tylu argumentów!");

                return temp.data;

            }
        }

        public OrderedList(T data){
            start = new Node<>(data);
        }
    public Node<T> start;

    @Override
    public boolean search(T el) {
        return start.search(el);
    }

    @Override
    public void insert(T el) throws Exception {
        if (el==null)
            throw new NullPointerException("Podany element jest wartoscia null!");

        start.insert(el);
    }

    @Override
    public void remove(T el) {
        int index=index(el);
        if (index==0)
            start=start.next;

        else if (index>0)
            start.remove(index);
    }

    @Override
    public T max() {

        if (start.next==null)
            return start.data;

        return start.max();
    }

    @Override
    public T min() {
        return start.data;
    }

    @Override
    public T at(int pos) throws Exception {
        return start.at(pos);
    }

    @Override
    public int index(T el) {
        return start.index(el);
    }

    @Override
    public String toString() {
        return "OrderedList{" +
                "start=" + start.toString() +
                '}';
    }
}
