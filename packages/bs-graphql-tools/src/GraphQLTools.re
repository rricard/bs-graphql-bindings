external makeExecutableSchema :
  Js.t {. typeDefs : string, resolvers : Js.t 'a} => GraphQL.Type.schema =
  "makeExecutableSchema" [@@bs.module "graphql-tools"];
