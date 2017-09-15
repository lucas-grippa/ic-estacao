import React from 'react'
import color_sensor_img from '../../common/assets/images/color_sensor_img.png'

export default props => (
    <div>
        <img src={color_sensor_img} className="img-thumbnail" alt="Responsive image" /> 
        <p> Este sensor é capaz de idenficar cores em todo o espectro 
            visível da luz.
            A estação possui um sensor deste tipo localizado em cima da parede
            esquerda da esteira.<br/>
        </p>
        <hr/>
        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>

        <code>sensorDeCor.isItRed()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>&nbsp;
        se a peça medida for vermelha, ou valor <b>false</b> caso
        não seja.</p>
        <hr/>
        <code>sensorDeCor.isItGreen()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>&nbsp;
        se a peça medida for verde, ou valor <b>false</b> caso
        não seja.</p>
        <hr/>
        <code>sensorDeCor.isItBlue()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>&nbsp;
        se a peça medida for azul, ou valor <b>false</b> caso
        não seja.</p>
    </div>
)