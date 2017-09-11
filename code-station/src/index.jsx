import React from 'react'
import { render } from 'react-dom'
import { Provider } from 'react-redux'
import { createStore } from 'redux'
import rootReducer from './main/reducers'
import App from './main/app'

let store = createStore(rootReducer)

render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById('app')
)





//import React from 'react';
//import ReactDOM from 'react-dom'
//import App from './main/app';


//ReactDOM.render(<App />, document.getElementById('app'));
