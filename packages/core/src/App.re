/* State declaration */
type state = {
  count: int,
  show: bool,
  greeting: string,
};

/* Action declaration */
type action =
  | ButtonClick
  | InputChange(string)
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("App");

open PaceUi;

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {count: 4, show: true, greeting: ""},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | ButtonClick => ReasonReact.Update({...state, count: state.count + 1})
    | InputChange(greeting) => ReasonReact.Update({...state, greeting})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },
  render: self => {
    <div>
      <Button icon=`help> {ReasonReact.string("Help Button")} </Button>
      <Button
        onClick={_event => self.send(Toggle)} bsStyle=`warning icon=`warning>
        {ReasonReact.string("Warning Button")}
      </Button>
      <Button
        icon=`success
        onClick={_event => self.send(Toggle)}
        disabled=true
        bsStyle=`success>
        {ReasonReact.string("Success Button")}
      </Button>
      <Button bsStyle=`danger icon=`danger>
        {ReasonReact.string("Danger Button")}
      </Button>
    </div>;
  },
};