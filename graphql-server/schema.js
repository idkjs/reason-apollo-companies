import { log } from 'async';
// import { companies } from './companies.json'
// graphql-tools combines a schema string with resolvers.
const { makeExecutableSchema } = require('graphql-tools');

let companies = require("./companies.json");


// Construct a schema, using GraphQL schema language
const typeDefs = `
    
	type Company {
    id: ID!
    url: String!
    logo: String!
    name: String!
    employees: Int!
    tranch: String!
    address: String!
    location: String!
    sector: String!
    description: String!
    facebook: String!
    instagram: String!
    youtube: String!
    twitter: String!
  }
    
  type Query {
    companies: [Company!]!
  }

`;

// Provide resolver functions for your schema fields
const resolvers = {
  Query: {
    companies: () => {
      console.log(companies.length)
      return companies
    }
  }
};

exports.schema = makeExecutableSchema({
  typeDefs,
  resolvers,
});
