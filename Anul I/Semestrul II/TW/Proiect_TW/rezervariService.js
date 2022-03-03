const rezervariRepository = require("./rezervariRepository.js");
const uuid = require("uuid");

module.exports.getRezervari = () => {
    const listaRezervari = rezervariRepository.readJSONFile();
    return listaRezervari;
}

module.exports.addRezervare = (rezervare) => {
    const listaRezervari = rezervariRepository.readJSONFile();
    rezervare.id = uuid.v4.apply();
    listaRezervari.push(rezervare);
    rezervariRepository.writeJSONFile(listaRezervari);
}
/*
module.exports.updateRezervare = (rezervare) => {
    const rezervari = rezervariRepository.readJSONFile();
    let updateRezervare = false;
    if(rezervari.length != 0){
        rezervari[rezervari.length - 1].numarPersoane = rezervare.numarPersoane;
        rezervari[rezervari.length - 1].dataRezervata = rezervare.dataRezervata;
        rezervari[rezervari.length - 1].tip = rezervare.tip;
        rezervari[rezervari.length - 1].cod = rezervare.cod;
        updateRezervare = true;
    }
    rezervariRepository.writeJSONFile(rezervari);
    return updateRezervare;
}
*/
module.exports.deleteRezervare = () => {
    const rezervari = rezervariRepository.readJSONFile();
    let ok = false; 
    if(rezervari.length)
    {
        ok = true;
        rezervari.splice(rezervari.length - 1, 1);
    }
    rezervariRepository.writeJSONFile(rezervari);
    return ok;
}

