type state = {
  count: int,
  show: bool,
  greeting: string,
};

type action =
  | ButtonClick
  | InputChange(string)
  | Toggle;

let component = ReasonReact.reducerComponent("App");

open PaceUi;

let make = _children => {
  ...component,
  initialState: () => {count: 4, show: true, greeting: ""},
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
        icon=`success onClick={_event => self.send(Toggle)} bsStyle=`success>
        {ReasonReact.string("Success Button")}
      </Button>
      <Button bsStyle=`danger icon=`danger>
        {ReasonReact.string("Danger Button")}
      </Button>
      <Button bsStyle=`danger disabled=true>
        {ReasonReact.string("Disabled Button s")}
      </Button>
      <ReactJsComponent hide=false />
    </div>;
  },
};