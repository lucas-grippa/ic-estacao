export function selectItem(itemId) {
    console.log(itemId)
    return {
        type: 'ITEM_SELECTED',
        payload: itemId
    }
}