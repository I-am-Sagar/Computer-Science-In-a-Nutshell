import React from 'react';

import BuildControl from './BuildControl';
import "./BuildControls.css";

const controls = [
    { label: 'Cheese', type : 'cheese' },
    { label: 'Bacon', type : 'bacon' },
    { label: 'Meat', type : 'meat' },
    { label: 'Salad', type : 'salad' },
];

const buildControls = (props) => {
    return <div className="BuildControls">
        <h4>Total Price: &#8377; {props.price}</h4>
        {controls.map(ctrl => (
            <BuildControl key={ctrl.label} label={ctrl.label} 
                added = {props.ingredientAdded.bind(this, ctrl.type)} 
                removed = {props.ingredientRemoved.bind(this, ctrl.type)}
                disabled={props.disabled[ctrl.type]}/>
        ))}
        <button className="OrderButton" disabled={!props.purchasable} 
            onClick={props.ordered}>ORDER NOW!</button>
    </div>
};

export default buildControls;