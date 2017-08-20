# BuckleScript GraphQL bindings

[![CircleCI](https://circleci.com/gh/rricard/bs-graphql.svg?style=svg)](https://circleci.com/gh/rricard/bs-graphql)

This repository stores a collection of [BuckleScript](https://bucklescript.github.io/) bindings for various, widely used, [GraphQL](http://graphql.org/) projects.

## Packages

The following packages are contained in this repository and published on npm:

| Package | Binds to | NPM | Description |
|---------|----------|-----|-------------|
| [`bs-graphql`](./packages/bs-graphql) | [`graphql-js`](https://github.com/graphql/graphql-js/) | [![npm version](https://badge.fury.io/js/bs-graphql.svg)](https://badge.fury.io/js/bs-graphql) | Core GraphQL bindings over the JS reference implementation |
| [`bs-graphql-tools`](./packages/bs-graphql-tools) | [`graphql-js`](https://github.com/apollographql/graphql-tools/) | [![npm version](https://badge.fury.io/js/bs-graphql-tools.svg)](https://badge.fury.io/js/bs-graphql-tools) | Bindings for the Apollo GraphQL server tools |

> **WARNING**: Most of those bindings are **partial** for now! Please consult each binding's readme for more information.

## Contributing

Please read the [CONTRIBUTING](./CONTRIBUTING.md) document if you want to help or report issues.
