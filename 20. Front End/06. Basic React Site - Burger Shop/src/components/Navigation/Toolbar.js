import React from 'react';

import './Toolbar.css';
import Logo from '../Logo/Logo';
import NavigationItems from './NavigationItems';
import DrawerToggle from './DrawerToggle';

const toolbar = ( props ) => (
    <header className="Toolbar">
        <DrawerToggle clicked={props.drawerToggleClicked} />
        <div className="Logo">
            <Logo />
        </div>
        <nav className="DesktopOnly">
            <NavigationItems />
        </nav>
    </header>
);

export default toolbar;