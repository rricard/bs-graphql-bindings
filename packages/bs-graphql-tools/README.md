# bs-graphql-tools

[![npm version](https://badge.fury.io/js/bs-graphql-tools.svg)](https://badge.fury.io/js/bs-graphql-tools)

[BuckleScript](https://bucklescript.github.io/) binding for [graphql-tools](https://github.com/apollographql/graphql-tools/).

## Installation

```
npm install --save graphql bs-graphql bs-graphql-tools
# or
yarn add graphql bs-graphql bs-graphql-tools
```

As always, you will need to indicate to BuckleScript that the binding is available.

`bsconfig.json`
```json
{
  ...
  "bs-dependencies": [
    "bs-graphql",
    "bs-graphql-tools"
  ]
}
```

## Usage

> **WARNING**: Only `makeExecutableSchema` is implemented for now. More is coming soon but you can always contribute!

```reason
let typeDefs = "type Query { me: User } type User { name: String }";
let queryResolvers = {"me": fun () => {"name": "reason"}};
let userResolvers = {"name": fun user => user##name};
let resolvers = {"Query": queryResolvers, "User": userResolvers};
let schema = GraphQLTools.makeExecutableSchema {"typeDefs": typeDefs, "resolvers": resolvers};
Js.log (GraphQL.run schema ::rootValue "{ me { name } }");
```
