open Jest;

open ExpectJs;

let () = {
  let schema = GraphQL.Utilities.buildSchema "type Query { hello: String }";
  let rootValue = {"hello": fun () => "world"};
  describe
    "#createGraphQLExpressMiddleware"
    (
      fun () =>
        test
          "creates an express middleware"
          (
            fun () => {
              let middleware =
                ApolloServerExpress.createGraphQLExpressMiddleware schema ::rootValue;
              expect middleware |> toBeTruthy
            }
          )
    )
};
