import React, { Component } from 'react';
import { render } from 'react-dom'
import Grid from '../../common/layout/grid'

import MonacoEditor from '../../react-monaco-editor-electron/src';

class CodeEditor extends Component {
   
    render() {
      const defaultCode = "void TaskControleEstacao(void *pvParameters)\n{\n  (void) pvParameters; \n \n  //Escreva suas variáveis globais e funções aqui \n \n  for (;;) \n  { \n \n    //Escreva seu algoritimo aqui \n \n  }\n}"
      const options = {
        selectOnLineNumbers: true,
        roundedSelection: false,
        readOnly: false,
        cursorStyle: 'line',
        automaticLayout: true,
      };
      return (
        <Grid cols={this.props.cols}>
          <div className='code-editor-wrapper'>
            <MonacoEditor
              language="cpp"
              theme="vs-dark"
              value={defaultCode}
              options={options}
            />
          </div>
        </Grid> 
      );
    }
  }
  
  

export default CodeEditor