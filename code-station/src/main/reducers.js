import { combineReducers } from 'redux'

import ItemReducer from '../common/item/itemReducer'

const rootReducer = combineReducers({
    item: ItemReducer
})

export default rootReducer