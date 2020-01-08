/* https://dev.to/johnridesabike/optional-chaining-in-reason-1im6 */
// Belt.Option.map is the same as:

let map = (opt, fn) =>
  switch (opt) {
  | Some(x) => Some(fn(x))
  | None => None
  };

// Belt.Option.flatMap is the same as:

let flatMap = (opt, fn) =>
  switch (opt) {
  | Some(x) => fn(x)
  | None => None
  };
  /* They look very similar, and they are often confused. The difference is that the function passed to flatMap returns a value wrapped in option. The function passed to map returns a non-optional value, and map will automatically wrap it in option for you. */

type unreliableObject = {doesThisExist: option(doesThisExist)}
and doesThisExist = {orThis: option(string)};

let everythingExists = {doesThisExist: Some({orThis: Some("Horray!")})};
let doesntExist = {doesThisExist: None};

// And now you can access this with an old-fashioned switch statement:

let resultWithSwitch =
  switch (everythingExists) {
  | {doesThisExist: None}
  | {doesThisExist: Some({orThis: None})} => None
  | {doesThisExist: Some({orThis: Some(x)})} => Some(x ++ " it exists!")
  };

// example above can be rewritten like this:

// below, the function passed to flatMap returns a value wrapped in option so we are calling Option.map on it to unwrap it.
open Belt;
let unwrappingTheOption = everythingExists.doesThisExist->Option.flatMap(x => x.orThis)->Option.map(x => x ++ " it exists!");