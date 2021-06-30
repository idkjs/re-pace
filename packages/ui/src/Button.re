type bsStyle = [
  | `default
  | `primary
  | `success
  | `warning
  | `danger
  | `inverse
  | `minimal
  | `link
];

type bsSize = [ | `normal | `small | `xs];

module Styles = {
  /* Open the Css module, so we can access the style properties below without prefixing them with Css. */
  open Css;

  let getBackgroundColor = (~bsStyle) =>
    switch (bsStyle) {
    | `default => gray
    | `primary => green
    | `success => green
    | `warning => yellow
    | `danger => red
    | `inverse => white
    | `minimal => white
    | `link => white
    };

  let button = (~disabled, ~bsStyle) =>
    style([
      position(relative),
      display(inlineBlock),
      boxShadow(
        Shadow.box(~inset=true, ~y=px(1), rgba(255, 255, 255, `num(0.1))),
      ),
      borderWidth(px(1)),
      marginBottom(zero),
      borderColor(green),
      borderBottomColor(red),
      backgroundColor(disabled ? gray : getBackgroundColor(~bsStyle)),
      textAlign(center),
      verticalAlign(middle),
      cursor(disabled ? `notAllowed : `pointer),
      backgroundImage(none),
      borderStyle(solid),
      whiteSpace(nowrap),
    ]);
};

[@genType]
[@react.component]
let make =
    (
      ~onClick=?,
      ~disabled=false,
      ~caret=false,
      ~hide=?,
      ~icon=?,
      ~bsStyle: bsStyle=`default,
      ~bsSize: bsSize=`normal,
      ~children,
    ) => {
  let onButtonClick = event => {
    switch (onClick) {
    | None => ()
    | Some(onClick) => onClick(event)
    };
    Js.log(event);
  };
  let iconEl = _ =>
    switch (icon) {
    | None => React.null
    | Some(icon) => <Icon iconType=icon />
    };
  <button
    onClick=onButtonClick className={Styles.button(~disabled, ~bsStyle)}>
    {iconEl()}
    <span> children </span>
    {caret ? <span className="caret" /> : React.null}
  </button>;
};
