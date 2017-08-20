open Jest;

open ExpectJs;

let () =
  describe
    "#buildSchema"
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
    );
