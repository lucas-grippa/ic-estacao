import React, { Component } from 'react'
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

import Content from '../common/template/content'
import Row from  '../common/layout/row'
import Itens from '../common/item/itens'
import ItensHeader from '../common/item/itensHeader'
import ItemHeader from '../common/item/itemHeader'
import ItensContent from '../common/item/itensContent'
import ItemContent from '../common/item/itemContent'
import { selectItem } from '../common/item/itemActions'

import ConveyorBelt from './devices/conveyorBelt'
import ActuatorOne from './devices/actuatorOne'
import ActuatorTwo from './devices/actuatorTwo'
import ActuatorThree from './devices/actuatorThree'
import CircularActuator from './devices/circularActuator'
import DisplayLcd from './devices/displayLcd'
import BarrierSensor from './devices/barrierSensor'
import UltrasonicSensor from './devices/ultrasonicSensor'
import ColorSensor from './devices/colorSensor'

import CodeEditor from './codeEditor/codeEditor'

class Dashboard extends Component {

    componentWillMount() {
        this.props.selectItem('initial-content')
    }

    render() {
        return (
            <div> 
                <Content>
                    <Row> 
                        <Itens cols='4'>
                            <ItensHeader>
                                <ItemHeader id='initial-content' label='Station Devices' />
                                <ItemHeader id='belt' label='Esteira' />
                                <ItemHeader id='actuator-1' label='Atuador 1' />
                                <ItemHeader id='actuator-2' label='Atuador 2' />
                                <ItemHeader id='actuator-3' label='Atuador 3' />
                                <ItemHeader id='circular-actuator' label='Atuador Circular' />
                                <ItemHeader id='lcd' label='Display LCD' />
                                <ItemHeader id='laser' label='Sensores de Barreira' />
                                <ItemHeader id='ultrasonic-sensor' label='Sensor Ultrassônico' />
                                <ItemHeader id='color-sensor' label='Sensor De Cor' />
                            </ItensHeader>
                            <ItensContent>
                                <ItemContent id='initial-content'><h1>inicial</h1></ItemContent>
                                <ItemContent id='belt'><ConveyorBelt /></ItemContent>
                                <ItemContent id='actuator-1'><ActuatorOne /></ItemContent>
                                <ItemContent id='actuator-2'><ActuatorTwo /></ItemContent>
                                <ItemContent id='actuator-3'><ActuatorThree /></ItemContent>
                                <ItemContent id='circular-actuator'><CircularActuator /></ItemContent>
                                <ItemContent id='lcd'><DisplayLcd /></ItemContent>
                                <ItemContent id='laser'><BarrierSensor /></ItemContent>
                                <ItemContent id='ultrasonic-sensor'><UltrasonicSensor /></ItemContent>
                                <ItemContent id='color-sensor'><ColorSensor /></ItemContent>
                            </ItensContent>
                        </Itens>
                        <CodeEditor cols='8' /> 
                    </Row> 
                    
                        
                </Content> 
            </div>
        )
    }
}

const mapDispatchToProps = dispatch => bindActionCreators({selectItem}, dispatch)
export default connect(null, mapDispatchToProps)(Dashboard)