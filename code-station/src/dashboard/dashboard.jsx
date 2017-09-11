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

class Dashboard extends Component {

    render() {
        return (
            <div> 
                <Content>
                    <Row> 
                        <Itens cols='4'>
                            <ItensHeader>
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
                                <ItemContent id='belt'><h1>Esteira</h1></ItemContent>
                                <ItemContent id='actuator-1'><h1>Atuador 1</h1></ItemContent>
                                <ItemContent id='actuator-2'><h1>Atuador 2</h1></ItemContent>
                                <ItemContent id='actuator-3'><h1>Atuador 3</h1></ItemContent>
                                <ItemContent id='circular-actuator'><h1>Atuador Circular</h1></ItemContent>
                                <ItemContent id='lcd'><h1>LCD</h1></ItemContent>
                                <ItemContent id='laser'><h1>Laser</h1></ItemContent>
                                <ItemContent id='ultrasonic-sensor'><h1>Sensor Ultrassonico</h1></ItemContent>
                                <ItemContent id='color-sensor'><h1>Sensor de Cor</h1></ItemContent>
                            </ItensContent>
                        </Itens> 
                    </Row> 
                </Content> 
            </div>
        )
    }
}

export default Dashboard