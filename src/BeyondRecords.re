let (<$>) = Belt.Option.map;
let (>>=) = Belt.Option.flatMap;

let result =
  UnReliableObject.everythingExists.doesThisExist
  >>= (x => x.orThis)
  <$> (x => x ++ " it exists!");

Js.log2("UnReliableObjectResult",result);
module Covering = {
  type t =
    | Fur(string)
    | Feathers(string);
  let toColor = (Fur(color) | Feathers(color)) => color;
};
module Species = {
  type t =
    | Dog(Covering.t)
    | Fish;
  let toCovering =
    fun
    | Dog(fur) => Some(fur)
    | Fish => None;
};
module Thing = {
  type t =
    | Animal(Species.t)
    | Machine;
  let toSpecies =
    fun
    | Animal(species) => Some(species)
    | Machine => None;
};
let toto = Thing.Animal(Species.Dog(Covering.Fur("black")));
let totoFurColor =
  toto |> Thing.toSpecies >>= Species.toCovering <$> Covering.toColor;
/* totoFurColor = Some("black") */
let nemo = Thing.Animal(Species.Fish);
let nemoFurColor =
  nemo |> Thing.toSpecies >>= Species.toCovering <$> Covering.toColor;
/* nemoFurColor = None */
Js.log(toto)
Js.log(totoFurColor);
Js.log(nemo)
Js.log(nemoFurColor)