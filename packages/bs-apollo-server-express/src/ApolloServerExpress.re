/**
 * Represents a function taking express request and response to output a promise for some graphqlOptions
 */
type expressGraphQLOptionsFunction 'rootValue 'context 'response =
  Express.Request.t =>
  Express.Response.t =>
  Js.Promise.t (ApolloServerCore.graphqlOptions 'rootValue 'context 'response);


/**
 * Calls the graphqlExpress middleware creation with static options
 */
external graphqlExpress :
  ApolloServerCore.graphqlOptions 'rootValue 'context 'response => Express.Middleware.t =
  "graphqlExpress" [@@bs.module "apollo-server-express"];


/**
 * Calls the graphqlExpress middleware creation with function options
 */
external graphqlExpressAsync :
  expressGraphQLOptionsFunction 'rootValue 'context 'response => Express.Middleware.t =
  "graphqlExpress" [@@bs.module "apollo-server-express"];


/**
 * Usability wrapper around the static graphqlExpress function
 */
let createGraphQLExpressMiddleware
    ::formatError=?
    ::rootValue=?
    ::context=?
    ::logFunction=?
    ::formatParams=?
    ::validationRules=?
    ::formatResponse=?
    ::fieldResolver=?
    ::debug=?
    schema =>
  graphqlExpress {
    "schema": schema,
    "formatError": Js.Null_undefined.from_opt formatError,
    "rootValue": Js.Null_undefined.from_opt rootValue,
    "context": Js.Null_undefined.from_opt context,
    "logFunction": Js.Null_undefined.from_opt logFunction,
    "formatParams": Js.Null_undefined.from_opt formatParams,
    "validationRules": Js.Null_undefined.from_opt validationRules,
    "formatResponse": Js.Null_undefined.from_opt formatResponse,
    "fieldResolver": Js.Null_undefined.from_opt fieldResolver,
    "debug": Js.Null_undefined.from_opt debug
  };
