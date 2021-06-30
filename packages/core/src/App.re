type state = {
  count: int,
  show: bool,
  greeting: string,
};

type action =
  | ButtonClick
  | InputChange(string)
  | Toggle;

open PaceUi;
[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ButtonClick => {...state, count: state.count + 1}
        | InputChange(greeting) => {...state, greeting}
        | Toggle => {...state, show: !state.show}
        },
      {count: 4, show: true, greeting: ""},
    );

  <div>
    <Button icon=`help> {React.string("Help Button")} </Button>
    <Button
      onClick={_event => dispatch(Toggle)} bsStyle=`warning icon=`warning>
      {React.string("Warning Button")}
    </Button>
    <Button
      icon=`success onClick={_event => dispatch(Toggle)} bsStyle=`success>
      {React.string("Success Button")}
    </Button>
    <Button bsStyle=`danger icon=`danger>
      {React.string("Danger Button")}
    </Button>
    <Button bsStyle=`danger disabled=true>
      {React.string("Disabled Button s")}
    </Button>
    // <Button hide=false />
  </div>;
};
