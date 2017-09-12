import React from 'react'
import ultrasonic_sensor_img from '../../common/assets/images/ultrasonic_sensor_img.png'

export default props => (
    <div>
        <img src={ultrasonic_sensor_img} className="img-thumbnail" alt="Responsive image" />
        <p> Este sensor é capaz de medir distancias através de um emissor ultrassônico, um receptor
            e um circuito de controle. Dessa forma podemos medir a altura das peças. 
            A estação possui um sensor deste tipo localizado na frente do reservatório 
            de peças, assim a medição pode ser feita quando uma peça é empurrada para 
            fora do reservatório e cai na esteira<br/>
        </p>
        <hr/>
        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>
        
        <code>sensorUltrassonico.getHeight()</code><br/><br/>
        <p>Esta função retorna um <code>float</code> com a altura medida
           no momento em que a função é chamada</p>
        <hr/>
        <code>sensorUltrassonico.isItShort()</code><br/><br/>
        <p> Esta função retorna um <code>boolean</code> com valor <b>true</b>&nbsp;
            se a peça medida for do tipo "pequena", ou valor <b>false</b> caso
            não seja.</p>
        <hr/>
        <code>sensorUltrassonico.isItHigh()</code><br/><br/>
        <p> Esta função retorna um <code>boolean</code> com valor <b>true</b>&nbsp;
            se a peça medida for do tipo "grande", ou valor <b>false</b> caso
            não seja.</p>
    </div>
 
)