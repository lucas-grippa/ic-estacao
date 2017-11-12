import React from 'react'
import station_img from '../../common/assets/images/station_img.png'

export default props => (
    <div>
        <img src={station_img} className="img-thumbnail" alt="Responsive image" /> 
        <p><strong>Bem vindo a Code Station!</strong><br/>
        Este software permite que a estação automatizada seja programada de maneira
        extremamente simples, fazendo do dispositivo uma ótima plataforma de ensino técnico.
        </p>
        <hr/>

        <strong>Como Funciona</strong><br/><br/>
        <p>Este software utiliza o firmware da estação para abstrair ao maximo o código necessário para que
        tudo funcione, isso é feito gerando um código com todas as bibliotecas e configurações necessárias que é
        exacutado de forma paralela em um RTOS (Real Time Operating System) instalado no microcontrolador da estação.
        Dessa forma você só precisa se preocupar com funções de alto nivel que cada dispositivo da estação possui em sua
        biblioteca, essas funções podem ser utilizadas sem nenhum código adicional (nada precisa ser importado ou instanciado 
        é só escrever a função e pronto!)
        </p>
        <hr/>
        <i className='fa fa-arrow-left'></i>&nbsp;<strong>Dispositivos da Estação</strong><br/><br/>
        <p>Os dispositivos disponiveis na estação estão listados no menu ao lado, cada um deles possui suas
            próprias funções é só clicar para ver quais são e o que cada uma faz.
        </p>
        <hr/>
        <strong>Editor de Código</strong>&nbsp;<i className='fa fa-arrow-right'></i><br/><br/>
        <p>Do lado direito da interface está o editor de código, é aqui que você desenvolve seu algoritimo.
            Quando estiver tudo pronto é só exportar o código e fazer upload para a estação utilizando a Arduino IDE.
        </p>
    </div>
)