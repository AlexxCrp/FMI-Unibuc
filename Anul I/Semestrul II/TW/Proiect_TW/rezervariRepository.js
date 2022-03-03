const fs = require("fs");

const router = require("./rezervariController.js");

module.exports.readJSONFile = () => {
    return JSON.parse(fs.readFileSync("db.json"))["tip1"];
}

module.exports.writeJSONFile = (content) => {
    fs.writeFileSync(
      "db.json",
      JSON.stringify({ tip1: content }, null, 4),
      "utf8",
      err => {
        if (err) {
          console.log(err);
        }
      }
    );
}