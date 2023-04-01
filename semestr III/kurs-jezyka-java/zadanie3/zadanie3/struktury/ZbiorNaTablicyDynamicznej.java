package struktury;

import java.util.Arrays;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy{

    public ZbiorNaTablicyDynamicznej() throws Exception {
        super(2);
    }

    public void ZmienRozmiar(){

        if ((ile() < pary.length / 4) || (ile() == pary.length)) {

            Para[] new_pary;

            if (ile() < pary.length / 4) {

                new_pary = new Para[pary.length / 2];
                System.arraycopy(pary, 0, new_pary, 0, pary.length / 2);

            }
            else{

                new_pary = new Para[pary.length * 2];
                System.arraycopy(pary, 0, new_pary, 0, pary.length);

            }
            pary = new_pary;
        }
    }

    @Override
    public void wstaw(Para p) throws Exception {

        ZmienRozmiar();
        super.wstaw(p);
    }

    @Override
    public void ustaw(Para p) throws Exception {

        int pairIndex = findPair(p.klucz);

        if (pairIndex==-1)
            ZmienRozmiar();

        super.ustaw(p);

    }

    @Override
    public void usun(String k) throws Exception {

        super.usun(k);
        ZmienRozmiar();
    }

    @Override
    public void czysc() {

        super.czysc();
        pary = new Para[2];

    }

    @Override
    public String toString() {
        return "ZbiorNaTablicyDynamicznej{" +
                "pary=" + Arrays.toString(pary) +
                '}';
    }
}
