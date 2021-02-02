import React from 'react';

import "./BuildControl.css";

const buildControl = (props) => {
    return <div className="BuildControl">
        <p className="Label">{props.label}</p>
        <button className="Less" onClick={props.removed} disabled={props.disabled}>-</button>
        <button className="More" onClick={props.added}>+</button>
    </div>
};

export default buildControl;