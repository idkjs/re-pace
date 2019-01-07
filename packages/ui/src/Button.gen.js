/** 
 * @flow strict
 * @generated
 * @nolint
 */

const $$toRE153033107 = {"default": 465819841, "primary": 58474434, "success": 944645571, "warning": 164354652, "danger": 512905955, "inverse": 1039223728, "minimal": -873810847, "link": -944564230};

// $FlowExpectedError: Reason checked type sufficiently
import * as ButtonBS from './Button.bs';

// $FlowExpectedError: Reason checked type sufficiently
import * as Curry from 'bs-platform/lib/es6/curry.js';

// $FlowExpectedError: Reason checked type sufficiently
import * as ReasonReact from 'reason-react/src/ReasonReact.js';

// flowlint-next-line nonstrict-import:off
import type {Icons_iconType as PaceUi_Icons_iconType} from './PaceUi.gen';

// flowlint-next-line nonstrict-import:off
import type {Mouse_t as ReactEvent_Mouse_t} from './ReactEvent.shim';

// flowlint-next-line nonstrict-import:off
import type {reactElement as ReasonReact_reactElement} from './ReactShim.shim';

export type bsStyle = "default" | "primary" | "success" | "warning" | "danger" | "inverse" | "minimal" | "link";

export type Props = {|
  +onClick?: (ReactEvent_Mouse_t) => void, 
  +disabled?: boolean, 
  +caret?: boolean, 
  +icon?: PaceUi_Icons_iconType, 
  +bsStyle?: bsStyle, 
  +children?: Array<ReasonReact_reactElement>
|};

export const component: React$ComponentType<Props> = ReasonReact.wrapReasonForJs(
  ButtonBS.component,
  (function _(jsProps: Props) {
     return Curry._6(ButtonBS.make, jsProps.onClick, jsProps.disabled, jsProps.caret, jsProps.icon, $$toRE153033107[jsProps.bsStyle], jsProps.children);
  }));

export default component;