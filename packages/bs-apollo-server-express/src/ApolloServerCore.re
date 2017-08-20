type logAction = string;

type logStep = string;

type logMessage =
  Js.t {
    .
    action : logAction,
    step : logStep,
    key : Js.null_undefined string,
    data : Js.null_undefined Js.Types.obj_val
  };

type graphqlOptions 'rootValue 'context 'response =
  Js.t {
    .
    schema : GraphQL.Type.schema,
    formatError : Js.null_undefined (Js.Exn.t => GraphQL.Error.error),
    rootValue : Js.null_undefined (Js.t 'rootValue),
    context : Js.null_undefined (Js.t 'context),
    logFunction : Js.null_undefined (logMessage => unit),
    formatParams : Js.null_undefined (Js.Types.obj_val => Js.Types.obj_val),
    validationRules : Js.null_undefined GraphQL.Validation.validationContext,
    formatResponse :
      Js.null_undefined (GraphQL.Execution.executionResult Js.Types.obj_val => Js.t 'response),
    fieldResolver :
      Js.null_undefined (GraphQL.Type.fieldResolver Js.Types.obj_val Js.Types.obj_val),
    debug : Js.null_undefined Js.boolean
  };
