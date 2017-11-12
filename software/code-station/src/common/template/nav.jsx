import React from 'react'
import NavItem from './navItem'

export default props => (
    <ul className='nav navbar-nav'>
        {props.children}
    </ul>
)