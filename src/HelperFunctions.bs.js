// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

function map(opt, fn) {
  if (opt !== undefined) {
    return Caml_option.some(Curry._1(fn, Caml_option.valFromOption(opt)));
  }
  
}

function flatMap(opt, fn) {
  if (opt !== undefined) {
    return Curry._1(fn, Caml_option.valFromOption(opt));
  }
  
}

var match = {
  orThis: "Horray!"
};

var resultWithSwitch;

if (match !== undefined) {
  var match$1 = match.orThis;
  resultWithSwitch = match$1 !== undefined ? match$1 + " it exists!" : undefined;
} else {
  resultWithSwitch = undefined;
}

var unwrappingTheOption = Belt_Option.map(Belt_Option.flatMap({
          orThis: "Horray!"
        }, (function (x) {
            return x.orThis;
          })), (function (x) {
        return x + " it exists!";
      }));

var everythingExists = {
  doesThisExist: {
    orThis: "Horray!"
  }
};

var doesntExist = {
  doesThisExist: undefined
};

exports.map = map;
exports.flatMap = flatMap;
exports.everythingExists = everythingExists;
exports.doesntExist = doesntExist;
exports.resultWithSwitch = resultWithSwitch;
exports.unwrappingTheOption = unwrappingTheOption;
/* unwrappingTheOption Not a pure module */
