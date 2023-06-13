package zadanie4;

public record InsertingPINState(ATM atm) implements State {

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
        throw new Exception("Firstly insert PIN!");
    }

    @Override
    public boolean insertPIN(int PIN) {

        if (PIN == 1234) {
            atm.setState(new OwnerAcceptedState(atm));
            return true;
        }
        return false;

    }
}