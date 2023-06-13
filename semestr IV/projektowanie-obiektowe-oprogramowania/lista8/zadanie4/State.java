package zadanie4;

public interface State {

    void insertPlasticCard(PlasticCard plasticCard) throws Exception;
    PlasticCard returnPlasticCard() throws Exception;
    int getCash(int cash) throws Exception;
    boolean insertPIN(int PIN) throws Exception;

}