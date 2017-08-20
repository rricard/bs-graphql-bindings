open Jest;

open ExpectJs;

let () = {
  let schema = GraphQL.Utilities.buildSchema "type Query { hello: String }";
  let rootValue = {"hello": fun () => "world"};
  let source = "{ hello }";
  describe
    "#run"
    (
      fun () =>
        testPromise
          "run queries through the function"
          (
            fun () =>
              GraphQL.run schema source ::rootValue |>
              Js.Promise.then_ (
                fun execResult =>
                  Js.Promise.resolve (expect execResult##data##hello |> toEqual "world")
              )
          )
    );
  describe
    "#graphql"
    (
      fun () =>
        testPromise
          "run queries through the function"
          (
            fun () =>
              GraphQL.graphql {
                "schema": schema,
                "source": source,
                "rootValue": Js.Null_undefined.return rootValue,
                "contextValue": Js.Null_undefined.undefined,
                "variableValue": Js.Null_undefined.undefined,
                "operationName": Js.Null_undefined.undefined,
                "fieldResolver": Js.Null_undefined.undefined
              } |>
              Js.Promise.then_ (
                fun execResult =>
                  Js.Promise.resolve (expect execResult##data##hello |> toEqual "world")
              )
          )
    );
  describe
    "Utilities#buildSchema"
    (
      fun () =>
        testPromise
          "creates a usable schema with nested types"
          (
            fun () => {
              let schema =
                GraphQL.Utilities.buildSchema "type Query { me: User } type User { name: String }";
              let rootValue = {"me": fun () => {"name": "reason"}};
              let source = "{ me { name } }";
              GraphQL.run schema source ::rootValue |>
              Js.Promise.then_ (
                fun execResult =>
                  Js.Promise.resolve (expect execResult##data##me##name |> toEqual "reason")
              )
            }
          )
    )
};
