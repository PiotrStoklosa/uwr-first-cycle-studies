package zadanie4;

public class ATM{

    private PlasticCard plasticCard;
    private State state;

    public void setState(State state) {
        this.state = state;
    }

    public ATM() {
        state = new WaitingState(this);
    }

    protected PlasticCard getPlasticCard() {
        return plasticCard;
    }

    public void setPlasticCard(PlasticCard plasticCard) {
        this.plasticCard = plasticCard;
    }


    public void insertPlasticCard(PlasticCard plasticCard) throws Exception {
            state.insertPlasticCard(plasticCard);
    }


    public int getCash(int cash) throws Exception {
        return state.getCash(cash);
    }


    public boolean insertPIN(int PIN) throws Exception {
        return state.insertPIN(PIN);
    }

    PlasticCard returnPlasticCard() throws Exception{
        return state.returnPlasticCard();
    }
}
