import React, { Component } from 'react'
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

import If from '../operator/if'

class ItemHeader extends Component {
    render () {
        const selected = this.props.item.selected === this.props.id
        return (
            <If test={selected}>
                <li className={selected ? 'active' : ''}> 
                    <a href='javascript:;'>
                        {this.props.label}
                    </a> 
                </li> 
            </If>
        )
    }
}

const mapStateToProps = state => ({item: state.item})
export default connect(mapStateToProps)(ItemHeader)