let component = ReasonReact.statelessComponent("TodoItem");

let make = (~company, _children) => {
  ...component,
  render: (_) =>
    <li className="company">
      <div className="view">
        /* <ToggleCompany company /> */
         <label> <String text=company##name /> </label> </div>
    </li>
};