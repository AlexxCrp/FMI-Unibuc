var express = require('express');
var router = express.Router();

let rezervariService = require("./rezervariService.js");
let rezervariRepository = require("./rezervariRepository.js");

router.post("/tip1", (req, res) => {
    let newRezervare = rezervariService.addRezervare(req.body);
    res.status(200).send(newRezervare);
});

router.get("/tip1", (req, res) => {
    let rezervari = rezervariService.getRezervari()
    if(rezervari != undefined && rezervari.length != 0) {
        res.status(200).send(rezervari);
    } else {
        res.status(404).send("Nu avem rezervari!");
    }
});
/*
router.put("/tip1", (req, res) => {
    let rez = rezervariService.updateRezervare(req.body);
    if(rez !== false) {
        res.status(200).send(rez);
    } else {
        res.status(404).send("Nu am gasit rezervari!");
    }
});
*/

router.put("/tip1", (req,res) => {

    const rezervari = rezervariService.getRezervari();
    let Exists = false;
        if(rezervari.length != 0) {
            rezervari[rezervari.length - 1].numarPersoane = req.body.numarPersoane;
            rezervari[rezervari.length - 1].dataRezervata = req.body.dataRezervata;
            rezervari[rezervari.length - 1].tip = req.body.tip;
            rezervari[rezervari.length - 1].cod = req.body.cod;

            Exists = true;
        }

    if(Exists === true) {
        rezervariRepository.writeJSONFile(rezervari);
        res.status(200).send(req.body);
    }
    else {
        res.status(404).send("Nu am gasit rezervari!");
    }
});

router.delete("/tip1", (req, res) => {
    let deleteFlag = rezervariService.deleteRezervare();
    if(deleteFlag === true) {
        res.status(200).send("Rezervare stearsa!");
    } else {
        res.status(404).send("Rezervare not found!");
    }
});

module.exports = router;