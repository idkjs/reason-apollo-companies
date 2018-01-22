let component = ReasonReact.statelessComponent("Todo");

module Query = Apollo.Client.Query;

module CompaniesQuery = [%graphql
  {|
    query allCompanies {
        companies{
          id
          name
          url
          logo
        }
      }
|}
];

let companiesQuery = CompaniesQuery.make();

let make = (_children) => {
  ...component,
  render: (_) =>
    <section className="main">
      <Query query=companiesQuery>
        (
          (result, parse) =>
            switch result {
            | Failed(error) => <div> <String text=error /> </div>
            | Loading => <div> <String text="Loading" /> </div>
            | Loaded(result) =>
              let companies = parse(result)##companies;
              <ul className="todo-list">
                (
                  Array.map((company) => <CompanyItem company key=company##id />, companies)
                  |> ReasonReact.arrayToElement
                )
              </ul>
            }
        )
      </Query>
    </section>
};