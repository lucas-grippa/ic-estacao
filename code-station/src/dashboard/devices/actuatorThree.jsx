import React from 'react'
import actuator3_img from '../../common/assets/images/actuator3_img.png'

export default props => (
    <div>
        <img src={actuator3_img} className="img-thumbnail" alt="Responsive image" /> 
        <p>Este atuador linear de passo tem como objetivo "carimbar" as peças do processo.
           Ele pode ser utilizado em modo "digital", onde pode ser programado para avançar e 
           recuar totalmente, ou em modo "passo" onde pode ser programado para avançar e
           recuar de forma parcial, através de um numero de passos fornecido. Em ambos os modos
           a velocidade do atuador pode ser controlada.
           Ele possui dois sensores digitais, um de avanço e outro de recuo.</p>
        <hr/>
        <i className='fa fa-microchip'></i>&nbsp;<strong>Sensores</strong><br/><br/>

        <code>atuador3.getDirection()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor <b>1</b>
        &nbsp; se o atuador estiver avançado ou avançando, ou valor <b>0</b>, se o
        atuador estiver recuado ou recuando.
        </p>  
        <hr/>
        <code>atuador3.isItForward()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o atuador estiver totalmente avançado, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>
        <code>atuador3.isItBackward()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o atuador estiver totalmente recuado, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>

        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>

        <code>atuador3.setSpeed(int)</code><br/><br/>
        <p>Esta função configura a velocidade do atuador
           Recebe uma variavel do tipo <code>int</code> com valor
           entre <b>0</b> e <b>200</b>.</p>
        <hr/>
        <code>atuador3.getSpeed()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor da velocidade
           que foi definida.</p>
        <hr/>
        <code>atuador3.goForward()</code><br/><br/>
        <p>Esta função faz o atuador <b>avançar</b>.</p>
        <hr/>
        <code>atuador3.goBackward()</code><br/><br/>
        <p>Esta função faz o atuador <b>recuar</b>.</p>
        <hr/>
        <code>atuador3.stepModeOn()</code><br/><br/>
        <p>Esta função liga o modo "passo" do atuador.</p>
        <hr/>
        <code>atuador3.stepModeOff()</code><br/><br/>
        <p>Esta função desliga o modo "passo" do atuador.</p>
        <hr/>
        <code>atuador3.getStepModeStatus()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor <b>1</b>
        &nbsp; se o modo "passo" do atuador estiver ligado, ou valor <b>0</b>, 
        caso contrário.</p>
        <hr/>
        <code>atuador3.getSteps()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor de passos
        que foi definido.</p>
        <hr/>
        <code>atuador3.goForwardSteps(int)</code><br/><br/>
        <p>Esta função faz o atuador avançar a quantidade de passos, na forma
           de um <code>int</code>, enviada através de seu argumento.</p>
        <hr/>
        <code>atuador3.goBackwardSteps(int)</code><br/><br/>
        <p>Esta função faz o atuador recuar a quantidade de passos, na forma
           de um <code>int</code>, enviada através de seu argumento.</p>
    </div>
)