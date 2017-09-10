import React from 'react'

export default props => (
    <header className='main-header'>
        <a href='/#/' className='logo'>
            <span className='logo-mini'><i className='icon-station_icon'></i></span>
            <span className='logo-lg'>
                <i className='icon-station_icon'></i>
                <b>Code</b> Station
            </span>        
        </a>
        <nav className='navbar navbar-static-top'>
            <a href className='sidebar-toggle' data-toggle='offcanvas'></a>
        </nav>
    </header>
)