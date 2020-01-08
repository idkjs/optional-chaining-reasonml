# Nullable types
Keep in mind that if you’re dealing with values coming from JavaScript that may be null, then Belt.Option won’t be enough. (None in Reason is the same as undefined, but not null.) You’ll need to convert it with Js.Nullable.toOption:

```ocaml
let (<$>) = (nullable, f) => Belt.Option.map(Js.Nullable.toOption(nullable), f);
```
