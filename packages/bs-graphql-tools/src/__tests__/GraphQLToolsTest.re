open Jest;

open ExpectJs;

let () =
  describe
    "#makeExecutableSchema"
    (
      fun () =>
        testPromise
          "creates schemas that run correclty"
          (
            fun () => {
              let typeDefs = "type Query { me: User } type User { name: String }";
              let queryResolvers = {"me": fun () => {"name": "reason"}};
              let userResolvers = {"name": fun user => user##name};
              let resolvers = {"Query": queryResolvers, "User": userResolvers};
              let schema =
                GraphQLTools.makeExecutableSchema {"typeDefs": typeDefs, "resolvers": resolvers};
              let source = "{ me { name } }";
              GraphQL.run schema source |>
              Js.Promise.then_ (
                fun execResult =>
                  Js.Promise.resolve (expect execResult##data##me##name |> toEqual "reason")
              )
            }
          )
    );
