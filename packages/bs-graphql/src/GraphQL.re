module Language = {
  type location = Js.t {. line : int, column : int};
  type source = Js.t {. body : string, name : string, locationOffset : location};
  type astNode;
};

module Error = {

  /**
   * Represents a GraphQL Error type
   */
  type error =
    Js.t {
      .
      message : string,
      locations : Js.null_undefined (Js.Array.t Language.location),
      nodes : Js.null_undefined (Js.Array.t Language.astNode),
      source : Js.null_undefined Language.source,
      positions : Js.null_undefined (Js.Array.t int),
      originalError : Js.null_undefined Js.Exn.t
    };
};

module Type = {

  /**
   * Represents a compiled GraphQL schema
   */
  type schema;
  type resolveInfo;
  type fieldResolver 'source 'context =
    Js.t {. source : 'source, args : Js.Types.obj_val, context : 'context, info : resolveInfo} =>
    Js.Types.obj_val;
};

module Execution = {

  /**
   * Represents a result from GraphQL, being either a success or a failure
   */
  type executionResult 'dataObj =
    Js.t {. data : Js.t 'dataObj, errors : Js.Null.t (Js.Array.t Error.error)};

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
      schema : Type.schema,
      source : string,
      rootValue : Js.null_undefined (Js.t 'rootObjType),
      contextValue : Js.null_undefined (Js.t 'contextObjType),
      variableValue : Js.null_undefined (Js.t 'variableValuesObjType),
      operationName : Js.null_undefined string,
      fieldResolver : Js.null_undefined 'resolverFunc
    };
};

module Utilities = {

  /**
   * A helper function to build a GraphQLSchema directly from a source
   * document.
   */
  external buildSchema : string => Type.schema = "buildSchema" [@@bs.module "graphql"];
};

module Validation = {
  type validationContext;
};


/**
 * This is the primary entry point function for fulfilling GraphQL operations
 * by parsing, validating, and executing a GraphQL document along side a
 * GraphQL schema.
 *
 * More sophisticated GraphQL servers, such as those which persist queries,
 * may wish to separate the validation and execution phases to a static time
 * tooling step, and a server runtime step.
 *
 * Accepts either an object with named arguments.
 */
external graphql :
  Execution.executionArgs 'rootObjType 'contextObjType 'variableValuesObjType 'resolverFunc =>
  Js.Promise.t (Execution.executionResult 'a) =
  "graphql" [@@bs.module "graphql"];


/**
 * Easy to use wrapper of the graphql call
 */
let run
    ::rootValue=?
    ::contextValue=?
    ::variableValue=?
    ::operationName=?
    ::fieldResolver=?
    schema
    source =>
  graphql {
    "schema": schema,
    "source": source,
    "rootValue": Js.Null_undefined.from_opt rootValue,
    "contextValue": Js.Null_undefined.from_opt contextValue,
    "variableValue": Js.Null_undefined.from_opt variableValue,
    "operationName": Js.Null_undefined.from_opt operationName,
    "fieldResolver": Js.Null_undefined.from_opt fieldResolver
  };
