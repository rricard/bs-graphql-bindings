/**
 * Represents a compiled GraphQL schema
 */
type schema;

type resolveInfo;

type fieldResolver 'source 'context =
  Js.t {. source : 'source, args : Js.Types.obj_val, context : 'context, info : resolveInfo} =>
  Js.Types.obj_val;
