import React from 'react'
import laser_img from '../../common/assets/images/laser_img.png'

export default props => (
    <div>
        <img src={laser_img} className="img-thumbnail" alt="Responsive image" /> 
        <p>Os sensores de barreira da estação funcionam de maneira digital e são 
            baseados em dois componentes: um módulo laser, que atua como emissor, 
            e um LDR (Light Dependent Resistor), que atua como recepetor. Dessa forma
            uma "barreira" de luz é formada entre os dois módulos e o sensor envia 
            um sinal se esta "barreira" for interrompida.
            A estação possui 5 sensores de barreira:<br/>
        </p>
            <ul>
                <li>
                    Quatro na esteira.
                    <ul>
                        <li>
                            Antes do sensor de cor.<br/>
                            <code>sensorDeBareira1</code>
                        </li>
                        <li>
                            Antes do atuador 3.<br/>
                            <code>sensorDeBareira2</code>
                        </li>
                        <li>
                            Antes do atuador 2.<br/>
                            <code>sensorDeBareira3</code>
                        </li>
                        <li>
                            No fim da esteira.<br/>
                            <code>sensorDeBareira4</code>
                        </li>
                    </ul>
                </li>
                <li>
                    Um no reservatório de peças.<br/>
                    <code>sensorDeBareira5</code>
                </li>
            </ul>
        
        <hr/>
        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>
        
        <code>sensorDeBareira.laserChangeState()</code><br/><br/>
        <p>Esta função muda o estado do laser, ou seja
            vai liga-lo caso esteja desligado, ou desliga-lo
            caso esteja ligado.</p>
        <hr/>
        <code>sensorDeBareira.lightBlocked()</code><br/><br/>
        <p>Esta função retorna um <code>boolean</code> com valor <b>true</b>
        &nbsp; se o feixe de luz estiver bloqueado, ou valor <b>false</b> caso
        não esteja.</p>
    </div>
)