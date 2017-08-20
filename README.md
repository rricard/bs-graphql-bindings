# BuckleScript GraphQL bindings

[![CircleCI](https://circleci.com/gh/rricard/bs-graphql.svg?style=svg)](https://circleci.com/gh/rricard/bs-graphql)

This repository stores a collection of [BuckleScript](https://bucklescript.github.io/) bindings for various, widely used, [GraphQL](http://graphql.org/) projects.

## Packages

The following packages are contained in this repository and published on npm:

| Package | Binds to | NPM | Description |
|---------|----------|-----|-------------|
| [`bs-graphql`](./packages/bs-graphql) | [`graphql-js`](https://github.com/graphql/graphql-js/) | [![npm version](https://badge.fury.io/js/bs-graphql.svg)](https://badge.fury.io/js/bs-graphql) | Core GraphQL bindings over the JS reference implementation |
| [`bs-graphql-tools`](./packages/bs-graphql-tools) | [`graphql-tools`](https://github.com/apollographql/graphql-tools/) | [![npm version](https://badge.fury.io/js/bs-graphql-tools.svg)](https://badge.fury.io/js/bs-graphql-tools) | Bindings for the Apollo GraphQL server tools |
| [`bs-apollo-server-express`](./packages/bs-apollo-server-express) | [`apollo-server-express`](https://github.com/apollographql/apollo-server/) | [![npm version](https://badge.fury.io/js/bs-apollo-server-express.svg)](https://badge.fury.io/js/bs-apollo-server-express) | Bindings to mount an apollo server on express |

> **WARNING**: Most of those bindings are **partial** for now! Please consult each binding's readme for more information.

## Guides

### Your first Reason-GraphQL server

This short guide will show you how to setup a GraphQL server fast.

First, you will need a reason codebase:

```sh
npm install -g bs-platform
bsb -init my-graphql-server -theme basic-reason
cd my-graphql-server
yarn install || npm install
```

Now, you need to install the packages here and graphql as well as express:

```
yarn add graphql express body-parser \
  bs-express bs-graphql bs-apollo-server-express bs-graphql-tools || \
npm install --save graphql express body-parser \
  bs-express bs-graphql bs-apollo-server-express bs-graphql-tools
```
Add the bindings in `bsconfig.json`:

```json
{
  "name": "my-graphql-server",
  "sources": [
    "src"
  ],
  "bs-dependencies" : [
    "bs-express",
    "bs-graphql",
    "bs-graphql-tools",
    "bs-apollo-server-express"
  ]
}
```

We're starting the development, you should run a watch process: `yarn watch || npm run watch`.

Remove `demo.re` and the following files:

First we'll define a Reason type alongside an associated GraphQL schema and resolver functions: `Episode.re`:

```reason
type t = {
  name: string,
  number: int
};
let hope = {name: "A New Hope", number: 4};
let empire = {name: "The Empire Strikes Back", number: 5};
let jedi = {name: "The Return of the Jedi", number: 6};
let getName e => e.name;
let getNumber e => e.number;
let typeDef = "type Episode { name: String!, number: Int! }";
let resolvers = {"name": getName, "number": getNumber};
```

Then, we'll define the base Query type similarly: `Query.re`:

```reason
let getEpisodes () => [|Episode.hope, Episode.empire, Episode.jedi|];
let getFavoriteEpisode () => Episode.empire;
let typeDef = "type Query { episodes: [Episode!]!, favoriteEpisode: Episode! }";
let resolvers = {"episodes": getEpisodes, "favoriteEpisode": getFavoriteEpisode};
```

We can now put together a schema: `Schema.re`:

```reason
let typeDefs = Query.typeDef ^ " " ^ Episode.typeDef;
let resolvers = {"Query": Query.resolvers, "Episode": Episode.resolvers};
let schema = GraphQLTools.makeExecutableSchema {"typeDefs": typeDefs, "resolvers": resolvers};
```

And finally, we can mount a server: `Server.js`:

```reason
let port = 8080;

external bodyParserJson : unit => Express.Middleware.t = "json" [@@bs.module "body-parser"];

let () = {
  let app = Express.App.make ();
  Express.App.use app (bodyParserJson ());
  let middleware = ApolloServerExpress.createGraphQLExpressMiddleware Schema.schema;
  Express.App.useOnPath app middleware path::"/graphql";
  Express.App.listen app ::port;
  Js.log ("GraphQL Server listening on http://localhost:" ^ string_of_int port)
};
```

If your watcher worked so far, you can now run the server and run a query against it:

```sh
node ./lib/js/src/server.js
curl --request POST \
  --url http://localhost:8080/graphql \
  --header 'content-type: application/json' \
  --data '{"query":"{ favoriteEpisode { name, number }}"}'
```

## Contributing

Please read the [CONTRIBUTING](./CONTRIBUTING.md) document if you want to help or report issues.
