import React from 'react'
import belt_img from '../../common/assets/images/belt_img.png'

export default props => (
    <div>
        <img src={belt_img} className="img-thumbnail" alt="Responsive image" /> 
        <p>A esteira tem como objetivo transportar as peças ao longo da estação.</p>
        <hr/>
        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>
        
        <code>esteira.setSpeed(int)</code><br/><br/>
        <p>Esta função configura a velocidade da esteira.<br/>
           Recebe uma variavel do tipo <code>int</code> com valor
           entre <b>0</b> e <b>50</b></p>
        <hr/>
        <code>esteira.setDirectionToRight()</code><br/><br/>
        <p>Esta função configura o sentido de rotação da
            esteira para a direita.
        </p>
        <hr/>
        <code>esteira.setDirectionToLeft()</code><br/><br/>
        <p>Esta função configura o sentido de rotação da
            esteira para a esquerda.
        </p>
        <hr/>
        <code>esteira.turnOn()</code><br/><br/>
        <p>Esta função liga a esteira.<br/>
        </p>
        <hr/>
        <code>esteira.turnOff()</code><br/><br/>
        <p>Esta função desliga a esteira.
        </p>
        <hr/>
        <code>esteira.getOnOffStatus()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor <b>1</b>
           &nbsp; se a esteira estiver ligada, ou valor <b>0</b>, se estiver
           deligada.
        </p>  
   </div>
)