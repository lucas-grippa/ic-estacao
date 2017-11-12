import '../common/template/dependencies'
import React from 'react';
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

import Dashboard from '../dashboard/dashboard'

import Header from '../common/template/header'
import SideBar from '../common/template/sideBar'
import Menu from '../common/template/menu'
import MenuItem from '../common/template/menuItem'
import Footer from  '../common/template/footer'

export default props => (
  <div className='wrapper'>
    <Header path='#/' target='initial-content' />
    <SideBar>
      <Menu>
        <MenuItem path='#/' label='Esteira' icon='icon-belt_icon' target='belt' />
        <MenuItem path='#/' label='Atuador 1' icon='icon-actuator1_icon' target='actuator-1' />
        <MenuItem path='#/' label='Atuador 2' icon='icon-actuator2_icon' target='actuator-2' />
        <MenuItem path='#/' label='Atuador 3' icon='icon-actuator3_icon' target='actuator-3' />
        <MenuItem path='#/' label='Atuador Circular' icon='icon-circularActuator_icon' target='circular-actuator' />
        <MenuItem path='#/' label='Display LCD' icon='icon-lcd_icon' target='lcd' />
        <MenuItem path='#/' label='Sensores de Barreira' icon='icon-laser_icon' target='laser' />
        <MenuItem path='#/' label='Sensor Ultrassônico' icon='icon-ultrasonicSensor_icon' target='ultrasonic-sensor' />
        <MenuItem path='#/' label='Sensor de Cor' icon='icon-colorSensor_icon' target='color-sensor' />
      </Menu>
    </SideBar>
    <div className='content-wrapper'>
      <Dashboard />
    </div>
    <Footer />
  </div>
)
