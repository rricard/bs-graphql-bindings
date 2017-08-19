/* PRIVATE USAGE */
type errorLocation = Js.t {. line : int, column : int};

/* PRIVATE USAGE */
type error = Js.t {. message : string, locations : Js.Array.t errorLocation};


/**
 * Represents a result from GraphQL, being either a success or a failure
 */
type executionResult 'dataObj =
  Js.t {. data : Js.t 'dataObj, errors : Js.Null.t (Js.Array.t error)};


/**
 * Represents arguments being passed to the execution engine
 *
 * schema:
 *    The GraphQL type system to use when validating and executing a query.
 * source:
 *    A GraphQL language formatted string representing the requested operation.
 * rootValue:
 *    The value provided as the first argument to resolver functions on the top
 *    level type (e.g. the query object type).
 * variableCalues:
 *    A mapping of variable name to runtime value to use for all variables
 *    defined in the requestString.
 * operationName:
 *    The name of the operation to use if requestString contains multiple
 *    possible operations. Can be omitted if requestString contains only
 *    one operation.
 * fieldResolver:
 *    A resolver function to use when one is not provided by the schema.
 *    If not provided, the default field resolver is used (which looks for a
 *    value or method on the source value with the field's name).
 */
type executionArgs 'rootObjType 'contextObjType 'variableValuesObjType 'resolverFunc =
  Js.t {
    .
    schema : GraphQLType_.schema,
    source : string,
    rootValue : Js.null_undefined (Js.t 'rootObjType),
    contextValue : Js.null_undefined (Js.t 'contextObjType),
    variableValue : Js.null_undefined (Js.t 'variableValuesObjType),
    operationName : Js.null_undefined string,
    fieldResolver : Js.null_undefined 'resolverFunc
  };
