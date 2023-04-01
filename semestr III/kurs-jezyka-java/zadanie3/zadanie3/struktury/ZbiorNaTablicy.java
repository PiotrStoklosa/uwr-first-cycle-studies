package struktury;

import java.util.Arrays;

public class ZbiorNaTablicy extends Zbior {

    protected Para[] pary;
    protected int licznik=0;

    public ZbiorNaTablicy(int rozmiar) throws Exception {

        if (rozmiar<2)
            throw new SizeException();

        pary = new Para[rozmiar];
    }

    protected int findPair(String klucz){
        for (int i=0; i<ile(); i++)
            if (klucz.equals(pary[i].klucz))
                return i;
        return -1;
    }

    @Override
    public Para szukaj(String k) throws Exception {

        int pairIndex = findPair(k);

        if (pairIndex!=-1)
            return pary[pairIndex];

        throw new LackOfPairException();
    }

    @Override
    public void wstaw(Para p) throws Exception {


        if (ile()==pary.length)
            throw new OutOfSpaceException();

        int pairIndex = findPair(p.klucz);

        if (pairIndex==-1)
            pary[ile()] = p;
        else
            throw new ExistPairException();

        licznik++;

    }

    @Override
    public void usun(String k) throws Exception {

        int pairIndex = findPair(k);

        if (pairIndex==-1)
            throw new LackOfPairException();

        for (int i=pairIndex; i<pary.length-1; i++){

            if (pary[i+1]==null)
                pary[i] = null;
            else
                pary[i] = new Para(pary[i+1].klucz,pary[i+1].getWartosc());
        }

        licznik--;
    }

    @Override
    public double czytaj(String k) throws Exception {

        int pairIndex = findPair(k);

        if (pairIndex!=-1)
            return pary[pairIndex].getWartosc();

        throw new LackOfPairException();
    }

    @Override
    public void ustaw(Para p) throws Exception {

        int pairIndex = findPair(p.klucz);

        if (pairIndex==-1) {
            if (pary.length==ile())
                throw new OutOfSpaceException();

            pary[ile()] = p;
            licznik++;
        }
        else
            pary[pairIndex]=p;
    }

    @Override
    public void czysc() {

        for (int i=0; pary[i]!=null; i++)
            pary[i]=null;

        licznik = 0;
        }

    @Override
    public int ile() {

        return licznik;

    }

    @Override
    public String toString() {
        return "ZbiorNaTablicy{" +
                "pary=" + Arrays.toString(pary) +
                '}';
    }
}
