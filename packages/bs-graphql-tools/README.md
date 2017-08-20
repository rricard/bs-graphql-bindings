# bs-graphql-tools

[![npm version](https://badge.fury.io/js/bs-graphql-tools.svg)](https://badge.fury.io/js/bs-graphql-tools) [![CircleCI](https://circleci.com/gh/rricard/bs-graphql-tools.svg?style=svg)](https://circleci.com/gh/rricard/bs-graphql-tools)

[BuckleScript](https://bucklescript.github.io/) binding for [graphql-tools](https://github.com/apollographql/graphql-tools/).

## Installation

This package is just a binding and you will need to import the original graphql-tools package as well.

```
npm install --save graphql-tools bs-graphql-tools
# or
yarn add graphql-tools bs-graphql-tools
```

As always, you will need to indicate to BuckleScript that the binding is available.

`bsconfig.json`
```json
{
  ...
  "bs-dependencies": [
    "bs-graphql-tools"
  ]
}
```

## Usage

> **WARNING**: Only `makeExecutableSchema` is implemented for now. More is coming soon but you can always contribute!

The following example also uses [bs-graphql](https://github.com/rricard/bs-graphql):

```reason
let typeDefs = "type Query { me: User } type User { name: String }";
let queryResolvers = {"me": fun () => {"name": "reason"}};
let userResolvers = {"name": fun user => user##name};
let resolvers = {"Query": queryResolvers, "User": userResolvers};
let schema = GraphQLTools.makeExecutableSchema {"typeDefs": typeDefs, "resolvers": resolvers};
Js.log (GraphQL.run schema ::rootValue "{ me { name } }");
```

## Contribute

```
git clone git@github.com:rricard/bs-graphql-tools.git
cd bs-graphql-tools
yarn
yarn build
```

Then, you can run two watchers, one for compiling, one for testing:

- `yarn watch`
- `yarn test -- --watch`
