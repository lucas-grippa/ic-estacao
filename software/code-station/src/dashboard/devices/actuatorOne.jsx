import React from 'react'
import actuator1_img from '../../common/assets/images/actuator1_img.png'

export default props => (
    <div>
        <img src={actuator1_img} className="img-thumbnail" alt="Responsive image" /> 
        <p>Este atuador linear tem como objetivo empurrar as peças
            do reservatório para que elas caiam na esteira transportadora.
            Ele possui dois sensores digitais, um de avanço e outro de
            recuo.</p>
        <hr/>
        <i className='fa fa-microchip'></i>&nbsp;<strong>Sensores</strong><br/><br/>
        
        <code>atuador1.getDirection()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor <b>1</b>
        &nbsp; se o atuador estiver avançado ou avançando, ou valor <b>0</b>, se o
        atuador estiver recuado ou recuando.
        </p>  
        <hr/>
        <code>atuador1.isItForward()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o atuador estiver totalmente avançado, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>
        <code>atuador1.isItBackward()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o atuador estiver totalmente recuado, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>

        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>
        
        <code>atuador1.goForward()</code><br/><br/>
        <p>Esta função faz o atuador <b>avançar</b>.</p>
        <hr/>
        <code>atuador1.goBackward()</code><br/><br/>
        <p>Esta função faz o atuador <b>recuar</b>.</p>
        
    </div>
)