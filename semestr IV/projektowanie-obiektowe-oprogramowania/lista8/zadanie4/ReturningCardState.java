package zadanie4;

public record ReturningCardState(ATM atm) implements State {

    @Override
    public void insertPlasticCard(PlasticCard plasticCard) throws Exception {
        throw new Exception("PlasticCard already inserted!");
    }

    @Override
    public PlasticCard returnPlasticCard() {

        atm.setState(new WaitingState(atm));
        return atm.getPlasticCard();

    }

    @Override
    public int getCash(int cash) throws Exception {
        throw new Exception("PlasticCard already taken!");
    }

    @Override
    public boolean insertPIN(int PIN) throws Exception {
        throw new Exception("PIN already inserted!");
    }
}
