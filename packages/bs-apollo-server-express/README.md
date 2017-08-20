# bs-apollo-server-express

[BuckleScript](https://bucklescript.github.io/) binding for [apollo-server-express](https://github.com/apollographql/apollo-server).

## Installation

```
npm install --save graphql express body-parser bs-express bs-graphql bs-apollo-server-express
# or
yarn add graphql express body-parser bs-express bs-graphql bs-apollo-server-express
```

As always, you will need to indicate to BuckleScript that the binding is available.

`bsconfig.json`
```json
{
  ...
  "bs-dependencies": [
    "bs-express",
    "bs-graphql",
    "bs-apollo-server-express"
  ]
}
```

## Usage

You can start a GraphQL server using bs-graphql, bs-express and this binding:

```reason
let app = Express.App.make ();

let schema = GraphQL.Utilities.buildSchema "type Query { hello: String }";

let rootValue = {"hello": fun () => "world"};

let middleware = ApolloServerExpress.createGraphQLExpressMiddleware schema ::rootValue;

external bodyParserJson : unit => Express.Middleware.t = "json" [@@bs.module "body-parser"];

Express.App.use app (bodyParserJson ());

Express.App.useOnPath app middleware path::"/graphql";

Express.App.listen app port::8080;
```

Now you can make GraphQL queries to `http://localhost:8080`.
