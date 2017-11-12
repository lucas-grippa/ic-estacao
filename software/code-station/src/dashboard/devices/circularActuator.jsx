import React from 'react'
import circular_actuator_img from '../../common/assets/images/circular_actuator_img.png'

export default props => (
    <div>
        <img src={circular_actuator_img} className="img-thumbnail" alt="Responsive image" />
        <p>Este atuador circular é o reservatório final das peças.
           Pode ser rotacionado para que qualquer um dos três tubos
           fique posicionado de forma perpendicular a esteira.
           Ele possui três sensores digitais, um para cada tubo (1,2 e 3), 
           que são acionados assim que seu respectivo tubo passa pela 
           esteira.</p>
        <hr/>
        <i className='fa fa-microchip'></i>&nbsp;<strong>Sensores</strong><br/><br/>

        <code>atuadorCircular.getPosition()</code><br/><br/>
        <p>Esta função retorna um <code>int</code> com valor <b>1,2</b> ou <b>3</b>, 
        de acordo com qual tubo do reservatório estiver posicionado
        de forma perpendicular a esteira.
        </p>  
        <hr/>
        <code>atuadorCircular.isItInPosition1()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o tubo 1 do reservatório estiver posicionado
        de forma perpendicular a esteira, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>
        <code>atuadorCircular.isItInPosition2()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o tubo 2 do reservatório estiver posicionado
        de forma perpendicular a esteira, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>
        <code>atuadorCircular.isItInPosition3()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o tubo 3 do reservatório estiver posicionado
        de forma perpendicular a esteira, ou valor <b>false</b> caso
        contrário.
        </p>  
        <hr/>

        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>

        <code>atuadorCircular.setSpeed(int)</code><br/><br/>
        <p>Esta função configura a velocidade do atuador
           Recebe uma variavel do tipo <code>int</code> com valor
           entre <b>0</b> e <b>50</b>.</p>
        <hr/>
        <code>atuadorCircular.goToPosition1()</code><br/><br/>
        <p>Esta função faz o atuador mover o tubo 1 do reservatório para a esteira.</p>
        <hr/>
        <code>atuadorCircular.goToPosition2()</code><br/><br/>
        <p>Esta função faz o atuador mover o tubo 2 do reservatório para a esteira.</p>
        <hr/>
        <code>atuadorCircular.goToPosition3()</code><br/><br/>
        <p>Esta função faz o atuador mover o tubo 3 do reservatório para a esteira.</p>
    </div> 
)