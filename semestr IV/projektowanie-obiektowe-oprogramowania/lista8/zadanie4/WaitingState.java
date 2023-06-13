package zadanie4;

public record WaitingState(ATM atm) implements State{

    @Override
    public void insertPlasticCard(PlasticCard plasticCard) {
        atm.setPlasticCard(plasticCard);
        atm.setState(new InsertingPINState(atm));
    }

    @Override
    public PlasticCard returnPlasticCard() throws Exception {
        throw new Exception("Plastic card is not inserted!");
    }

    @Override
    public int getCash(int cash) throws Exception {
        throw new Exception("Plastic card is not inserted!");
    }

    @Override
    public boolean insertPIN(int PIN) throws Exception {
        throw new Exception("Plastic card is not inserted!");
    }
}
