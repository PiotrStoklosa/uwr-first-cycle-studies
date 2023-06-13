package Zadanie3;

import java.util.ArrayList;
import java.util.List;

public class Airport {

    private final int capacity;

    private final List<Plane> ready = new ArrayList<>();
    private final List<Plane> released = new ArrayList<>();

    public Airport(int capacity){
        if (capacity <= 0)
            throw new IllegalArgumentException();

        this.capacity = capacity;

    }

    public Plane AcquirePlane(){

        if (released.size() == capacity)
            throw new IllegalArgumentException();

        if (ready.isEmpty()){
            Plane newPlane = new Plane();
            ready.add(newPlane);
        }

        Plane returnPlane = ready.get(0);

        ready.remove(0);
        released.add(returnPlane);

        return returnPlane;

    }

    public void ReleasePlane(Plane plane){

        if (!released.contains(plane))
            throw new IllegalArgumentException();

        released.remove(plane);
        ready.add(plane);

    }

}
