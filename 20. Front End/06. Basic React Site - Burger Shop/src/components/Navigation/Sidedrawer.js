import React from 'react';

import Logo from '../Logo/Logo';
import NavigationItems from './NavigationItems';
import './Sidedrawer.css';
import Backdrop from '../UI/Backdrop';
import Aux from '../../hoc/Helper';

const sideDrawer = ( props ) => {
    let attachedClasses = ["SideDrawer", "Close"];
    if (props.open) {
        attachedClasses = ["SideDrawer", "Open"];
    }
    return (
        <Aux>
            <Backdrop show={props.open} clicked={props.closed}/>
            <div className={attachedClasses.join(' ')}>
                <div className="Logo" style={{height: "11%"}}>  
                    <Logo />
                </div>
                <nav>
                    <NavigationItems />
                </nav>
            </div>
        </Aux>
    );
};

export default sideDrawer;