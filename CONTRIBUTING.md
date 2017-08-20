# Reporting Issues

You are encouraged to open issues [here on GitHub](https://github.com/rricard/bs-graphql/issues). Each issue you open should tell which package is affected and if it is a bug or a feature request. Please follow the template to make sure you are not forgetting anything!

# Working in the repository

This repository is a [lerna](http://lernajs.io) monorepo. That means a few different things than a normal npm-based repo.

We require you to use [yarn](https://yarnpkg.com/en/).

Now you can install lerna and pull the repository:

```sh
yarn global add lerna
git pull git@github.com:rricard/bs-graphql.git
cd bs-graphql
```

From there you will need to install the dev dependencies and bootstrap the packages:

```sh
yarn install
lerna bootstrap
```

Now, you can try to build the packages and run their tests:

```sh
yarn build
yarn test
```

# Submitting a pull-request

You are encouraged to submit your changes [here on GitHub](https://github.com/rricard/bs-graphql/pulls). Each pull request you create should tell which package is affected and if it solves a bug or adds a new feature. Either way, try to provide tests. Please follow the template to make sure you are not forgetting anything!
