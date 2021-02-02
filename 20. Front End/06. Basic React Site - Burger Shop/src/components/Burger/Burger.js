import React from 'react';

import "./Burger.css";
import BurgerIngredient from './BurgerIngredient';

const burger = (props) => {
    // We are receiving 'ingredients' from BurgerBuilder as an object. 
    // We can't use map function directly on it. So we transform our object,
    // to appropiate type as follows:
    let transformIngridients = Object.keys(props.ingredients).map(
        ingredientsKey => {return [...Array(props.ingredients[ingredientsKey])].map(
            (_, i) => {
                return <BurgerIngredient key={ingredientsKey + i} type={ingredientsKey}/>
            })
        }).reduce(
            (arr, el) => {
                return arr.concat(el);
            }, []
        );

    if (transformIngridients.length === 0) {
        transformIngridients = <p>Please start adding Ingredients!</p>
    }        

    return (
        <div className="Burger">
            <BurgerIngredient type="bread-top" />
            {transformIngridients}
            <BurgerIngredient type="bread-bottom" />
        </div>
    )
}

export default burger;