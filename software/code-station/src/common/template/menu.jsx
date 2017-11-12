import React from 'react'
import MenuItem from './menuItem'

export default props => (
    <ul className='sidebar-menu'>
        {props.children}
    </ul>
)