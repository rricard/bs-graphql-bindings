/**
 * Represents a GraphQL Error type
 */
type error =
  Js.t {
    .
    message : string,
    locations : Js.null_undefined (Js.Array.t GraphQLLanguage_.location),
    nodes : Js.null_undefined (Js.Array.t GraphQLLanguage_.astNode),
    source : Js.null_undefined GraphQLLanguage_.source,
    positions : Js.null_undefined (Js.Array.t int),
    originalError : Js.null_undefined Js.Exn.t
  };
