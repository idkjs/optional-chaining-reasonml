type unreliableObject = {doesThisExist: option(doesThisExist)}
and doesThisExist = {orThis: option(string)};

let everythingExists = {doesThisExist: Some({orThis: Some("Horray!")})};
let everythingExistsNone = {doesThisExist: Some({orThis: None})};
let doesntExist = {doesThisExist: None};

let result =
  switch (everythingExists) {
  | {doesThisExist: None}
  | {doesThisExist: Some({orThis: None})} => None
  | {doesThisExist: Some({orThis: Some(x)})} => Some(x ++ " it exists!")
  };
let resultNone =
  switch (everythingExistsNone) {
  | {doesThisExist: None}
  | {doesThisExist: Some({orThis: None})} => None
  | {doesThisExist: Some({orThis: Some(x)})} => Some(x ++ " it exists!")
  };

Js.log(result)
Js.log(resultNone)

open Belt;
let resultWithBelt =
  everythingExists.doesThisExist
  ->Option.flatMap(x => x.orThis)
  ->Option.map(x => x ++ " it exists!");
Js.log2("resultWithBelt",resultWithBelt)