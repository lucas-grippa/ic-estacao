import React from 'react'
import { shell } from 'electron';

export default props => (
    <footer className='main-footer'>
        <small>
            Desenvolvido por <strong>Lucas Grippa</strong> &nbsp;
            <a onClick={() => shell.openExternal('https://github.com/lucas-grippa/ic-estacao')}><i className='fa fa-github' aria-hidden="true"></i></a>
            &nbsp; 2017 
        </small>
    </footer>   
)