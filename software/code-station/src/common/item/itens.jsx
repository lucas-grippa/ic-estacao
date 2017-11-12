import React from 'react'
import Grid from '../layout/grid'

export default props => (
    <Grid cols={props.cols}>
            <div className='nav-tabs-custom'> 
                {props.children}
            </div>
    </Grid> 
)