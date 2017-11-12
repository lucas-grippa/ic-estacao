import React from 'react'
import lcd_img from '../../common/assets/images/lcd_img.png'

export default props => (
    <div>
        <img src={lcd_img} className="img-thumbnail" alt="Responsive image" /> 
        <p>Este display LCD pode exibir até duas linhas de 16 caracteres.
           Pode ser usado para exibir qualquer tipo de informação, como por exemplo:
           a quantidade de peça que passaram pelo processo, cores das peças, etc. 
        </p>
        <hr/>
        <i className='fa fa-code'></i>&nbsp;<strong>Funções</strong><br/><br/>
        
        <code>displayLcd.setLine1(String)</code><br/><br/>
        <p>Esta função recebe um argumento do tipo
           <code>String</code> de até <b>16</b> caracteres que é 
           exibido na primeira linha do display LCD.</p>
        <hr/>
        <code>displayLcd.setLine2(String)</code><br/><br/>
        <p>Esta função recebe um argumento do tipo
           <code>String</code> de até <b>16</b> caracteres que é 
           exibido na segunda linha do display LCD.</p>
        <hr/>
        <code>displayLcd.getLine1()</code><br/><br/>
        <p>Esta função retorna uma <code>String</code> com o 
           conteúdo da primeira linha do display LCD.</p>
        <hr/>
        <code>displayLcd.getLine2()</code><br/><br/>
        <p>Esta função retorna uma <code>String</code> com o 
           conteúdo da segunda linha do display LCD.</p>
    </div>
)