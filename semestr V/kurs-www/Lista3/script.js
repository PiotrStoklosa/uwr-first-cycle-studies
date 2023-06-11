const marka = document.querySelector("#marka");
const nowa = document.querySelector("#nowa");
const model = document.querySelector("#model");

marka.addEventListener("change", (e) => {
  ustawModele(e.target.value);
});

const dane = {
  Fiat: ["punto", "panda"],
  Ford: ["mustang", "focus"],
};

Object.keys(dane).forEach((value) => {
  dodajMarke(value);
});

ustawModele(marka.value);

const _dodaj = document.querySelector("#dodaj");
_dodaj.addEventListener("click", dodaj);


function ustawModele(nazwaMarki) {
  for (let i = model.options.length; i >= 0; i--) model.remove(i);
  dane[nazwaMarki].forEach((model) => {
    dodajModel(model);
  });
}

function dodajMarke(nazwaMarki) {
  const option = document.createElement("option");
  option.value = nazwaMarki;
  option.text = nazwaMarki;
  marka.add(option);
  nowa.value = "";
}

function dodajModel(nazwaModelu) {
  const option = document.createElement("option");
  option.value = nazwaModelu;
  option.text = nazwaModelu;
  model.add(option);
  nowa.value = "";
}

function dodaj() {
  var ObiektSelect;
  if (nowa.value == "") {
    return;
  }
  if (document.getElementById("r1").checked) {
    dane[nowa.value] = [];
    dodajMarke(nowa.value);
  } else {
    dane[marka.value].push(nowa.value);
  }
}