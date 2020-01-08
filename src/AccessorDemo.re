// https://bucklescript.github.io/docs/en/generate-converters-accessors#generate-first-class-accessors-for-record-types

type pet = {name: string};

let pets = [{name: "bob"}, {name: "bob2"}];
pets |> List.map(pet => pet.name) |> String.concat("&") |> Js.log;

[@bs.deriving accessors]
type pet2 = {name: string};

let pets = [{name: "bob"}, {name: "bob2"}];
pets |> List.map(name) |> String.concat("&") |> Js.log;
Js.log(pets);
let petsArray = [|{name: "bob"}, {name: "bob2"}|];
Js.log(petsArray)
petsArray |> Array.map(pet => pet.name) |> Js.log;