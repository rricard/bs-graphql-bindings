module Execution = GraphQLExecution_;

module Type = GraphQLType_;

module Utilities = GraphQLUtilities_;


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
