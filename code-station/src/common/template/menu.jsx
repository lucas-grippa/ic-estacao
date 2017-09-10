import React from 'react'
import MenuItem from './menuItem'

export default props => (
    <ul className='sidebar-menu'>
        <MenuItem path='#/' label='Esteira' icon='icon-belt_icon' />
        <MenuItem path='#/' label='Atuador 1' icon='icon-actuator1_icon' />
        <MenuItem path='#/' label='Atuador 2' icon='icon-actuator2_icon' />
        <MenuItem path='#/' label='Atuador 3' icon='icon-actuator3_icon' />
        <MenuItem path='#/' label='Atuador Circular' icon='icon-circularActuator_icon' />
        <MenuItem path='#/' label='Display LCD' icon='icon-lcd_icon' />
        <MenuItem path='#/' label='Sensores de Barreira' icon='icon-laser_icon' />
        <MenuItem path='#/' label='Sensor Ultrassônico' icon='icon-ultrasonicSensor_icon' />
        <MenuItem path='#/' label='Sensor de Cor' icon='icon-colorSensor_icon' />
    </ul>
)