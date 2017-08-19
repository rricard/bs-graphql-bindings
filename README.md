# bs-graphql

[![npm version](https://badge.fury.io/js/bs-graphql.svg)](https://badge.fury.io/js/bs-graphql) [![CircleCI](https://circleci.com/gh/rricard/bs-graphql.svg?style=svg)](https://circleci.com/gh/rricard/bs-graphql)

[BuckleScript](https://bucklescript.github.io/) binding for [graphql-js](http://graphql.org/graphql-js/).

## Installation

This package is just a binding and you will need to import the original graphql package as well.

```
npm install --save graphql bs-graphql
# or
yarn add graphql bs-graphql
```

As always, you will need to indicate to BuckleScript that the binding is available.

`bsconfig.json`
```json
{
  ...
  "bs-dependencies": [
    "bs-graphql"
  ]
}
```

## Usage

> **WARNING:** This package has been published so far with the only goal of being usable for simple graphql server development. For now, you can only count on `graphql` and `buildSchema` functions alongside a sugared call to `graphql`: `run`. You are obviously welcome to contribute any other missing part!

You can use this binding to build and execute some simple GraphQL schemas:

```reason
let schema = GraphQL.Utilities.buildSchema "type Query { me: User } type User { name: String }";
let rootValue = {"me": fun () => {"name": "reason"}};
Js.log (GraphQL.run schema ::rootValue "{ me { name } }");
```

## Contribute

Only a small API surface of graphql-js is covered for now. Your help will be more than welcome to fully develop this binding.

```
git clone git@github.com:rricard/bs-graphql.git
cd bs-graphql
yarn
yarn build
```

Then, you can run two watchers, one for compiling, one for testing:

- `yarn watch`
- `yarn test -- --watch`
