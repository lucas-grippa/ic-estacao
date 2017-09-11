import React, { Component } from 'react'
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

import { selectItem } from '../item/itemActions'

class MenuItem extends Component {
    render() {
        return (
            <li> 
                <a href={this.props.path}
                    data-toggle='item'
                    onClick={() => this.props.selectItem(this.props.target)}
                    data-target={this.props.target}>
                    <i className={this.props.icon}></i> <span className='menu-item-content'>&nbsp; {this.props.label}</span>
                 </a>
            </li>
        )
    }
}

const mapStateToProps = state => ({item : state.item})
const mapDispatchToProps = dispatch => bindActionCreators({selectItem}, dispatch)
export default connect(mapStateToProps, mapDispatchToProps)(MenuItem)