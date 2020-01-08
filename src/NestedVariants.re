/* Keep in mind that if you’re dealing with values coming from JavaScript that may be null, then Belt.Option won’t be enough. (None in Reason is the same as undefined, but not null.) You’ll need to convert it with Js.Nullable.toOption: */

// let (<$>) = (nullable, f) => Belt.Option.map(Js.Nullable.toOption(nullable), f);
let (<$>) = Belt.Option.map;
let (>>=) = Belt.Option.flatMap;
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
Js.log(totoFurColor);
let nemo = Thing.Animal(Species.Fish);
let nemoFurColor =
  nemo |> Thing.toSpecies >>= Species.toCovering <$> Covering.toColor;
/* nemoFurColor = None */
Js.log(nemoFurColor);