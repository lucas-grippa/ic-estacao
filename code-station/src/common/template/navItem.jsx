import React from 'react'

export default props => (
    <li>
        <a href='#'
        data-toggle='item'
        aria-expanded='false'
        >
            <i className={props.icon}></i>
        </a>
    </li>
)