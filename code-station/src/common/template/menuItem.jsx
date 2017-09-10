import React from 'react'

export default props => (
    <li> 
        <a href={props.path}>
            <i className={`${props.icon}`}></i> <span className='menu-item-content'>&nbsp; {props.label}</span>
        </a>
    </li>
)