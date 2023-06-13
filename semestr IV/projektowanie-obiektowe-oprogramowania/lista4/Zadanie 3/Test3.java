package Zadanie3;

import org.junit.Assert;

public class Test3 {

    @org.junit.Test(expected = IllegalArgumentException.class)
    public void Test3InvalidCapacity() {

        new Airport(0);

    }

    @org.junit.Test
    public void ValidCapacity() {

        Airport airport = new Airport(1);
        Plane plane = airport.AcquirePlane();

        Assert.assertNotNull(plane);

    }

    @org.junit.Test(expected = IllegalArgumentException.class)
    public void CapacityDepleted() {

        Airport airport = new Airport(1);
        airport.AcquirePlane();
        airport.AcquirePlane();

    }

    @org.junit.Test
    public void ReusedObject() {

        Airport airport = new Airport(1);
        Plane plane = airport.AcquirePlane();

        airport.ReleasePlane(plane);

        Plane plane2 = airport.AcquirePlane();

        Assert.assertEquals(plane,plane2);

    }

    @org.junit.Test(expected = IllegalArgumentException.class)
    public void ReleaseInvalidPlane() {

        Airport airport = new Airport(1);

        Plane plane = new Plane();

        airport.ReleasePlane(plane);

    }

}
